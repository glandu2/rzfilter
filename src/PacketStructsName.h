struct PacketNameInfo {
	unsigned int id;
	const char* name;
};

static const PacketNameInfo gamePacketNames[] = {
	{0, "TS_SC_RESULT"},
	{1, "TS_CS_LOGIN"},
	{2, "TS_TIMESYNC"},
	{3, "TS_SC_ENTER"},
	{4, "TS_SC_LOGIN_RESULT"},
	{5, "TS_CS_MOVE_REQUEST"},
	{6, "TS_SC_MOVE_ACK"},
	{7, "TS_CS_REGION_UPDATE"},
	{8, "TS_SC_MOVE"},
	{9, "TS_SC_LEAVE"},
	{10, "TS_SC_SET_TIME"},
	{11, "TS_SC_REGION_ACK"},
	{12, "TS_SC_WARP"},
	{13, "TS_CS_QUERY"},
	{15, "TS_CS_ENTER_EVENT_AREA"},
	{16, "TS_CS_LEAVE_EVENT_AREA"},
	{20, "TS_CS_CHAT_REQUEST"},
	{21, "TS_SC_CHAT_LOCAL"},
	{22, "TS_SC_CHAT"},
	{23, "TS_CS_RETURN_LOBBY"},
	{24, "TS_SC_CHAT_RESULT"},
	{25, "TS_CS_REQUEST_RETURN_LOBBY"},
	{26, "TS_CS_REQUEST_LOGOUT"},
	{27, "TS_CS_LOGOUT"},
	{28, "TS_SC_DISCONNECT_DESC"},
	{30, "TS_SC_CHANGE_NAME"},
	{31, "TS_CS_CHANGE_ALIAS"},
	{51, "TS_CS_VERSION"},
	{53, "TS_SC_ANTI_HACK"},
	{54, "TS_CS_ANTI_HACK"},
	{55, "TS_SC_GAME_GUARD_AUTH_QUERY"},
	{56, "TS_CS_GAME_GUARD_AUTH_ANSWER"},
	{57, "TS_CS_CHECK_ILLEGAL_USER"},
	{58, "TS_SC_XTRAP_CHECK"},
	{59, "TS_CS_XTRAP_CHECK"},
	{61, "TS_CS_LOGIN_2"},
	{62, "TS_CS_LOGIN_3"},
	{64, "TS_SC_LOGIN_RESULT_2"},
	{65, "TS_CS_MOVE_REQUEST_2"},
	{67, "TS_CS_REGION_UPDATE_2"},
	{100, "TS_CS_ATTACK_REQUEST"},
	{101, "TS_SC_ATTACK_EVENT"},
	{102, "TS_SC_CANT_ATTACK"},
	{103, "TS_SC_DOUBLE_WEAPON_ATTACK_EVENT"},
	{150, "TS_CS_CANCEL_ACTION"},
	{200, "TS_CS_PUTON_ITEM"},
	{201, "TS_CS_PUTOFF_ITEM"},
	{202, "TS_SC_WEAR_INFO"},
	{203, "TS_CS_DROP_ITEM"},
	{204, "TS_CS_TAKE_ITEM"},
	{205, "TS_SC_DROP_RESULT"},
	{207, "TS_SC_INVENTORY"},
	{208, "TS_CS_ERASE_ITEM"},
	{210, "TS_SC_TAKE_ITEM_RESULT"},
	{211, "TS_SC_OPEN_STORAGE"},
	{212, "TS_CS_STORAGE"},
	{213, "TS_SC_GET_CHAOS"},
	{214, "TS_CS_PUTON_CARD"},
	{215, "TS_CS_PUTOFF_CARD"},
	{216, "TS_SC_BELT_SLOT_INFO"},
	{217, "TS_SC_ITEM_COOL_TIME"},
	{218, "TS_CS_CHANGE_ITEM_POSITION"},
	{219, "TS_CS_ARRANGE_ITEM"},
	{221, "TS_CS_HIDE_EQUIP_INFO"},
	{222, "TS_SC_HIDE_EQUIP_INFO"},
	{223, "TS_CS_SWAP_EQUIP"},
	{224, "TS_SC_SKIN_INFO"},
	{240, "TS_SC_NPC_TRADE_INFO"},
	{250, "TS_SC_MARKET"},
	{251, "TS_CS_BUY_ITEM"},
	{252, "TS_CS_SELL_ITEM"},
	{253, "TS_CS_USE_ITEM"},
	{254, "TS_SC_DESTROY_ITEM"},
	{255, "TS_SC_UPDATE_ITEM_COUNT"},
	{256, "TS_CS_MIX"},
	{257, "TS_SC_MIX_RESULT"},
	{258, "TS_CS_DONATE_ITEM"},
	{259, "TS_CS_DONATE_REWARD"},
	{259, "TS_SC_SHOW_SOULSTONE_CRAFT_WINDOW"},
	{260, "TS_CS_SOULSTONE_CRAFT"},
	{261, "TS_SC_SHOW_SOULSTONE_REPAIR_WINDOW"},
	{262, "TS_CS_REPAIR_SOULSTONE"},
	{263, "TS_CS_TRANSMIT_ETHEREAL_DURABILITY"},
	{264, "TS_CS_TRANSMIT_ETHEREAL_DURABILITY_TO_EQUIPMENT"},
	{265, "TS_CS_DECOMPOSE"},
	{266, "TS_CS_DECOMPOSE_RESULT"},
	{280, "TS_TRADE"},
	{281, "TS_CS_PUTON_ITEM_SET"},
	{282, "TS_SC_ITEM_DROP_INFO"},
	{283, "TS_SC_USE_ITEM_RESULT"},
	{284, "TS_CS_BIND_SKILLCARD"},
	{285, "TS_CS_UNBIND_SKILLCARD"},
	{286, "TS_SC_SKILLCARD_INFO"},
	{287, "TS_SC_ITEM_WEAR_INFO"},
	{301, "TS_SC_ADD_SUMMON_INFO"},
	{302, "TS_SC_REMOVE_SUMMON_INFO"},
	{303, "TS_SC_EQUIP_SUMMON"},
	{304, "TS_CS_SUMMON"},
	{305, "TS_SC_UNSUMMON"},
	{306, "TS_SC_UNSUMMON_NOTICE"},
	{307, "TS_SC_SUMMON_EVOLUTION"},
	{310, "TS_SC_TAMING_INFO"},
	{320, "TS_SC_MOUNT_SUMMON"},
	{321, "TS_SC_UNMOUNT_SUMMON"},
	{322, "TS_SC_SHOW_SUMMON_NAME_CHANGE"},
	{323, "TS_CS_CHANGE_SUMMON_NAME"},
	{324, "TS_CS_GET_SUMMON_SETUP_INFO"},
	{350, "TS_SC_UNSUMMON_PET"},
	{351, "TS_SC_ADD_PET_INFO"},
	{352, "TS_SC_REMOVE_PET_INFO"},
	{353, "TS_SC_SHOW_SET_PET_NAME"},
	{354, "TS_CS_SET_PET_NAME"},
	{400, "TS_CS_SKILL"},
	{401, "TS_SC_SKILL"},
	{402, "TS_CS_LEARN_SKILL"},
	{403, "TS_SC_SKILL_LIST"},
	{404, "TS_SC_ADDED_SKILL_LIST"},
	{406, "TS_SC_STATE_RESULT"},
	{407, "TS_SC_AURA"},
	{408, "TS_CS_REQUEST_REMOVE_STATE"},
	{410, "TS_CS_JOB_LEVEL_UP"},
	{451, "TS_SC_SKILL_LEVEL_LIST"},
	{452, "TS_CS_SUMMON_CARD_SKILL_LIST"},
	{500, "TS_SC_STATUS_CHANGE"},
	{503, "TS_CS_UPDATE"},
	{504, "TS_SC_DEAD"},
	{505, "TS_SC_STATE"},
	{506, "TS_SC_RAGE"},
	{507, "TS_SC_PROPERTY"},
	{508, "TS_CS_SET_PROPERTY"},
	{509, "TS_SC_HPMP"},
	{510, "TS_SC_REGEN_INFO"},
	{511, "TS_CS_TARGETING"},
	{512, "TS_SC_TARGET"},
	{513, "TS_CS_RESURRECTION"},
	{514, "TS_SC_SP"},
	{515, "TS_SC_ENERGY"},
	{516, "TS_SC_REGEN_HPMP"},
	{517, "TS_CS_MONSTER_RECOGNIZE"},
	{550, "TS_CS_GET_REGION_INFO"},
	{600, "TS_SC_QUEST_LIST"},
	{601, "TS_SC_QUEST_STATUS"},
	{602, "TS_SC_QUEST_INFOMATION"},
	{603, "TS_CS_DROP_QUEST"},
	{604, "TS_CS_QUEST_INFO"},
	{605, "TS_CS_END_QUEST"},
	{625, "TS_SC_TITLE_LIST"},
	{626, "TS_SC_TITLE_CONDITION_LIST"},
	{627, "TS_SC_REMAIN_TITLE_TIME"},
	{628, "TS_CS_SET_MAIN_TITLE"},
	{629, "TS_SC_SET_MAIN_TITLE"},
	{630, "TS_CS_SET_SUB_TITLE"},
	{631, "TS_SC_SET_SUB_TITLE"},
	{632, "TS_CS_BOOKMARK_TITLE"},
	{633, "TS_SC_BOOKMARK_TITLE"},
	{634, "TS_SC_ACHIEVE_TITLE"},
	{635, "TS_SC_OPEN_TITLE"},
	{636, "TS_SC_CHANGE_TITLE_CONDITION"},
	{650, "TS_SC_SHOW_CREATE_GUILD"},
	{651, "TS_SC_OPEN_GUILD_WINDOW"},
	{660, "TS_SC_SHOW_CREATE_ALLIANCE"},
	{700, "TS_CS_START_BOOTH"},
	{701, "TS_CS_STOP_BOOTH"},
	{702, "TS_CS_WATCH_BOOTH"},
	{703, "TS_SC_WATCH_BOOTH"},
	{704, "TS_CS_STOP_WATCH_BOOTH"},
	{705, "TS_CS_BUY_FROM_BOOTH"},
	{706, "TS_CS_SELL_TO_BOOTH"},
	{707, "TS_CS_GET_BOOTHS_NAME"},
	{708, "TS_SC_GET_BOOTHS_NAME"},
	{709, "TS_SC_BOOTH_CLOSED"},
	{710, "TS_SC_BOOTH_TRADE_INFO"},
	{711, "TS_CS_CHECK_BOOTH_STARTABLE"},
	{800, "TS_CS_TURN_ON_PK_MODE"},
	{801, "TS_CS_TURN_OFF_PK_MODE"},
	{900, "TS_CS_CHANGE_LOCATION"},
	{901, "TS_SC_CHANGE_LOCATION"},
	{902, "TS_SC_WEATHER_INFO"},
	{903, "TS_CS_GET_WEATHER_INFO"},
	{1000, "TS_SC_STAT_INFO"},
	{1001, "TS_SC_GOLD_UPDATE"},
	{1002, "TS_SC_LEVEL_UPDATE"},
	{1002, "TS_SC_LEVEL_UPDATE"},
	{1003, "TS_SC_EXP_UPDATE"},
	{1005, "TS_SC_DETECT_RANGE_UPDATE"},
	{1100, "TS_CS_GAME_TIME"},
	{1101, "TS_SC_GAME_TIME"},
	{1201, "TS_SC_EMOTION"},
	{1202, "TS_CS_EMOTION"},
	{1300, "TS_CS_AUCTION_SEARCH"},
	{1301, "TS_SC_AUCTION_SEARCH"},
	{1302, "TS_CS_AUCTION_SELLING_LIST"},
	{1303, "TS_SC_AUCTION_SELLING_LIST"},
	{1304, "TS_CS_AUCTION_BIDDED_LIST"},
	{1305, "TS_SC_AUCTION_BIDDED_LIST"},
	{1306, "TS_CS_AUCTION_BID"},
	{1308, "TS_CS_AUCTION_INSTANT_PURCHASE"},
	{1309, "TS_CS_AUCTION_REGISTER"},
	{1310, "TS_CS_AUCTION_CANCEL"},
	{1350, "TS_CS_ITEM_KEEPING_LIST"},
	{1351, "TS_SC_ITEM_KEEPING_LIST"},
	{1352, "TS_CS_ITEM_KEEPING_TAKE"},
	{2000, "TS_CS_ACCOUNT"},
	{2001, "TS_CS_CHARACTER_LIST"},
	{2002, "TS_CS_CREATE_CHARACTER"},
	{2003, "TS_CS_DELETE_CHARACTER"},
	{2004, "TS_SC_CHARACTER_LIST"},
	{2005, "TS_CS_ACCOUNT_WITH_AUTH"},
	{2006, "TS_CS_CHECK_CHARACTER_NAME"},
	{2008, "TS_CS_CHARACTER_LIST_2"},
	{3000, "TS_SC_DIALOG"},
	{3001, "TS_CS_DIALOG"},
	{3002, "TS_CS_CONTACT"},
	{3003, "TS_SC_SHOW_WINDOW"},
	{3004, "TS_SC_GENERAL_MESSAGE_BOX"},
	{4000, "TS_CS_HUNTAHOLIC_INSTANCE_LIST"},
	{4001, "TS_SC_HUNTAHOLIC_INSTANCE_LIST"},
	{4002, "TS_SC_HUNTAHOLIC_INSTANCE_INFO"},
	{4003, "TS_CS_HUNTAHOLIC_CREATE_INSTANCE"},
	{4004, "TS_CS_HUNTAHOLIC_JOIN_INSTANCE"},
	{4005, "TS_CS_HUNTAHOLIC_LEAVE_INSTANCE"},
	{4006, "TS_SC_HUNTAHOLIC_HUNTING_SCORE"},
	{4007, "TS_SC_HUNTAHOLIC_UPDATE_SCORE"},
	{4008, "TS_CS_HUNTAHOLIC_LEAVE_LOBBY"},
	{4009, "TS_SC_HUNTAHOLIC_BEGIN_HUNTING"},
	{4010, "TS_SC_HUNTAHOLIC_MAX_POINT_ACHIEVED"},
	{4011, "TS_CS_HUNTAHOLIC_BEGIN_HUNTING"},
	{4012, "TS_SC_HUNTAHOLIC_BEGIN_COUNTDOWN"},
	{4250, "TS_CS_INSTANCE_GAME_ENTER"},
	{4251, "TS_CS_INSTANCE_GAME_EXIT"},
	{4252, "TS_CS_INSTANCE_GAME_SCORE_REQUEST"},
	{4253, "TS_SC_INSTANCE_GAME_SCORE_REQUEST"},
	{4500, "TS_CS_COMPETE_REQUEST"},
	{4501, "TS_SC_COMPETE_REQUEST"},
	{4502, "TS_CS_COMPETE_ANSWER"},
	{4503, "TS_SC_COMPETE_ANSWER"},
	{4504, "TS_SC_COMPETE_COUNTDOWN"},
	{4505, "TS_SC_COMPETE_START"},
	{4506, "TS_SC_COMPETE_END"},
	{4700, "TS_SC_BATTLE_ARENA_PENALTY_INFO"},
	{4701, "TS_CS_BATTLE_ARENA_JOIN_QUEUE"},
	{4702, "TS_SC_BATTLE_ARENA_JOIN_QUEUE"},
	{4703, "TS_SC_BATTLE_ARENA_UPDATE_WAIT_USER_COUNT"},
	{4704, "TS_CS_BATTLE_ARENA_LEAVE"},
	{4705, "TS_SC_BATTLE_ARENA_LEAVE"},
	{4706, "TS_SC_BATTLE_ARENA_BATTLE_INFO"},
	{4707, "TS_CS_BATTLE_ARENA_ENTER_WHILE_COUNTDOWN"},
	{4708, "TS_CS_BATTLE_ARENA_EXERCISE_READY"},
	{4709, "TS_SC_BATTLE_ARENA_EXERCISE_READY_STATUS"},
	{4710, "TS_CS_BATTLE_ARENA_EXERCISE_START"},
	{4711, "TS_SC_BATTLE_ARENA_BATTLE_STATUS"},
	{4712, "TS_SC_BATTLE_ARENA_BATTLE_SCORE"},
	{4713, "TS_SC_BATTLE_ARENA_JOIN_BATTLE"},
	{4714, "TS_SC_BATTLE_ARENA_DISCONNECT_BATTLE"},
	{4715, "TS_SC_BATTLE_ARENA_RECONNECT_BATTLE"},
	{4716, "TS_SC_BATTLE_ARENA_RESULT"},
	{4717, "TS_CS_BATTLE_ARENA_ABSENCE_CHECK_REQUEST"},
	{4718, "TS_SC_BATTLE_ARENA_ABSENCE_CHECK"},
	{4719, "TS_CS_BATTLE_ARENA_ABSENCE_CHECK_ANSWER"},
	{5000, "TS_CS_RANKING_TOP_RECORD"},
	{5001, "TS_SC_RANKING_TOP_RECORD"},
	{6000, "TS_CS_REQUEST_FARM_INFO"},
	{6001, "TS_SC_FARM_INFO"},
	{6002, "TS_CS_FOSTER_CREATURE"},
	{6003, "TS_SC_RESULT_FOSTER"},
	{6004, "TS_CS_RETRIEVE_CREATURE"},
	{6005, "TS_SC_RESULT_RETRIEVE"},
	{6006, "TS_CS_NURSE_CREATURE"},
	{6007, "TS_SC_RESULT_NURSE"},
	{6008, "TS_CS_REQUEST_FARM_MARKET"},
	{8000, "TS_CS_REPORT"},
	{9000, "TS_SC_OPEN_URL"},
	{9001, "TS_SC_URL_LIST"},
	{9002, "TS_SC_CREATE_SECURITY_NO"},
	{9004, "TS_SC_REQUEST_SECURITY_NO"},
	{9005, "TS_CS_SECURITY_NO"},
	{9006, "TS_CS_CREATE_SECURITY_NO"},
	{9007, "TS_CS_CHANGE_SECURITY_NO"},
	{9008, "TS_CS_REQUEST_SECURITY_NO_CHANGE"},
	{9009, "TS_SC_CHANGE_SECURITY_NO"},
	{9010, "TS_CS_REQUEST_CLEAR_SECURITY_NO"},
	{9011, "TS_SC_CLEAR_SECURITY_NO"},
	{9012, "TS_CS_CLEAR_SECURITY_NO"},
	{9999, "TS_DUMMY"},
	{10000, "TS_CS_OPEN_ITEM_SHOP"},
	{10001, "TS_SC_OPEN_ITEM_SHOP"},
	{10002, "TS_SC_OPEN_PAID_STORAGE"},
	{10003, "TS_SC_COMMERCIAL_STORAGE_INFO"},
	{10004, "TS_SC_COMMERCIAL_STORAGE_LIST"},
	{10005, "TS_CS_TAKEOUT_COMMERCIAL_ITEM"}
};

