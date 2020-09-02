#pragma once

// NOTE : Item�� ���� ���� Ŭ������.
//        Icon, Model (droped on ground), Game Data

#include "../eterLib/GrpSubImage.h"
#include "../eterGrnLib/Thing.h"

class CItemData
{
	public:
		enum
		{
			ITEM_NAME_MAX_LEN = 32,
			ITEM_LIMIT_MAX_NUM = 2,
			ITEM_VALUES_MAX_NUM = 6,
			ITEM_SMALL_DESCR_MAX_LEN = 256,
			ITEM_APPLY_MAX_NUM = 4,
			ITEM_SOCKET_MAX_NUM = 3,
		};

		enum EItemType
		{
			ITEM_TYPE_NONE,					//0
			ITEM_TYPE_WEAPON,				//1//����
			ITEM_TYPE_ARMOR,				//2//����
			ITEM_TYPE_USE,					//3//������ ���
			ITEM_TYPE_AUTOUSE,				//4
			ITEM_TYPE_MATERIAL,				//5
			ITEM_TYPE_SPECIAL,				//6 //����� ������
			ITEM_TYPE_TOOL,					//7
			ITEM_TYPE_LOTTERY,				//8//����
			ITEM_TYPE_ELK,					//9//��
			ITEM_TYPE_METIN,				//10
			ITEM_TYPE_CONTAINER,			//11
			ITEM_TYPE_FISH,					//12//����
			ITEM_TYPE_ROD,					//13
			ITEM_TYPE_RESOURCE,				//14
			ITEM_TYPE_CAMPFIRE,				//15
			ITEM_TYPE_UNIQUE,				//16
			ITEM_TYPE_SKILLBOOK,			//17
			ITEM_TYPE_QUEST,				//18
			ITEM_TYPE_POLYMORPH,			//19
			ITEM_TYPE_TREASURE_BOX,			//20//��������
			ITEM_TYPE_TREASURE_KEY,			//21//�������� ����
			ITEM_TYPE_SKILLFORGET,			//22
			ITEM_TYPE_GIFTBOX,				//23
			ITEM_TYPE_PICK,					//24
			ITEM_TYPE_HAIR,					//25//�Ӹ�
			ITEM_TYPE_TOTEM,				//26//����
			ITEM_TYPE_BLEND,				//27//�����ɶ� �����ϰ� �Ӽ��� �ٴ� �๰
			ITEM_TYPE_COSTUME,				//28//�ڽ��� ������ (2011�� 8�� �߰��� �ڽ��� �ý��ۿ� ������)
			ITEM_TYPE_DS,					//29 //��ȥ��
			ITEM_TYPE_SPECIAL_DS,			//30 // Ư���� ��ȥ�� (DS_SLOT�� �����ϴ� UNIQUE �������̶� �����ϸ� ��)
			ITEM_TYPE_EXTRACT,					//31 ���⵵��.
			ITEM_TYPE_SECONDARY_COIN,			//32 ����.
			ITEM_TYPE_RING,						//33 ���� (����ũ ������ �ƴ� ���� ���� ����)
			ITEM_TYPE_BELT,						//34 ��Ʈ

			ITEM_PET,				//35
			ITEM_MEDIUM,			//36
			ITEM_GACHA,				//37
			ITEM_SOUL,				//38

			ITEM_TYPE_MAX_NUM,				
		};

		enum EWeaponSubTypes
		{
			WEAPON_SWORD,
			WEAPON_DAGGER,	//�̵���
			WEAPON_BOW,
			WEAPON_TWO_HANDED,
			WEAPON_BELL,
			WEAPON_FAN,
			WEAPON_ARROW,

			WEAPON_MOUNT_SPEAR,
			WEAPON_CLAW,
			WEAPON_QUIVER,
			WEAPON_BOUQUET,			// 10

			WEAPON_NUM_TYPES,

			WEAPON_NONE = WEAPON_NUM_TYPES+1,
		};

