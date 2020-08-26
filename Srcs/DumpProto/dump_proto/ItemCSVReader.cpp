#include <math.h>
#include "ItemCSVReader.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

inline string trim_left(const string& str)
{
    string::size_type n = str.find_first_not_of(" \t\v\n\r");
    return n == string::npos ? str : str.substr(n, str.length());
}

inline string trim_right(const string& str)
{
    string::size_type n = str.find_last_not_of(" \t\v\n\r");
    return n == string::npos ? str : str.substr(0, n + 1);
}

string trim(const string& str){return trim_left(trim_right(str));}

std::vector<std::string> split_string(const std::string& s, char delim) {
	std::stringstream ss(s);
	std::string current;
	std::vector<std::string> values;

	while (std::getline(ss, current, delim)) {
		values.push_back(std::move(current));

	}
	return values;
}


int get_flags_value(std::string inputString, std::vector<std::string> flags, char sep)
{
	if (inputString.compare("NONE") == 0)
		return 0;

	int retValue = 0;
	std::vector<std::string> values = split_string(inputString, sep);
	for (auto& val : values)
	{
		val.erase(std::remove(val.begin(), val.end(), ' '), val.end());

		bool found = false;
		int n = 0;

		for (const auto& f : flags)
		{
			if (val.compare(f) == 0)
			{
				found = true;
				retValue += std::pow(2, n);
				break;
			}

			++n;
		}

		if (!found)
		{
			//sys_err("Not existing flag !! (flag %s)", val.c_str());
			return -1;
		}
	}

	return retValue;
}

