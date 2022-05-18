// functions and data for all character types (mobs)

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
  int  dmg;       // class specific damage bonus
  int  armor;     // class specific armor bonus
  int  max_hp;    // max hit points (hp) per level
  int  cur_hp;    // current hit points
  int  dodge;     // class specific bonus to dodge
  int  max_mana;  // max mana per level for spells and special attacks
  int  cur_mana;  // current mana
  int  xp;        // Experience points - earned when mob is defeated or amount a player has
  int  lvl;       // mob level, reflects relative power
  int  coin;      // money the player earns when mob is defeated or the amount a player has
} mob;
