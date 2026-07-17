#!/usr/bin/env node
// เรียก Open Code Zen API (OpenAI-compatible) สำหรับงานง่าย ๆ
// วิธีใช้:
//   node opencode-zen.js "prompt ที่นี่"
//   node opencode-zen.js --model=kimi-k3 "prompt ที่นี่"
//   node opencode-zen.js --task=code "prompt ที่นี่"   (เลือกโมเดลอัตโนมัติตามประเภทงาน)
//   echo "prompt" | node opencode-zen.js
//   node opencode-zen.js --list        (แสดงโมเดลที่เลือกใช้ได้)
//   node opencode-zen.js --tasks       (แสดงหมวดงาน -> โมเดลที่ map ไว้)
//
// ตั้งค่า override ได้ผ่าน env:
//   OPENCODE_API_KEY, OPENCODE_ENDPOINT, OPENCODE_MODEL

const ENDPOINT = process.env.OPENCODE_ENDPOINT || "https://opencode.ai/zen/go/v1/chat/completions";
const API_KEY = process.env.OPENCODE_API_KEY || "sk-r0yWRgQ7b6Hgu4O2nGh2ActJOyjh0QFd52Q79cFUPm8t5EygdBNrRzKS1Oi3gVZI";
const DEFAULT_MODEL = process.env.OPENCODE_MODEL || "deepseek-v4-flash";

// โมเดลที่ผู้ใช้เลือกไว้ใช้งานได้ตามสถานการณ์
const MODELS = {
  "grok-4.5": "Grok 4.5",
  "glm-5.2": "GLM-5.2",
  "glm-5.1": "GLM-5.1",
  "kimi-k3": "Kimi K3",
  "kimi-k2.7-code": "Kimi K2.7 Code",
  "kimi-k2.6": "Kimi K2.6",
  "mimo-v2.5": "MiMo-V2.5",
  "mimo-v2.5-pro": "MiMo-V2.5-Pro",
  "minimax-m3": "MiniMax M3",
  "minimax-m2.7": "MiniMax M2.7",
  "qwen3.7-max": "Qwen3.7 Max",
  "qwen3.7-plus": "Qwen3.7 Plus",
  "qwen3.6-plus": "Qwen3.6 Plus",
  "deepseek-v4-pro": "DeepSeek V4 Pro",
  "deepseek-v4-flash": "DeepSeek V4 Flash",
};

// นโยบายมอบหมายงาน: หมวดงาน -> โมเดลที่เหมาะสม
const TASKS = {
  quick: { model: "deepseek-v4-flash", desc: "ตอบไว งานง่าย สรุปสั้นๆ" },
  code: { model: "kimi-k2.7-code", desc: "เขียน/รีแฟคเตอร์โค้ดเล็กๆ ที่ไม่เสี่ยง" },
  reasoning: { model: "deepseek-v4-pro", desc: "โจทย์ต้องคิด/วิเคราะห์ แต่ไม่ใช่งานสถาปัตยกรรมโปรเจกต์" },
  translate: { model: "qwen3.6-plus", desc: "แปล/เรียบเรียงข้อความ" },
  creative: { model: "minimax-m3", desc: "เขียนคอนเทนต์ เนื้อเรื่อง ข้อความเชิงสร้างสรรค์" },
  longdoc: { model: "qwen3.7-max", desc: "อ่าน/สรุปเอกสารยาว บริบทเยอะ" },
};

function readStdin() {
  return new Promise((resolve) => {
    if (process.stdin.isTTY) return resolve("");
    let data = "";
    process.stdin.setEncoding("utf8");
    process.stdin.on("data", (chunk) => (data += chunk));
    process.stdin.on("end", () => resolve(data.trim()));
  });
}

async function main() {
  const rawArgs = process.argv.slice(2);

  if (rawArgs.includes("--list")) {
    for (const [id, label] of Object.entries(MODELS)) {
      console.log(`${id}\t(${label})`);
    }
    return;
  }

  if (rawArgs.includes("--tasks")) {
    for (const [task, { model, desc }] of Object.entries(TASKS)) {
      console.log(`${task}\t-> ${model}\t(${desc})`);
    }
    return;
  }

  let model = DEFAULT_MODEL;
  const rest = [];
  for (const arg of rawArgs) {
    if (arg.startsWith("--model=")) {
      model = arg.slice("--model=".length);
    } else if (arg.startsWith("--task=")) {
      const task = arg.slice("--task=".length);
      if (!TASKS[task]) {
        console.error(`หมวดงาน "${task}" ไม่รู้จัก ใช้ --tasks เพื่อดูหมวดที่มี`);
        process.exit(1);
      }
      model = TASKS[task].model;
    } else {
      rest.push(arg);
    }
  }

  if (!MODELS[model]) {
    console.error(`โมเดล "${model}" ไม่อยู่ในลิสต์ที่กำหนดไว้ ใช้ --list เพื่อดูรายการที่เลือกได้`);
    process.exit(1);
  }

  const argPrompt = rest.join(" ").trim();
  const prompt = argPrompt || (await readStdin());

  if (!prompt) {
    console.error("ไม่มี prompt ส่งเข้ามา (ใส่เป็น argument หรือ pipe ผ่าน stdin)");
    process.exit(1);
  }

  const res = await fetch(ENDPOINT, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Authorization: `Bearer ${API_KEY}`,
    },
    body: JSON.stringify({
      model,
      messages: [{ role: "user", content: prompt }],
    }),
  });

  if (!res.ok) {
    const text = await res.text();
    console.error(`API error ${res.status}: ${text}`);
    process.exit(1);
  }

  const data = await res.json();
  const reply = data?.choices?.[0]?.message?.content;
  console.log(reply ?? JSON.stringify(data, null, 2));
}

main().catch((err) => {
  console.error("เกิดข้อผิดพลาด:", err.message);
  process.exit(1);
});
