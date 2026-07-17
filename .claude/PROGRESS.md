# OpenDBO-Core — กระดานงานร่วม (Multi-Agent Coordination Board)

> ไฟล์นี้คือ "จุดนัดพบ" ของ AI ทุกตัวที่เข้ามาแตะโปรเจกต์นี้ — Claude (main session)
> และ agent ที่ถูก delegate ผ่าน `.claude/tools/opencode-agent-task.js` / `opencode-zen.js`
>
> **กติกา:** ก่อนเริ่มงานใดๆ ต้องอ่านไฟล์นี้ก่อนเสมอ เพื่อรู้ว่ามีงานค้าง/งานที่คนอื่นถืออยู่หรือไม่
> เมื่อเริ่มงาน ต้อง "จอง" แถวในตาราง Active Tasks ก่อนแก้ไฟล์ เมื่อเสร็จ ต้องย้ายไปตาราง Completed Log
> พร้อมสรุปสั้นๆ ว่าทำอะไรไป — ห้ามแก้ไฟล์เดียวกันพร้อมกันกับงานที่ "Active" อยู่แล้วโดยไม่เช็คก่อน

อ้างอิงบริบทโปรเจกต์เต็ม: [`AGENTS.md`](../AGENTS.md)

---

## 1. Active Tasks (งานที่กำลังทำอยู่ตอนนี้)

| # | ผู้รับผิดชอบ | งาน | ไฟล์ที่แตะ | เริ่มเมื่อ | สถานะ |
|---|---|---|---|---|---|
| _ยังไม่มีงาน active_ | | | | | |

> เพิ่มแถวใหม่ที่นี่ก่อนแก้โค้ด ระบุ **ไฟล์/ระบบที่คาดว่าจะแตะ** ให้ชัด เพื่อให้ agent อื่นเช็คการชนกันได้ทันที

---

## 2. Backlog / งานที่รู้ว่ามีแต่ยังไม่ได้ทำ

### 2.1 บั๊ก/ของหายในเวอร์ชัน Main เอง (AGENTS.md §5)

- [ ] Dogi system (`UG_DOGI_CREATE_REQ`, `UG_DOGI_CHANGE_REQ`) — ปัจจุบัน map เป็น OnInvalid *(พังทั้ง Main และ V2 — ดู 2.3)*
- [ ] Remote shop/repair/identify (5 opcodes) — OnInvalid *(พังทั้งคู่)*
- [ ] Budokai GM features (5 opcodes) — OnInvalid *(พังทั้งคู่)*
- [ ] Cash shop start/end opcodes — ไม่ได้ลงทะเบียนเลย
- [ ] ~30 Quest event types ที่ยังเป็น stub (item_use, skill_use, budokai, slot_machine, hoipoi_mix, private_shop, free_battle ฯลฯ)
- [ ] DWC (Dynamic World Control) — 5 node types ถูก comment ทิ้งไว้ *(พังทั้งคู่)*
- [ ] BotAi cross-system relay stubs (SPS/AIS ↔ WPS/TQS) *(พังทั้งคู่)*
- [ ] Budokai ranking hardcoded เป็น 4544
- [ ] TMQ EXP ไม่มีการคำนวณจริง ("ALWAYS EXP")
- [ ] `Skill - Copy.cpp` — ไฟล์ dead code ควรลบ

### 2.2 พอร์ตฟีเจอร์จาก V2 (dbo-2023) → Main (AGENTS.md §11)

