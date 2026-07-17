#pragma once
//last update 20.08.2015
#include "Table.h"
#include <fstream>

#pragma pack(push, 4)
struct sEVENT_TIME_TBLDAT : public sTBLDAT
{

public:

	WCHAR		wszNameText[256];
	BYTE		byEventType;
	bool		bMonday;
	bool		bTuesday;
	bool		bWednesday;
	bool		bThursday;
	bool		bFriday;
	bool		bSaturday;
	bool		bSunday;
	BYTE		byStarTime;
	BYTE		byEndTime;

public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CEventTimeTable : public CTable
{
public:
	CEventTimeTable(void);
	virtual ~CEventTimeTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT* FindData(TBLIDX tblidx);
	bool			ConvertTableTXT();
	template <typename T>
	void			add(std::wofstream& fw, T str);

protected:
	WCHAR** GetSheetListInWChar() { return &(CEventTimeTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void* pvTable, bool bReload, bool bUpdate);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);

public:
	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload, bool bUpdate);
	virtual bool				SaveToBinary(CNtlSerializer& serializer);
	virtual bool				LoadFromTXT(std::wstring pathNameTxt);
private:
	static WCHAR* m_pwszSheetList[];
};