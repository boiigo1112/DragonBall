# OpenDBO-Core Project Context

> Dragon Ball Online (DBO) MMORPG Private Server Emulator — Full Client + Server stack
> License: GNU AGPL v3 | Base: DBOG (Dragon Ball Online Global)

---

## 1. Project Structure

```
OpenDBO-Core/
├── DboClient/          ← Game Client (Win32, DirectX 9, RenderWare, Scaleform GFx, FMOD)
│   ├── Client/         ← Main source
│   │   ├── Main/       ← WinMain, Packet handlers
│   │   ├── Gui/        ← ~160+ UI files (login, inventory, chat, quest, shops)
│   │   ├── Stage/      ← Login → Lobby → Char → Game stages
│   │   ├── Camera/     ← Camera control
│   │   ├── Parser/     ← Cheat commands, encryption
│   │   └── Localize/   ← Localization
│   ├── Lib/            ← Client static libs (NtlCore, NtlGui, NtlSound, NtlFlasher, etc.)
│   ├── Tool/           ← ~40 dev tools (WorldEditor, ModelTool, TableEditor, etc.)
│   ├── Renderware/     ← RenderWare 3D SDK
│   └── DboClient.sln   ← VS 2019, Win32
│
├── DboServer/          ← Game Server (x64)
│   ├── Server/
│   │   ├── MasterServer/   ← Central coordinator (ports 40001-40005)
│   │   ├── AuthServer/     ← Login/authentication (20200)
│   │   ├── CharServer/     ← Character selection (20300)
│   │   ├── GameServer/     ← Core gameplay (~1344 files, port 30000)
│   │   ├── ChatServer/     ← Chat/Guild/Party/Auction (20400)
│   │   └── QueryServer/    ← Database gateway (41000-41002)
│   ├── Database/       ← SQL schemas
│   │   ├── dbo_acc.sql
│   │   ├── dbo_char.sql
│   │   └── dbo_log.sql
│   └── ExecutionEnv/   ← Runtime (exes, configs, batch scripts, resource/)
│       └── config/     ← INI configs for all 6 servers
│
├── DboShared/          ← Shared code (Client + Server)
│   ├── DboTrigger/     ← Quest/Event trigger system (~336 files)
│   ├── NtlGameTable/   ← Game data table parsers (~179 files, 80+ table types)
│   └── NtlShared2/     ← Packet definitions, game types, protocol (~153 files)
│
├── NtlLib/             ← Core engine libraries
│   ├── Client/         ← NtlClientNet
│   ├── Server/         ← Database, NtlNetwork, NtlSfx, NtlSystem, NtlThread, servercommon
│   └── Shared/         ← Lua, NtlTrigger, NtlNavi, NtlPathEngine, XML, Zip, Util
│
├── Directory.Build.targets   ← MSBuild (suppresses C4819)
├── README.md
└── LICENSE
```

---

## 2. Tech Stack

| Component | Technology |
|-----------|-----------|
| Language | C++ ~95%, SQL, Lua, Batch |
| Build | Visual Studio 2019 (v142) |
| Client | Win32, DirectX 9, RenderWare 3D, Scaleform GFx 3.3 (Flash UI), FMOD audio |
| Server | x64 console applications, TCP socket inter-server communication |
| Database | MySQL 5.7 (via libmysql.dll) |
| Pathfinding | PathEngine 5.10 (DLL) |
| Scripting | Lua 5.x + lua_tinker, Custom trigger/script system (TQS/WPS/SPS/AIS) |
| UI Framework | Xtreme ToolkitPro v15.2.1 (MFC) |
| Other | zlib, BugTrap, Discord SDK, DevIL, Expat XML |

---

## 3. Server Architecture

```
                    ┌──────────────┐
                    │ MasterServer │
                    └──────┬───────┘
            ┌──────┬───────┼───────┬──────┐
            │      │       │       │      │
        ┌───▼──┐ ┌─▼──┐ ┌──▼──┐ ┌──▼──┐ ┌▼────────┐
        │Auth  │ │Char│ │Game │ │Chat │ │Query    │
        │Server│ │Svr │ │Svr  │ │Svr  │ │Server   │
        └───┬──┘ └─┬──┘ └──┬──┘ └──┬──┘ └┬────────┘
            └──────┴───────┴───────┴──────┘
                              │
                    ┌─────────▼─────────┐
                    │  MySQL Database    │
                    │ (dbo_acc/char/log) │
                    └───────────────────┘
```

