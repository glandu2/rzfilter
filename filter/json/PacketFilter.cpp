#include "PacketFilter.h"
#include <sstream>
#include "Packet/JSONWriter.h"
#include "Core/Utils.h"

#include "AuthClient/TS_AC_ACCOUNT_NAME.h"
#include "AuthClient/TS_AC_AES_KEY_IV.h"
#include "AuthClient/TS_AC_RESULT.h"
#include "AuthClient/TS_AC_RESULT_WITH_STRING.h"
#include "AuthClient/TS_AC_SELECT_SERVER.h"
#include "AuthClient/TS_AC_SERVER_LIST.h"
#include "AuthClient/TS_AC_UPDATE_PENDING_TIME.h"
#include "AuthClient/TS_CA_ACCOUNT.h"
#include "AuthClient/TS_CA_DISTRIBUTION_INFO.h"
#include "AuthClient/TS_CA_IMBC_ACCOUNT.h"
#include "AuthClient/TS_CA_OTP_ACCOUNT.h"
#include "AuthClient/TS_CA_RSA_PUBLIC_KEY.h"
#include "AuthClient/TS_CA_SELECT_SERVER.h"
#include "AuthClient/TS_CA_SERVER_LIST.h"
#include "AuthClient/TS_CA_VERSION.h"

