#include "precomp_dboclient.h"
#include "DboEvent.h"

#include "ceventhandler.h"


RWS::CEventId g_EventVirtualServerPacket;	// virutal server packet event

RWS::CEventId g_EventLogInServerConnect;	// LogIn server�� ����Ǿ���.

RWS::CEventId g_EventLobbyServerConnect;	// lobby server�� ����Ǿ���.

RWS::CEventId g_EventGameServerConnect;		// game server�� ����Ǿ���.	


RWS::CEventId g_EventLogInStageStateEnter;	// login stage state enter

RWS::CEventId g_EventLogInStageStateExit;	// login stage state exit

RWS::CEventId g_EventLogInStageTimeOut;			// login stage time out


RWS::CEventId g_EventCharStageStateEnter;	// character stage state enter

RWS::CEventId g_EventCharStageStateExit;	// character stage state exit

RWS::CEventId g_EventCharMake;				// Character Making ����

RWS::CEventId g_EventLoginMessage;			// Login Message

RWS::CEventId g_EventLobbyMessage;			// Lobby Message


RWS::CEventId g_EventDebug_for_Developer;	// �����ڸ� ���� ����� ��� �̺�Ʈ

RWS::CEventId g_EventLobbyPacketHelper;		// login Packet helper

RWS::CEventId g_EventLoginGuiEnable;		// login gui enable

RWS::CEventId g_EventVirtualKeyboard;		// virtual keyboard key pressed

RWS::CEventId g_EventCharSelectGuiEnable;	// char select gui enable

RWS::CEventId g_EventMsgBoxShow;			// MsgBox show event

RWS::CEventId g_EventMsgBoxResult;			// Message box resount event

RWS::CEventId g_EventChatGuiMode;			// chatting gui mode

RWS::CEventId g_EventSayMessage;			// chatting message show

RWS::CEventId g_EventSetTextToChatInput;	// Set Text to Chat Input

RWS::CEventId g_EventTimeFixedNotify;		// Time Fixed Notify message

RWS::CEventId g_EventCautionSideNotify;		// Time Fixed Notify -> Caution SideIcon Notify

RWS::CEventId g_EventNotify;				// Notify

RWS::CEventId g_EventFlashNotify;			// Flash notify
RWS::CEventId g_EventFlashNotifyFinish;		// Flash notify finish

RWS::CEventId g_EventFlashNotifyString;		// Flash notify string

RWS::CEventId g_EventFlashFinishNotify;		// Flash finish notify

RWS::CEventId g_EventGroupNotify;			// Group Notify

RWS::CEventId g_EventNameNotify;			// Name Notify

RWS::CEventId g_EventIconMoveClick;			// Icon Move Click

RWS::CEventId g_EventIconPopupShow;			// PopupMenu show

RWS::CEventId g_EventIconPopupResult;		// PopupMenu Result

RWS::CEventId g_EventCalcPopupShow;			// CalcPopup

RWS::CEventId g_EventCalcPopupResult;		// CalcPopup Result

RWS::CEventId g_EventPickedUpHide;			

RWS::CEventId g_EventShop;					// ���� �̺�Ʈ

RWS::CEventId g_EventDialog;				// ���̾�α� �̺�Ʈ

RWS::CEventId g_EventPostDialog;			// ���̾�α� ����Ʈ �̺�Ʈ

RWS::CEventId g_EventUpdateRP;				// RP��ȭ�̺�Ʈ

RWS::CEventId g_EventUpdateRpStock;         // RP Stock ��ȭ �̺�Ʈ

RWS::CEventId g_EventUpdateExp;				// Exp ���� �̺�Ʈ.

RWS::CEventId g_EventCharObjDelete;			// ĳ���� �Ҹ� �̺�Ʈ.

RWS::CEventId g_EventSobCreateDropItemInfo;

RWS::CEventId g_EventItemUpgradeResult;		// ������ ���׷��̵� ���

RWS::CEventId g_EventItemChangeOptionConfirmation;
RWS::CEventId g_EventItemChangeOptionResult;

RWS::CEventId g_EventItemChangeBattleAttributeResult;		// ������ ���׷��̵� ���

RWS::CEventId g_EventRegisterItemUpgrade;	// ������ ���׷��̵彽�Կ� ���( ���콺 �����ʹ�ư )

RWS::CEventId g_EventRegisterItemChangeBattleAttribute;

RWS::CEventId g_EventCharTitleSelectRes;
RWS::CEventId g_EventCharTitleUpdate;

RWS::CEventId g_EventQuickSlotInfo;			// ����� ������ ������ ���.