static const PacketNameInfo authPacketNames[] = {
	{0, "TS_SC_RESULT"},
	{71, "TS_CA_RSA_PUBLIC_KEY"},
	{72, "TS_AC_AES_KEY_IV"},
	{9999, "TS_DUMMY"},
	{10000, "TS_AC_RESULT"},
	{10001, "TS_CA_VERSION"},
	{10002, "TS_AC_RESULT_WITH_STRING"},
	{10010, "TS_CA_ACCOUNT"},
	{10011, "TS_CA_OTP_ACCOUNT"},
	{10012, "TS_CA_IMBC_ACCOUNT"},
	{10021, "TS_CA_SERVER_LIST"},
	{10022, "TS_AC_SERVER_LIST"},
	{10023, "TS_CA_SELECT_SERVER"},
	{10024, "TS_AC_SELECT_SERVER"},
	{10026, "TS_CA_DISTRIBUTION_INFO"}
};

static const char* authPacketNamesArray[65535] = {0};
static const char* gamePacketNamesArray[65535] = {0};

static void initPacketName() {
	for(size_t i=0; i < sizeof(authPacketNames)/sizeof(PacketNameInfo); i++) {
		authPacketNamesArray[authPacketNames[i].id] = authPacketNames[i].name;
	}

	for(size_t i=0; i < sizeof(gamePacketNames)/sizeof(PacketNameInfo); i++) {
		gamePacketNamesArray[gamePacketNames[i].id] = gamePacketNames[i].name;
	}
}
	
static const char* getPacketName(unsigned int id, bool isAuth) {
	if(gamePacketNamesArray[0] == nullptr)
		initPacketName();

	const char* name;

	if(isAuth)
		name = authPacketNamesArray[id];
	else
		name = gamePacketNamesArray[id];
	
	return name ? name : "UnknownPacket";
}