#include "GameClient/TS_CS_ACCOUNT_WITH_AUTH.h"
#include "GameClient/TS_CS_ANTI_HACK.h"
#include "GameClient/TS_CS_ARRANGE_ITEM.h"
#include "GameClient/TS_CS_ATTACK_REQUEST.h"
#include "GameClient/TS_CS_AUCTION_BIDDED_LIST.h"
#include "GameClient/TS_CS_AUCTION_BID.h"
#include "GameClient/TS_CS_AUCTION_CANCEL.h"
#include "GameClient/TS_CS_AUCTION_INSTANT_PURCHASE.h"
#include "GameClient/TS_CS_AUCTION_REGISTER.h"
#include "GameClient/TS_CS_AUCTION_SEARCH.h"
#include "GameClient/TS_CS_AUCTION_SELLING_LIST.h"
#include "GameClient/TS_CS_BATTLE_ARENA_ABSENCE_CHECK_ANSWER.h"
#include "GameClient/TS_CS_BATTLE_ARENA_ABSENCE_CHECK_REQUEST.h"
#include "GameClient/TS_CS_BATTLE_ARENA_ENTER_WHILE_COUNTDOWN.h"
#include "GameClient/TS_CS_BATTLE_ARENA_EXERCISE_READY.h"
#include "GameClient/TS_CS_BATTLE_ARENA_EXERCISE_START.h"
#include "GameClient/TS_CS_BATTLE_ARENA_JOIN_QUEUE.h"
#include "GameClient/TS_CS_BATTLE_ARENA_LEAVE.h"
#include "GameClient/TS_CS_BIND_SKILLCARD.h"
#include "GameClient/TS_CS_BOOKMARK_TITLE.h"
#include "GameClient/TS_CS_BUY_FROM_BOOTH.h"
#include "GameClient/TS_CS_BUY_ITEM.h"
#include "GameClient/TS_CS_CANCEL_ACTION.h"
#include "GameClient/TS_CS_CHANGE_ALIAS.h"
#include "GameClient/TS_CS_CHANGE_ITEM_POSITION.h"
#include "GameClient/TS_CS_CHANGE_LOCATION.h"
#include "GameClient/TS_CS_CHANGE_SUMMON_NAME.h"
#include "GameClient/TS_CS_CHARACTER_LIST.h"
#include "GameClient/TS_CS_CHAT_REQUEST.h"
#include "GameClient/TS_CS_CHECK_BOOTH_STARTABLE.h"
#include "GameClient/TS_CS_CHECK_CHARACTER_NAME.h"
#include "GameClient/TS_CS_CHECK_ILLEGAL_USER.h"
#include "GameClient/TS_CS_COMPETE_ANSWER.h"
#include "GameClient/TS_CS_COMPETE_REQUEST.h"
#include "GameClient/TS_CS_CONTACT.h"
#include "GameClient/TS_CS_CREATE_CHARACTER.h"
#include "GameClient/TS_CS_DECOMPOSE.h"
#include "GameClient/TS_CS_DELETE_CHARACTER.h"
#include "GameClient/TS_CS_DIALOG.h"
#include "GameClient/TS_CS_DONATE_ITEM.h"
#include "GameClient/TS_CS_DONATE_REWARD.h"
#include "GameClient/TS_CS_DROP_ITEM.h"
#include "GameClient/TS_CS_DROP_QUEST.h"
#include "GameClient/TS_CS_EMOTION.h"
#include "GameClient/TS_CS_END_QUEST.h"
#include "GameClient/TS_CS_ENTER_EVENT_AREA.h"
#include "GameClient/TS_CS_ERASE_ITEM.h"
#include "GameClient/TS_CS_FOSTER_CREATURE.h"
#include "GameClient/TS_CS_GAME_GUARD_AUTH_ANSWER.h"
#include "GameClient/TS_CS_GAME_TIME.h"
#include "GameClient/TS_CS_GET_BOOTHS_NAME.h"
#include "GameClient/TS_CS_GET_REGION_INFO.h"
#include "GameClient/TS_CS_GET_SUMMON_SETUP_INFO.h"
#include "GameClient/TS_CS_GET_WEATHER_INFO.h"
#include "GameClient/TS_CS_GROUP_FINDER_LIST.h"
#include "GameClient/TS_CS_HIDE_EQUIP_INFO.h"
#include "GameClient/TS_CS_HUNTAHOLIC_BEGIN_HUNTING.h"
#include "GameClient/TS_CS_HUNTAHOLIC_CREATE_INSTANCE.h"
#include "GameClient/TS_CS_HUNTAHOLIC_INSTANCE_LIST.h"
#include "GameClient/TS_CS_HUNTAHOLIC_JOIN_INSTANCE.h"
#include "GameClient/TS_CS_HUNTAHOLIC_LEAVE_INSTANCE.h"
#include "GameClient/TS_CS_HUNTAHOLIC_LEAVE_LOBBY.h"
#include "GameClient/TS_CS_INSTANCE_GAME_ENTER.h"
#include "GameClient/TS_CS_INSTANCE_GAME_EXIT.h"
#include "GameClient/TS_CS_INSTANCE_GAME_SCORE_REQUEST.h"
#include "GameClient/TS_CS_ITEM_KEEPING_LIST.h"
#include "GameClient/TS_CS_ITEM_KEEPING_TAKE.h"
#include "GameClient/TS_CS_JOB_LEVEL_UP.h"
#include "GameClient/TS_CS_LEARN_SKILL.h"
#include "GameClient/TS_CS_LEAVE_EVENT_AREA.h"
#include "GameClient/TS_CS_LOGIN.h"
#include "GameClient/TS_CS_LOGOUT.h"
#include "GameClient/TS_CS_MIX.h"
#include "GameClient/TS_CS_MONSTER_RECOGNIZE.h"
#include "GameClient/TS_CS_MOVE_REQUEST.h"
#include "GameClient/TS_CS_NURSE_CREATURE.h"
#include "GameClient/TS_CS_OPEN_ITEM_SHOP.h"
#include "GameClient/TS_CS_PUTOFF_CARD.h"
#include "GameClient/TS_CS_PUTOFF_ITEM.h"
#include "GameClient/TS_CS_PUTON_CARD.h"
#include "GameClient/TS_CS_PUTON_ITEM.h"
#include "GameClient/TS_CS_PUTON_ITEM_SET.h"
#include "GameClient/TS_CS_QUERY.h"
#include "GameClient/TS_CS_QUEST_INFO.h"
#include "GameClient/TS_CS_RANKING_TOP_RECORD.h"
#include "GameClient/TS_CS_REGION_UPDATE.h"
#include "GameClient/TS_CS_REPAIR_SOULSTONE.h"
#include "GameClient/TS_CS_REPORT.h"
#include "GameClient/TS_CS_REQUEST_FARM_INFO.h"
#include "GameClient/TS_CS_REQUEST_FARM_MARKET.h"
#include "GameClient/TS_CS_REQUEST_LOGOUT.h"
#include "GameClient/TS_CS_REQUEST_REMOVE_STATE.h"
#include "GameClient/TS_CS_REQUEST_RETURN_LOBBY.h"
#include "GameClient/TS_CS_RESURRECTION.h"
#include "GameClient/TS_CS_RETRIEVE_CREATURE.h"
#include "GameClient/TS_CS_RETURN_LOBBY.h"
#include "GameClient/TS_CS_SECURITY_NO.h"
#include "GameClient/TS_CS_SELL_ITEM.h"
#include "GameClient/TS_CS_SELL_TO_BOOTH.h"
#include "GameClient/TS_CS_SET_MAIN_TITLE.h"
#include "GameClient/TS_CS_SET_PET_NAME.h"
#include "GameClient/TS_CS_SET_PROPERTY.h"
#include "GameClient/TS_CS_SET_SUB_TITLE.h"
#include "GameClient/TS_CS_SKILL.h"
#include "GameClient/TS_CS_SOULSTONE_CRAFT.h"
#include "GameClient/TS_CS_START_BOOTH.h"
#include "GameClient/TS_CS_STOP_BOOTH.h"
#include "GameClient/TS_CS_STOP_WATCH_BOOTH.h"
#include "GameClient/TS_CS_STORAGE.h"
#include "GameClient/TS_CS_SUMMON_CARD_SKILL_LIST.h"
#include "GameClient/TS_CS_SUMMON.h"
#include "GameClient/TS_CS_SWAP_EQUIP.h"
#include "GameClient/TS_CS_TAKE_ITEM.h"
#include "GameClient/TS_CS_TAKEOUT_COMMERCIAL_ITEM.h"
#include "GameClient/TS_CS_TARGETING.h"
#include "GameClient/TS_CS_TRANSMIT_ETHEREAL_DURABILITY.h"
#include "GameClient/TS_CS_TRANSMIT_ETHEREAL_DURABILITY_TO_EQUIPMENT.h"
#include "GameClient/TS_CS_TURN_OFF_PK_MODE.h"
#include "GameClient/TS_CS_TURN_ON_PK_MODE.h"
#include "GameClient/TS_CS_UNBIND_SKILLCARD.h"
#include "GameClient/TS_CS_UPDATE.h"
#include "GameClient/TS_CS_USE_ITEM.h"
#include "GameClient/TS_CS_VERSION.h"
#include "GameClient/TS_CS_WATCH_BOOTH.h"
#include "GameClient/TS_CS_XTRAP_CHECK.h"
#include "GameClient/TS_EQUIP_SUMMON.h"
#include "GameClient/TS_SC_ACHIEVE_TITLE.h"
#include "GameClient/TS_SC_ADDED_SKILL_LIST.h"
#include "GameClient/TS_SC_ADD_PET_INFO.h"
#include "GameClient/TS_SC_ADD_SUMMON_INFO.h"
#include "GameClient/TS_SC_ANTI_HACK.h"
#include "GameClient/TS_SC_ATTACK_EVENT.h"
#include "GameClient/TS_SC_AUCTION_BIDDED_LIST.h"
#include "GameClient/TS_SC_AUCTION_SEARCH.h"
#include "GameClient/TS_SC_AUCTION_SELLING_LIST.h"
#include "GameClient/TS_SC_AURA.h"
#include "GameClient/TS_SC_BATTLE_ARENA_ABSENCE_CHECK.h"
#include "GameClient/TS_SC_BATTLE_ARENA_BATTLE_INFO.h"
#include "GameClient/TS_SC_BATTLE_ARENA_BATTLE_SCORE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_BATTLE_STATUS.h"
#include "GameClient/TS_SC_BATTLE_ARENA_DISCONNECT_BATTLE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_EXERCISE_READY_STATUS.h"
#include "GameClient/TS_SC_BATTLE_ARENA_JOIN_BATTLE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_JOIN_QUEUE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_LEAVE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_PENALTY_INFO.h"
#include "GameClient/TS_SC_BATTLE_ARENA_RECONNECT_BATTLE.h"
#include "GameClient/TS_SC_BATTLE_ARENA_RESULT.h"
#include "GameClient/TS_SC_BATTLE_ARENA_UPDATE_WAIT_USER_COUNT.h"
#include "GameClient/TS_SC_BELT_SLOT_INFO.h"
#include "GameClient/TS_SC_BONUS_EXP_JP.h"
#include "GameClient/TS_SC_BOOKMARK_TITLE.h"
#include "GameClient/TS_SC_BOOTH_CLOSED.h"
#include "GameClient/TS_SC_BOOTH_TRADE_INFO.h"
#include "GameClient/TS_SC_CANT_ATTACK.h"
#include "GameClient/TS_SC_CHANGE_LOCATION.h"
#include "GameClient/TS_SC_CHANGE_NAME.h"
#include "GameClient/TS_SC_CHANGE_TITLE_CONDITION.h"
#include "GameClient/TS_SC_CHARACTER_LIST.h"
#include "GameClient/TS_SC_CHAT.h"
#include "GameClient/TS_SC_CHAT_LOCAL.h"
#include "GameClient/TS_SC_CHAT_RESULT.h"
#include "GameClient/TS_SC_COMMERCIAL_STORAGE_INFO.h"
#include "GameClient/TS_SC_COMMERCIAL_STORAGE_LIST.h"
#include "GameClient/TS_SC_COMPETE_ANSWER.h"
#include "GameClient/TS_SC_COMPETE_COUNTDOWN.h"
#include "GameClient/TS_SC_COMPETE_END.h"
#include "GameClient/TS_SC_COMPETE_REQUEST.h"
#include "GameClient/TS_SC_COMPETE_START.h"
#include "GameClient/TS_SC_DECOMPOSE_RESULT.h"
#include "GameClient/TS_SC_DESTROY_ITEM.h"
#include "GameClient/TS_SC_DETECT_RANGE_UPDATE.h"
#include "GameClient/TS_SC_DIALOG.h"
#include "GameClient/TS_SC_DISCONNECT_DESC.h"
#include "GameClient/TS_SC_DROP_RESULT.h"
#include "GameClient/TS_SC_EMOTION.h"
#include "GameClient/TS_SC_ENERGY.h"
#include "GameClient/TS_SC_ENTER.h"
#include "GameClient/TS_SC_ERASE_ITEM.h"
#include "GameClient/TS_SC_EXP_UPDATE.h"
#include "GameClient/TS_SC_FARM_INFO.h"
#include "GameClient/TS_SC_GAME_GUARD_AUTH_QUERY.h"
#include "GameClient/TS_SC_GAME_TIME.h"
#include "GameClient/TS_SC_GENERAL_MESSAGE_BOX.h"
#include "GameClient/TS_SC_GET_BOOTHS_NAME.h"
#include "GameClient/TS_SC_GET_CHAOS.h"
#include "GameClient/TS_SC_GOLD_UPDATE.h"
#include "GameClient/TS_SC_GROUP_FINDER_DETAIL.h"
#include "GameClient/TS_SC_GROUP_FINDER_LIST.h"
#include "GameClient/TS_SC_HAIR_INFO.h"
#include "GameClient/TS_SC_HIDE_EQUIP_INFO.h"
#include "GameClient/TS_SC_HPMP.h"
#include "GameClient/TS_SC_HUNTAHOLIC_BEGIN_COUNTDOWN.h"
#include "GameClient/TS_SC_HUNTAHOLIC_BEGIN_HUNTING.h"
#include "GameClient/TS_SC_HUNTAHOLIC_HUNTING_SCORE.h"
#include "GameClient/TS_SC_HUNTAHOLIC_INSTANCE_INFO.h"
#include "GameClient/TS_SC_HUNTAHOLIC_INSTANCE_LIST.h"
#include "GameClient/TS_SC_HUNTAHOLIC_MAX_POINT_ACHIEVED.h"
#include "GameClient/TS_SC_HUNTAHOLIC_UPDATE_SCORE.h"
#include "GameClient/TS_SC_INSTANCE_GAME_SCORE_REQUEST.h"
#include "GameClient/TS_SC_INVENTORY.h"
#include "GameClient/TS_SC_ITEM_COOL_TIME.h"
#include "GameClient/TS_SC_ITEM_DROP_INFO.h"
#include "GameClient/TS_SC_ITEM_KEEPING_LIST.h"
#include "GameClient/TS_SC_ITEM_WEAR_INFO.h"
#include "GameClient/TS_SC_LEAVE.h"
#include "GameClient/TS_SC_LEVEL_UPDATE.h"
#include "GameClient/TS_SC_LOGIN_RESULT.h"
#include "GameClient/TS_SC_MARKET.h"
#include "GameClient/TS_SC_MIX_RESULT.h"
#include "GameClient/TS_SC_MOUNT_SUMMON.h"
#include "GameClient/TS_SC_MOVE_ACK.h"
#include "GameClient/TS_SC_MOVE.h"
#include "GameClient/TS_SC_NPC_TRADE_INFO.h"
#include "GameClient/TS_SC_OPEN_GUILD_WINDOW.h"
#include "GameClient/TS_SC_OPEN_ITEM_SHOP.h"
#include "GameClient/TS_SC_OPEN_STORAGE.h"
#include "GameClient/TS_SC_OPEN_TITLE.h"
#include "GameClient/TS_SC_OPEN_URL.h"
#include "GameClient/TS_SC_PROPERTY.h"
#include "GameClient/TS_SC_QUEST_INFOMATION.h"
#include "GameClient/TS_SC_QUEST_LIST.h"
#include "GameClient/TS_SC_QUEST_STATUS.h"
#include "GameClient/TS_SC_RANKING_TOP_RECORD.h"
#include "GameClient/TS_SC_REGEN_HPMP.h"
#include "GameClient/TS_SC_REGEN_INFO.h"
#include "GameClient/TS_SC_REGION_ACK.h"
#include "GameClient/TS_SC_REMAIN_TITLE_TIME.h"
#include "GameClient/TS_SC_REMOVE_PET_INFO.h"
#include "GameClient/TS_SC_REMOVE_SUMMON_INFO.h"
#include "GameClient/TS_SC_REQUEST_SECURITY_NO.h"
#include "GameClient/TS_SC_RESULT_FOSTER.h"
#include "GameClient/TS_SC_RESULT.h"
#include "GameClient/TS_SC_RESULT_NURSE.h"
#include "GameClient/TS_SC_RESULT_RETRIEVE.h"
#include "GameClient/TS_SC_SET_MAIN_TITLE.h"
#include "GameClient/TS_SC_SET_SUB_TITLE.h"
#include "GameClient/TS_SC_SET_TIME.h"
#include "GameClient/TS_SC_SHOW_CREATE_ALLIANCE.h"
#include "GameClient/TS_SC_SHOW_CREATE_GUILD.h"
#include "GameClient/TS_SC_SHOW_SET_PET_NAME.h"
#include "GameClient/TS_SC_SHOW_SOULSTONE_CRAFT_WINDOW.h"
#include "GameClient/TS_SC_SHOW_SOULSTONE_REPAIR_WINDOW.h"
#include "GameClient/TS_SC_SHOW_SUMMON_NAME_CHANGE.h"
#include "GameClient/TS_SC_SHOW_WINDOW.h"
#include "GameClient/TS_SC_SKILLCARD_INFO.h"
#include "GameClient/TS_SC_SKILL.h"
#include "GameClient/TS_SC_SKILL_LEVEL_LIST.h"
#include "GameClient/TS_SC_SKILL_LIST.h"
#include "GameClient/TS_SC_SP.h"
#include "GameClient/TS_SC_STATE.h"
#include "GameClient/TS_SC_STATE_RESULT.h"
#include "GameClient/TS_SC_STAT_INFO.h"
#include "GameClient/TS_SC_STATUS_CHANGE.h"
#include "GameClient/TS_SC_SUMMON_EVOLUTION.h"
#include "GameClient/TS_SC_TAKE_ITEM_RESULT.h"
#include "GameClient/TS_SC_TAMING_INFO.h"
#include "GameClient/TS_SC_TARGET.h"
#include "GameClient/TS_SC_TITLE_CONDITION_LIST.h"
#include "GameClient/TS_SC_TITLE_LIST.h"
#include "GameClient/TS_SC_UNMOUNT_SUMMON.h"
#include "GameClient/TS_SC_UNSUMMON.h"
#include "GameClient/TS_SC_UNSUMMON_NOTICE.h"
#include "GameClient/TS_SC_UNSUMMON_PET.h"
#include "GameClient/TS_SC_UPDATE_ITEM_COUNT.h"
#include "GameClient/TS_SC_URL_LIST.h"
#include "GameClient/TS_SC_USE_ITEM_RESULT.h"
#include "GameClient/TS_SC_WARP.h"
#include "GameClient/TS_SC_WATCH_BOOTH.h"
#include "GameClient/TS_SC_WEAR_INFO.h"
#include "GameClient/TS_SC_WEATHER_INFO.h"
#include "GameClient/TS_SC_XTRAP_CHECK.h"
#include "GameClient/TS_TIMESYNC.h"
#include "GameClient/TS_TRADE.h"