### Startup Order:
1. MasterServer (everything connects to it)
2. QueryServer (database gateway)
3. CharServer
4. AuthServer
5. GameServer (channel)
6. ChatServer

### Packet Naming Convention: `[Source][Destination]`
- **UA/AU** — User ↔ Auth
- **UC/CU** — User ↔ Char
- **UG/GU** — User ↔ Game (~329 opcodes, ~302 implemented)
- **GM/MG** — Game ↔ Master
- **GT/TG** — Game ↔ Chat
- **GQ/QG** — Game ↔ Query (~246 opcodes, ~117 implemented)
- **CM/MC** — Chat ↔ Master
- **CQ/QC** — Chat ↔ Query
- **TM/MT** — Chat ↔ Master (party/guild routing)
- **TQ/QT** — Chat ↔ Query

---

## 4. GameSystems

### 4.1 Class Hierarchy
```
CGameObject → CMoveableObject → CCharacterObject → CCharacter → CPlayer
                                                          → CNpc → CMonster
```

### 4.2 Races & Classes
- **Races:** Human, Namek, Majin
- **Classes:** Fighter, Crayman, Mechanic, Warrior, Spiritualist, Ranger (6 per race)
- **Resources:** LP, EP, RP, AP, RpBall (Rage)

### 4.3 Major Systems Location

| System | Key Files | Status |
|--------|-----------|--------|
| Combat | `battle.cpp`, `char_battle.cpp`, `calcs.cpp` | ✅ Complete |
| Skills | `Skill.cpp`, `SkillManagerPc.cpp`, `HtbSkill.h` | ✅ Complete |
| Buffs | `Buff.cpp`, `BuffManagerPc.cpp`, `BuffLinkedObject.h` | ✅ Complete |
| Items | `item.cpp`, `ItemManager.h`, `PlayerItemContainer.h` | ✅ Complete |
| Quests | `Quest.cpp` (~2975 lines), `QuestProgress.cpp` | ⚠️ ~70% (30 event types stub) |
| NPC/AI | `Npc.cpp`, `Monster.cpp`, `BotAi*.cpp` (~47 actions, ~30 conditions) | ✅ ~85% Actions, ~83% Conditions |
| World/Map | `World.cpp`, `WorldManager.cpp`, `WorldCell.cpp` | ✅ Complete |
| Party | `Party.cpp`, `PartyMatching.cpp` | ✅ Complete |
| Guild | `Guild.cpp` (Game + Chat + Query) | ✅ Complete |
| Trade | `trade.cpp` | ✅ Complete |
| Mail | QueryServer mail handlers | ✅ Complete |
| Private Shop | `privateshop.cpp` | ✅ Complete |
| Free Battle | `freebattle.cpp` | ✅ Complete |
| Budokai | `BudokaiManager.cpp` (~7306 lines) | ⚠️ Partial (GM features disabled) |
| Rank Battle | `RankBattle.cpp` (ChatServer) | ⚠️ Partial (Init/Destroy empty) |
| Dojo | `Dojo.cpp`, `DojoWar.cpp`, `DojoManager.cpp` | ⚠️ Partial (scramble disabled) |
| Dungeon (TMQ) | `TimeQuest.cpp` (12-state machine) | ✅ Complete |
| Dungeon (CCBD) | `BattleDungeon.cpp` | ✅ Complete |
| Dungeon (UD) | `UltimateDungeon.cpp` | ✅ Complete |
| Dragonball | `DragonballHunt.cpp`, `DragonballScramble.cpp`, `ShenronManager.cpp` | ✅ Complete |
| Vehicle | Vehicle handlers in PacketGameServer.cpp | ✅ Complete |
| Transformation | `AspectState_*.cpp` (SuperSaiyan, Kaioken, etc.) | ✅ Complete |
| Mascot/Pet | `Pet*.cpp`, `SummonPet.cpp`, mascot handlers | ✅ Complete |
| Cash Shop | `CashshopManager.cpp` (Query), HLS handlers | ✅ Complete |
| Crafting | Hoipoi Mix handlers | ✅ Complete |
| World Boss | `WorldBossEvent.cpp` | ✅ Complete (new) |
| Honey Bee | `HoneyBeeEvent.cpp` | ✅ Complete |
| Bus System | `BusSystem.cpp` | ✅ Complete |

