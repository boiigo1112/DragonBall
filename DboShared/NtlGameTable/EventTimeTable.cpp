//***********************************************************************************
//
//	File		:	HLSItemTable.h
//
//	Begin		:	2009-8-14
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Chung Doo sup   ( john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#include "stdafx.h"
#include "EventTimeTable.h"
#include "NtlDebug.h"
//#include "NtlBattle.h"
#include "NtlSerializer.h"
#include <codecvt>

//- yoshiki : Let's consider of implementing NtlAssert series.
//#include "NtlAssert.h"

WCHAR* CEventTimeTable::m_pwszSheetList[] =
{
	L"Table_Data_KOR",
	NULL
};

CEventTimeTable::CEventTimeTable(void)
{
	Init();
}

CEventTimeTable::~CEventTimeTable(void)
{
	Destroy();
}

bool CEventTimeTable::Create(DWORD dwCodePage)
{
	return CTable::Create(dwCodePage);
}

void CEventTimeTable::Destroy()
{
}

void CEventTimeTable::Init()
{
}

void* CEventTimeTable::AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEVENT_TIME_TBLDAT* pNewItem = new sEVENT_TIME_TBLDAT;
		if (NULL == pNewItem)
			return NULL;

		CPINFO cpInfo;
		if (false == GetCPInfo(dwCodePage, &cpInfo))
		{
			delete pNewItem;
			return NULL;
		}

		m_dwCodePage = dwCodePage;
		return pNewItem;
	}

	return NULL;
}

bool CEventTimeTable::DeallocNewTable(void* pvTable, WCHAR* pwszSheetName)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEVENT_TIME_TBLDAT* pItem = (sEVENT_TIME_TBLDAT*)pvTable;
		if (FALSE != IsBadReadPtr(pItem, sizeof(*pItem)))
			return false;

		delete pItem;

		return true;
	}

	return false;
}

bool CEventTimeTable::AddTable(void* pvTable, bool bReload, bool bUpdate)
{
	UNREFERENCED_PARAMETER(bUpdate);

	sEVENT_TIME_TBLDAT* pTbldat = (sEVENT_TIME_TBLDAT*)pvTable;
	sEVENT_TIME_TBLDAT* pExistTbldat = NULL;

	if (bReload)
	{
		pExistTbldat = (sEVENT_TIME_TBLDAT*)FindData(pTbldat->tblidx);
		if (pExistTbldat)
		{
			CopyMemory(pTbldat, pExistTbldat, pTbldat->GetDataSize());
			// ����Ÿ�� ���ε� ������ ���� true ��ȯ
			return true;
		}
	}

	if (false == m_mapTableList.insert(std::map<TBLIDX, sTBLDAT*>::value_type(pTbldat->tblidx, pTbldat)).second)
	{
		CTable::CallErrorCallbackFunction(L"[File] : %s\r\n Table Tblidx[%u] is Duplicated ", m_wszXmlFileName, pTbldat->tblidx);
		_ASSERTE(0);
		return false;
	}


	return true;
}