#define PACKET_TO_JSON(type_) \
	case type_::packetID: \
	(void)(sizeof(&type_::getSize)); \
	packet->process(this, &PacketFilter::showPacketJson<type_>, version); \
	break;

#define PACKET_TO_JSON_2(type_) \
	case_packet_is(type_) \
	packet->process(this, &PacketFilter::showPacketJson<type_>, version); \
	break;

#define PACKET_TO_JSON_CLISERV(isServerMsg, type_serv, type_cli) \
	case type_serv::packetID: \
	static_assert(type_serv::packetID == type_cli::packetID, "expected same packet ID"); \
	(void)(sizeof(&type_serv::getSize)); \
	(void)(sizeof(&type_cli::getSize)); \
	if(isServerMsg) \
	    packet->process(this, &PacketFilter::showPacketJson<type_serv>, version); \
	else \
	    packet->process(this, &PacketFilter::showPacketJson<type_cli>, version); \
	break;

PacketFilter::PacketFilter(PacketFilter *oldFilter)
{
	if(oldFilter) {
		data = oldFilter->data;
		oldFilter->data = nullptr;
	} else {
		data = new Data;
	}
}

PacketFilter::~PacketFilter()
{
	if(data)
		delete data;
}

void PacketFilter::sendChatMessage(IFilterEndpoint* client, const char* msg, const char* sender, TS_CHAT_TYPE type) {
	TS_SC_CHAT chatRqst;

	chatRqst.message = msg;
	if(chatRqst.message.size() > 32766)
		chatRqst.message.resize(32766);
	chatRqst.message.append(1, '\0');

	chatRqst.szSender = sender;
	chatRqst.type = type;

	client->sendPacket(chatRqst);
}

