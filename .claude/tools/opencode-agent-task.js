#!/usr/bin/env node
// มอบหมายงานจริง (แก้ไฟล์/รันคำสั่ง) ให้ local opencode agent server ทำแทน
// ต้องมี `opencode --port <PORT>` รันอยู่แล้วในโปรเจกต์นี้ก่อน
//
// วิธีใช้:
//   node opencode-agent-task.js --model=kimi-k2.7-code "งานที่ต้องการมอบหมาย"
//   node opencode-agent-task.js --port=61598 --model=deepseek-v4-flash "..."
//
// ผลลัพธ์: พิมพ์คำตอบของ agent และ diff ของไฟล์ที่ถูกแก้ (ยังไม่ commit ใดๆ)
// ให้ผู้เรียก (Claude) ตรวจสอบก่อนสรุปให้ผู้ใช้เสมอ — สคริปต์นี้ไม่ auto-approve อะไร

const PROVIDER_ID = "opencode-go";
const DEFAULT_MODEL = "deepseek-v4-flash";

function parseArgs(argv) {
  let port = 61598;
  let model = DEFAULT_MODEL;
  const rest = [];
  for (const arg of argv) {
    if (arg.startsWith("--port=")) port = Number(arg.slice("--port=".length));
    else if (arg.startsWith("--model=")) model = arg.slice("--model=".length);
    else rest.push(arg);
  }
  return { port, model, prompt: rest.join(" ").trim() };
}

async function main() {
  const { port, model, prompt } = parseArgs(process.argv.slice(2));
  if (!prompt) {
    console.error("ไม่มี prompt/งานที่จะมอบหมาย");
    process.exit(1);
  }

  const base = `http://127.0.0.1:${port}`;

  const health = await fetch(`${base}/api/health`).catch(() => null);
  if (!health || !health.ok) {
    console.error(`เชื่อมต่อ opencode server ที่ port ${port} ไม่ได้ (ต้องรัน "opencode --port ${port}" ก่อน)`);
    process.exit(1);
  }

  const sessionRes = await fetch(`${base}/session`, { method: "POST" });
  if (!sessionRes.ok) {
    console.error(`สร้าง session ไม่สำเร็จ: ${sessionRes.status} ${await sessionRes.text()}`);
    process.exit(1);
  }
  const session = await sessionRes.json();
  const sessionID = session.id;
  console.log(`session: ${sessionID}`);

  const msgRes = await fetch(`${base}/session/${sessionID}/message`, {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({
      model: { providerID: PROVIDER_ID, modelID: model },
      parts: [{ type: "text", text: prompt }],
    }),
  });

  if (!msgRes.ok) {
    console.error(`ส่งงานไม่สำเร็จ: ${msgRes.status} ${await msgRes.text()}`);
    process.exit(1);
  }

  const msg = await msgRes.json();
  const textParts = (msg.parts || []).filter((p) => p.type === "text").map((p) => p.text);
  console.log("\n=== คำตอบจาก agent ===");
  console.log(textParts.join("\n") || "(ไม่มีข้อความตอบกลับ)");

  const diffRes = await fetch(`${base}/session/${sessionID}/diff?messageID=${msg.info.id}`);
  if (diffRes.ok) {
    const diffs = await diffRes.json();
    if (diffs.length > 0) {
      console.log("\n=== ไฟล์ที่ถูกแก้ (ยังไม่ commit) ===");
      for (const d of diffs) {
        console.log(`\n--- ${d.file} (${d.status}, +${d.additions}/-${d.deletions}) ---`);
        console.log(d.patch || "");
      }
    } else {
      console.log("\n(ไม่มีไฟล์ถูกแก้ไข)");
    }
  }

  console.log(`\nsessionID: ${sessionID} (ใช้ /session/${sessionID}/revert เพื่อยกเลิกการแก้ไขได้)`);
}

main().catch((err) => {
  console.error("เกิดข้อผิดพลาด:", err.message);
  process.exit(1);
});