		enum EMaterialSubTypes
		{
			MATERIAL_LEATHER,
			MATERIAL_BLOOD,
			MATERIAL_ROOT,
			MATERIAL_NEEDLE,
			MATERIAL_JEWEL,
			MATERIAL_DS_REFINE_NORMAL, 
			MATERIAL_DS_REFINE_BLESSED, 
			MATERIAL_DS_REFINE_HOLLY,
			MATERIAL_DS_CHANGE_ATTR,
		};

		enum EQuestSubTypes
		{
			QUEST_NONE,
			QUEST_PET_PAY,
		};

		enum EArmorSubTypes
		{
			ARMOR_BODY,
			ARMOR_HEAD,
			ARMOR_SHIELD,
			ARMOR_WRIST,
			ARMOR_FOOTS,
		    ARMOR_NECK,
			ARMOR_EAR,
			ARMOR_PENDANT,
			ARMOR_NUM_TYPES
		};

		enum ECostumeSubTypes
		{
			COSTUME_BODY,				//0	����(main look)
			COSTUME_HAIR,				//1	���(Ż������)
			COSTUME_MOUNT,
			COSTUME_ACCE,
			COSTUME_WEAPON,
			COSTUME_AURA,
			COSTUME_NUM_TYPES,
		};

		enum EUseSubTypes
		{
			USE_POTION,					// 0
			USE_TALISMAN,
			USE_TUNING,
			USE_MOVE,
			USE_TREASURE_BOX,
			USE_MONEYBAG,
			USE_BAIT,
			USE_ABILITY_UP,
			USE_AFFECT,
			USE_CREATE_STONE,
			USE_SPECIAL,				// 10
			USE_POTION_NODELAY,
			USE_CLEAR,
			USE_INVISIBILITY,
			USE_DETACHMENT,
			USE_BUCKET,
			USE_POTION_CONTINUE,
			USE_CLEAN_SOCKET,
			USE_CHANGE_ATTRIBUTE,
			USE_ADD_ATTRIBUTE,
			USE_ADD_ACCESSORY_SOCKET,	// 20
			USE_PUT_INTO_ACCESSORY_SOCKET,
			USE_ADD_ATTRIBUTE2,
			USE_RECIPE,
			USE_CHANGE_ATTRIBUTE2,
			USE_BIND,
			USE_UNBIND,
			USE_TIME_CHARGE_PER,
			USE_TIME_CHARGE_FIX,				// 28
			USE_PUT_INTO_BELT_SOCKET,			// 29 ��Ʈ ���Ͽ� ����� �� �ִ� ������ 
			USE_PUT_INTO_RING_SOCKET,			// 30 ���� ���Ͽ� ����� �� �ִ� ������ (����ũ ���� ����, ���� �߰��� ���� ����)

			USE_CHANGE_COSTUME_ATTR,			// 31
			USE_RESET_COSTUME_ATTR,				// 32

			USE_SELECT_ATTRIBUTE = 34,			// 34
			USE_FLOWER,							// 35
			USE_EMOTION_PACK,					// 36

			USE_ELEMENT_UPGRADE,				// 37
			USE_ELEMENT_DOWNGRADE,				// 38
			USE_ELEMENT_CHANGE,					// 39

			USE_UNK40,						// 40
		};

		enum EDragonSoulSubType
		{
			DS_SLOT1,
			DS_SLOT2,
			DS_SLOT3,
			DS_SLOT4,
			DS_SLOT5,
			DS_SLOT6,
			DS_SLOT_NUM_TYPES = 6,
		};

		enum EMetinSubTypes
		{
			METIN_NORMAL,
			METIN_GOLD,
		};


		enum EPetSubTypes
		{
			PET_EGG,
			PET_UPBRINGING,
			PET_BAG,
			PET_FEEDSTUFF,
			PET_SKILL,
			PET_SKILL_DEL_BOOK,
			PET_NAME_CHANGE,
			PET_EXPFOOD,
			PET_SKILL_ALL_DEL_BOOK,
			PET_EXPFOOD_PER,
			PET_ATTR_DETERMINE,
			PET_ATTR_CHANGE,
			PET_PAY,
			PET_PRIMIUM_FEEDSTUFF,
		};

		enum EMediumSubTypes
		{
			MEDIUM_MOVE_COSTUME_ATTR,
			MEDIUM_MOVE_ACCE_ATTR,
		};