bool PacketFilter::onServerPacket(IFilterEndpoint* client, IFilterEndpoint* server, const TS_MESSAGE* packet, ServerType serverType) {
	clientp = client;

	if(serverType == ST_Game)
		printGamePacketJson(packet, server->getPacketVersion(), true);
	else
		printAuthPacketJson(packet, server->getPacketVersion(), true);

	//if(serverType != ST_Game)
		return true;

	switch(packet->id) {
//		case TS_SC_STATE_RESULT::packetID: {
//			TS_SC_STATE_RESULT stateResult;
//			bool ok = packet->process(stateResult, EPIC_LATEST);
//			char buffer[1024];

//			sprintf(buffer, "DOT(caster 0x%08X, target 0x%08X, id %d Lv%d, result %d, value %d, targetval %d, total %d, final %d)",
//					stateResult.caster_handle,
//					stateResult.target_handle,
//					stateResult.code,
//					stateResult.level,
//					stateResult.result_type,
//					stateResult.value,
//					stateResult.target_value,
//					stateResult.total_amount,
//					stateResult.final);
//			sendChatMessage(client, buffer);

//			break;
//		}

		case TS_SC_CHAT::packetID: {
			TS_SC_CHAT chatPacket;
			if(packet->process(chatPacket, server->getPacketVersion())) {
				onChatMessage(&chatPacket);
				return false;
			}
			break;
		}

		case_packet_is(TS_SC_ENTER) {
			break;
		}

		case TS_SC_WEAR_INFO::packetID: {
			break;
		}
	}

	return true;
}

