// functions and data for non playable character types

#define MOBS 4     // number of mobs

// this should be consolidated to be a shared struct between both pc and npc since they
// really use the same stats, etc.
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
  int  xp;        // Experience points - earned when defeated
  int  lvl;       // mob level, reflects relative power
  int  coin;      // money the player earns when mob is defeated
} mob;

pc mobs[MOBS] = {
  // Rat
  {
    "rat",     // name
    "rat",     // role
    "A smelly rat shrieks and races toward you!",
    10,           // str       - strength
    14,           // dex       - dexterity
    12,           // con       - constitution
    10,           // intel     - intelligence
    10,           // wis       - wisdom
    10,           // cha       - charisma
    0,            // dmg       - innate damage bonus
    0,            // armor     - innate armor (defense) bonus
    4,            // max_hp    - max hp earned per level
    4,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge
    4,            // max_mana  - max mana per level
    4,            // cur_mana  - current mana
    10,           // xp        - experience points
    1,            // level     - current level
    1,            // coin      - money
  },
  // Kobold
  {
    "Kobold",     // name
    "Kobold",     // role
    "A tiny kobold jumps out the darkness and attacks!",
    12,           // str       - strength
    12,           // dex       - dexterity
    12,           // con       - constitution
    10,           // intel     - intelligence
    10,           // wis       - wisdom
    10,           // cha       - charisma
    1,            // dmg       - innate damage bonus
    1,            // armor     - innate armor (defense) bonus
    6,            // max_hp    - max hp earned per level
    6,            // cur_hp    - current hp
    1,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    20,            // xp        - experience points
    1,            // level     - current level
    2,            // coin      - money
  },
  // Skeleton
  {
    "Skeleton",     // name
    "Skeleton",     // role
    "You hear a clattering sound and see a skeleton approaching!",
    14,           // str       - strength
    10,           // dex       - dexterity
    12,           // con       - constitution
    10,           // intel     - intelligence
    10,           // wis       - wisdom
    10,           // cha       - charisma
    2,            // dmg       - innate damage bonus
    2,            // armor     - innate armor (defense) bonus
    8,            // max_hp    - max hp earned per level
    8,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    30,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
  },
  // Bugbear
  {
    "Bugbear",     // name
    "Bugbear",     // role
    "A large bugbear bursts into the room and strides toward you!",
    10,           // str       - strength   // change from 14 for testing
    12,           // dex       - dexterity
    12,           // con       - constitution
    12,           // intel     - intelligence
    12,           // wis       - wisdom
    12,           // cha       - charisma
    0,            // dmg       - innate damage bonus // change from 3 for testing
    2,            // armor     - innate armor (defense) bonus
    20,            // max_hp    - max hp earned per level   //change from 9 for testing
    20,            // cur_hp    - current hp                // change from 9 for testing
    1,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    50,            // xp        - experience points
    1,            // level     - current level
    4,            // coin      - money
  }
};

//char *class_list[PCS] = {"Cleric", "Knight", "Rogue", "Wizard"};