		enum EGachaSubTypes
		{
			USE_GACHA,
			GEM_LUCKY_BOX_GACHA,
			SPECIAL_LUCKY_BOX_GACHA,
		};

		enum ESoulSubTypes
		{
			SOUL_RED,
			SOUL_BLUE,
		};

		enum EItemMaskTypes
		{
			MASK_ITEM_NONE,
			MASK_ITEM_MOUNT_PET,
			MASK_ITEM_EQUIPMENT_WEAPON,
			MASK_ITEM_EQUIPMENT_ARMOR,
			MASK_ITEM_EQUIPMENT_JEWELRY,
			MASK_ITEM_TUNING,
			MASK_ITEM_POTION,
			MASK_ITEM_FISHING_PICK,
			MASK_ITEM_DRAGON_STONE,
			MASK_ITEM_COSTUMES,
			MASK_ITEM_SKILL,
			MASK_ITEM_UNIQUE,
			MASK_ITEM_ETC,
		};

		enum EMountPetMaskSubTypes
		{
			MASK_MOUNT_PET_MOUNT,
			MASK_MOUNT_PET_CHARGED_PET,
			MASK_MOUNT_PET_FREE_PET,
			MASK_MOUNT_PET_EGG,
		};

		enum EWeaponMaskTypes
		{
			MASK_EQUIPMENT_WEAPON_SWORD,
			MASK_EQUIPMENT_WEAPON_DAGGER,
			MASK_EQUIPMENT_WEAPON_BOW,
			MASK_EQUIPMENT_WEAPON_TWO_HANDED,
			MASK_EQUIPMENT_WEAPON_BELL,
			MASK_EQUIPMENT_WEAPON_CLAW,
			MASK_EQUIPMENT_WEAPON_FAN,
			MASK_EQUIPMENT_WEAPON_MOUNT_SPEAR,
			MASK_EQUIPMENT_WEAPON_ARROW,
		};

		enum EArmorMaskSubTypes
		{
			MASK_EQUIPMENT_ARMOR_BODY,
			MASK_EQUIPMENT_ARMOR_HEAD,
			MASK_EQUIPMENT_ARMOR_SHIELD,
		};

		enum EJewelryMaskSubTypes
		{
			MASK_EQUIPMENT_JEWELRY_ARMOR_WRIST,
			MASK_EQUIPMENT_JEWELRY_ARMOR_FOOTS,
			MASK_EQUIPMENT_JEWELRY_ARMOR_NECK,
			MASK_EQUIPMENT_JEWELRY_ARMOR_EAR,
			MASK_EQUIPMENT_JEWELRY_ITEM_BELT,
			MASK_EQUIPMENT_JEWELRY_ARMOR_PENDANT,
		};

		enum ETuningMaskSubTypes
		{
			MASK_TUNING_RESOURCE,
			MASK_TUNING_STONE,
			MASK_TUNING_ETC,
		};

		enum EPotionMaskSubTypes
		{
			MASK_POTION_ABILITY,
			MASK_POTION_HAIRDYE,
			MASK_POTION_ETC,
		};

		enum EFishMaskSubTypes
		{
			MASK_FISHING_PICK_FISHING_POLE,
			MASK_FISHING_PICK_EQUIPMENT_PICK,
			MASK_FISHING_PICK_FOOD,
			MASK_FISHING_PICK_STONE,
			MASK_FISHING_PICK_ETC,
		};

		enum EDragonSoulMaskSubTypes
		{
			MASK_DRAGON_STONE_DRAGON_DIAMOND,
			MASK_DRAGON_STONE_DRAGON_RUBY,
			MASK_DRAGON_STONE_DRAGON_JADE,
			MASK_DRAGON_STONE_DRAGON_SAPPHIRE,
			MASK_DRAGON_STONE_DRAGON_GARNET,
			MASK_DRAGON_STONE_DRAGON_ONYX,
			MASK_DRAGON_STONE_ETC,
		};

		enum ECostumeMaskSubTypes
		{
			MASK_COSTUMES_COSTUME_WEAPON,
			MASK_COSTUMES_COSTUME_BODY,
			MASK_COSTUMES_COSTUME_HAIR,
			MASK_COSTUMES_SASH,
			MASK_COSTUMES_AURA,
			MASK_COSTUMES_ETC,
		};

