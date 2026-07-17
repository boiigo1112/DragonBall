/*****************************************************************************
 *
 * File			: DboEvent.h
 * Author		: HyungSuk, Jang
 * Copyright	: (��)NTL
 * Date			: 2005. 9. 28	
 * Abstract		: DBO standard event.
 *****************************************************************************
 * Desc         : 
 *
 *****************************************************************************/

#ifndef __DBO_EVENT_H___
#define __DBO_EVENT_H___

// shared
#include "NtlSharedDef.h"

#include "ceventhandler.h"
#include "DboDef.h"
#include "NtlMail.h"
#include "ScriptLinkTable.h"
#include "NtlPacketGU.h"
#include "ItemTable.h"


//////////////////////////////////////////////////////////////////////////////////
/**
* network�� ���õ� event
*/

extern RWS::CEventId g_EventVirtualServerPacket;	// virutal server packet event

extern RWS::CEventId g_EventLogInServerConnect;		// lobby server�� ����Ǿ���.

extern RWS::CEventId g_EventLobbyServerConnect;		// lobby server�� ����Ǿ���.

extern RWS::CEventId g_EventGameServerConnect;		// game server�� ����Ǿ���.	

//////////////////////////////////////////////////////////////////////////////////
// LogIn stage
extern RWS::CEventId g_EventLogInStageStateEnter;	// login stage state enter

extern RWS::CEventId g_EventLogInStageStateExit;	// login stage state exit

extern RWS::CEventId g_EventLogInStageTimeOut;			// login stage state exit


//////////////////////////////////////////////////////////////////////////////////
// ĳ���� ����Ʈ & ����ŷ

extern RWS::CEventId g_EventCharStageStateEnter;	// character stage state enter

extern RWS::CEventId g_EventCharStageStateExit;		// character stage state exit

extern RWS::CEventId g_EventCharMake;				// Character Making ����

extern RWS::CEventId g_EventLoginMessage;			// Login Message

extern RWS::CEventId g_EventLobbyMessage;			// Lobby Message

//////////////////////////////////////////////////////////////////////////////////
/**
* gui�� ���õ� event
*/

extern RWS::CEventId g_EventDebug_for_Developer;	// �����ڸ� ���� ����� ��� �̺�Ʈ

extern RWS::CEventId g_EventLobbyPacketHelper;		// login Packet helper

extern RWS::CEventId g_EventLoginGuiEnable;			// login gui enable

extern RWS::CEventId g_EventVirtualKeyboard;		// virtual keyboard key pressed

extern RWS::CEventId g_EventCharSelectGuiEnable;	// char select gui enable

extern RWS::CEventId g_EventMsgBoxShow;				// Message box show event

extern RWS::CEventId g_EventMsgBoxResult;			// Message box resount event

extern RWS::CEventId g_EventChatGuiMode;			// chatting gui mode

extern RWS::CEventId g_EventSayMessage;				// chatting message show

extern RWS::CEventId g_EventSetTextToChatInput;		// Set Text to Chat Input

extern RWS::CEventId g_EventTimeFixedNotify;		// Time Fixed Notify message

extern RWS::CEventId g_EventCautionSideNotify;		// Time Fixed Notify -> Caution SideIcon Notify

extern RWS::CEventId g_EventNotify;					// Notify

extern RWS::CEventId g_EventFlashNotify;			// Flash notify
extern RWS::CEventId g_EventFlashNotifyFinish;		// Flash notify finish

extern RWS::CEventId g_EventFlashNotifyString;		// Flash notify string

extern RWS::CEventId g_EventFlashFinishNotify;		// Flash finish notify

extern RWS::CEventId g_EventGroupNotify;			// Group Notify

extern RWS::CEventId g_EventNameNotify;				// Name Notify

extern RWS::CEventId g_EventIconMoveClick;			// Icon Move Click

extern RWS::CEventId g_EventIconPopupShow;			// PopupMenu show

extern RWS::CEventId g_EventIconPopupResult;		// PopupMenu Result

extern RWS::CEventId g_EventCalcPopupShow;			// CalcPopup SHow

extern RWS::CEventId g_EventCalcPopupResult;		// CalcPopup Result

extern RWS::CEventId g_EventPickedUpHide;			

extern RWS::CEventId g_EventShop;					// ���� �̺�Ʈ

extern RWS::CEventId g_EventDialog;					// ���̾�α� �̺�Ʈ

extern RWS::CEventId g_EventPostDialog;				// ���̾�α� ����Ʈ �̺�Ʈ

extern RWS::CEventId g_EventUpdateRP;				// RP ��ȭ �̺�Ʈ.
extern RWS::CEventId g_EventUpdateRpStock;          // RP Stock �̺�Ʈ

extern RWS::CEventId g_EventUpdateExp;				// EXP ��ȭ �̺�Ʈ.

extern RWS::CEventId g_EventCharObjDelete;			// ĳ���� ������Ʈ ����.

extern RWS::CEventId g_EventItemUpgradeResult;		// ������ ���׷��̵� ���

extern RWS::CEventId g_EventItemChangeOptionConfirmation;
extern RWS::CEventId g_EventItemChangeOptionResult;

extern RWS::CEventId g_EventItemChangeBattleAttributeResult;

extern RWS::CEventId g_EventRegisterItemUpgrade;	// ������ ���׷��̵� ���Կ� ���. (���콺 ������ ��ư)

extern RWS::CEventId g_EventRegisterItemChangeBattleAttribute;

extern RWS::CEventId g_EventCharTitleSelectRes;
extern RWS::CEventId g_EventCharTitleUpdate;

extern RWS::CEventId g_EventQuickSlotInfo;			// ����� ������ ������ ���.

extern RWS::CEventId g_EventQuickSlotDelNfy;		// ���������� ������ ���� ����.

extern RWS::CEventId g_EventNPCDialogOpen;			// NPC���� ���̾�α� ����

extern RWS::CEventId g_EventEndterWorld;			// ������ �����̳� �����̵���

extern RWS::CEventId g_EventMap;					// �̴ϸ�, ��, ����� �޼���

extern RWS::CEventId g_EventUserTrade;				// ���� Ʈ���̵�

extern RWS::CEventId g_EventServerCharDialog;		// Server�� ���ɿ� ���� ��ȭâ ����.

extern RWS::CEventId g_EventOpenHelpWindow;			// Help Wnd ���°� ���ÿ� Condition Check ǥ��

extern RWS::CEventId g_EventOpenHelpContent;		// Help Wnd ���°� ���ÿ� �������� htm ������ ����

extern RWS::CEventId g_EventEnableItemIcon;				// ItemIcon�� Enable����.
extern RWS::CEventId g_EventCapsuleLockItem;			// ItemIcon�� Lock/Unlock ����
extern RWS::CEventId g_EventCapsuleLockItemWithoutBag;	// ItemIcon�� Lock/Unlock ����(���濡�� ��ũ�� �����ۿ�)

