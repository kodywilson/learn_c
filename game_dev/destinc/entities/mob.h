// functions and data for all character types (mobs)

#define MAX_BUFFS 4

// shared struct for all mobs, pc and npc
typedef struct Mob {
  char name[32];  // mob name
  char role[16];  // mob class
  char desc[256]; // mob description
  int  str;       // --= Begin basic stat block
  int  dex;
  int  con;
  int  intel;
  int  wis;
  int  cha;       // End basic stat block =--
  int  dmg;       // innate damage bonus - mostly used for monsters
  int  armor;     // armor - AC - until we get equipment, it is armor and shield (if any)
  int  max_hp;    // max hit points (hp) per level - class specific + Con bonus
  int  cur_hp;    // current hit points
  int  dodge;     // class specific bonus to dodge -- may drop this at some point
  int  max_mana;  // max mana per level for spells and special attacks
  int  cur_mana;  // current mana
  int  xp;        // Experience points - earned when mob is defeated or amount a player has
  int  lvl;       // mob level, reflects relative power
  int  coin;      // money the player earns when mob is defeated or the amount a player has
  int  to_hit;    // modifier to chance to hit
  int  dice_dam;  // damage dice. 6 for 1d6, 12 for 1d12, etc.  -- used with dice_num (1d6) = (dice_num x dice_dam)
  int  dice_num;  // number of damage dice. 2 for 2d6, 1 for 1d8, etc. -- used with dice_dam
  int  buffs[MAX_BUFFS];  // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
} mob;
