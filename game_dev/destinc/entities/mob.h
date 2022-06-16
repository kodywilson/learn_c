// functions and data for all character types (mobs)

#define MAX_BUFFS 4
#define WORN_SLOTS 3
#define BAG_SLOTS 20

// shared struct for all mobs, pc and npc
typedef struct Mob {
  char name[32];      // mob name
  char role[16];      // mob class
  char desc[256];     // mob description
  int  str;           // --= Begin basic stat block
  int  dex;
  int  con;
  int  intel;
  int  wis;
  int  cha;           // End basic stat block =--
  int  dmg;           // innate damage bonus - mostly used for monsters
  int  armor;         // armor - AC - only used for npcs
  int  hit_die;       // how many HP you get per level
  int  hit_die_num;   // how many Hit Dice you have - for players, will equal level
  int  max_hp;        // max hit points (hp) per level - class specific + Con bonus
  int  cur_hp;        // current hit points
  int  dodge;         // class specific bonus to dodge -- may drop this at some point
  int  max_mana;      // max mana per level for spells and special attacks
  int  cur_mana;      // current mana
  int  xp;            // Experience points - earned when mob is defeated or amount a player has
  int  lvl;           // mob level, reflects relative power
  int  coin;          // money the player earns when mob is defeated or the amount a player has
  int  to_hit;        // modifier to chance to hit
  int  dice_dam;      // damage dice. 6 for 1d6, 12 for 1d12, etc.  -- used with dice_num (1d6) = (dice_num x dice_dam)
  int  dice_num;      // number of damage dice. 2 for 2d6, 1 for 1d8, etc. -- used with dice_dam
  int  is_pc;         // is this a player character? combat calculations vary a bit so we need to know
  int  type;          // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
  int  alignment;     // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  float chal_rate;    // challenge rating. Not really relevant for players, but very much so for monsters...
  time_t date_time;   // store datetime - use to track saves + later could be used for mob spawns
  int  buffs[MAX_BUFFS];       // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
  item worn_items[WORN_SLOTS]; // gear currently equipped - 0 = armor, 1 = main hand, 2  off hand (shield, etc.)
  item backpack[BAG_SLOTS];    // items in your backpack
} mob;