extern RWS::CEventId g_EventDirectMoveIcon;			// �������� ���� �ű�� ����.

extern RWS::CEventId g_EventPrivateShopSelectNfy;	// ���λ��� �������� ����Ʈ �ߴܰ� �˷��ִ� �̺�Ʈ

extern RWS::CEventId g_EventRegPrivateShopCartItem;	// ���λ��� īƮ�� �������� ����Ѵ�.

extern RWS::CEventId g_EventRegPrivateShopItem;		// ���λ����� �Ǹž������� ����Ѵ�.

extern RWS::CEventId g_EventPrivateShopBusinessStart;			// ���λ��� ������ ����

extern RWS::CEventId g_EventPrivateShopBusinessFluctuations;	// ���λ��� ���� ���� ���� ����

extern RWS::CEventId g_EventPrivateShopBusinessCloseWindow;

extern RWS::CEventId g_EventBackboard;				// Backboard Gui �̺�Ʈ

extern RWS::CEventId g_EventSummonPet;				// SummonPet UI�� ���� �̺�Ʈ

extern RWS::CEventId g_EventOpenSendMail;			// SendMail�� ����.

extern RWS::CEventId g_EventReadingMail;			// ReadMail�� �а� �ִ�.

extern RWS::CEventId g_EventRegMailAttachItem;		// Mail�� �������� ���

extern RWS::CEventId g_EventRegBindSealingAttachItem;

extern RWS::CEventId g_EventRegHoiPoiMixMaterialItem;

extern RWS::CEventId g_EventRegCCBDCouponItem;

extern RWS::CEventId g_EventRegOptionReconstructItem;

extern RWS::CEventId g_EventOpenQuickTeleport;
extern RWS::CEventId g_EventQuickTeleportLoad;
extern RWS::CEventId g_EventQuickTeleportUpdate;
extern RWS::CEventId g_EventQuickTeleportDelete;
extern RWS::CEventId g_EventQuickTeleportMove;

extern RWS::CEventId g_EventRegAuctionHouseItem;

extern RWS::CEventId g_EventMailSlotUpdate;			// Mail Slot�� ������Ʈ ����

extern RWS::CEventId g_EventQuestMessage;			// Quest messageâ ���� �̺�Ʈ

extern RWS::CEventId g_EventQuestMessage2;			// Quest message2â ���� �̺�Ʈ

extern RWS::CEventId g_EventRpBonusSetup;			// Skill RpBonus Setup UI�� Open�Ѵ�.

extern RWS::CEventId g_EventRpBonusSelect;			// Skill RpBonus�� �����ؾ� �Ѵ�.

extern RWS::CEventId g_EventRpBonusAuto;			// Skill RpBonus�� Auto�� ����Ͽ���.

extern RWS::CEventId g_EventTargetStatusRefresh;	// ���� Ÿ������â�� ��������. ��ī���� ���� ������ǥ�� � ���.

extern RWS::CEventId g_EventRankBattleRankListRes;	// ��ŷ ������ ����Ʈ�� �޴´�.

extern RWS::CEventId g_EventRankBattleRankFindCharacterRes;	// ��ŷ ���忡�� ĳ���� �˻� ����� �޴´�.

extern RWS::CEventId g_EventRankBattleRankCompareDayRes;	// ��ŷ ���忡�� �񱳳�¥ ��û ����� �޴´�.

extern RWS::CEventId g_EventRankBoardDisable;

extern RWS::CEventId g_EventZennyLootingEffect;		// ���ϸ� �ֿ����� Effect

extern RWS::CEventId g_EventItemCreatedEffect;		// �������� ������ �������� Effect

extern RWS::CEventId g_EventSideDialog;				// ���̵� ���̾�α� ����

extern RWS::CEventId g_EventTMQRecordListRes;		// TMQ ��ŷ�� ����Ʈ�� �޴´�.

extern RWS::CEventId g_EventTMQMemberListRes;		// TMQ ��ŷ���� ������ ��Ƽ ����Ʈ�� �޴´�.

extern RWS::CEventId g_EventBudokaiNews;				// õ������ ����ȸ �ҽ���
extern RWS::CEventId g_EventBudokaiPrizeWinnerName;		// õ������ ����ȸ ����� �̸�

extern RWS::CEventId g_EventScriptLinkNotify;

extern RWS::CEventId g_EventBudokaiTournamentIndividualList;	// õ������ ����ȸ ������ʸ�Ʈ
extern RWS::CEventId g_EventBudokaiTournamentIndividualInfo;	
extern RWS::CEventId g_EventBudokaiTournamentTeamList;			// õ������ ����ȸ ������ʸ�Ʈ
extern RWS::CEventId g_EventBudokaiTournamentTeamInfo;	

extern RWS::CEventId g_EventDiceStart;				// �ֻ��� ����

extern RWS::CEventId g_EventDiceResult;				// �ֻ��� ���� ���
extern RWS::CEventId g_EventDiceResultShow;			// �ֻ��� ����� ǥ���Ѵ�

extern RWS::CEventId g_EventDiceRollReqtoServer;	// �ֻ����� ���� ������� ������ ��û�Ѵ�

extern RWS::CEventId g_EventShopGambleBuyRes;			// �׺� ������ ���� ���
extern RWS::CEventId g_EventGambleUseEffect;			// �׺� ������ ��� ����

extern RWS::CEventId g_EventPetition;				// ���� ���� �ý��� ���� �޼���

// game teleport proposal notify
extern RWS::CEventId g_EventTeleportProposalNfy;		///< �ڷ���Ʈ ���� �̺�Ʈ
extern RWS::CEventId g_EventTeleportConfirmRes;			///< �ڷ���Ʈ Ȯ�� ����Ʈ

extern RWS::CEventId g_EventObserverMenu;					///< GM �޴� ����

extern RWS::CEventId g_EventRPCharge;					// RP Charge;

extern RWS::CEventId g_EventBattleCombatMode;					//

extern RWS::CEventId g_EventItemIdentifyEffect;		///< ������ ���� ����Ʈ

// Hoipoi Mix
extern RWS::CEventId g_EventHoipoiMixItemMakeRes;		///< ������ �����
extern RWS::CEventId g_EventHoipoiMixCreateStart;		///< �����Ƿ� ������ �����

extern RWS::CEventId g_EventHintViewClosed;				///< ���̵� �並 �����Ѵ�.

// Loading
extern RWS::CEventId g_EventLoading;

// NetPyShop
extern RWS::CEventId g_EventNetPyShopEvent;

// CommercialExtend
extern RWS::CEventId g_EventCommercialExtendCommand;