RWS::CEventId g_EventQuickSlotDelNfy;		// ���������� ������ ���� ����.

RWS::CEventId g_EventNPCDialogOpen;			// NPC���� ���̾�α� ����.

RWS::CEventId g_EventEndterWorld;			// ������ �����̳� �����̵���

RWS::CEventId g_EventMap;					// �̴ϸ�, ��, ����� �޼���

RWS::CEventId g_EventUserTrade;				// ���� Ʈ���̵�

RWS::CEventId g_EventServerCharDialog;		// Server�� ���ɿ� ���� ��ȭâ ����.

RWS::CEventId g_EventOpenHelpWindow;		// Help Wnd ���°� ���ÿ� Condition Check ǥ��

RWS::CEventId g_EventOpenHelpContent;

RWS::CEventId g_EventEnableItemIcon;			// ItemIcon�� Enable����.
RWS::CEventId g_EventCapsuleLockItem;			// ItemIcon�� Lock/Unlock ����
RWS::CEventId g_EventCapsuleLockItemWithoutBag; // ItemIcon�� Lock/Unlock ����(���濡�� ��ũ�� �����ۿ�)

RWS::CEventId g_EventDirectMoveIcon;		// �������� ���� �ű�� ����.

RWS::CEventId g_EventPrivateShopSelectNfy;	// �������� ����϶�� ��Ƽ����

RWS::CEventId g_EventRegPrivateShopCartItem;	// ���λ��� īƮ�� �������� ����Ѵ�.

RWS::CEventId g_EventRegPrivateShopItem;	// ���λ����� �Ǹž������� ����Ѵ�.

RWS::CEventId g_EventPrivateShopBusinessStart;			// ���λ��� ������ ����

RWS::CEventId g_EventPrivateShopBusinessFluctuations;	// ���λ��� ���� ���� ���� ����

RWS::CEventId g_EventPrivateShopBusinessCloseWindow;	// ���λ��� ����â Close

RWS::CEventId g_EventBackboard;				// Backboard Gui �̺�Ʈ

RWS::CEventId g_EventSummonPet;		// SummonPet UI�� ���� �̺�Ʈ

RWS::CEventId g_EventOpenSendMail;			// SendMail�� ����.

RWS::CEventId g_EventReadingMail;			// ReadMail�� �д� ���̴�.

RWS::CEventId g_EventRegMailAttachItem;		// ���� Attach â�� �������� ����Ѵ�.

RWS::CEventId g_EventRegBindSealingAttachItem;		// Attach bind sealing item (equipment or seal coin)

RWS::CEventId g_EventRegHoiPoiMixMaterialItem;

RWS::CEventId g_EventRegCCBDCouponItem;		// Attach CCBD coupon

RWS::CEventId g_EventRegOptionReconstructItem;

RWS::CEventId g_EventOpenQuickTeleport;
RWS::CEventId g_EventQuickTeleportLoad;
RWS::CEventId g_EventQuickTeleportUpdate;
RWS::CEventId g_EventQuickTeleportDelete;
RWS::CEventId g_EventQuickTeleportMove;

RWS::CEventId g_EventRegAuctionHouseItem;

RWS::CEventId g_EventMailSlotUpdate;		// ���� Slot�� ������Ʈ

RWS::CEventId g_EventQuestMessage;			// Quest messageâ ���� �̺�Ʈ

RWS::CEventId g_EventQuestMessage2;			// Quest message2â ���� �̺�Ʈ

RWS::CEventId g_EventRpBonusSetup;			// Skill RpBonus Setup UI�� Open�Ѵ�.

RWS::CEventId g_EventRpBonusSelect;			// Skill RpBonus�� �����ؾ� �Ѵ�.

RWS::CEventId g_EventRpBonusAuto;		// Skill RpBonus�� Auto�� ����� �Ǿ���.

RWS::CEventId g_EventTargetStatusRefresh;	// ���� Ÿ������â�� ��������. ��ī���� ���� ������ǥ�� � ���.

RWS::CEventId g_EventRankBattleRankListRes;	// ��ŷ ������ ����Ʈ�� �޴´�.

RWS::CEventId g_EventRankBattleRankFindCharacterRes;	// ��ŷ ���忡�� ĳ���� �˻� ����� �޴´�.

RWS::CEventId g_EventRankBattleRankCompareDayRes;	// ��ŷ ���忡�� �񱳳�¥ ��û ����� �޴´�.

RWS::CEventId g_EventRankBoardDisable;				// ��ũ ���带 Disable ���·� ��ȯ�϶�.