bool PacketFilter::onClientPacket(IFilterEndpoint*, IFilterEndpoint* server, const TS_MESSAGE* packet, ServerType serverType) {
	if(serverType == ST_Game)
		printGamePacketJson(packet, server->getPacketVersion(), false);
	else
		printAuthPacketJson(packet, server->getPacketVersion(), false);

	return true;
}

void PacketFilter::printAuthPacketJson(const TS_MESSAGE* packet, int version, bool isServerMsg) {
	switch(packet->id) {
		PACKET_TO_JSON(TS_AC_ACCOUNT_NAME);
		PACKET_TO_JSON(TS_AC_AES_KEY_IV);
		PACKET_TO_JSON(TS_AC_RESULT);
		PACKET_TO_JSON(TS_AC_RESULT_WITH_STRING);
		PACKET_TO_JSON(TS_AC_SELECT_SERVER);
		PACKET_TO_JSON(TS_AC_SERVER_LIST);
		PACKET_TO_JSON(TS_AC_UPDATE_PENDING_TIME);
		PACKET_TO_JSON(TS_CA_ACCOUNT);
		PACKET_TO_JSON(TS_CA_DISTRIBUTION_INFO);
		PACKET_TO_JSON(TS_CA_IMBC_ACCOUNT);
		PACKET_TO_JSON(TS_CA_OTP_ACCOUNT);
		PACKET_TO_JSON(TS_CA_RSA_PUBLIC_KEY);
		PACKET_TO_JSON(TS_CA_SELECT_SERVER);
		PACKET_TO_JSON(TS_CA_SERVER_LIST);
		PACKET_TO_JSON(TS_CA_VERSION);

		PACKET_TO_JSON(TS_SC_RESULT);

		case 9999: break;

		default:
			Object::logStatic(Object::LL_Warning, "rzfilter_module", "packet id %d unknown\n", packet->id);
			break;
	}
}