//hlshop
extern RWS::CEventId g_EventHLShopEvent;
extern RWS::CEventId g_EventHLShopEventBuy;
extern RWS::CEventId g_EventHLShopEventGift;
extern RWS::CEventId g_EventHLShopEventItemInfo;
extern RWS::CEventId g_EventHLShopEventItemInfoRes;
extern RWS::CEventId g_EventHLShopEventItemBuyRes;
extern RWS::CEventId g_EventHLShopEventItemMoveRes;
extern RWS::CEventId g_EventHLShopEventItemUseRes;
extern RWS::CEventId g_EventHLShopEventItemAddNfy;
extern RWS::CEventId g_EventHLShopEventItemDelNfy;
extern RWS::CEventId g_EventHLShopEventItemGiftRes;

// Open BagGui, ScouterBackgroundGui, ...
extern RWS::CEventId g_EventOpenBagGui; 
extern RWS::CEventId g_EventOpenScouterBackgroundGui;

// test code
extern RWS::CEventId g_EventSCS;

// Mascot
extern RWS::CEventId g_EventMascotRegister;
extern RWS::CEventId g_EventMascotDelete;
extern RWS::CEventId g_EventMascotSummon;
extern RWS::CEventId g_EventMascotUnSummon;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum eServerConnectType
{
	SERVER_CONNECT_TYPE_CONNENCT_SUCCESS,
	SERVER_CONNECT_TYPE_CONNENCT_FAIL,
	SERVER_CONNECT_TYPE_CONNENCT_DISCONNECT
};

struct SDboEventServerConnect
{
	RwUInt8		byConnectType;
};


//////////////////////////////////////////////////////////////////////////////////
/**
* gui�� ���õ� event, enum
*/

enum eDEVELOPER_TYPE
{
	DEVELOPER_RESET_GUI,						///< GUI�� ���� ������ �ٽ� �ε��Ѵ�
	DEVELOPER_PREVIEW_OPEN,						///< ���߿� Preview Gui�� ����
	DEVELOPER_PREVIEW_CLOSE,					///< ���߿� Preview Gui�� �ݴ´�
};

struct sDboDeveloperData
{
	RwUInt32	uiType;
};

struct SDboEventLogInStageStateEnter
{
	RwUInt8 byState;
};

struct SDboEventKeyboard
{
	std::string key;
};

struct SDboEventLogInStageStateExit
{
	RwUInt8 byState;
};

struct SDboEventLogInStageTimeOut
{
	RwUInt8 byState;
};

//struct SDboEventConnectBoxShow
//{
//	//WCHAR		pString[MAX_MSG_BOX_STRING_LEN];
//	std::wstring	wstrString;
//	RwUInt8			byMsgBoxType;
//	RwUInt32		uiMsgProcessType;
//	RwReal			fRemainTime;	
//	sMsgBoxData*	pExData;
//};

enum eNetMsgBoxProcessType
{
	NPT_NONE,

	
};

struct SDboEventCharStageStateEnter
{
	RwUInt8 byState;
};

struct SDboEventCharStageStateExit
{
	RwUInt8 byState;
};

struct SNtlEventCharMake
{
	RwBool	bSetDefaultCamera;
	BYTE	byRace;
	BYTE	byClass;		
	BYTE	byHair;
	BYTE	byHairColor;	
	BYTE	byFace;
	BYTE	bySkinColor;
	BYTE	byGender;
};

enum eLoginEventType
{
	LOGIN_EVENT_SUCCESS_LOGIN,						// Login succeeded.
	LOGIN_EVENT_DISCONNECTED_AUTH_SERVER,			// ���� ������ ������ ������
	LOGIN_EVENT_FINISH_LOGO_PLAY,					// �� ȸ���� �ΰ� ǥ�ð� ������
	LOGIN_EVENT_START_INTRO_MOVIE_PLAY,				// ��Ʈ�� �������� �����ش�
	LOGIN_EVENT_SHOW_CONTRACT_PAGE,					// ��� �������� �����ش�
	LOGIN_EVENT_FINISH_LOADING_AND_MOVIE,			// �ε��� ���� ������
	LOGIN_EVENT_RETRY_LOGIN_REQ,					// Login failed and try again
};

struct SDboEventLoginMessage
{
	RwUInt8		byMessage;							// �޼���
	RwReal		fValue;								// ��
	RwUInt32	uiExData;
};

enum eLobbyEventType
{	
	LMT_UPDATE_SERVER,									// ���� ������Ʈ	
	LMT_UPDATE_CHANNEL,									// ä�� ������Ʈ
	LMT_REFRESH_SERVER,									// ���� ���� ����
	LMT_REFRESH_CHANEL,									// ä�� ���� ����
	LMT_UPDATE_CHARACTER_LIST,							// ĳ���� ����Ʈ�� ������Ʈ �Ͽ���
	LMT_RENAME_CHARACTER,								// ĳ���� �̸��� �ٲ����		// this is 8 in tw
	LMT_SELECT_CHARACTER,								// ĳ���͸� �����ߴ�			// this is 9 in tw
	LMT_DESTORY_LOBBY_AVATAR,							// �κ��� �ƹ�Ÿ ������ �����
	LMT_DESTORY_LOBBY_WORLD,							// �κ��� ���带 �����Ѵ�

	LMT_SELECT_CHANNEL,									// Channel�� �����ߴ�
	LMT_CREATE_CHARACTER,								// ĳ���� ����� ��ư�� ������

	LMT_GAME_SERVER_WAIT_CHECK_REQ,						// Game Server�� ������ �������� üũ�Ѵ�
	LMT_START_CONNECT_GAME_SERVER,						// Game Server�� ������ �����Ѵ�		// 19 in tw

	LMT_ROTATION_STOP,									// Stop Rotation					// 20 in tw
	LMT_ROTATION_FOREWARD,								// ĳ���Ͱ� ������ �ٶ󺸰� �����
	LMT_ROTATION_LEFT,									// Left Rotation
	LMT_ROTATION_RIGHT,									// Right Rotation			// 23 in tw
	LMT_ROTATION,										// �־��� �� ��ŭ ȸ���Ѵ�
	LMT_ZOOM_IN,										// ĳ���͸� �����Ѵ�
	LMT_ZOOM_OUT,										// ĳ���͸� �ܾƿ��Ѵ�
	LMT_ZOOM_FAR,										// ���� �� �� �ܰ�
	LMT_ZOOM_DEFUALT,									// ĳ���͸� ����Ʈ ��
	LMT_ZOOM_FROM_FAR_TO_DEFUALUT,						// ���� �� �� �ܰ迡�� default �ܰ�� ��ȭ
};