		enum ESkillbookMaskSubTypes
		{
			MASK_SKILL_PAHAE,
			MASK_SKILL_SKILL_BOOK,
			MASK_SKILL_BOOK_OF_OBLIVION,
			MASK_SKILL_ETC,
		};

		enum EUniqueMaskSubTypes
		{
			MASK_UNIQUE_ABILITY,
			MASK_UNIQUE_ETC,
		};

		enum EETcMaskSubTypes
		{
			MASK_ETC_GIFTBOX,
			MASK_ETC_MATRIMORY,
			MASK_ETC_EVENT,
			MASK_ETC_SEAL,
			MASK_ETC_PARTI,
			MASK_ETC_POLYMORPH,
			MASK_ETC_RECIPE,
			MASK_ETC_ETC,
		};


		enum ELimitTypes
		{
			LIMIT_NONE,

			LIMIT_LEVEL,
			LIMIT_STR,
			LIMIT_DEX,
			LIMIT_INT,
			LIMIT_CON,
			LIMIT_PCBANG,

			/// ���� ���ο� ��� ���� �ǽð����� �ð� ���� (socket0�� �Ҹ� �ð��� ����: unix_timestamp Ÿ��)
			LIMIT_REAL_TIME,						

			/// �������� �� ó�� ���(Ȥ�� ����) �� �������� ����Ÿ�� Ÿ�̸� ���� 
			/// ���� ��� ������ socket0�� ��밡�ɽð�(�ʴ���, 0�̸� �������� limit value�� ���) ���� �����ִٰ� 
			/// ������ ���� socket1�� ��� Ƚ���� ������ socket0�� unix_timestamp Ÿ���� �Ҹ�ð��� ����.
			LIMIT_REAL_TIME_START_FIRST_USE,

			/// �������� ���� ���� ���� ��� �ð��� �����Ǵ� ������
			/// socket0�� ���� �ð��� �ʴ����� ����. (������ ���� ���� �ش� ���� 0�̸� �������� limit value���� socket0�� ����)
			LIMIT_TIMER_BASED_ON_WEAR,

			LIMIT_MAX_NUM
		};

		enum EItemAntiFlag
		{
			ITEM_ANTIFLAG_FEMALE        = (1 << 0),		// ���� ��� �Ұ�
			ITEM_ANTIFLAG_MALE          = (1 << 1),		// ���� ��� �Ұ�
			ITEM_ANTIFLAG_WARRIOR       = (1 << 2),		// ���� ��� �Ұ�
			ITEM_ANTIFLAG_ASSASSIN      = (1 << 3),		// �ڰ� ��� �Ұ�
			ITEM_ANTIFLAG_SURA          = (1 << 4),		// ���� ��� �Ұ� 
			ITEM_ANTIFLAG_SHAMAN        = (1 << 5),		// ���� ��� �Ұ�
			ITEM_ANTIFLAG_GET           = (1 << 6),		// ���� �� ����
			ITEM_ANTIFLAG_DROP          = (1 << 7),		// ���� �� ����
			ITEM_ANTIFLAG_SELL          = (1 << 8),		// �� �� ����
			ITEM_ANTIFLAG_EMPIRE_A      = (1 << 9),		// A ���� ��� �Ұ�
			ITEM_ANTIFLAG_EMPIRE_B      = (1 << 10),	// B ���� ��� �Ұ�
			ITEM_ANTIFLAG_EMPIRE_R      = (1 << 11),	// C ���� ��� �Ұ�
			ITEM_ANTIFLAG_SAVE          = (1 << 12),	// ������� ����
			ITEM_ANTIFLAG_GIVE          = (1 << 13),	// �ŷ� �Ұ�
			ITEM_ANTIFLAG_PKDROP        = (1 << 14),	// PK�� �������� ����
			ITEM_ANTIFLAG_STACK         = (1 << 15),	// ��ĥ �� ����
			ITEM_ANTIFLAG_MYSHOP        = (1 << 16),	// ���� ������ �ø� �� ����
			ITEM_ANTIFLAG_SAFEBOX		= (1 << 17), 
			ITEM_ANTIFLAG_WOLFMAN		= (1 << 18),
			ITEM_ANTIFLAG_PET			= (1 << 19),
			ITEM_ANTIFLAG_QUICKSLOT		= (1 << 20),
			ITEM_ANTIFLAG_CHANGELOOK	= (1 << 21),
			ITEM_ANTIFLAG_REINFORCE		= (1 << 22),
			ITEM_ANTIFLAG_ENCHANT		= (1 << 23),
			ITEM_ANTIFLAG_PETFEED		= (1 << 24),
			ITEM_ANTIFLAG_ENERGY		= (1 << 25),
			ITEM_ANTIFLAG_APPLY			= (1 << 26),
			ITEM_ANTIFLAG_ACCE			= (1 << 27),
			ITEM_ANTIFLAG_MAIL			= (1 << 28),
		};