void PacketFilter::printGamePacketJson(const TS_MESSAGE* packet, int version, bool isServerMsg) {
	switch(packet->id) {
		PACKET_TO_JSON(TS_CS_ACCOUNT_WITH_AUTH);
		PACKET_TO_JSON(TS_CS_ANTI_HACK);
		PACKET_TO_JSON(TS_CS_ARRANGE_ITEM);
		PACKET_TO_JSON(TS_CS_ATTACK_REQUEST);
		PACKET_TO_JSON(TS_CS_AUCTION_BIDDED_LIST);
		PACKET_TO_JSON(TS_CS_AUCTION_BID);
		PACKET_TO_JSON(TS_CS_AUCTION_CANCEL);
		PACKET_TO_JSON(TS_CS_AUCTION_INSTANT_PURCHASE);
		PACKET_TO_JSON(TS_CS_AUCTION_REGISTER);
		PACKET_TO_JSON(TS_CS_AUCTION_SEARCH);
		PACKET_TO_JSON(TS_CS_AUCTION_SELLING_LIST);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_ABSENCE_CHECK_ANSWER);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_ABSENCE_CHECK_REQUEST);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_ENTER_WHILE_COUNTDOWN);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_EXERCISE_READY);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_EXERCISE_START);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_JOIN_QUEUE);
		PACKET_TO_JSON(TS_CS_BATTLE_ARENA_LEAVE);
		PACKET_TO_JSON(TS_CS_BIND_SKILLCARD);
		PACKET_TO_JSON(TS_CS_BOOKMARK_TITLE);
		PACKET_TO_JSON(TS_CS_BUY_FROM_BOOTH);
		PACKET_TO_JSON(TS_CS_BUY_ITEM);
		PACKET_TO_JSON(TS_CS_CANCEL_ACTION);
		PACKET_TO_JSON(TS_CS_CHANGE_ALIAS);
		PACKET_TO_JSON(TS_CS_CHANGE_ITEM_POSITION);
		PACKET_TO_JSON(TS_CS_CHANGE_LOCATION);
		PACKET_TO_JSON(TS_CS_CHANGE_SUMMON_NAME);
		PACKET_TO_JSON_2(TS_CS_CHARACTER_LIST);
		PACKET_TO_JSON(TS_CS_CHAT_REQUEST);
		PACKET_TO_JSON(TS_CS_CHECK_BOOTH_STARTABLE);
		PACKET_TO_JSON(TS_CS_CHECK_CHARACTER_NAME);
		PACKET_TO_JSON(TS_CS_CHECK_ILLEGAL_USER);
		PACKET_TO_JSON(TS_CS_COMPETE_ANSWER);
		PACKET_TO_JSON(TS_CS_COMPETE_REQUEST);
		PACKET_TO_JSON(TS_CS_CONTACT);
		PACKET_TO_JSON(TS_CS_CREATE_CHARACTER);
		PACKET_TO_JSON(TS_CS_DECOMPOSE);
		PACKET_TO_JSON(TS_CS_DELETE_CHARACTER);
		PACKET_TO_JSON(TS_CS_DIALOG);
		PACKET_TO_JSON(TS_CS_DONATE_ITEM);
		PACKET_TO_JSON(TS_CS_DROP_ITEM);
		PACKET_TO_JSON(TS_CS_DROP_QUEST);
		PACKET_TO_JSON(TS_CS_EMOTION);
		PACKET_TO_JSON(TS_CS_END_QUEST);
		PACKET_TO_JSON(TS_CS_ENTER_EVENT_AREA);
		PACKET_TO_JSON(TS_CS_ERASE_ITEM);
		PACKET_TO_JSON(TS_CS_FOSTER_CREATURE);
		PACKET_TO_JSON(TS_CS_GAME_GUARD_AUTH_ANSWER);
		PACKET_TO_JSON(TS_CS_GAME_TIME);
		PACKET_TO_JSON(TS_CS_GET_BOOTHS_NAME);
		PACKET_TO_JSON(TS_CS_GET_REGION_INFO);
		PACKET_TO_JSON(TS_CS_GET_SUMMON_SETUP_INFO);
		PACKET_TO_JSON(TS_CS_GET_WEATHER_INFO);
		PACKET_TO_JSON(TS_CS_GROUP_FINDER_LIST);
		PACKET_TO_JSON(TS_CS_HIDE_EQUIP_INFO);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_BEGIN_HUNTING);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_CREATE_INSTANCE);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_INSTANCE_LIST);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_JOIN_INSTANCE);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_LEAVE_INSTANCE);
		PACKET_TO_JSON(TS_CS_HUNTAHOLIC_LEAVE_LOBBY);
		PACKET_TO_JSON(TS_CS_INSTANCE_GAME_ENTER);
		PACKET_TO_JSON(TS_CS_INSTANCE_GAME_EXIT);
		PACKET_TO_JSON(TS_CS_INSTANCE_GAME_SCORE_REQUEST);
		PACKET_TO_JSON(TS_CS_ITEM_KEEPING_LIST);
		PACKET_TO_JSON(TS_CS_ITEM_KEEPING_TAKE);
		PACKET_TO_JSON(TS_CS_JOB_LEVEL_UP);
		PACKET_TO_JSON(TS_CS_LEARN_SKILL);
		PACKET_TO_JSON(TS_CS_LEAVE_EVENT_AREA);
		PACKET_TO_JSON_2(TS_CS_LOGIN);
		PACKET_TO_JSON(TS_CS_LOGOUT);
		PACKET_TO_JSON(TS_CS_MIX);
		PACKET_TO_JSON(TS_CS_MONSTER_RECOGNIZE);
		PACKET_TO_JSON_2(TS_CS_MOVE_REQUEST);
		PACKET_TO_JSON(TS_CS_NURSE_CREATURE);
		PACKET_TO_JSON(TS_CS_OPEN_ITEM_SHOP);
		PACKET_TO_JSON(TS_CS_PUTOFF_CARD);
		PACKET_TO_JSON(TS_CS_PUTOFF_ITEM);
		PACKET_TO_JSON(TS_CS_PUTON_CARD);
		PACKET_TO_JSON(TS_CS_PUTON_ITEM);
		PACKET_TO_JSON(TS_CS_PUTON_ITEM_SET);
		PACKET_TO_JSON(TS_CS_QUERY);
		PACKET_TO_JSON(TS_CS_QUEST_INFO);
		PACKET_TO_JSON(TS_CS_RANKING_TOP_RECORD);
		PACKET_TO_JSON_2(TS_CS_REGION_UPDATE);
		PACKET_TO_JSON(TS_CS_REPAIR_SOULSTONE);
		PACKET_TO_JSON(TS_CS_REPORT);
		PACKET_TO_JSON(TS_CS_REQUEST_FARM_INFO);
		PACKET_TO_JSON(TS_CS_REQUEST_FARM_MARKET);
		PACKET_TO_JSON(TS_CS_REQUEST_LOGOUT);
		PACKET_TO_JSON(TS_CS_REQUEST_REMOVE_STATE);
		PACKET_TO_JSON(TS_CS_REQUEST_RETURN_LOBBY);
		PACKET_TO_JSON(TS_CS_RESURRECTION);
		PACKET_TO_JSON(TS_CS_RETRIEVE_CREATURE);
		PACKET_TO_JSON(TS_CS_RETURN_LOBBY);
		PACKET_TO_JSON(TS_CS_SECURITY_NO);
		PACKET_TO_JSON(TS_CS_SELL_ITEM);
		PACKET_TO_JSON(TS_CS_SELL_TO_BOOTH);
		PACKET_TO_JSON(TS_CS_SET_MAIN_TITLE);
		PACKET_TO_JSON(TS_CS_SET_PET_NAME);
		PACKET_TO_JSON(TS_CS_SET_PROPERTY);
		PACKET_TO_JSON(TS_CS_SET_SUB_TITLE);
		PACKET_TO_JSON(TS_CS_SKILL);
		PACKET_TO_JSON(TS_CS_SOULSTONE_CRAFT);
		PACKET_TO_JSON(TS_CS_START_BOOTH);
		PACKET_TO_JSON(TS_CS_STOP_BOOTH);
		PACKET_TO_JSON(TS_CS_STOP_WATCH_BOOTH);
		PACKET_TO_JSON(TS_CS_STORAGE);
		PACKET_TO_JSON(TS_CS_SUMMON_CARD_SKILL_LIST);
		PACKET_TO_JSON(TS_CS_SUMMON);
		PACKET_TO_JSON(TS_CS_SWAP_EQUIP);
		PACKET_TO_JSON(TS_CS_TAKE_ITEM);
		PACKET_TO_JSON(TS_CS_TAKEOUT_COMMERCIAL_ITEM);
		PACKET_TO_JSON(TS_CS_TARGETING);
		PACKET_TO_JSON(TS_CS_TRANSMIT_ETHEREAL_DURABILITY);
		PACKET_TO_JSON(TS_CS_TRANSMIT_ETHEREAL_DURABILITY_TO_EQUIPMENT);
		PACKET_TO_JSON(TS_CS_TURN_OFF_PK_MODE);
		PACKET_TO_JSON(TS_CS_TURN_ON_PK_MODE);
		PACKET_TO_JSON(TS_CS_UNBIND_SKILLCARD);
		PACKET_TO_JSON(TS_CS_UPDATE);
		PACKET_TO_JSON(TS_CS_USE_ITEM);
		PACKET_TO_JSON_2(TS_CS_VERSION);
		PACKET_TO_JSON(TS_CS_WATCH_BOOTH);
		PACKET_TO_JSON(TS_CS_XTRAP_CHECK);
		PACKET_TO_JSON(TS_EQUIP_SUMMON);
		PACKET_TO_JSON(TS_SC_ACHIEVE_TITLE);
		PACKET_TO_JSON(TS_SC_ADDED_SKILL_LIST);
		PACKET_TO_JSON(TS_SC_ADD_PET_INFO);
		PACKET_TO_JSON(TS_SC_ADD_SUMMON_INFO);
		PACKET_TO_JSON(TS_SC_ANTI_HACK);
		PACKET_TO_JSON(TS_SC_ATTACK_EVENT);
		PACKET_TO_JSON(TS_SC_AUCTION_BIDDED_LIST);
		PACKET_TO_JSON(TS_SC_AUCTION_SEARCH);
		PACKET_TO_JSON(TS_SC_AUCTION_SELLING_LIST);
		PACKET_TO_JSON(TS_SC_AURA);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_ABSENCE_CHECK);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_BATTLE_INFO);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_BATTLE_SCORE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_BATTLE_STATUS);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_DISCONNECT_BATTLE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_EXERCISE_READY_STATUS);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_JOIN_BATTLE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_JOIN_QUEUE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_LEAVE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_PENALTY_INFO);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_RECONNECT_BATTLE);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_RESULT);
		PACKET_TO_JSON(TS_SC_BATTLE_ARENA_UPDATE_WAIT_USER_COUNT);
		PACKET_TO_JSON(TS_SC_BELT_SLOT_INFO);
		PACKET_TO_JSON(TS_SC_BONUS_EXP_JP);
		PACKET_TO_JSON(TS_SC_BOOKMARK_TITLE);
		PACKET_TO_JSON(TS_SC_BOOTH_CLOSED);
		PACKET_TO_JSON(TS_SC_BOOTH_TRADE_INFO);
		PACKET_TO_JSON(TS_SC_CANT_ATTACK);
		PACKET_TO_JSON(TS_SC_CHANGE_LOCATION);
		PACKET_TO_JSON(TS_SC_CHANGE_NAME);
		PACKET_TO_JSON(TS_SC_CHANGE_TITLE_CONDITION);
		PACKET_TO_JSON(TS_SC_CHARACTER_LIST);
		PACKET_TO_JSON(TS_SC_CHAT);
		PACKET_TO_JSON(TS_SC_CHAT_LOCAL);
		PACKET_TO_JSON(TS_SC_CHAT_RESULT);
		PACKET_TO_JSON(TS_SC_COMMERCIAL_STORAGE_INFO);
		PACKET_TO_JSON(TS_SC_COMMERCIAL_STORAGE_LIST);
		PACKET_TO_JSON(TS_SC_COMPETE_ANSWER);
		PACKET_TO_JSON(TS_SC_COMPETE_COUNTDOWN);
		PACKET_TO_JSON(TS_SC_COMPETE_END);
		PACKET_TO_JSON(TS_SC_COMPETE_REQUEST);
		PACKET_TO_JSON(TS_SC_COMPETE_START);
		PACKET_TO_JSON(TS_SC_DECOMPOSE_RESULT);
		PACKET_TO_JSON(TS_SC_DESTROY_ITEM);
		PACKET_TO_JSON(TS_SC_DETECT_RANGE_UPDATE);
		PACKET_TO_JSON(TS_SC_DIALOG);
		PACKET_TO_JSON(TS_SC_DISCONNECT_DESC);
		PACKET_TO_JSON(TS_SC_DROP_RESULT);
		PACKET_TO_JSON(TS_SC_EMOTION);
		PACKET_TO_JSON(TS_SC_ENERGY);
		PACKET_TO_JSON_2(TS_SC_ENTER);
		PACKET_TO_JSON(TS_SC_ERASE_ITEM);
		PACKET_TO_JSON(TS_SC_EXP_UPDATE);
		PACKET_TO_JSON(TS_SC_FARM_INFO);
		PACKET_TO_JSON(TS_SC_GAME_GUARD_AUTH_QUERY);
		PACKET_TO_JSON(TS_SC_GAME_TIME);
		PACKET_TO_JSON(TS_SC_GENERAL_MESSAGE_BOX);
		PACKET_TO_JSON(TS_SC_GET_BOOTHS_NAME);
		PACKET_TO_JSON(TS_SC_GET_CHAOS);
		PACKET_TO_JSON(TS_SC_GOLD_UPDATE);
		PACKET_TO_JSON(TS_SC_GROUP_FINDER_DETAIL);
		PACKET_TO_JSON(TS_SC_GROUP_FINDER_LIST);
		PACKET_TO_JSON(TS_SC_HAIR_INFO);
		PACKET_TO_JSON(TS_SC_HIDE_EQUIP_INFO);
		PACKET_TO_JSON(TS_SC_HPMP);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_BEGIN_COUNTDOWN);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_BEGIN_HUNTING);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_HUNTING_SCORE);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_INSTANCE_INFO);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_INSTANCE_LIST);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_MAX_POINT_ACHIEVED);
		PACKET_TO_JSON(TS_SC_HUNTAHOLIC_UPDATE_SCORE);
		PACKET_TO_JSON(TS_SC_INSTANCE_GAME_SCORE_REQUEST);
		PACKET_TO_JSON(TS_SC_INVENTORY);
		PACKET_TO_JSON(TS_SC_ITEM_COOL_TIME);
		PACKET_TO_JSON(TS_SC_ITEM_DROP_INFO);
		PACKET_TO_JSON(TS_SC_ITEM_KEEPING_LIST);
		PACKET_TO_JSON(TS_SC_ITEM_WEAR_INFO);
		PACKET_TO_JSON(TS_SC_LEAVE);
		PACKET_TO_JSON(TS_SC_LEVEL_UPDATE);
		PACKET_TO_JSON_2(TS_SC_LOGIN_RESULT);
		PACKET_TO_JSON(TS_SC_MARKET);
		PACKET_TO_JSON(TS_SC_MIX_RESULT);
		PACKET_TO_JSON(TS_SC_MOUNT_SUMMON);
		PACKET_TO_JSON(TS_SC_MOVE_ACK);
		PACKET_TO_JSON(TS_SC_MOVE);
		PACKET_TO_JSON(TS_SC_NPC_TRADE_INFO);
		PACKET_TO_JSON(TS_SC_OPEN_GUILD_WINDOW);
		PACKET_TO_JSON(TS_SC_OPEN_ITEM_SHOP);
		PACKET_TO_JSON(TS_SC_OPEN_STORAGE);
		PACKET_TO_JSON(TS_SC_OPEN_TITLE);
		PACKET_TO_JSON(TS_SC_OPEN_URL);
		PACKET_TO_JSON(TS_SC_PROPERTY);
		PACKET_TO_JSON(TS_SC_QUEST_INFOMATION);
		PACKET_TO_JSON(TS_SC_QUEST_LIST);
		PACKET_TO_JSON(TS_SC_QUEST_STATUS);
		PACKET_TO_JSON(TS_SC_RANKING_TOP_RECORD);
		PACKET_TO_JSON(TS_SC_REGEN_HPMP);
		PACKET_TO_JSON(TS_SC_REGEN_INFO);
		PACKET_TO_JSON(TS_SC_REGION_ACK);
		PACKET_TO_JSON(TS_SC_REMAIN_TITLE_TIME);
		PACKET_TO_JSON(TS_SC_REMOVE_PET_INFO);
		PACKET_TO_JSON(TS_SC_REMOVE_SUMMON_INFO);
		PACKET_TO_JSON(TS_SC_REQUEST_SECURITY_NO);
		PACKET_TO_JSON(TS_SC_RESULT_FOSTER);
		PACKET_TO_JSON(TS_SC_RESULT);
		PACKET_TO_JSON(TS_SC_RESULT_NURSE);
		PACKET_TO_JSON(TS_SC_RESULT_RETRIEVE);
		PACKET_TO_JSON(TS_SC_SET_MAIN_TITLE);
		PACKET_TO_JSON(TS_SC_SET_SUB_TITLE);
		PACKET_TO_JSON(TS_SC_SET_TIME);
		PACKET_TO_JSON(TS_SC_SHOW_CREATE_ALLIANCE);
		PACKET_TO_JSON(TS_SC_SHOW_CREATE_GUILD);
		PACKET_TO_JSON(TS_SC_SHOW_SET_PET_NAME);
		PACKET_TO_JSON(TS_SC_SHOW_SOULSTONE_REPAIR_WINDOW);
		PACKET_TO_JSON(TS_SC_SHOW_SUMMON_NAME_CHANGE);
		PACKET_TO_JSON(TS_SC_SHOW_WINDOW);
		PACKET_TO_JSON(TS_SC_SKILLCARD_INFO);
		PACKET_TO_JSON(TS_SC_SKILL);
		PACKET_TO_JSON(TS_SC_SKILL_LEVEL_LIST);
		PACKET_TO_JSON(TS_SC_SKILL_LIST);
		PACKET_TO_JSON(TS_SC_SP);
		PACKET_TO_JSON(TS_SC_STATE);
		PACKET_TO_JSON(TS_SC_STATE_RESULT);
		PACKET_TO_JSON(TS_SC_STAT_INFO);
		PACKET_TO_JSON(TS_SC_STATUS_CHANGE);
		PACKET_TO_JSON(TS_SC_SUMMON_EVOLUTION);
		PACKET_TO_JSON(TS_SC_TAKE_ITEM_RESULT);
		PACKET_TO_JSON(TS_SC_TAMING_INFO);
		PACKET_TO_JSON(TS_SC_TARGET);
		PACKET_TO_JSON(TS_SC_TITLE_CONDITION_LIST);
		PACKET_TO_JSON(TS_SC_TITLE_LIST);
		PACKET_TO_JSON(TS_SC_UNMOUNT_SUMMON);
		PACKET_TO_JSON(TS_SC_UNSUMMON);
		PACKET_TO_JSON(TS_SC_UNSUMMON_NOTICE);
		PACKET_TO_JSON(TS_SC_UNSUMMON_PET);
		PACKET_TO_JSON(TS_SC_UPDATE_ITEM_COUNT);
		PACKET_TO_JSON(TS_SC_URL_LIST);
		PACKET_TO_JSON(TS_SC_USE_ITEM_RESULT);
		PACKET_TO_JSON(TS_SC_WARP);
		PACKET_TO_JSON(TS_SC_WATCH_BOOTH);
		PACKET_TO_JSON(TS_SC_WEAR_INFO);
		PACKET_TO_JSON(TS_SC_WEATHER_INFO);
		PACKET_TO_JSON(TS_SC_XTRAP_CHECK);
		PACKET_TO_JSON(TS_TIMESYNC);
		PACKET_TO_JSON(TS_TRADE);

		PACKET_TO_JSON_CLISERV(isServerMsg, TS_SC_SHOW_SOULSTONE_CRAFT_WINDOW, TS_CS_DONATE_REWARD);

		case 9999: break;

		default:
			Object::logStatic(Object::LL_Warning, "rzfilter_module", "packet id %d unknown\n", packet->id);
			break;
	}
}