struct SDboEventLobbyMessage
{
	RwUInt8		byMessage;							// �޼���
	RwReal		fValue;								// ��
	RwUInt32	uiExData;
};

struct SDboEventVirtualServerPacket
{
	RwInt32 iDataLen;
	RwChar chPacket[MAX_VIRTUAL_SERVER_PACKET_SIZE];
};

struct SDboEventLoadingEnable
{
	RwBool bEnable;		// TRUE or FALSE
};

struct SDboEventMsgBoxShow	// Stage transition event data structer.
{
	std::wstring	wstrString;
	std::string		strKey;
	RwBool			bPopup;
	RwReal			fShowTime;
	RwBool			bAcceptDuplicate;
	RwBool			bHasInput;
	sMsgBoxData*	pData;
	RwBool			bUpdate;
	std::list<sMsgBoxCustomBtn>* plistCustomBtn;
};

struct SDboEventMsgBoxResult
{
	RwInt32			eResult;
	std::string		strID;
	sMsgBoxData*	pData;
};

struct SDboEventChatGuiMode
{
	RwBool			bMode;
};

struct SDboEventSayMessage
{
	RwUInt8 byMsgType;
	RwUInt32 uiSerial;
	WCHAR wchUserName[NTL_MAX_SIZE_CHAR_NAME + 1];
	WCHAR wchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE + 1];
	BYTE	byChannel;
};

struct SDboEventTimeFixedNotify
{
	RwBool			bActive;
	std::string		strStringID;
	const WCHAR*	pString;
};

/**
* \brief CautionNotify���� Caution SideIcon���� ������ �̺�Ʈ
*/
struct SDboEventCautionSideNotify
{
	RwBool			bActive;
	std::string		strStringID;	///< String index
	const WCHAR*	pString;		///< String
	RwReal			fLifeTime;		///< duration
};

struct SDboEventNotify
{
	enum TYPE { ACTION, PUBLIC, NPC, RESULTCODE, TERRITORY };
	
	RwUInt32	eType;
	WCHAR		wchMessage[NTL_MAX_LENGTH_OF_CHAT_MESSAGE + 1];
};

struct SDboEventFlashNotify
{
	RwUInt8		byProgressType;	
	RwUInt8		byMessageValue;
	RwUInt8		byMessageType;
};

struct SDboEventFlashNotifyString
{
	RwChar*		pcFlashFile;
	RwChar*		pcSecondFlashFile;
	RwBool		bFinishNotify;
};

struct SDboEventFlashFinishNotify
{
	RwUInt8		byProgressType;	
	RwUInt8		byMessageValue;
	RwUInt8		byMessageType;
	RwChar*		pcFlashFile;
	RwChar*		pcSecondFlashFile;
};

enum eGroupNotifyType
{
	GROUP_NOTIFY_PARTY,
	GROUP_NOTIFY_GUILD,
};

struct SDboEventGroupNotify
{
	RwUInt8		byType;
	WCHAR*		pwcText;
};

struct SDboEventNameNotify
{
	WCHAR*		pwcText;
};

struct SDboEventIconPopupShow
{
	RwBool bShow;
	RwUInt32 uiSerial;	
	RwInt32	nSrcPlace;
	RwInt32 nSrcSlotIdx;
	RwInt32 nXPos;
	RwInt32 nYPos;
};

struct SDboEventIconPopupResult
{
	RwUInt32 uiSerial;
	RwInt32 nSrcPlace;
	RwInt32 nSrcSlotIdx;
	RwInt32	nWorkId;
};

struct SDboEventCalcPopupShow
{
	RwBool bShow;
	RwUInt32 uiSerial;
	RwInt32	nSrcPlace;	
	RwInt32 nXPos;
	RwInt32 nYPos;
	RwInt32 uiMaxValue;
	bool	bAllowNull;
};

struct SDboEventCalcPopupResult
{
	RwUInt32	uiSerial;
	RwInt32		nSrcPlace;
	RwUInt32	uiValue;
};

struct SDboEventShop
{
	RwInt32			iType;

	RwUInt32		uiSerial;		///< NPC or Item
	unsigned long	ulPrice;		///< Item Price
	wchar_t*		pcItemName;		///< Item name
	RwUInt32		needItemCount;

	// for Server
	RwInt32			iPlace;			///< NPC Stores tab, or bag number
	RwInt32			iPosition;		///< The position of the item registered in the tab, the slot number in the bag
	RwInt32			iOverlapCount;	///< amount
};

enum eShopEventType
{
	TRM_NPCSHOP_OPEN,				///< NPC ������ ������
	TRM_ITEM_EXCHANGE_SHOP_OPEN,

	TRM_REG_ITEM_BY_NPCSHOP,		///< NPC �������� ������ ��� ���� ����Ͽ���.
	TRM_REG_ITEM_BY_NPCSHOP_LARGE_BUY,///< NPC �������� ������ ��� ���� �뷮 ����Ͽ���.
	TRM_REG_ITEM_BY_BAG,			///< ���濡�� ������ �ȱ����� ����Ͽ���.
	
	TRM_BUY_SUCCESS,				///< ���� ����
	TRM_SELL_SUCCESS,				///< �Ǹ� ����	

	TRM_CLOSE,						///< īƮ�� �ݴ´�.

	TRM_MESSAGETYPE_NUM
};

struct SDboEventDialog
{
	RwInt32			iType;			///< NPC �̺�Ʈ Ÿ��

	RwInt32			iSrcDialog;		///< �̺�Ʈ�� �߻���Ű�� Dialog
	RwInt32			iDestDialog;	///< �̺�Ʈ�� �޴� Dialog

	RwInt32			iUserData;
	RwInt32			iUserData2;
	RwUInt32		uiUserData3;
	RwUInt32		uiUserData4;
};

enum eDialogEventType
{	
	DIALOGEVENT_NPC_BYEBYE,						///< NPC���� ��ȭ, �ŷ����� �۾��� �����ϰ� ������.
	DIALOGEVENT_BEGIN_TRADING_ITEM_IN_BAG,		///< ���� ���� �������� �ŷ��� �����Ѵ�.
												///< UserData : ���� ���� �ε���, UserData2 : ���� ��ȣ
	DIALOGEVENT_END_TRADING_ITEM_IN_BAG,		///< ���� ���� �������� �ŷ��� ������.
												///< UserData : ���� ���� �ε���, UserData2 : ���� ��ȣ
	DIALOGEVENT_BEGIN_UPGRADE_ITEM_IN_BAG,		///< ������� �������� ���׷��̵� �Ѵ�.
												///< UserData : ���� ���� �ε���, UserData2 : ���� ��ȣ
	DIALOGEVENT_END_UPGRADE_ITEM_IN_BAG,		///< ������� �������� ���׷��̵带 ������.
												///< UserData : ���� ���� �ε���, UserData2 : ���� ��ȣ