		enum EItemFlag
		{
			ITEM_FLAG_REFINEABLE        = (1 << 0),		// ���� ����
			ITEM_FLAG_SAVE              = (1 << 1),
			ITEM_FLAG_STACKABLE         = (1 << 2),     // ������ ��ĥ �� ����
			ITEM_FLAG_COUNT_PER_1GOLD   = (1 << 3),		// ������ ���� / �������� ����
			ITEM_FLAG_SLOW_QUERY        = (1 << 4),		// ���� ����ÿ��� SQL�� ������
			ITEM_FLAG_RARE              = (1 << 5),
			ITEM_FLAG_UNIQUE            = (1 << 6),
			ITEM_FLAG_MAKECOUNT			= (1 << 7),
			ITEM_FLAG_IRREMOVABLE		= (1 << 8),
			ITEM_FLAG_CONFIRM_WHEN_USE	= (1 << 9),
			ITEM_FLAG_QUEST_USE         = (1 << 10),    // ����Ʈ ��ũ��Ʈ ��������?
			ITEM_FLAG_QUEST_USE_MULTIPLE= (1 << 11),    // ����Ʈ ��ũ��Ʈ ��������?
			ITEM_FLAG_UNUSED03          = (1 << 12),    // UNUSED03
			ITEM_FLAG_LOG               = (1 << 13),    // ���� �α׸� ����� �������ΰ�?
			ITEM_FLAG_APPLICABLE		= (1 << 14),
		};

		enum EWearPositions
		{
			WEAR_BODY,          // 0
			WEAR_HEAD,          // 1
			WEAR_FOOTS,         // 2
			WEAR_WRIST,         // 3
			WEAR_WEAPON,        // 4
			WEAR_NECK,          // 5
			WEAR_EAR,           // 6
			WEAR_UNIQUE1,       // 7
			WEAR_UNIQUE2,       // 8
			WEAR_ARROW,         // 9
			WEAR_SHIELD,        // 10
			WEAR_MAX_NUM,
		};

		enum EItemWearableFlag
		{
			WEARABLE_BODY       = (1 << 0),
			WEARABLE_HEAD       = (1 << 1),
			WEARABLE_FOOTS      = (1 << 2),
			WEARABLE_WRIST      = (1 << 3),
			WEARABLE_WEAPON     = (1 << 4),
			WEARABLE_NECK       = (1 << 5),
			WEARABLE_EAR        = (1 << 6),
			WEARABLE_UNIQUE     = (1 << 7),
			WEARABLE_SHIELD     = (1 << 8),
			WEARABLE_ARROW      = (1 << 9),
		};