### 4.4 Script System Types
1. **SPS** — NPC Scripted Play System
2. **WPS** — World Play Script
3. **TQS** — Time Quest Script
4. **AIS** — AI Behavior Script
5. **Trigger** — Quest/World trigger (~336 files in DboTrigger)

---

## 5. Disabled / Broken Systems

### 5.1 Opcodes mapped to OnInvalid (silently dropped):
- `UG_DOGI_CREATE_REQ`, `UG_DOGI_CHANGE_REQ` — Dogi system
- `UG_GUILD_DOGI_*_REQ` (3 opcodes) — Guild dogi
- `UG_REMOTE_SHOP_*_REQ` (5 opcodes) — Remote shop/repair/identify
- `UG_CHAR_SKILL_INIT_REQ` — Skill reset
- `UG_ITEM_UPGRADED_EXCHANGE_REQ` — Item exchange
- `UG_TMQ_LIMIT_COUNT_PLUS_REQ` — TMQ limit+
- `UG_PET_RECALL_NFY` — Pet recall notify
- `UG_BUDOKAI_GM_*_REQ` (5 opcodes) — Budokai GM features
- `UG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ` — Prize winner team name

### 5.2 Not registered at all:
- `UG_CASHITEM_START_REQ`, `UG_CASHITEM_END_REQ` — Cash shop start/end

### 5.3 Stub functions:
- `BotAiAction_SPS_SendEvent`, `BotAiAction_AIS_SendEventToWps`, `BotAiAction_AIS_SendEventToTqs`, `BotAiAction_SendEscortEventToTs`, `BotAiAction_SendEventToTqs` — Cross-system event relay stubs
- `BotAiCondition_AIS_RecvEventFromWps`, `BotAiCondition_AIS_RecvEventFromTqs`, `BotAiCondition_Follow_Teleport`, `BotAiCondition_RangedAttack`, `BotAiCondition_Terror` — Condition stubs
- `BotBreakUp::AddMove_Level3/4` — printf("TODO") only
- `Npc::OnMsg_YouHit` — return NTL_SUCCESS; //TODO
- `RecvCharStandingSlip`, `RecvCharStandingSlipEnd` — empty bodies
- Sliding/knockdown mechanics — commented out (in char_battle.cpp)
- PlayBgm/PlayJingle WPSNodeAction — CheckParameter() always returns true

### 5.4 Completely unimplemented:
- DWC (Dynamic World Control) system — 5 node types commented out
- ~30 Quest event types (item_use, skill_use, budokai, slot_machine, hoipoi_mix, private_shop, free_battle, etc.)

### 5.5 Known issues/TODOs:
- Budokai ranking hardcoded as `4544` (wrapper code)
- TMQ EXP = "ALWAYS EXP" (no calculation)
- Wagu point deduction not checked
- Swimming movement check missing
- Quest progress timer for Quest 53 unknown
- DynamicFieldSystem is a bare counter (36 lines)
- `Skill - Copy.cpp` = dead duplicate file

---

## 6. Database Schema Overview

### dbo_acc (Account)
`accounts`, `accounts_banned`, `cashshop_storage`, `event_reward`, `shortcuts`

### dbo_char (Character)
`characters`, `items`, `skills`, `htb_skills`, `buffs`, `quests`, `questitems`, `quickslot`, `guilds`, `guild_members`, `dojos`, `friendlist`, `mail`, `portals`, `rank_battle`, `mascots`, `titles`, `warfog`, `bind`, `quick_teleport`, `hoipoi_recipe`, `items_cd`

### dbo_log (Logging)
`auth_login_log`, `character_delete_log`, `gm_log`, `tradelogs`, `privateshoplogs`, `auctionhouse_log`, `mail_deleted`, `slot_machine_log`, `budokai`, `budokai_winners`, `item_upgrade_log`, `mute_log`, `dynamic_field_count`, `founder_log`, `guild_name_change_log`, `change_char_name`

---

## 7. Key Config Files

| File | Location | Key Settings |
|------|----------|-------------|
| GameServer.ini | `ExecutionEnv/config/` | MaxLevel=70, SoloExpRate=1000, PartyExpRate=1000, ItemDropRate=0, ZeniDropRate=0, TablePath, Script paths |
| AuthServer.ini | same | IP, Port, DB credentials, connection limits |
| MasterServer.ini | same | All server ports |
| CharServer.ini | same | Character server config |
| ChatServer.ini | same | Chat server config |
| QueryServer.ini | same | DB gateway config |