	DIALOGEVENT_BEGIN_ITEM_IN_OPTIONRECONSTRUCTION,
	DIALOGEVENT_END_ITEM_IN_OPTIONRECONSTRUCTION,

	DIALOGEVENT_OPEN_FAIL_NPC_DIALOG,			///< NPC ���̾�α׸� ���� ���� �����Ͽ���
	DIALOGEVENT_INPUTEDITBOX_LOST_FOCUS_WITH_ESC_KEY,	///< InputEditbBox�� ESCŰ�� ���� ��Ŀ���� �Ҿ���

	DIALOGEVENT_SKIP_MOUSE_WHEEL,				///< GUI Chatting Displayâ���� MouseWheel�� �۵��Ͽ� 3D ������ MouseWheel�� �����Ѵ�

	DIALOGEVENT_CLOSE_EMBLEM_MAKER,				///< Guild Dialog�� Emlem Maker gui�� �ݴ´�
	DIALOGEVENT_FAIL_CLOSE_EMBLEM_MAKER,		///< Guild Dialog�� Emlem Maker gui�� �ݱ⸦ �����ߴ�

	DIALOGEVENT_CLOSE_GUILD_NOTICE,				///< Guild Dialog�� Notice gui�� �ݴ´�
	DIALOGEVENT_FAIL_CLOSE_GUILD_NOTICE,		///< Guild Dialog�� Notice gui�� �ݱ⸦ �����ߴ�

	DIALOGEVENT_REPAIR,							///< �������� ������ �� �������� ���ƴ�.
	DIALOGEVENT_REPAIR_ALL,						///< �������� ������ ��� �������� ���ƴ�.

	DIALOGEVENT_CREATE_DOJO_GUI,				/// ���� GUI�� �����Ѵ�
};

struct SDboEventUpdateRP
{
	RwUInt32	hSerial;
	RwInt32		nRP;
	RwInt32		nMaxRP;
};

struct SDboEventUpdateRpStock
{
    RwUInt32    hSerial;
    RwInt32     nRpStock;
    RwInt32     nMaxRpStock;
	bool		bDropByTime;
};

struct SDboEventUpdateExp
{
	RwUInt32	uiIncreasedExp;         ///< ��Ż ��·�
    RwUInt32    uiAcquisitionExp;       ///< ���� ��·�, PC�� ���ʽ��� ����Ѵ�
    RwUInt32    uiBonusExp;             ///< ���ʽ� ��·�, PC�� ���ʽ��� ����Ѵ�.
};

struct SDboEventPartyContribution
{
	RwUInt32		iType;				///< �̺�Ʈ Ÿ��
	RwUInt8			byPos;				///< ���� ��ġ
	RwUInt32		uiValue;
};

struct SDboItemUpgradeResult
{
	WORD	wResultcode;
	BYTE	byGrade;
	WORD	wResultMessageCode;
	BYTE	byStoneCount;
	BYTE	byGuardStoneCount;
};

struct SDboRegisterItemUpgrade
{
	RwUInt32		hSrcSerial;
	RwUInt32		eSrcPlace;
	RwUInt32		uiSrcSlotIdx;
};

struct SDboItemChangeOptionResult
{
	void*	pItemOptionSet;
	BYTE	byBoxCount;
};

struct SDboItemChangeBattleAttributeResult
{
	WORD		wResultcode;
	RwUInt8		byBattleAttribute;
};

struct SDboNpcDialogOpen
{
	RwUInt32		hSerialId;
	RwInt32			eDialog;
};

enum eMapMessageType
{
	MMT_MINIMAP_ZOON_IN,				///< �̴ϸ� Ȯ��
	MMT_MINIMAP_ZOON_OUT,				///< �̴ϸ� ���

	MMT_APPEAR_HIDDEN_OBJECT,			///< ���� ������Ʈ�� ȭ�鿡 ��Ÿ����
	MMT_DISAPPEAR_HIDDEN_OBJECT,		///< ���� ������Ʈ�� ȭ�鼭 �������

	MMT_WARFOG_UPDATE,					///< �����׸� ������Ʈ �Ѵ�

	MMT_MINIMAP_SHOW_OUR_TEAM,			///< �̴ϸʿ� �츮���� ǥ���Ѵ�
	MMT_MINIMAP_HIDE_OUR_TEAM,			///< �̴ϸʿ� �츮���� ǥ������ �ʴ´�

	MMT_MINIMAP_SHOW_OTHER_TEAM,		///< �̴ϸʿ� ������� ǥ���Ѵ�
	MMT_MINIMAP_HIDE_OTHER_TEAM,		///< �̴ϸʿ� ������� ǥ������ �ʴ´�
};

struct SDboEventMap
{
	RwInt32			iMessage;
	RwUInt32		uiValue;
};

enum eUserTradeEventType
{
	USERTRADE_START,					///< ����
	USERTRADE_ADD_ITEM,					///< �ڽ��� �������� ��ϵǾ���	
	USERTRADE_DEL_ITEM,					///< �ڽ��� �������� �����Ǿ���	
	USERTRADE_UPDATE_ITEM,				///< �������� ������ ����Ǿ���
	USERTRADE_UPDATE_ZENNY,				///< ���ϰ� ����Ǿ���
	USERTRADE_REDAY,					///< �ŷ� �غ� �Ǿ���

	USERTRADE_ADD_ITEM_NOTIFY,			///< �ٸ� ����� �������� ��ϵǾ���
	USERTRADE_DEL_ITEM_NOTIFY,			///< �ٸ� ����� �������� �����Ǿ���
	USERTRADE_UPDATE_ITEM_NOTIFY,		///< �ٸ� ����� �������� ������ �����Ͽ���
	USERTRADE_UPDATE_ZENNY_NOTIFY,		///< �ٸ� ����� ���ϸ� �����Ͽ���
	USERTRADE_REDAY_NOTIFY,				///< �ٸ� ����� �ŷ� �غ� �Ǿ���

	USERTRADE_END,						///< ����
	USERTRADE_DECLINE,					///< �ŷ� ��û �ź�
	USERTRADE_ACCEPT,					///< �ŷ� ��û ���
};

struct SDboEventUserTrade
{
	RwUInt8			byEventType;
	RwUInt32		uiTarget;
	RwUInt32		uiHandle;
	RwUInt8			byCount;
	void*			pData;
};

struct SDboEventServerCharDialog
{
	RwUInt32		uiSerial;
	RwUInt8			byDialogType;
	RwUInt32		uiTextTblIdx;
	RwBool			bIsRefSpeechTable;
	RwUInt16		wTextLen;
	WCHAR*			pTextData;
};