		enum EApplyTypes
		{
			APPLY_NONE,                 // 0
			APPLY_MAX_HP,               // 1
			APPLY_MAX_SP,               // 2
			APPLY_CON,                  // 3
			APPLY_INT,                  // 4
			APPLY_STR,                  // 5
			APPLY_DEX,                  // 6
			APPLY_ATT_SPEED,            // 7
			APPLY_MOV_SPEED,            // 8
			APPLY_CAST_SPEED,           // 9
			APPLY_HP_REGEN,             // 10
			APPLY_SP_REGEN,             // 11
			APPLY_POISON_PCT,           // 12
			APPLY_STUN_PCT,             // 13
			APPLY_SLOW_PCT,             // 14
			APPLY_CRITICAL_PCT,         // 15
			APPLY_PENETRATE_PCT,        // 16
			APPLY_ATTBONUS_HUMAN,       // 17
			APPLY_ATTBONUS_ANIMAL,      // 18
			APPLY_ATTBONUS_ORC,         // 19
			APPLY_ATTBONUS_MILGYO,      // 20
			APPLY_ATTBONUS_UNDEAD,      // 21
			APPLY_ATTBONUS_DEVIL,       // 22
			APPLY_STEAL_HP,             // 23
			APPLY_STEAL_SP,             // 24
			APPLY_MANA_BURN_PCT,        // 25
			APPLY_DAMAGE_SP_RECOVER,    // 26
			APPLY_BLOCK,                // 27
			APPLY_DODGE,                // 28
			APPLY_RESIST_SWORD,         // 29
			APPLY_RESIST_TWOHAND,       // 30
			APPLY_RESIST_DAGGER,        // 31
			APPLY_RESIST_BELL,          // 32
			APPLY_RESIST_FAN,           // 33
			APPLY_RESIST_BOW,           // 34
			APPLY_RESIST_FIRE,          // 35
			APPLY_RESIST_ELEC,          // 36
			APPLY_RESIST_MAGIC,         // 37
			APPLY_RESIST_WIND,          // 38
			APPLY_REFLECT_MELEE,        // 39
			APPLY_REFLECT_CURSE,        // 40
			APPLY_POISON_REDUCE,        // 41
			APPLY_KILL_SP_RECOVER,      // 42
			APPLY_EXP_DOUBLE_BONUS,     // 43
			APPLY_GOLD_DOUBLE_BONUS,    // 44
			APPLY_ITEM_DROP_BONUS,      // 45
			APPLY_POTION_BONUS,         // 46
			APPLY_KILL_HP_RECOVER,      // 47
			APPLY_IMMUNE_STUN,          // 48
			APPLY_IMMUNE_SLOW,          // 49
			APPLY_IMMUNE_FALL,          // 50
			APPLY_SKILL,                // 51
			APPLY_BOW_DISTANCE,         // 52
			APPLY_ATT_GRADE_BONUS,            // 53
			APPLY_DEF_GRADE_BONUS,            // 54
			APPLY_MAGIC_ATT_GRADE,      // 55
			APPLY_MAGIC_DEF_GRADE,      // 56
			APPLY_CURSE_PCT,            // 57
			APPLY_MAX_STAMINA,			// 58
			APPLY_ATT_BONUS_TO_WARRIOR, // 59
			APPLY_ATT_BONUS_TO_ASSASSIN,// 60
			APPLY_ATT_BONUS_TO_SURA,    // 61
			APPLY_ATT_BONUS_TO_SHAMAN,  // 62
			APPLY_ATT_BONUS_TO_MONSTER, // 63
			APPLY_MALL_ATTBONUS,        // 64 ���ݷ� +x%
			APPLY_MALL_DEFBONUS,        // 65 ���� +x%
			APPLY_MALL_EXPBONUS,        // 66 ����ġ +x%
			APPLY_MALL_ITEMBONUS,       // 67 ������ ����� x/10��
			APPLY_MALL_GOLDBONUS,       // 68 �� ����� x/10��
			APPLY_MAX_HP_PCT,           // 69 �ִ� ����� +x%
			APPLY_MAX_SP_PCT,           // 70 �ִ� ���ŷ� +x%
			APPLY_SKILL_DAMAGE_BONUS,   // 71 ��ų ������ * (100+x)%
			APPLY_NORMAL_HIT_DAMAGE_BONUS,      // 72 ��Ÿ ������ * (100+x)%
			APPLY_SKILL_DEFEND_BONUS,   // 73 ��ų ������ ��� * (100-x)%
			APPLY_NORMAL_HIT_DEFEND_BONUS,      // 74 ��Ÿ ������ ��� * (100-x)%
			APPLY_EXTRACT_HP_PCT,		//75
			APPLY_PC_BANG_EXP_BONUS,		//76
			APPLY_PC_BANG_DROP_BONUS,		//77
			APPLY_RESIST_WARRIOR,			//78
			APPLY_RESIST_ASSASSIN ,			//79
			APPLY_RESIST_SURA,				//80
			APPLY_RESIST_SHAMAN,			//81
			APPLY_ENERGY,					//82
			APPLY_DEF_GRADE,				// 83 ����. DEF_GRADE_BONUS�� Ŭ�󿡼� �ι�� �������� �ǵ��� ����(...)�� �ִ�.
			APPLY_COSTUME_ATTR_BONUS,		// 84 �ڽ�Ƭ �����ۿ� ���� �Ӽ�ġ ���ʽ�
			APPLY_MAGIC_ATTBONUS_PER,		// 85 ���� ���ݷ� +x%
			APPLY_MELEE_MAGIC_ATTBONUS_PER,			// 86 ���� + �и� ���ݷ� +x%
			