void PacketFilter::onChatMessage(const TS_SC_CHAT* packet)
{
	//9:38:23
	//2017-01-29 17:26:22
	struct tm currentTime;
	char newMessage[32767];
	Utils::getGmTime(time(nullptr), &currentTime);

	if(packet->szSender[0] == '@') {
		if(packet->szSender == "@PARTY" || packet->szSender == "@GUILD")
			return;
		snprintf(newMessage, sizeof(newMessage), "<b>%02d:%02d:%02d</b>: Next message: %s",
		         currentTime.tm_hour,
		         currentTime.tm_min,
		         currentTime.tm_sec,
		         packet->szSender.c_str());
		newMessage[sizeof(newMessage)-1] = '\0';
		sendChatMessage(clientp, newMessage);
		clientp->sendPacket(*packet);
		return;
	}

	snprintf(newMessage, sizeof(newMessage), "<b>%02d:%02d:%02d</b>: %s",
	         currentTime.tm_hour,
	         currentTime.tm_min,
	         currentTime.tm_sec,
	         packet->message.c_str());
	newMessage[sizeof(newMessage)-1] = '\0';

	sendChatMessage(clientp, newMessage, packet->szSender.c_str(), packet->type);
}

IFilter *createFilter(IFilter *oldFilter)
{
	Object::logStatic(Object::LL_Info, "rzfilter_module", "Loaded filter from data: %p\n", oldFilter);
	return new PacketFilter((PacketFilter*)oldFilter);
}

void destroyFilter(IFilter *filter)
{
	delete filter;
}

template<class Packet>
void PacketFilter::showPacketJson(const Packet* packet)
{
	JSONWriter jsonWriter(EPIC_LATEST, false);
	packet->serialize(&jsonWriter);
	jsonWriter.finalize();
	std::string jsonData = jsonWriter.toString();

	Object::logStatic(Object::LL_Info, "rzfilter_module", "%s packet:\n%s\n", Packet::getName(), jsonData.c_str());
}