struct SDboEventEnableItemIcon
{
	RwBool			bEnable;
	RwInt32			ePlace;
	RwInt32			nPlaceIdx;
	RwUInt32		uiSlotIdx;	
};

struct SDboEventCapsuleLockItem
{
	RwBool			bEnable;
	RwInt32			ePlace;
	RwInt32			nPlaceIdx;
	RwUInt32		uiSlotidx;
};

struct SDboEventCapsuleLockItemWithoutBag
{
	RwBool			bEnable;
	SERIAL_HANDLE	hItem;
};

struct SDboEventDirectMoveIcon
{
	RwUInt32		uiSrcSerial;
	RwUInt32		eSrcPlace;
	RwUInt32		eDestPlace;
	RwUInt32		uiSrcSlotIdx;
	RwUInt32		uiSrcStackCount;
};

struct SDboEventOpenHelpWindow
{
	RwUInt32		uiTableIndex;
};

struct SDboEventOpenHelpContent
{
	RwUInt32		uiDialogType;
};

struct SDboEventTMQ
{
	RwUInt32		uiMessage;
	RwUInt32		uiValue;
	RwUInt32		uiValue2;
	VOID*			pData;
}; 

struct SDboEventPrivateShopSelectNfy
{
	RwUInt8			uiPrivateShopPos;
	RwUInt8			uiItemState;
};

struct SDboEventRegPrivateShopCartItem
{
	RwUInt32		uiSerial;
	RwUInt32		uiPlace;
	RwUInt32		uiPos;
	RwUInt32		uiStackCount;
	RwUInt32		uiPrice;
	void*			pData;
};

struct SDboEventRegPrivateShopItem
{
	RwUInt32		uiPlace;
	RwUInt32		uiIndex;
	RwUInt32		uiPos;
};

/**
* \brief ���λ��� ���� ���� �̺�Ʈ�� ����ü
*/
struct SDboEventPrivateShopBusinessStart
{
	RwUInt8					uiType;					///< ��������, �մ� Type
	RwUInt32				uiShopOwner;			///< ���������� �ڵ�
	WCHAR					awcTargetName[NTL_MAX_SIZE_CHAR_NAME + 1];	///< ������ ĳ���� �̸�
	sPRIVATESHOP_ITEM_DATA* pPrivateShopItemData;	///< ���λ��� ������ ����Ÿ ����ü
	void*					pGui;					///< ���λ����� GUI Ŭ���� ������
};

/**
* \brief ���λ��� ���� ��������(��ñ���)�� ����ü
*/
struct SDboEventPrivateShopBusinessFluctuations
{
	RwUInt8					uiType;					///< ��������, �մ� Type
	sPRIVATESHOP_ITEM_DATA* pPrivateShopItemData;	///< ���λ��� ������ ����Ÿ ����ü
	RwUInt32				uiStartPrice;			///< ���� ���۰���
};

/**
* \brief ���λ��� ����â�� ������� �̺�Ʈ
*/
struct SDboEventPrivateShopBusinessCloseWindowNfy
{
	RwUInt32				uiShopOwner;
};

enum eBackboardEventType
{
	BET_COLOR,							///< ������ �ٲ۴�
	BET_ALPHA,							///< �������� �ٲ۴�
};

struct SDboEventBackboard
{
	RwUInt32		uiMessage;
	RwUInt8			byValue;
	RwUInt8			byValue2;
	RwUInt8			byValue3;
};

struct SDboEventSummonPet
{
	RwBool			bCreate;			// �����̸� TRUE, �Ҹ��̸� False
	RwUInt32		uiSerialID;			// Summon Pet�� �ø��� ID
};

struct SDboEventOpenSendMail
{
	WCHAR			awcTargetName[NTL_MAX_SIZE_CHAR_NAME + 1];
};

struct SDboEventReadingMail
{
	RwUInt32		uiMailID;
	RwBool			bReading;
};

enum eQuestMessageType
{
	QUEST_MESSAGE_QUEST_TEXT_TABLE,
	QUEST_MESSAGE_TMQ_SCRIPT,
	QUEST_MESSAGE_VISIT_QUEST,
};

struct SDboEventQuestMessage
{
	RwUInt32		uiValue;
	RwUInt32		uiValue2;
};

struct SDboEventQuestMessage2
{
	sQUEST_INFO*	pQuestInfo;
	RwUInt32		uiEventGenType;
	RwUInt32		uiID;
};

struct SDboEventRpBonusSetup
{
	RwInt32 iXPos;
	RwInt32 iYPos;
	VOID*	pData;
};

struct SDboEventRpBonusAuto
{
	RwUInt8 byRpBonusType;
};

struct SDboEventRankBattleRankListRes
{
	RwUInt16	wResultCode;
	RwUInt32	dwPage;
	RwUInt8		byCompareDay;
	RwUInt8		byRankInfoCount;
	RwUInt16	wRankInfo;
	VOID*		sData;
};

struct SDboEventRankBattleRankFindCharacterRes
{
	RwUInt16	wResultCode;
	RwUInt32	dwPage;
	RwUInt8		byCompareDay;
	WCHAR*		pwsCharName;
	RwUInt8		byRankInfoCount;
	RwUInt16	wRankInfo;
	VOID*		sData;
};

struct SDboEventRankBattleRankCompareDayRes
{
	RwUInt16	wResultCode;
	RwUInt32	dwPage;
	RwUInt8		byCompareDay;
	RwBool		bIsFullList;
	RwUInt8		byInfoCount;
	union
	{
		RwUInt16	wRankInfo;
		RwUInt16	wCompareInfo;
	};

	VOID*		sData;
};

struct SDboEventZennyLootingEffect
{
	RwUInt32	uiZenny;
};

struct SDboEventItemCreatedEffect
{
	RwUInt32	hSerial;
	RwUInt8		ucBagIdx;
	RwUInt8		ucSlotIdx;
};

enum eSideDialogMessageType
{
	SDIALOG_MESSAGE_CONTROLLER_ADD_BUTTON,		///< Add a button to Side dialog controller
	SDIALOG_MESSAGE_CONTROLLER_DEL_BUTTON,		///< Delete the button from Side dialog controller
	SDIALOG_MESSAGE_MINIMIZE,					///< Side dialog minimization
	SDIALOG_MESSAGE_INACTIVE,					///< Side dialog Close Minimize window
};

struct SDBoEventSideDialog
{
	RwUInt8		byMessage;
	RwUInt32	uiSrcSDialog;
	RwUInt32	uiDestSDialog;
	RwUInt32	uiExData;
};

struct SDboEventTMQRecordListRes
{
	RwUInt16	wResultCode;
	RwUInt32	tmqTblidx;
	RwUInt8		byDifficult;
	RwUInt8		byTeamCount;
	VOID*		paTeam;
};