			APPLY_RESIST_ICE,		// 87 �ñ� ����
			APPLY_RESIST_EARTH,		// 88 ���� ����
			APPLY_RESIST_DARK,		// 89 ��� ����

			APPLY_ANTI_CRITICAL_PCT,	//90 ũ��Ƽ�� ����
			APPLY_ANTI_PENETRATE_PCT,	//91 ����Ÿ�� ����

			APPLY_BLEEDING_REDUCE,		//92
			APPLY_BLEEDING_PCT,			//93

			APPLY_ATTBONUS_WOLFMAN,		// 94
			APPLY_RESIST_WOLFMAN,		// 95
			APPLY_RESIST_CLAW,			// 96
			APPLY_ACCEDRAIN_RATE,		// 97
			APPLY_RESIST_MAGIC_REDUCTION,	// 98

			// ENCHANT
			APPLY_ENCHANT_ELECT, 		// 99
			APPLY_ENCHANT_FIRE,			// 100
			APPLY_ENCHANT_ICE,			// 101
			APPLY_ENCHANT_WIND,			// 102
			APPLY_ENCHANT_EARTH,		// 103
			APPLY_ENCHANT_DARK,			// 104

			APPLY_ATTBONUS_CZ,			// 105
			APPLY_ATTBONUS_INSECT,		// 106
			APPLY_ATTBONUS_DESERT,		// 107
			APPLY_ATTBONUS_SWORD,		// 108
			APPLY_ATTBONUS_TWOHAND,		// 109
			APPLY_ATTBONUS_DAGGER,		// 110
			APPLY_ATTBONUS_BELL,		// 111
			APPLY_ATTBONUS_FAN,			// 112
			APPLY_ATTBONUS_BOW,			// 113	
			APPLY_ATTBONUS_CLAW,		// 114

			APPLY_RESIST_HUMAN,			// 115
			APPLY_RESIST_MOUNT_FALL,	// 116

			APPLY_MOUNT = 118,			// 118

   			MAX_APPLY_NUM,              // 
		};

		enum EImmuneFlags
		{
			IMMUNE_PARA         = (1 << 0),
			IMMUNE_CURSE        = (1 << 1),
			IMMUNE_STUN         = (1 << 2),
			IMMUNE_SLEEP        = (1 << 3),
			IMMUNE_SLOW         = (1 << 4),
			IMMUNE_POISON       = (1 << 5),
			IMMUNE_TERROR       = (1 << 6),
		};

#pragma pack(push)
#pragma pack(1)
		typedef struct SItemLimit
		{
			BYTE        bType;
			long        lValue;
		} TItemLimit;

		typedef struct SItemApply
		{
			BYTE        bType;
			long        lValue;
		} TItemApply;