---

## 8. Game Data Tables

~236 `.rdf` files in `ExecutionEnv/resource/server_data/table/rdf/`
- 64 core game tables (Item, Skill, Mob, NPC, PC, Quest, World, etc.)
- 170 spawn tables (NPC/Mob/Object per world)
- All 64 expected tables present on disk
- `characterproperty.rdf` = 9.8MB present
- `ObjectProperty/` directory = MISSING (but flag disabled, not loaded)

### Table Format: Binary RDF (LoadTableFormat=1)

---

## 9. How to Add a New System (Checklist)

1. **NtlShared2/** → Add packet opcode enum + protocol struct
2. **GameServer/ug_opcodes.cpp** → Register opcode
3. **GameServer/PacketGameServer.cpp** → Write handler function
4. **GameServer/NewSystem.h/.cpp** → Business logic class
5. **QueryServer/** → If DB storage needed: add handler + opcode registration
6. **Database/**.sql → Add table schema
7. **NtlGameTable/** → If config data needed: create table class + register in TableContainer
8. **Config/*.ini** → If config values needed
9. **Client/Gui/** → If new UI needed
10. **Script system** → If script-driven events needed (SPS/WPS/TQS/AIS/Trigger)

### Minimal path: 1 → 2 → 3 → 4

---

## 10. Build & Run

- **Client:** VS 2019, `DboClient/DboClient.sln`, `Release|Win32`
- **Server:** VS 2019, `DboServer/DboServer.sln`, `Release|x64`
- **Dependencies:** DX9, RenderWare, Scaleform GFx 3.3 (GFXSDK_DIR env var), Xtreme ToolkitPro (XtremeToolkitPro_Dir env var), FMOD, MySQL 5.7, PathEngine 5.10
- **3rd Party repo:** https://github.com/OpenDBO/OpenDBO-3rdParty/releases
- **Client Assets repo:** https://github.com/OpenDBO/OpenDBO-Assets

---

## 11. DBOG V2 (dbo-2023) — Reference for Porting

> Location: `D:\DBOGLOBALV2\dbo-2023\dbo-2023\` (another version of the same codebase)
> Contains many features **missing or incomplete** in this main version.

### 11.1 Features Present in V2 but Missing in Main

#### A. Server-side (GameServer) — New Transformation States (7 classes)

| File | Class | Description |
|------|-------|-------------|
| `AspectState_SuperSaiyan2.cpp/.h` | `CAspectState_SuperSaiyan2` | Super Saiyan 2 (EP drain, aftereffect) |
| `AspectState_SuperSaiyan3.cpp/.h` | `CAspectState_SuperSaiyan3` | Super Saiyan 3 (EP drain, aftereffect) |
| `AspectState_SuperSaiyanBlue.cpp/.h` | `CAspectState_SuperSaiyanBlue` | Super Saiyan Blue/SSGSS |
| `AspectState_EvilBoo.cpp/.h` | `CAspectState_EvilBoo` | Evil Buu (model change, restore on exit) |
| `AspectState_SuperBoo.cpp/.h` | `CAspectState_SuperBoo` | Super Buu |
| `AspectState_EvilNamek.cpp/.h` | `CAspectState_EvilNamek` | Evil Namek (Dragon Clan purification) |
| `AspectState_KingNamek.cpp/.h` | `CAspectState_KingNamek` | King Namek (Giant Namek form) |

#### B. Server-side — Events & Systems

| System | Details |
|--------|---------|
| **Fairy Event** (`Fairy Event.cpp/.h`) | Auto-scheduled event with mob spawn, boss, loot. Uses EventTimeTable (ID 8). Tick every 5s, spawns by level range (15/45/65), 10% chance on kill. |
| **ExpEvent (enhanced)** | Uses `TABLE_EVENT_TIME` (ID 7) for scheduling instead of hardcoded weekend-only. Configurable per-day-of-week + duration. |
| **Exp Toggle** | `RecvExpEnabledReq`, `RecvResetExpReq` — players can enable/disable EXP gain |
| **Scouter Start** | `RecvScouterStartReq` — scouter activation toggle |
| **Skill Reset Plus** | `RecvSkillResetPlusReq` — item-based skill reset using `ITEM_TYPE_SKILL_POINT_RESET_PLUS` |
| **Web Integration** | `MasterServer/WebPacket.cpp` — 5 API functions: GetPlayerCount, GetChannelStatus, SendCharItem, SendItemHLS, SendGameEnterReq. Port 40000. |

#### C. Client-side — New GUI Files (~30 files)

| GUI File(s) | Function |
|-------------|----------|
| `WorldBoss.cpp/.h` | World Boss side icon GUI |
| `BroadCastSystem.cpp/.h` | Scrolling announcement text |
| `AggroListGui.cpp/.h` | Threat/aggro list display |
| `DragonBallScrambleDialog.cpp/.h` | Scramble explanation dialog |
| `DragonBallScrambleIconGui.cpp/.h` | Scramble side icon |
| `DropItemOwnerShipGui.cpp/.h` | Drop item ownership timer |
| `DynamicFieldSideIcon.cpp/.h` | Dynamic Field world event side icon |
| `DynamicFieldSideViewGui.cpp/.h` | Dynamic Field side view panel |
| `EventMachineSideIconGui.cpp/.h` | Event machine side icon |
| `EventMachineSideViewGui.cpp/.h` | Event machine side view |
| `EventRewardMainGui.cpp/.h` | Event reward main window |
| `EventRewardSubGui.cpp/.h` | Event reward sub window |
| `EventTimeTableGui.cpp/.h` | Scheduled event timetable GUI |
| `EventTimeTableIcon.cpp/.h` | Event timetable side icon |
| `EventTimeTableView.cpp/.h` | Event timetable view |
| `GiftShopCartGui.cpp/.h` | Gift shop shopping cart |
| `GiftShopGui.cpp/.h` | Gift shop main window |
| `GiftSideIconGui.cpp/.h` | Gift shop side icon |
| `GiftSideView.cpp/.h` | Gift shop side view |
| `MascotExGui.cpp/.h` | Extended mascot (8 slots, 4 skills, fusion, VP/XP) |
| `MascotFusion.cpp/.h` | Mascot fusion system |
| `MascotSkillReMake.cpp/.h` | Mascot skill remake |
| `NetPyShop.cpp/.h` | NetPy premium shop |
| `NetPySideIconGui.cpp/.h` | NetPy shop side icon |
| `NetPySideView.cpp/.h` | NetPy shop side view |
| `PreviewGui.cpp/.h` | Item/preview display |
| `QuickTeleportGui.cpp/.h` | Quick teleport UI |
| `ScouterMeasureDlgGui.cpp/.h` | Scouter measurement dialog |
| `ScouterOldBodyGui.cpp/.h` | Old scouter body style |
| `ScouterOldSystemGui.cpp/.h` | Old scouter system |
| `TreasureBoxGui.cpp/.h` | Treasure box opening (chest + key) |
| `VirtualKeyboardGui.cpp/.h` | On-screen virtual keyboard |
| `WaguMachineInfo.cpp/.h` | Wagu slot/gacha machine info |
| `WaguMachineSideIconGui.cpp/.h` | Wagu machine side icon |
| `WaguMachineSideView.cpp/.h` | Wagu machine side view |

#### D. Game Data Tables (NtlGameTable) — 17 New Table Parsers

| Table | Enum | Purpose |
|-------|------|---------|
| `BasicDropTable` | DROP_BASIC | Basic drop table |
| `ClassTable` | CLASS | Class base stats |
| `ContentsConditionTable` | CONTENTS_CONDITION | Content access conditions |
| `EachDropTable` | DROP_EACH | Per-monster drop table |
| `EventTimeTable` | EVENT_TIME | Event schedule timetable |
| `ExcellentDropTable` | DROP_EXCELLENT | Excellent quality drops |
| `GameManiaTimeTable` | GAME_MANIA_TIME | Game Mania Time bonus schedule |
| `ItemEnchantRateTable` | ITEM_ENCHANT_RATE | Enchant success rates |
| `ItemOptionValueProbabilityTable` | ITEM_OPTION_VALUE_PROBABILITY | Option value probability |
| `ItemUpgradeRateTable` | ITEM_UPGRADE_RATE | Upgrade rates (original) |
| `LegendaryDropTable` | DROP_LEGENDARY | Legendary quality drops |
| `NormalDropTable` | DROP_NORMAL | Normal quality drops |
| `RaceTable` | RACE | Race base stats |
| `SuperiorDropTable` | DROP_SUPERIOR | Superior quality drops |
| `TextServerTable` | TEXT_SERVER | Server-side text |
| `TypeDropTable` | DROP_TYPE | Type-based drops |
| `QuestDropTable` (enhanced) | QUEST_DROP | Quest-specific drops |

**Note:** These tables need corresponding `.rdf` data files in `resource/server_data/table/rdf/`. Check V2's ExecutionEnv for the data files if porting.

#### E. Packet Opcodes (NtlPacketUG.h) — 3 New in V2

| Opcode | Handler | Purpose |
|--------|---------|---------|
| `UG_EXP_ENABLED_REQ` | `RecvExpEnabledReq` | Player enable/disable EXP |
| `UG_RESET_EXP_REQ` | `RecvResetExpReq` | Reset EXP |
| `UG_SCOUTER_START_REQ` | `RecvScouterStartReq` | Scouter toggle |

**Also:** V2 has `UG_SKILL_RESET_PLUS_REQ` → `RecvSkillResetPlusReq` (Main missing)

#### F. Protocol Struct Differences (important for compat)

| Opcode | V2 | Main |
|--------|----|------|
| `UG_CHAR_EXIT_REQ` | Has `bool bIsItem` | Empty struct |
| `UG_EVENT_REWARD_SELECT_REQ` | Has `DWORD eventId` (3rd field) | No eventId |

### 11.2 Systems Still Broken in BOTH Versions (no need to port)

These are incomplete in V2 just like Main:

- **Dogi System** (`UG_DOGI_*`, `UG_GUILD_DOGI_*`) → OnInvalid
- **Remote Shop/Repair/Identify** (`UG_REMOTE_*`) → OnInvalid
- **Budokai GM Features** (5 opcodes) → OnInvalid ("NOT EXIST YET")
- **Budokai Prize Winner Team Name** → OnInvalid ("TO DO")
- **DWC System** (5 node types) → Commented out in WorldPlayControlFactoy.cpp
- **BotAiAction_SPS_SendEvent** et al. (6 stub actions) → Cross-system event relay stubs
- **BotAiCondition_AIS_RecvEventFromWps** et al. (5 stub conditions) → Condition stubs
- **BotBreakUp::AddMove_Level3/4** → printf("TODO") stubs
- **Npc::OnMsg_YouHit** → return NTL_SUCCESS; //TODO
- **Sliding/Knockdown** → Commented out in char_battle.cpp
- **RecvCharStandingSlip** / **RecvCharStandingSlipEnd** → Empty bodies
- **PlayBgm/PlayJingle** → CheckParameter() returns true unconditionally

### 11.3 Priority Order for Porting

| Priority | What | Effort |
|----------|------|--------|
| 🟢 **High** | 7 new transformation classes (copy .h/.cpp) | Low |
| 🟢 **High** | Fairy Event system | Medium |
| 🟢 **High** | EventTimeTable + enhanced ExpEvent | Medium |
| 🟢 **High** | MascotEx + MascotFusion + MascotSkillReMake GUI | Medium |
| 🟢 **High** | GiftShop + NetPyShop + WaguMachine GUI | Medium |
| 🟢 **High** | WorldBoss GUI + DynamicField GUI | Low |
| 🟢 **High** | Drop tables (7+ table parsers + .rdf data) | Medium |
| 🟡 **Medium** | Scouter Start opcode + handler | Low |
| 🟡 **Medium** | Exp Toggle opcodes + handlers | Low |
| 🟡 **Medium** | Skill Reset Plus handler | Low |
| 🟡 **Medium** | AggroList, DropOwnership, Broadcast, PreviewGui | Medium |
| 🟡 **Medium** | EventTimeTableGui, EventReward, EventMachine GUI | Medium |
| 🟡 **Medium** | Protocol struct fixes (CHAR_EXIT, EVENT_REWARD_SELECT) | Low |
| 🟡 **Medium** | Web Integration (MasterServer) | Medium |
| 🔵 **Low** | TreasureBox, ScouterOld, VirtualKeyboard GUI | Low |
| 🔵 **Low** | ContentsConditionTable | Low |

### 11.4 Porting Checklist (per system)

1. **Copy files** from V2 → Main
2. **Register** in appropriate manager (TableContainerManager, ug_opcodes, etc.)
3. **Add enum entries** if needed (eTABLE, UG opcode enum)
4. **Add data files** (.rdf) if needed
5. **Update build** (add to .vcxproj)
6. **Verify** no naming conflicts or duplicate symbols