> Source: `D:\DBOGLOBALV2\dbo-2023\dbo-2023\` — โค้ดฐานเดียวกัน แต่มีฟีเจอร์ครบกว่า
> ก่อน delegate งาน porting ต้องแนบ AGENTS.md §11 (ตารางที่เกี่ยวข้อง) ในพรอมต์เสมอ
> เพราะมีชื่อไฟล์/opcode/struct field เฉพาะที่ agent ย่อยเดาไม่ได้

**🟢 High priority**
- [ ] 7 transformation classes ใหม่ (SSJ2, SSJ3, SSJ Blue, Evil Boo, Super Boo, Evil Namek, King Namek) — copy .h/.cpp ตรงๆ, effort ต่ำ
- [ ] Fairy Event system
- [x] ~~EventTimeTable~~ table parser พอร์ตแล้ว (2026-07-18) — แต่ enhanced ExpEvent (logic ที่ใช้ตารางนี้) ยังไม่ทำ
- [ ] MascotEx + MascotFusion + MascotSkillReMake GUI
- [ ] GiftShop + NetPyShop + WaguMachine GUI
- [ ] WorldBoss GUI + DynamicField GUI
- [x] ~~Drop tables (7+ table parser ใหม่)~~ พอร์ตครบแล้ว (2026-07-18) — ดู Completed Log

**🟡 Medium priority**
- [ ] Scouter Start opcode (`UG_SCOUTER_START_REQ`) + handler
- [ ] Exp Toggle opcodes (`UG_EXP_ENABLED_REQ`, `UG_RESET_EXP_REQ`) + handler
- [ ] Skill Reset Plus handler (`UG_SKILL_RESET_PLUS_REQ`)
- [ ] AggroListGui, DropItemOwnerShipGui, BroadCastSystem, PreviewGui
- [ ] EventTimeTableGui, EventReward*, EventMachine* GUI
- [ ] Protocol struct fixes: `UG_CHAR_EXIT_REQ` (ขาด `bool bIsItem`), `UG_EVENT_REWARD_SELECT_REQ` (ขาด `eventId`) ⚠️ ต้องเช็ค backward-compat ก่อนแก้ struct
- [ ] Web Integration (MasterServer/WebPacket.cpp, port 40000, 5 API functions)

**🔵 Low priority**
- [x] ~~VirtualKeyboardGui~~ พอร์ตครบแล้ว (2026-07-18) — ดู Completed Log
- [ ] TreasureBoxGui, ScouterOld* GUI
- [ ] ContentsConditionTable

**Porting checklist ต่อ 1 ระบบ** (AGENTS.md §11.4): copy files → register ใน manager ที่เกี่ยวข้อง → เพิ่ม enum ถ้าจำเป็น → เพิ่ม .rdf data ถ้าจำเป็น → เพิ่มใน .vcxproj → เช็คชื่อชนกัน/symbol ซ้ำ

### 2.3 พังทั้ง Main และ V2 (ไม่ต้อง port เพราะ V2 ก็ไม่มี — ไม่ใช่ backlog เร่งด่วน)

Dogi, Remote Shop, Budokai GM (5 opcodes), Budokai Prize Winner Team Name, DWC, BotAiAction_SPS_SendEvent กลุ่ม, BotAiCondition_AIS_* กลุ่ม, BotBreakUp::AddMove_Level3/4, Npc::OnMsg_YouHit, Sliding/Knockdown, RecvCharStandingSlip(End), PlayBgm/PlayJingle CheckParameter

---

## 3. Completed Log (ประวัติงานที่เสร็จแล้ว — ใหม่สุดบนสุด)

| วันที่ | ผู้ทำ | งาน | ผลลัพธ์/ไฟล์ที่เปลี่ยน | หมายเหตุ |
|---|---|---|---|---|
| 2026-07-18 | Claude | พอร์ต `VirtualKeyboardGui` (คีย์บอร์ดเสมือนหน้า login) จาก V2 เข้า Main ครบทั้ง C++ และ resource pack: (1) คัดลอก `VirtualKeyboardGui.h/.cpp` เข้า `DboClient/Client/Gui/`, (2) เพิ่ม event `g_EventVirtualKeyboard`/`SDboEventKeyboard`/`SendVirtualKeyboard()` ใน `DboEvent.h/.cpp`, `DboEventGenerator.h/.cpp`, `DboEventHandler.cpp`, (3) แก้ `LoginGui.h/.cpp` เพิ่มปุ่ม toggle (`VirtualKeyButton`), การสร้าง/destroy คีย์บอร์ด, GotFocus handler (Account ซ่อน/Password โชว์), (4) เขียนเครื่องมือ unpack/repack pak ใหม่ (`GuiPakTool`, scratch — ใช้ `CNtlFileSerializer`/`CNtlCipher` ของโปรเจกต์เองเพื่อความถูกต้องของ DES header encryption) มา unpack `gui.pak`/`gui0.pak` จริง (632 entries, verify round-trip 100%) แล้วแก้ `login.frm` เพิ่มปุ่ม `VirtualKeyButton` (ใช้ surface เดิม `srfNormalBtnUp/Down/Foc` ของ Main เพราะ `rsrLogin6`/`TW_login.PNG` ที่ V2 อ้างอิงไม่มีใน Main) + เพิ่ม `virtualkeyboard.frm/rsr/srf` ใหม่ 3 ไฟล์ (คัดลอกจาก V2 ตรงๆ) แล้ว repack เป็น 635 entries, (5) พบว่า `VirtualKeyboard.srf` ทุก surface (พื้นหลัง+ปุ่มทุกปุ่ม) อ้างอิง texture เดียวคือ `TW_login.PNG` ที่ไม่มีใน Main's `tex.pak` เลย — เพิ่มเครื่องมือโหมด `addunit` เพื่อเพิ่ม texture เป็น unit ใหม่ (unit 62) แยกจากของเดิมทั้งหมด (ไม่แตะ 62 unit เดิม) เข้า `tex.pak`+`tex62.pak` ใหม่ | `DboClient/Client/Gui/VirtualKeyboardGui.h,.cpp`, `DboEvent.h/.cpp`, `DboEventGenerator.h/.cpp`, `DboEventHandler.cpp`, `LoginGui.h/.cpp`, `DboClient/Client/Client.vcxproj(.filters)`, `DboClient/DragonBall/pack/gui.pak`, `gui0.pak`, `tex.pak`, `tex62.pak` (ของเดิมสำรองไว้เป็น `.bak` ทั้งหมด) | Build `DboClient.sln` (Win32/Release) ผ่าน — ต้องส่ง `DXSDK_DIR`/`GFXSDK_DIR`/`XtremeToolkitPro_Dir` เป็น MSBuild property ตรงๆ เพราะ shell ที่ใช้ build ไม่เห็น env var ที่ตั้งไว้ใน registry ทดสอบเปิด client จริง คลิกช่อง Password → คีย์บอร์ดเสมือนขึ้นครบพร้อม texture/label ถูกต้อง (ยืนยันด้วย screenshot) จุดที่ยังไม่สมบูรณ์: ปุ่ม `VirtualKeyButton`/ปุ่มบนคีย์บอร์ดยังไม่มีข้อความ localization (`DST_VIRTUALKEY*`) ใน Main จึงโชว์ fallback "String not found" — ไม่กระทบการทำงาน เป็นแค่ label |
| 2026-07-18 | Claude | พอร์ต 16 game data table parser class จาก V2 (dbo-2023) เข้า Main ครบ: BasicDropTable, ClassTable, ContentsConditionTable, EachDropTable, EventTimeTable, ExcellentDropTable, GameManiaTimeTable, ItemEnchantRateTable, ItemOptionValueProbabilityTable, ItemUpgradeRateTable, LegendaryDropTable, NormalDropTable, RaceTable, SuperiorDropTable, TextServerTable, TypeDropTable + เพิ่ม ConvertTableTXT/LoadFromTXT ให้ QuestDropTable เดิม | `DboShared/NtlGameTable/*.h,*.cpp` (ไฟล์ใหม่ 32 ไฟล์ + Table.h/.cpp เพิ่ม helper `split`/`sti`), `TableContainer.h/.cpp`, `NtlGameTable.vcxproj(.filters)`, `DboServer/Server/GameServer/TableContainerManager.cpp`, `DboServer/ExecutionEnv/resource/server_data/table/rdf/*.rdf` (14 ไฟล์ข้อมูลจริงจาก V2 staging) | ลงทะเบียนโหลดจริงเฉพาะ GameServer (14/16 ตาราง มีข้อมูลจริง, เว้น BasicDrop/GameManiaTime ไม่มี .rdf); เจอ 3 ปัญหาระหว่าง build: (1) `CTable::Destroy()` เป็น private ใน Main ต่างจาก V2 — ลบการเรียก base call ออกจาก Destroy() ของทั้ง 15 คลาส ให้ตรงกับ pattern เดิมของ QuestDropTable, (2) V2's Table.h มี `using namespace std;` ที่ Main ไม่มี — เพิ่ม `split()`/`sti()` helper ลง Table.h/.cpp แบบ qualify ด้วย `std::` แทนการเพิ่ม `using namespace std` ระดับ global, (3) พบไฟล์ `EachDropTable.cpp` เข้ารหัส UTF-16LE ต่างจากไฟล์อื่น (ASCII/UTF-8) ทำให้ sed แก้ไม่ติด ต้องแปลงเข้ารหัสเฉพาะไฟล์นั้น — build ผ่านทั้ง NtlGameTable.lib และ GameServer.exe (Release\|x64) สำเร็จ ทดสอบรัน full server chain แล้ว (2026-07-18): build ทั้ง `DboServer.sln` (ผ่าน `SolutionDir` ให้ exe deploy ไป `DboServer/ExecutionEnv/` ถูกที่ — build แค่ .vcxproj เดี่ยวจะ deploy ผิดที่) แล้วสตาร์ททั้ง 6 เซิร์ฟเวอร์ตามลำดับ (Master→Query→Auth→Char→Game→Chat) ทุกตัว Responding=True และ listen port ถูกต้องครบ (40001/41000/20200/20300/30000/20400) ไม่มี crash จากการโหลดตารางใหม่ |
| 2026-07-17 | Claude | อ่าน AGENTS.md §11 (V2 porting reference) ที่เพิ่มใหม่ + อัปเดต backlog ใน PROGRESS.md §2 | .claude/PROGRESS.md | แยก backlog เป็น 3 กลุ่ม: บั๊ก Main เอง / porting จาก V2 / พังทั้งคู่ |
| 2026-07-17 | Claude | อ่านและสรุป AGENTS.md + .claude/ ให้ผู้ใช้เข้าใจภาพรวม | — | ไม่มีการแก้โค้ด |

---

## 4. กติกาการมอบหมายงาน (Delegation Policy)

อ้างอิง memory: `opencode_zen_delegation.md`

| ระดับความเสี่ยง/ความซับซ้อน | ใครทำ | เครื่องมือ |
|---|---|---|
| ปรึกษา/สรุป/แปล/งานความคิดเบาๆ ไม่แตะไฟล์ | โมเดลอื่นตาม task category | `opencode-zen.js --task=<quick\|code\|reasoning\|translate\|creative\|longdoc>` |
| แก้ไฟล์จริงแต่ขอบเขตแคบ ความเสี่ยงต่ำ (เช่น 1-2 ไฟล์, ไม่แตะ core system) | opencode agent (แล้ว Claude ตรวจ diff ก่อนส่งต่อผู้ใช้) | `opencode-agent-task.js --model=<model> "<งาน>"` |
| งานสถาปัตยกรรม, แก้ core game logic, packet protocol, DB schema, งานเสี่ยงสูง/กว้าง | Claude ทำเอง | — |

**เมื่อ delegate งานใดๆ ต้อง:**
1. จองแถวใน Active Tasks ก่อน (ไฟล์ที่คาดว่าจะแตะ)
2. **แนบส่วนที่เกี่ยวข้องของ AGENTS.md ลงในพรอมต์ตรงๆ เสมอ** — agent ย่อย (opencode-zen /
   opencode-agent) ไม่มี context ของ repo นี้เอง เห็นแค่สิ่งที่ใส่ไปในพรอมต์เท่านั้น
   ตัวอย่างสิ่งที่ควรแนบตามประเภทงาน:
   - แก้ packet handler → §3 Packet Naming Convention + §9 checklist
   - แก้ระบบ stub/disabled → §5 Disabled/Broken Systems (บอกให้ชัดว่าระบบนี้ตั้งใจปิดไว้หรือเป็นบั๊ก)
   - แก้ DB → §6 Database Schema Overview
   - งานทั่วไป → อย่างน้อยควรมี §1 Project Structure ส่วนที่เกี่ยวข้อง
3. ตรวจ diff ที่ได้กลับมาก่อนสรุปให้ผู้ใช้เสมอ (agent ย่อยไม่ auto-commit)
4. ย้ายงานไป Completed Log พร้อมสรุปผลลัพธ์จริง (ไม่ใช่สิ่งที่ agent "อ้างว่าทำ")