struct SDboEventTMQMemberListRes
{
	RwUInt16	wResultCode;
	RwUInt32	tmqTblidx;
	RwUInt8		byDifficult;
	RwUInt8		byRank;
	VOID*		pTeam;
};

/**
* \brief õ������ ����ȸ �ҽ��� Interface�� �����ϴ� �̺�Ʈ ����ü
*/
struct SDboEventBudokaiNews
{
	RwBool		bShow;			///< Open Close ����
	RwUInt8		byType;			///< Open�� Type
};

/**
* \brief Script Link Table�� �����϶�� �̺�Ʈ
*/
struct SDboEventScriptLinkNotify
{
	RwUInt8		byType;								///< ������ �������� Ÿ��
	RwUInt8		byAction;							///< Ÿ�Կ� ���� �ൿ�� ����
	WCHAR		wszValue[DBO_MAX_LENGTH_FILE + 1];	///< Value
};

struct SDboEventBudokaiTournamentIndividualList
{
	RwUInt16	wEntryTeam_var;
	RwUInt8		byMatchDataCount;
	RwUInt16	wMatchData_var;
	sVARIABLE_DATA*	pData;
};

struct SDboEventBudokaiTournamentIndividualInfo
{
	RwUInt16		wTeamType[2];
	sVARIABLE_DATA* pData;
};

struct SDboEventBudokaiTournamentTeamList
{
	RwUInt16	wEntryTeam_var;
	RwUInt8		byMatchDataCount;
	RwUInt16	wMatchData_var;
	sVARIABLE_DATA*	pData;
};

struct SDboEventBudokaiTournamentTeamInfo
{
	RwUInt16		wTeamType[2];
	sVARIABLE_DATA* pData;	
};

struct SDboEventDiceResult
{
	SERIAL_HANDLE hHandle;
	RwUInt8		byWorkID;
	RwUInt8		byResultNum;
};

typedef SDboEventDiceResult SDboEventDiceResultShow;

struct SDboEventDiceStart
{
	RwUInt8		byWorkID;
	void*		pExData;
};

struct SDboEventDiceRequesttoServer
{
	RwUInt8		byWorkID;
};

struct SDboEventShopGambleBuyRes
{
	RwUInt16 wResultCode;
	RwUInt32 hHandle;
	RwUInt32 hItem;
};

struct SDboEventGambleUseEffect
{
	RwUInt8	ucBagIdx;			// �׺� ������ ������ Item �� ���濡 ���� ������ ���ֱ� ����
	RwUInt8	ucSlotIdx;
	RwUInt32 hCreateSerial;		///< �׺��� ������ ������
	RwChar  szEffectFile[ DBO_MAX_LENGTH_ITEM_ICON_NAME + 1 ];		// ���� ���� �̸�
};

struct SDboEventRegMailAttachItem
{
	SERIAL_HANDLE	hHandle;
	RwUInt32		uiPlace;
	RwUInt32		uiIndex;
	RwUInt32		uiPos;
};

struct SDboEventQuickTeleportLoad
{
	BYTE					byCount;
	sQUICK_TELEPORT_INFO*	asData;
};

struct SDboEventQuickTeleportUpdate
{
	void*	asData;
};

struct SDboEventQuickTeleportDeleteAndMove
{
	BYTE	bySlot;
};

enum ePetitionEventType
{
	PETITON_OPEN_DILAOG,						///< ���(����) ��ûâ�� ����
	PETITON_CLOSE_DILAOG,						///< ���(����) ��ûâ�� �ݴ´�
	PETITON_REQUEST_OK,							///< ���(����)�� ��û�� GM���� ���޵Ǿ���
	PETITON_MODIFY_OK,							///< ���(����)�� ���� ��û�� GM���� ���޵Ǿ���
	PETITON_CANCEL,								///< ���(����)�� ��ҵǾ���.
	PETITON_FINISH,								///< ���(����)�� ó���Ǿ���.

	PETITON_ENABLE_PETITON_GUI,					///< PetitionGui�� Ȱ��ȭ �Ѵ�

	PETITON_CHATTING_START,						///< GM ä���� �����Ѵ�
	PETITON_CHATTING_END,						///< GM ä���� �����Ѵ�
	PETITON_FINISH_RESEARCH_SATISFACTION,		///< ������ ���縦 �����Ѵ�
};

struct SDboEventPetition
{
	RwUInt32		uiEventType;
};

struct SDboEventTeleportProposalNfy
{
	RwUInt8				byTeleportType;
	RwUInt8				byInfoIndex;

	RwUInt16			wWaitTime;
	TBLIDX				worldTblidx;

	union
	{
		RwUInt32		dwReserve;
		RwUInt8			byBudokaiMatchDepth;
	};

	WCHAR				wszSummonnerName[NTL_MAX_SIZE_CHAR_NAME + 1];
};

struct SDboEventTeleportConfirmRes
{
	RwUInt16			wResultCode;
	RwUInt8				byTeleportIndex;
	bool				bTeleport;
	bool				bClearInterface;
};

enum eObserverMenuEventType
{
	OBSERVER_START_OBSERVER,					///< ������ �޴��� �����Ѵ�
	OBSERVER_END_OBSERVER,						///< ������ �޴��� �����Ѵ�
	OBSERVER_SHOW_PLAYER_INFO,					///< PlayerInfo Gui�� �����ش�
	OBSERVER_REMOVE_PLAYERINFO_GUI,				///< PlayerInfo Gui�� �����Ѵ�
	OBSERVER_SELECT_POPUPMENU,					///< Popup �޴����� ������ �ߴ�
	OBSERVER_TENKAICHI_MATCH_DATA_REQ,			///< õ������ ����ȸ ���������� ��û�ߴ�
	OBSERVER_TENKAICHI_MATCH_DATA_RES,			///< õ������ ����ȸ ���������� �޾Ҵ�
	OBSERVER_TENKAICHI_MATCH_DATA,				///< õ������ ����ȸ �������� ����
};

struct SDboEventObserverMenu
{
	RwUInt8			byEventType;
	SERIAL_HANDLE	hHandle;
	RwUInt32		uiValue;
	void*			pExdata;
};

struct SDboEventRPCharge
{
	RwBool			bIncrease;					///< or Decrease
	RwBool			bStop;						///< or Start
};

struct SDboEventBattleCombatMode
{
	bool			bCombatMode;
};

struct SDboEventItemIdentifyEffect
{
	RwBool			bHandle;					///< Handle���̳� Pos���̳��� ����

	SERIAL_HANDLE	hItemHandle;
	RwUInt8			byPlace;
	RwUInt8			byPos;
};

// Hoipoi

struct SDboEventHoipoiMixItemMakeRes
{
	RwUInt16		wResultCode;
	TBLIDX			itemTblidx;
	HOBJECT			hObject;
	TBLIDX			idxRecipeTbl;
	SERIAL_HANDLE	hItem;
};