int get_Item_Type_Value(string inputString)
{
	string arType[] = { "ITEM_NONE", "ITEM_WEAPON",
		"ITEM_ARMOR", "ITEM_USE",
		"ITEM_AUTOUSE", "ITEM_MATERIAL",
		"ITEM_SPECIAL", "ITEM_TOOL",
		"ITEM_LOTTERY", "ITEM_ELK",					//9개

		"ITEM_METIN", "ITEM_CONTAINER",
		"ITEM_FISH", "ITEM_ROD",
		"ITEM_RESOURCE", "ITEM_CAMPFIRE",
		"ITEM_UNIQUE", "ITEM_SKILLBOOK",
		"ITEM_QUEST", "ITEM_POLYMORPH",				//19개

		"ITEM_TREASURE_BOX", "ITEM_TREASURE_KEY",
		"ITEM_SKILLFORGET", "ITEM_GIFTBOX",
		"ITEM_PICK", "ITEM_HAIR",
		"ITEM_TOTEM", "ITEM_BLEND",
		"ITEM_COSTUME", "ITEM_DS",					//31개

		"ITEM_SPECIAL_DS",	"ITEM_EXTRACT",
		"ITEM_SECONDARY_COIN",						//32개

		"ITEM_RING",								//33
		"ITEM_BELT",								//34

		"ITEM_PET",									//35
		"ITEM_MEDIUM",								//36
		"ITEM_GACHA",								//37
		"ITEM_SOUL",		//38
	};


	int retInt = -1;
	//cout << "Type : " << typeStr << " -> ";
	for (int j = 0; j < sizeof(arType) / sizeof(arType[0]); j++) {
		string tempString = arType[j];
		if (inputString.find(tempString) != string::npos && tempString.find(inputString) != string::npos) {
			//cout << j << " ";
			retInt = j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Item_SubType_Value(int type_value, string inputString)
{
	static string arSub1[] = { "WEAPON_SWORD", "WEAPON_DAGGER", "WEAPON_BOW", "WEAPON_TWO_HANDED",
				"WEAPON_BELL", "WEAPON_FAN", "WEAPON_ARROW", "WEAPON_MOUNT_SPEAR", "WEAPON_CLAW",
				"WEAPON_QUIVER", "WEAPON_BOUQUET" };
	static string arSub2[] = { "ARMOR_BODY", "ARMOR_HEAD", "ARMOR_SHIELD", "ARMOR_WRIST", "ARMOR_FOOTS",
				"ARMOR_NECK", "ARMOR_EAR", "ARMOR_PENDANT" };
	static string arSub3[] = { "USE_POTION", "USE_TALISMAN", "USE_TUNING", "USE_MOVE", "USE_TREASURE_BOX", "USE_MONEYBAG", "USE_BAIT",
				"USE_ABILITY_UP", "USE_AFFECT", "USE_CREATE_STONE", "USE_SPECIAL", "USE_POTION_NODELAY", "USE_CLEAR",
				"USE_INVISIBILITY", "USE_DETACHMENT", "USE_BUCKET", "USE_POTION_CONTINUE", "USE_CLEAN_SOCKET",
				"USE_CHANGE_ATTRIBUTE", "USE_ADD_ATTRIBUTE", "USE_ADD_ACCESSORY_SOCKET", "USE_PUT_INTO_ACCESSORY_SOCKET",
				"USE_ADD_ATTRIBUTE2", "USE_RECIPE", "USE_CHANGE_ATTRIBUTE2", "USE_BIND", "USE_UNBIND", "USE_TIME_CHARGE_PER",
				"USE_TIME_CHARGE_FIX", "USE_PUT_INTO_BELT_SOCKET", "USE_PUT_INTO_RING_SOCKET",
				"USE_CHANGE_COSTUME_ATTR", "USE_RESET_COSTUME_ATTR", "", "USE_SELECT_ATTRIBUTE", "USE_FLOWER",
				"USE_EMOTION_PACK", "USE_ELEMENT_UPGRADE", "USE_ELEMENT_DOWNGRADE", "USE_ELEMENT_CHANGE", "USE_UNK40" };
	static string arSub4[] = { "AUTOUSE_POTION", "AUTOUSE_ABILITY_UP", "AUTOUSE_BOMB", "AUTOUSE_GOLD", "AUTOUSE_MONEYBAG", "AUTOUSE_TREASURE_BOX" };
	static string arSub5[] = { "MATERIAL_LEATHER", "MATERIAL_BLOOD", "MATERIAL_ROOT", "MATERIAL_NEEDLE", "MATERIAL_JEWEL",
								"MATERIAL_DS_REFINE_NORMAL", "MATERIAL_DS_REFINE_BLESSED", "MATERIAL_DS_REFINE_HOLLY",
								"MATERIAL_DS_CHANGE_ATTR", };
	static string arSub6[] = { "SPECIAL_MAP", "SPECIAL_KEY", "SPECIAL_DOC", "SPECIAL_SPIRIT" };
	static string arSub7[] = { "TOOL_FISHING_ROD" };
	static string arSub8[] = { "LOTTERY_TICKET", "LOTTERY_INSTANT" };
	static string arSub10[] = { "METIN_NORMAL", "METIN_GOLD" };
	static string arSub12[] = { "FISH_ALIVE", "FISH_DEAD" };
	static string arSub14[] = { "RESOURCE_FISHBONE", "RESOURCE_WATERSTONEPIECE", "RESOURCE_WATERSTONE", "RESOURCE_BLOOD_PEARL",
						"RESOURCE_BLUE_PEARL", "RESOURCE_WHITE_PEARL", "RESOURCE_BUCKET", "RESOURCE_CRYSTAL", "RESOURCE_GEM",
						"RESOURCE_STONE", "RESOURCE_METIN", "RESOURCE_ORE", "RESOURCE_AURA" };
	static string arSub16[] = { "UNIQUE_NONE", "UNIQUE_BOOK", "UNIQUE_SPECIAL_RIDE", "UNIQUE_3", "UNIQUE_4", "UNIQUE_5",
					"UNIQUE_6", "UNIQUE_7", "UNIQUE_8", "UNIQUE_9", "USE_SPECIAL" };
	static string arSub28[] = { "COSTUME_BODY", "COSTUME_HAIR", "COSTUME_MOUNT", "COSTUME_ACCE", "COSTUME_WEAPON", "COSTUME_AURA" };
	static string arSub29[] = { "DS_SLOT1", "DS_SLOT2", "DS_SLOT3", "DS_SLOT4", "DS_SLOT5", "DS_SLOT6" };
	static string arSub31[] = { "EXTRACT_DRAGON_SOUL", "EXTRACT_DRAGON_HEART" };

	static string arSub35[] = { "PET_EGG","PET_UPBRINGING","PET_BAG",
								"PET_FEEDSTUFF","PET_SKILL","PET_SKILL_DEL_BOOK",
								"PET_NAME_CHANGE","PET_EXPFOOD","PET_SKILL_ALL_DEL_BOOK",
								"PET_EXPFOOD_PER","PET_ATTR_DETERMINE","PET_ATTR_CHANGE",
								"PET_PAY","PET_PRIMIUM_FEEDSTUFF" };

	static string arSub36[] = { "MEDIUM_MOVE_COSTUME_ATTR", "MEDIUM_MOVE_ACCE_ATTR" };

	static string arSub37[] = { "USE_GACHA", "GEM_LUCKY_BOX_GACHA", "SPECIAL_LUCKY_BOX_GACHA" };

	static string arSub38[] = { "SOUL_RED", "SOUL_BLUE" };

	static string* arSubType[] = { 0,	//0
		arSub1,		//1
		arSub2,	//2
		arSub3,	//3
		arSub4,	//4
		arSub5,	//5
		arSub6,	//6
		arSub7,	//7
		arSub8,	//8
		0,			//9
		arSub10,	//10
		0,			//11
		arSub12,	//12
		0,			//13
		arSub14,	//14
		0,			//15
		arSub16,	//16
		0,			//17
		0,			//18
		0,			//19
		0,			//20
		0,			//21
		0,			//22
		0,			//23
		0,			//24
		0,			//25
		0,			//26
		0,			//27
		arSub28,	//28
		arSub29,		//29
		arSub29,	//30
		arSub31,	//31
		0,			//32
		0,			//33 반지
		0,			//34 벨트
		arSub35,
		arSub36,	//36
		arSub37,	//37
		arSub38,
	};
	static int arNumberOfSubtype[_countof(arSubType)] = {
		0,
		sizeof(arSub1) / sizeof(arSub1[0]),
		sizeof(arSub2) / sizeof(arSub2[0]),
		sizeof(arSub3) / sizeof(arSub3[0]),
		sizeof(arSub4) / sizeof(arSub4[0]),
		sizeof(arSub5) / sizeof(arSub5[0]),
		sizeof(arSub6) / sizeof(arSub6[0]),
		sizeof(arSub7) / sizeof(arSub7[0]),
		sizeof(arSub8) / sizeof(arSub8[0]),
		0,
		sizeof(arSub10) / sizeof(arSub10[0]),
		0,
		sizeof(arSub12) / sizeof(arSub12[0]),
		0,
		sizeof(arSub14) / sizeof(arSub14[0]),
		0,
		sizeof(arSub16) / sizeof(arSub16[0]),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(arSub28) / sizeof(arSub28[0]),
		sizeof(arSub29) / sizeof(arSub29[0]),
		sizeof(arSub29) / sizeof(arSub29[0]),
		sizeof(arSub31) / sizeof(arSub31[0]),
		0, // 32
		0, // 33 반지
		0, // 34 벨트
		sizeof(arSub35) / sizeof(arSub35[0]),
		sizeof(arSub36) / sizeof(arSub36[0]),
		sizeof(arSub37) / sizeof(arSub37[0]),
		sizeof(arSub38) / sizeof(arSub38[0]),
	};

	//아이템 타입의 서브타입 어레이가 존재하는지 알아보고, 없으면 0 리턴
	if (arSubType[type_value] == 0) {
		return 0;
	}
	//

	int retInt = -1;
	//cout << "SubType : " << subTypeStr << " -> ";
	for (int j = 0; j < arNumberOfSubtype[type_value]; j++) {
		string tempString = arSubType[type_value][j];
		string tempInputString = trim(inputString);
		if (tempInputString.compare(tempString) == 0)
		{
			//cout << j << " ";
			retInt = j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Item_Mask_Type_Value(string inputString)
{
	string arTypeMask[] = { "MASK_ITEM_NONE","MASK_ITEM_MOUNT_PET","MASK_ITEM_EQUIPMENT_WEAPON",
									"MASK_ITEM_EQUIPMENT_ARMOR","MASK_ITEM_EQUIPMENT_JEWELRY","MASK_ITEM_TUNING",
									"MASK_ITEM_POTION","MASK_ITEM_FISHING_PICK","MASK_ITEM_DRAGON_STONE",
									"MASK_ITEM_COSTUMES","MASK_ITEM_SKILL","MASK_ITEM_UNIQUE","MASK_ITEM_ETC" };

	int retInt = -1;

	for (int j = 0; j < sizeof(arTypeMask) / sizeof(arTypeMask[0]); j++) {
		string tempString = arTypeMask[j];
		if (inputString.find(tempString) != string::npos && tempString.find(inputString) != string::npos) {
			retInt = j;
			break;
		}
	}

	return retInt;
}

int get_Item_Mask_SubType_Value(int type_value, string inputString)
{
	static string arSub1[] = { "MASK_MOUNT_PET_MOUNT","MASK_MOUNT_PET_CHARGED_PET","MASK_MOUNT_PET_FREE_PET","MASK_MOUNT_PET_EGG" };

	static string arSub2[] = { "MASK_EQUIPMENT_WEAPON_SWORD","MASK_EQUIPMENT_WEAPON_DAGGER","MASK_EQUIPMENT_WEAPON_BOW",
										"MASK_EQUIPMENT_WEAPON_TWO_HANDED","MASK_EQUIPMENT_WEAPON_BELL","MASK_EQUIPMENT_WEAPON_CLAW",
										"MASK_EQUIPMENT_WEAPON_FAN","MASK_EQUIPMENT_WEAPON_MOUNT_SPEAR","MASK_EQUIPMENT_WEAPON_ARROW" };

	static string arSub3[] = { "MASK_EQUIPMENT_ARMOR_BODY","MASK_EQUIPMENT_ARMOR_HEAD","MASK_EQUIPMENT_ARMOR_SHIELD" };

	static string arSub4[] = { "MASK_EQUIPMENT_JEWELRY_ARMOR_WRIST","MASK_EQUIPMENT_JEWELRY_ARMOR_FOOTS","MASK_EQUIPMENT_JEWELRY_ARMOR_NECK",
										"MASK_EQUIPMENT_JEWELRY_ARMOR_EAR","MASK_EQUIPMENT_JEWELRY_ITEM_BELT","MASK_EQUIPMENT_JEWELRY_ARMOR_PENDANT" };

	static string arSub5[] = { "MASK_TUNING_RESOURCE","MASK_TUNING_STONE","MASK_TUNING_ETC" };

	static string arSub6[] = { "MASK_POTION_ABILITY","MASK_POTION_HAIRDYE","MASK_POTION_ETC" };

	static string arSub7[] = { "MASK_FISHING_PICK_FISHING_POLE","MASK_FISHING_PICK_EQUIPMENT_PICK","MASK_FISHING_PICK_FOOD",
										 "MASK_FISHING_PICK_STONE","MASK_FISHING_PICK_ETC" };

	static string arSub8[] = { "MASK_DRAGON_STONE_DRAGON_DIAMOND","MASK_DRAGON_STONE_DRAGON_RUBY","MASK_DRAGON_STONE_DRAGON_JADE",
										"MASK_DRAGON_STONE_DRAGON_SAPPHIRE","MASK_DRAGON_STONE_DRAGON_GARNET","MASK_DRAGON_STONE_DRAGON_ONYX",
										"MASK_DRAGON_STONE_ETC" };

	static string arSub9[] = { "MASK_COSTUMES_COSTUME_WEAPON","MASK_COSTUMES_COSTUME_BODY","MASK_COSTUMES_COSTUME_HAIR",
										"MASK_COSTUMES_SASH","MASK_COSTUMES_AURA","MASK_COSTUMES_ETC" };

	static string arSub10[] = { "MASK_SKILL_PAHAE","MASK_SKILL_SKILL_BOOK","MASK_SKILL_BOOK_OF_OBLIVION","MASK_SKILL_ETC" };

	static string arSub11[] = { "MASK_UNIQUE_ABILITY","MASK_UNIQUE_ETC" };

	static string arSub12[] = { "MASK_ETC_GIFTBOX","MASK_ETC_MATRIMORY","MASK_ETC_EVENT",
											"MASK_ETC_SEAL","MASK_ETC_PARTI","MASK_ETC_POLYMORPH",
											"MASK_ETC_RECIPE","MASK_ETC_ETC" };


	static string* arMaskSubType[] = {
		0,	//0
		arSub1,		//1
		arSub2,	//2
		arSub3,	//3
		arSub4,	//4
		arSub5,	//5
		arSub6,	//6
		arSub7,	//7
		arSub8,	//8
		arSub9,			//9
		arSub10,	//10
		arSub11,			//11
		arSub12,	//12
	};

	static int arNumberOfMaskSubtype[_countof(arMaskSubType)] = {
		0,
		sizeof(arSub1) / sizeof(arSub1[0]),
		sizeof(arSub2) / sizeof(arSub2[0]),
		sizeof(arSub3) / sizeof(arSub3[0]),
		sizeof(arSub4) / sizeof(arSub4[0]),
		sizeof(arSub5) / sizeof(arSub5[0]),
		sizeof(arSub6) / sizeof(arSub6[0]),
		sizeof(arSub7) / sizeof(arSub7[0]),
		sizeof(arSub8) / sizeof(arSub8[0]),
		sizeof(arSub9) / sizeof(arSub9[0]),
		sizeof(arSub10) / sizeof(arSub10[0]),
		sizeof(arSub11) / sizeof(arSub11[0]),
		sizeof(arSub12) / sizeof(arSub12[0]),
	};

	//아이템 타입의 서브타입 어레이가 존재하는지 알아보고, 없으면 0 리턴
	if (arMaskSubType[type_value] == 0) {
		return 0;
	}
	//

	int retInt = -1;
	//cout << "SubType : " << subTypeStr << " -> ";
	for (int j = 0; j < arNumberOfMaskSubtype[type_value]; j++) {
		string tempString = arMaskSubType[type_value][j];
		string tempInputString = trim(inputString);
		if (tempInputString.compare(tempString) == 0)
		{
			//cout << j << " ";
			retInt = j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Item_AntiFlag_Value(string inputString) 
{

	vector<string> arAntiFlag = { "ANTI_FEMALE", "ANTI_MALE", "ANTI_MUSA", "ANTI_ASSASSIN", "ANTI_SURA", "ANTI_MUDANG",
							"ANTI_GET", "ANTI_DROP", "ANTI_SELL", "ANTI_EMPIRE_A", "ANTI_EMPIRE_B", "ANTI_EMPIRE_C",
							"ANTI_SAVE", "ANTI_GIVE", "ANTI_PKDROP", "ANTI_STACK", "ANTI_MYSHOP", "ANTI_SAFEBOX",
							"ANTI_WOLFMAN", "ANTI_PET", "ANTI_QUICKSLOT", "ANTI_CHANGELOOK", "ANTI_REINFORCE",
							"ANTI_ENCHANT", "ANTI_PETFEED", "ANTI_ENERGY", "ANTI_APPLY", "ANTI_ACCE", "ANTI_MAIL" };


	return get_flags_value(inputString, arAntiFlag, '|');
}

int get_Item_Flag_Value(string inputString) 
{

	vector<string> arFlag = {"ITEM_TUNABLE", "ITEM_SAVE", "ITEM_STACKABLE", "COUNT_PER_1GOLD", "ITEM_SLOW_QUERY", "ITEM_UNIQUE",
			"ITEM_MAKECOUNT", "ITEM_IRREMOVABLE", "CONFIRM_WHEN_USE", "QUEST_USE", "QUEST_USE_MULTIPLE",
			"QUEST_GIVE", "ITEM_QUEST", "LOG", "STACKABLE", "SLOW_QUERY", "REFINEABLE", "IRREMOVABLE", "ITEM_APPLICABLE"};


	return get_flags_value(inputString, arFlag, '|');
}

int get_Item_WearFlag_Value(string inputString) 
{

	vector<string> arWearrFlag = {"WEAR_BODY", "WEAR_HEAD", "WEAR_FOOTS", "WEAR_WRIST", "WEAR_WEAPON", "WEAR_NECK", "WEAR_EAR", "WEAR_UNIQUE", "WEAR_SHIELD",
					"WEAR_ARROW", "WEAR_HAIR", "WEAR_ABILITY", "WEAR_PENDANT"};

	return get_flags_value(inputString, arWearrFlag, '|');
}

int get_Item_Immune_Value(string inputString) 
{

	vector<string> arImmune = {"PARA","CURSE","STUN","SLEEP","SLOW","POISON","TERROR"};

	return get_flags_value(inputString, arImmune, '|');
}




int get_Item_LimitType_Value(string inputString)
{
	string arLimitType[] = {"LIMIT_NONE", "LEVEL", "STR", "DEX", "INT", "CON", "PC_BANG", "REAL_TIME", "REAL_TIME_FIRST_USE", "TIMER_BASED_ON_WEAR"};
	
	int retInt = -1;
	//cout << "LimitType : " << limitTypeStr << " -> ";
	for (int j=0;j<sizeof(arLimitType)/sizeof(arLimitType[0]);j++) {
		string tempString = arLimitType[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0)
		{
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}


int get_Item_ApplyType_Value(string inputString)
{
	string arApplyType[] = {"APPLY_NONE", "APPLY_MAX_HP", "APPLY_MAX_SP", "APPLY_CON", "APPLY_INT", "APPLY_STR", "APPLY_DEX", "APPLY_ATT_SPEED",
			"APPLY_MOV_SPEED", "APPLY_CAST_SPEED", "APPLY_HP_REGEN", "APPLY_SP_REGEN", "APPLY_POISON_PCT", "APPLY_STUN_PCT",
			"APPLY_SLOW_PCT", "APPLY_CRITICAL_PCT", "APPLY_PENETRATE_PCT", "APPLY_ATTBONUS_HUMAN", "APPLY_ATTBONUS_ANIMAL",
			"APPLY_ATTBONUS_ORC", "APPLY_ATTBONUS_MILGYO", "APPLY_ATTBONUS_UNDEAD", "APPLY_ATTBONUS_DEVIL", "APPLY_STEAL_HP",
			"APPLY_STEAL_SP", "APPLY_MANA_BURN_PCT", "APPLY_DAMAGE_SP_RECOVER", "APPLY_BLOCK", "APPLY_DODGE", "APPLY_RESIST_SWORD",
			"APPLY_RESIST_TWOHAND", "APPLY_RESIST_DAGGER", "APPLY_RESIST_BELL", "APPLY_RESIST_FAN", "APPLY_RESIST_BOW", "APPLY_RESIST_FIRE",
			"APPLY_RESIST_ELEC", "APPLY_RESIST_MAGIC", "APPLY_RESIST_WIND", "APPLY_REFLECT_MELEE", "APPLY_REFLECT_CURSE", "APPLY_POISON_REDUCE",
			"APPLY_KILL_SP_RECOVER", "APPLY_EXP_DOUBLE_BONUS", "APPLY_GOLD_DOUBLE_BONUS", "APPLY_ITEM_DROP_BONUS", "APPLY_POTION_BONUS",
			"APPLY_KILL_HP_RECOVER", "APPLY_IMMUNE_STUN", "APPLY_IMMUNE_SLOW", "APPLY_IMMUNE_FALL", "APPLY_SKILL", "APPLY_BOW_DISTANCE",
			"APPLY_ATT_GRADE_BONUS", "APPLY_DEF_GRADE_BONUS", "APPLY_MAGIC_ATT_GRADE", "APPLY_MAGIC_DEF_GRADE", "APPLY_CURSE_PCT",
			"APPLY_MAX_STAMINA", "APPLY_ATTBONUS_WARRIOR", "APPLY_ATTBONUS_ASSASSIN", "APPLY_ATTBONUS_SURA", "APPLY_ATTBONUS_SHAMAN",
			"APPLY_ATTBONUS_MONSTER", "APPLY_MALL_ATTBONUS", "APPLY_MALL_DEFBONUS", "APPLY_MALL_EXPBONUS", "APPLY_MALL_ITEMBONUS",
			"APPLY_MALL_GOLDBONUS", "APPLY_MAX_HP_PCT", "APPLY_MAX_SP_PCT", "APPLY_SKILL_DAMAGE_BONUS", "APPLY_NORMAL_HIT_DAMAGE_BONUS",
			"APPLY_SKILL_DEFEND_BONUS", "APPLY_NORMAL_HIT_DEFEND_BONUS", "APPLY_PC_BANG_EXP_BONUS", "APPLY_PC_BANG_DROP_BONUS",
			"APPLY_EXTRACT_HP_PCT", "APPLY_RESIST_WARRIOR", "APPLY_RESIST_ASSASSIN", "APPLY_RESIST_SURA", "APPLY_RESIST_SHAMAN",
			"APPLY_ENERGY",	"APPLY_DEF_GRADE", "APPLY_COSTUME_ATTR_BONUS", "APPLY_MAGIC_ATTBONUS_PER", "APPLY_MELEE_MAGIC_ATTBONUS_PER",
			"APPLY_RESIST_ICE", "APPLY_RESIST_EARTH", "APPLY_RESIST_DARK", "APPLY_ANTI_CRITICAL_PCT", "APPLY_ANTI_PENETRATE_PCT",
			"APPLY_BLEEDING_REDUCE", "APPLY_BLEEDING_PCT", "APPLY_ATTBONUS_WOLFMAN", "APPLY_RESIST_WOLFMAN", "APPLY_RESIST_CLAW",
			"APPLY_ACCEDRAIN_RATE", "APPLY_RESIST_MAGIC_REDUCTION", "APPLY_ENCHANT_ELECT", "APPLY_ENCHANT_FIRE", "APPLY_ENCHANT_ICE",
			"APPLY_ENCHANT_WIND", "APPLY_ENCHANT_EARTH", "APPLY_ENCHANT_DARK", "APPLY_ATTBONUS_CZ", "APPLY_ATTBONUS_INSECT",
			"APPLY_ATTBONUS_DESERT", "APPLY_ATTBONUS_SWORD", "APPLY_ATTBONUS_TWOHAND", "APPLY_ATTBONUS_DAGGER", "APPLY_ATTBONUS_BELL",
			"APPLY_ATTBONUS_FAN", "APPLY_ATTBONUS_BOW", "APPLY_ATTBONUS_CLAW", "APPLY_RESIST_HUMAN", "APPLY_RESIST_MOUNT_FALL", "", "APPLY_MOUNT",
	};

	int retInt = -1;
	//cout << "ApplyType : " << applyTypeStr << " -> ";
	for (int j=0;j<sizeof(arApplyType)/sizeof(arApplyType[0]);j++) {
		string tempString = arApplyType[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0)
		{ 
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}
	//cout << endl;

	return retInt;

}


//몬스터 프로토도 읽는다.


int get_Mob_Rank_Value(string inputString) 
{
	string arRank[] = {"PAWN", "S_PAWN", "KNIGHT", "S_KNIGHT", "BOSS", "KING"};

	int retInt = -1;
	//cout << "Rank : " << rankStr << " -> ";
	for (int j=0;j<sizeof(arRank)/sizeof(arRank[0]);j++) {
		string tempString = arRank[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0) 
		{
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}


int get_Mob_Type_Value(string inputString)
{
	string arType[] = { "MONSTER", "NPC", "STONE", "WARP", "DOOR", "BUILDING", "PC", "POLYMORPH_PC", "HORSE", "GOTO"};

	int retInt = -1;
	//cout << "Type : " << typeStr << " -> ";
	for (int j=0;j<sizeof(arType)/sizeof(arType[0]);j++) {
		string tempString = arType[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0) 
		{
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Mob_BattleType_Value(string inputString) 
{
	string arBattleType[] = { "MELEE", "RANGE", "MAGIC", "SPECIAL", "POWER", "TANKER", "SUPER_POWER", "SUPER_TANKER"};

	int retInt = -1;
	//cout << "Battle Type : " << battleTypeStr << " -> ";
	for (int j=0;j<sizeof(arBattleType)/sizeof(arBattleType[0]);j++) {
		string tempString = arBattleType[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0) 
		{ 
			//cout << j << " ";
			retInt =  j;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Mob_Size_Value(string inputString)
{
	string arSize[] = { "SAMLL", "MEDIUM", "BIG"};

	int retInt = 0;
	//cout << "Size : " << sizeStr << " -> ";
	for (int j=0;j<sizeof(arSize)/sizeof(arSize[0]);j++) {
		string tempString = arSize[j];
		string tempInputString = trim(inputString);
		if	(tempInputString.compare(tempString)==0) 
		{
			//cout << j << " ";
			retInt =  j + 1;
			break;
		}
	}
	//cout << endl;

	return retInt;
}

int get_Mob_AIFlag_Value(string inputString)
{
	vector<string> arAIFlag = {"AGGR","NOMOVE","COWARD","NOATTSHINSU","NOATTCHUNJO","NOATTJINNO","ATTMOB","BERSERK","STONESKIN","GODSPEED","DEATHBLOW","REVIVE"};

	return get_flags_value(inputString, arAIFlag, ',');
}

int get_Mob_RaceFlag_Value(string inputString)
{
	std::vector<std::string> arRaceFlag = { "ANIMAL","UNDEAD","DEVIL","HUMAN","ORC","MILGYO","INSECT","FIRE","ICE","DESERT","TREE",
		"ATT_ELEC","ATT_FIRE","ATT_ICE","ATT_WIND","ATT_EARTH","ATT_DARK" };

	return get_flags_value(inputString, arRaceFlag, ',');
}

int get_Mob_ImmuneFlag_Value(string inputString)
{
	std::vector<std::string> arImmuneFlag = { "STUN","SLOW","FALL","CURSE","POISON","TERROR", "REFLECT" };

	return get_flags_value(inputString, arImmuneFlag, ',');
}