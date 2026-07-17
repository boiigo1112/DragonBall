#include "stdafx.h"
#include "CharacterManager.h"
#include "QueryServer.h"


CCharacterManager::CCharacterManager()
{
	Init();
}

CCharacterManager::~CCharacterManager()
{
}


void CCharacterManager::Init()
{
	m_uiLastCharacterId = 0;

	smart_ptr<QueryResult> result = GetCharDB.Query("SELECT MAX(CharID) FROM characters");
	if (result)
	{
		Field* f = result->Fetch();

		m_uiLastCharacterId = f[0].GetUInt32();
	}

	ERR_LOG(LOG_GENERAL, "Last Character-ID %u", m_uiLastCharacterId);
}


void CCharacterManager::CreateCharacter(ACCOUNTID accountId, sPC_SUMMARY& sSum, SERVERFARMID serverFarmId)
{
	UNREFERENCED_PARAMETER(serverFarmId);

	// "%ls" in vsnprintf_s (used by Execute()) converts via the C-runtime's
	// current locale, which is never set for this process and defaults to
	// ASCII-only "C" - non-ASCII names (e.g. Thai) fail that conversion and
	// silently produce a malformed query (Execute() never checks for errors),
	// so the INSERT is dropped with no row and no error. Ntl_WC2MB converts via
	// WideCharToMultiByte(GetACP(), ...) instead, which correctly handles the
	// process's ANSI codepage (874/Thai on this machine), so pass it as "%s".
	char* pszCharName = Ntl_WC2MB(sSum.awchName);

	GetCharDB.Execute("INSERT INTO characters (CharID,CharName,AccountID,Race,Class,Gender,Face,Hair,HairColor,SkinColor,CurLocX,CurLocY,CurLocZ,WorldID,WorldTable,MapInfoIndex,CreateTime)"
		"VALUES (%u,'%s',%u,%u,%u,%u,%u,%u,%u,%u,%f,%f,%f,%u,%u,%u,%I64u)",
		sSum.charId, pszCharName, accountId, sSum.byRace, sSum.byClass, sSum.byGender, sSum.byFace, sSum.byHair, sSum.byHairColor, sSum.bySkinColor,
		sSum.fPositionX, sSum.fPositionY, sSum.fPositionZ,
		sSum.worldId, sSum.worldTblidx, sSum.dwMapInfoIndex, time(0));

	Ntl_CleanUpHeapString(pszCharName);
}