struct SDboEventHoipoiMixCreateStart
{
	TBLIDX			idxRecipeTbl;
};

enum eMailSlotUpdateType
{
	eMAILSLOT_UPDATE_LOCK = 0,

	eMAILSLOT_UPDATE_NUMS,
	eMAILSLOT_UPDATE_INVALID = 0xFF
};

struct SDboEventMailSlotUpdate
{
	RwUInt8		byType;
	RwUInt32	uiParam1;
	RwUInt32	uiParam2;
};

struct SDboEventShopNetPyItemStartRes
{
	RwUInt8 byType;	// 0 : �⺻ 1 : �������� �Ǹ� �̺�Ʈ NPC
};

enum eNetPyShopEventType
{
	eNETPYSHOP_EVENT_START,
	eNETPYSHOP_EVENT_REG_ITEM,
	eNETPYSHOP_EVENT_REG_ITEM_MAX,
	eNETPYSHOP_EVENT_BUY_SUCCESS,
	eNETPYSHOP_EVENT_END,

	eNETPYSHOP_NUMS,
	eNETPYSHOP_INVALID = 0xFF
};

// NetPyShop Event
struct SDboEventNetPyShopEvent
{
	RwUInt8 byEventType;

	RwUInt32		uiSerial;		///< NPC or Item
	unsigned long	ulPrice;		///< ������ ����
	wchar_t*		pcItemName;		///< ������ �̸�

	RwInt32			nPlace;			///< ������ ��, Ȥ�� ������ ��ȣ
	RwInt32			nPosition;		///< �Ǿ� ��ϵ� �������� ��ġ, ���� ���� ���� ��ȣ
	RwInt32			nOverlapCount;	///< ����
};

enum eHLShopEventType
{
	eHLSHOP_EVENT_START,
	eHLSHOP_EVENT_REFRESH,
	eHLSHOP_EVENT_END
};

struct SDboEventHLShopEvent
{
	BYTE		byEventType;
	DWORD		dwCash;
};

struct SDboEventHLShopEventBuy
{
	bool		bConfirm;
	TBLIDX		hlsItemIdx;
};

struct SDboEventHLShopEventGift
{
	bool		bConfirm;
	TBLIDX		hlsItemIdx;
	WCHAR		wchPlayer[NTL_MAX_SIZE_CHAR_NAME + 1];
};

struct SDboEventHLShopEventItemInfo
{
	BYTE byCount;
	sCASHITEM_BRIEF* aInfo;
};

struct SDboEventHLShopEventItemBuyRes
{
	DWORD dwCash;
};

struct SDboEventHLShopEventItemGiftRes
{
	DWORD dwCash;
};

struct SDboEventHLShopEventItemMoveRes
{
	QWORD qwProductId;
};

struct SDboEventHLShopEventItemAddNfy
{
	sCASHITEM_BRIEF* aInfo;
};

struct SDboEventHLShopEventItemDelNfy
{
	QWORD qwProductId;
};

// CommercialExtend
enum eCommercialExtendCommandType
{
	eSTART_PROCESS_BUY_NPC_DURATION_ITEM,	/// durration item �ŷ� ���� ����
	eSTART_PROCESS_BUY_NETPY_DURATION_ITEM,	/// durration item �ŷ� ���� ����
	eSTART_PROCESS_MOVE_DURATION_ITEM,	/// durration item �ߵ巡Ʈ �̵� ���� ����
	eSET_DURATION_ITEM,					/// �ŷ��� durration item tblidx setting
	eSET_DURATION_EXTEND_TARGET_ITEM,	/// �Ⱓ ������ Target NtlSobItem setting
	eCHANGE_COMMERCIALEXTEND_MODE,		/// COMMERCIALEXTEND_DIALOG����   GUI_EXTEND_MODE ����
	eOPEN_COMMERCIALEXTEND_DIALOG,		/// data: RwInt32 iMode, RwUInt32 uiItemIdx

	// Mascot
	eSUMMON_MASCOT,
	eUNSUMMON_MASCOT,
	eDELETE_MASCOT,
};

struct SDboEventCommercialExtendNPCData
{
	RwUInt32 uiItemIdx;
	RwUInt32 uiNPCSerial; 
	sSHOP_BUY_CART ShopBuyCart;
};

struct SDboEventCommercialExtendNetpyData
{
	RwUInt32 uiItemIdx;
	RwUInt32 uiMerchantTblidx;
	BYTE byMerchanSlotPos;
};

struct SDboEventCommercialExtendYardratData
{
	RwUInt32 uiItemIdx;
	RwUInt32 uiProductId;
};

struct SDboEventCommercialExtendOpenData
{
	int iMode;						/// GUI_EXTEND_MODE enum
	RwUInt32 uiItemIdx;
};

struct SDboEventCommercialExtendCommand
{
	eCommercialExtendCommandType eCommandType;
	void*				pData;
};

// quickslot
struct SDboEventQuickSlotDelNfy
{
	RwUInt8	bySlotIdx;
	HOBJECT	hHandle;
	RwBool	bSendPacket;
};

struct SDboEventCharTitleSelectRes
{
	TBLIDX	uiTitle;
};

struct SDboEventCharTitleUpdate
{
	TBLIDX	uiTitle;
	bool	bDelete;
};

struct SDboEventLoading
{
	RwUInt8 byMessage;
};

enum eLOADING_EVENT_MESSAGE
{
	LOADING_EVENT_FIRST_MOVIE_END,
	LOADING_EVENT_SECOND_MOVIE_END,
	LOADING_EVENT_THIRD_MOVIE_END,
};

//////////////////////////////////////////////////////////////////////////
// �ѱ� PC�� ���� 
//////////////////////////////////////////////////////////////////////////
extern RWS::CEventId g_EventUpdateNetPy;                       ///< NetPy�� ���� �Ǿ�����
extern RWS::CEventId g_EventNetMarbleMemberShipNfy;            ///< PC�� ������� ������ ������

struct SDboEventUpdateNetPy
{
    DWORD   netPy;                                              ///< ���� ����
    DWORD   dwAccumlationNetPy;                                 ///< ������ ���� NetPy
    DWORD   timeNextGainTime;                                   ///< ���� NetPy ȹ�� Ÿ�� (��)
};

struct SDboEventBudokaiPrizeWinnerName
{
	BYTE	byMatchType;

	WORD	wWinner;
	WORD	wSecondWinner;

	// sVARIABLE_DATA
	void*	pData;
};

// Mascot
struct SDboEventMascotRegister
{
	sMASCOT_DATA_EX mascotdata;
};

struct SDboEventMascotOperate
{
	BYTE	index;
};

#endif