		typedef struct SItemTable
		{
			DWORD       dwVnum;
			DWORD       dwVnumRange;
			char        szName[ITEM_NAME_MAX_LEN + 1];
			char        szLocaleName[ITEM_NAME_MAX_LEN + 1];
			BYTE        bType;
			BYTE        bSubType;

			BYTE	bMaskedType;
			BYTE	bMaskedSubType;
			
			BYTE        bWeight;
			BYTE        bSize;
			
			DWORD       dwAntiFlags;
			DWORD       dwFlags;
			DWORD       dwWearFlags;
			DWORD       dwImmuneFlag;
						
			DWORD       dwIBuyItemPrice;			
			DWORD		dwISellItemPrice;
			
			TItemLimit  aLimits[ITEM_LIMIT_MAX_NUM];
			TItemApply  aApplies[ITEM_APPLY_MAX_NUM];
			long        alValues[ITEM_VALUES_MAX_NUM];
			long        alSockets[ITEM_SOCKET_MAX_NUM];
			DWORD       dwRefinedVnum;
			WORD		wRefineSet;

			DWORD dw67Material;

			BYTE        bAlterToMagicItemPct;
			BYTE		bSpecular;
			BYTE        bGainSocketPct;
		} TItemTable;
#pragma pack(pop)

	public:
		CItemData();
		virtual ~CItemData();

		void Clear();
		void SetSummary(const std::string& c_rstSumm);
		void SetDescription(const std::string& c_rstDesc);

		CGraphicThing * GetModelThing();
		CGraphicThing * GetSubModelThing();
		CGraphicThing * GetDropModelThing();
		CGraphicSubImage * GetIconImage();

		DWORD GetLODModelThingCount();
		BOOL GetLODModelThingPointer(DWORD dwIndex, CGraphicThing ** ppModelThing);

		DWORD GetAttachingDataCount();
		BOOL GetCollisionDataPointer(DWORD dwIndex, const NRaceData::TAttachingData ** c_ppAttachingData);
		BOOL GetAttachingDataPointer(DWORD dwIndex, const NRaceData::TAttachingData ** c_ppAttachingData);

		/////
		const TItemTable*	GetTable() const;
		DWORD GetIndex() const;
		const char * GetName() const;
		const char * GetDescription() const;
		const char * GetSummary() const;
		BYTE GetType() const;
		BYTE GetSubType() const;
		UINT GetRefine() const;
		const char* GetUseTypeString() const;
		DWORD GetWeaponType() const;
		BYTE GetSize() const;
		BOOL IsAntiFlag(DWORD dwFlag) const;
		BOOL IsFlag(DWORD dwFlag) const;
		BOOL IsWearableFlag(DWORD dwFlag) const;
		BOOL HasNextGrade() const;
		DWORD GetWearFlags() const;
		DWORD GetIBuyItemPrice() const;
		DWORD GetISellItemPrice() const;
		BOOL GetLimit(BYTE byIndex, TItemLimit * pItemLimit) const;
		BOOL GetApply(BYTE byIndex, TItemApply * pItemApply) const;
		long GetValue(BYTE byIndex) const;
		long GetSocket(BYTE byIndex) const;
		long SetSocket(BYTE byIndex,DWORD value);
		int GetSocketCount() const;
		DWORD GetIconNumber() const;

		UINT	GetSpecularPoweru() const;
		float	GetSpecularPowerf() const;
	
		/////

		BOOL IsEquipment() const;

		/////

		//BOOL LoadItemData(const char * c_szFileName);
		void SetDefaultItemData(const char * c_szIconFileName, const char * c_szModelFileName  = NULL);
		void SetItemTableData(TItemTable * pItemTable);

	protected:
		void __LoadFiles();
		void __SetIconImage(const char * c_szFileName);

	protected:
		std::string m_strModelFileName;
		std::string m_strSubModelFileName;
		std::string m_strDropModelFileName;
		std::string m_strIconFileName;
		std::string m_strDescription;
		std::string m_strSummary;
		std::vector<std::string> m_strLODModelFileNameVector;

		CGraphicThing * m_pModelThing;
		CGraphicThing * m_pSubModelThing;
		CGraphicThing * m_pDropModelThing;
		CGraphicSubImage * m_pIconImage;
		std::vector<CGraphicThing *> m_pLODModelThingVector;

		NRaceData::TAttachingDataVector m_AttachingDataVector;
		DWORD		m_dwVnum;
		TItemTable m_ItemTable;
		
	public:
		static void DestroySystem();

		static CItemData* New();
		static void Delete(CItemData* pkItemData);

		static CDynamicPool<CItemData>		ms_kPool;
};