RWS::CEventId g_EventZennyLootingEffect;	// ���ϸ� �ֿ����� Effect

RWS::CEventId g_EventItemCreatedEffect;		// �������� ������ �������� Effect

RWS::CEventId g_EventSideDialog;				// ���̵� ���̾�α� ����

RWS::CEventId g_EventTMQRecordListRes;		// TMQ ��ŷ�� ����Ʈ�� �޴´�.

RWS::CEventId g_EventTMQMemberListRes;		// TMQ ��ŷ���� ������ ��Ƽ ����Ʈ�� �޴´�.

RWS::CEventId g_EventBudokaiNews;				// õ������ ����ȸ �ҽ��� UI�� Open, �Ǵ� Close �Ѵ�.
RWS::CEventId g_EventBudokaiPrizeWinnerName;	

RWS::CEventId g_EventScriptLinkNotify;		// Script Link Table �̺�Ʈ

RWS::CEventId g_EventBudokaiTournamentIndividualList;	// õ������ ����ȸ ������ʸ�Ʈ
RWS::CEventId g_EventBudokaiTournamentIndividualInfo;	
RWS::CEventId g_EventBudokaiTournamentTeamList;			// õ������ ����ȸ ������ʸ�Ʈ
RWS::CEventId g_EventBudokaiTournamentTeamInfo;	

RWS::CEventId g_EventDiceStart;					// �ֻ��� ����

RWS::CEventId g_EventDiceResult;				// �ֻ��� ���� ���
RWS::CEventId g_EventDiceResultShow;			// �ֻ��� ����� ǥ���Ѵ�

RWS::CEventId g_EventDiceRollReqtoServer;		// �ֻ����� ���� ������� ������ ��û�Ѵ�

RWS::CEventId g_EventShopGambleBuyRes;			// �׺� ������ ���� ���
RWS::CEventId g_EventGambleUseEffect;			// �׺� ������ ��� ����

RWS::CEventId g_EventPetition;				// ���� ���� �ý��� ���� �޼���

RWS::CEventId g_EventTeleportProposalNfy;		///< �ڷ���Ʈ ���� �̺�Ʈ
RWS::CEventId g_EventTeleportConfirmRes;		///< �ڷ���Ʈ Ȯ�� ����Ʈ

RWS::CEventId g_EventObserverMenu;					///< GM �޴� ����

RWS::CEventId g_EventRPCharge;					// RP Charge;

RWS::CEventId g_EventBattleCombatMode;			//

RWS::CEventId g_EventItemIdentifyEffect;

RWS::CEventId g_EventHoipoiMixItemMakeRes;		///< ������ �����
RWS::CEventId g_EventHoipoiMixCreateStart;		///< �����Ƿ� �������� ũ������Ʈ �Ѵ�.

RWS::CEventId g_EventHintViewClosed;			///< ���̵�並 �ϳ� �����Ѵ�.

RWS::CEventId g_EventLoading;

RWS::CEventId g_EventNetPyShopEvent;			///< NetPyShop Event

RWS::CEventId g_EventCommercialExtendCommand;	///< CommercialExtend command Event

RWS::CEventId g_EventHLShopEvent;				///< HLShop Event
RWS::CEventId g_EventHLShopEventBuy;
RWS::CEventId g_EventHLShopEventGift;
RWS::CEventId g_EventHLShopEventItemInfo;
RWS::CEventId g_EventHLShopEventItemInfoRes;
RWS::CEventId g_EventHLShopEventItemBuyRes;
RWS::CEventId g_EventHLShopEventItemMoveRes;
RWS::CEventId g_EventHLShopEventItemUseRes;
RWS::CEventId g_EventHLShopEventItemAddNfy;
RWS::CEventId g_EventHLShopEventItemDelNfy;
RWS::CEventId g_EventHLShopEventItemGiftRes;

RWS::CEventId g_EventOpenBagGui;				///< BagGui open�� �߻�
RWS::CEventId g_EventOpenScouterBackgroundGui;	///< ScouterBackgroundGui open�� �߻�(use scouter)

//------------------------------------------------------
// PC�� ���� �̺�Ʈ
RWS::CEventId g_EventUpdateNetPy;
RWS::CEventId g_EventNetMarbleMemberShipNfy;

//-------------------------------------------------------
// test code
RWS::CEventId g_EventSCS;

// Mascot
RWS::CEventId g_EventMascotRegister;
RWS::CEventId g_EventMascotDelete;
RWS::CEventId g_EventMascotSummon;
RWS::CEventId g_EventMascotUnSummon;