bool CEventTimeTable::SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData)
{

	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sEVENT_TIME_TBLDAT* pItem = (sEVENT_TIME_TBLDAT*)pvTable;

		if (0 == wcscmp(pstrDataName->c_str(), L"Tblidx"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->tblidx = READ_DWORD(bstrData);
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"EventName"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			READ_STRINGW(bstrData, pItem->wszNameText, _countof(pItem->wszNameText));
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"EventType"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->byEventType = READ_BYTE(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Monday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bMonday= READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Tuesday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bTuesday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Wednesday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bWednesday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Thursday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bThursday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Friday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bFriday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Saturday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bSaturday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Sunday"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->bSunday = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"StarTime"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->byStarTime = READ_BYTE(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"EndTime"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->byEndTime = READ_BYTE(bstrData, pstrDataName->c_str());
		}
		else
		{
			CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}


sTBLDAT* CEventTimeTable::FindData(TBLIDX tblidx)
{
	if (0 == tblidx)
		return NULL;

	TABLEIT iter;
	iter = m_mapTableList.find(tblidx);
	if (End() == iter)
		return NULL;

	return (sTBLDAT*)(iter->second);
}

bool CEventTimeTable::LoadFromBinary(CNtlSerializer& serializer, bool bReload, bool bUpdate)
{
	if (false == bReload)
	{
		Reset();
	}

	BYTE byMargin = 1;
	serializer >> byMargin;

	bool bLoop = true;
	do
	{
		sEVENT_TIME_TBLDAT* pTableData = new sEVENT_TIME_TBLDAT;
		if (NULL == pTableData)
		{
			//- yoshiki : To log system!
			Destroy();
			return false;
		}

		if (false == pTableData->LoadFromBinary(serializer))
		{
			delete pTableData;
			bLoop = false;
			break;
		}

		//	printf("pTableData->tblidx %u  %u  %u  %u  %u  %u  %u \n", pTableData->tblidx, pTableData->itemTblidx, pTableData->byCategory, pTableData->bOnSale, pTableData->dwCash, pTableData->byStackCount, pTableData->wDisplayBitFlag);
		if (false == AddTable(pTableData, bReload, bUpdate))
		{

			delete pTableData;
		}

	} while (false != bLoop);

	return true;
}

bool CEventTimeTable::SaveToBinary(CNtlSerializer& serializer)
{
	serializer.Refresh();

	BYTE byMargin = 1;
	serializer << byMargin;

	TABLE::iterator iter;
	for (iter = Begin(); End() != iter; iter++)
	{
		sEVENT_TIME_TBLDAT* pTableData = (sEVENT_TIME_TBLDAT*)(iter->second);

		pTableData->SaveToBinary(serializer);
	}

	return true;
}

template <typename T>
void CEventTimeTable::add(std::wofstream& fw, T str)
{
	fw << str << L"\t";
}

bool CEventTimeTable::ConvertTableTXT()
{
	std::string pathNameTxt = ".\\TXT\\table_event_time_data.txt";
	CTable::TABLEIT iter;

	std::wofstream fw;
	fw.open(pathNameTxt);

	if (fw.is_open())
	{
		const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
		fw.imbue(utf8_locale);

		for (iter = Begin(); End() != iter; iter++)
		{
			sEVENT_TIME_TBLDAT* table = (sEVENT_TIME_TBLDAT*)(iter->second);
			add(fw, table->tblidx);
			add(fw, table->wszNameText);
			add(fw, table->byEventType);
			add(fw, table->bMonday);
			add(fw, table->bTuesday);
			add(fw, table->bWednesday);
			add(fw, table->bThursday);
			add(fw, table->bFriday);
			add(fw, table->bSaturday);
			add(fw, table->bSunday);
			add(fw, table->byStarTime);
			add(fw, table->byEndTime);
			fw << L"\n";
		}
		fw.close();
	}
	return true;
}

bool CEventTimeTable::LoadFromTXT(std::wstring pathNameTxt)
{
	CTable::TABLEIT iter;

	std::wifstream infile(pathNameTxt);
	std::wstring line;
	const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	infile.imbue(utf8_locale);

	while (getline(infile, line))
	{
		sEVENT_TIME_TBLDAT* table = new sEVENT_TIME_TBLDAT;
		std::vector<std::wstring> row;
		BYTE num = 0;

		split(line, row);

		table->tblidx = sti(row.at(num++));
		wcsncpy(table->wszNameText, row.at(num++).c_str(), 256 + 1);
		table->byEventType = sti(row.at(num++));
		table->bMonday = sti(row.at(num++));
		table->bTuesday = sti(row.at(num++));
		table->bWednesday = sti(row.at(num++));
		table->bThursday = sti(row.at(num++));
		table->bFriday = sti(row.at(num++));
		table->bSaturday = sti(row.at(num++));
		table->bSunday = sti(row.at(num++));
		table->byStarTime = sti(row.at(num++));
		table->byEndTime = sti(row.at(num++));

		AddTable(table, false, false);
	}
	return true;
}