// functions and data for playable character types

#define PCS 4  // number of playable classes

typedef struct Player {
  char name[32];  // player name
  char role[16];  // player class choice
  char desc[256]; // class description
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
  int  xp;        // Experience points - used to gain levels
  int  lvl;       // player level, reflects relative power
  int  coin;      // money the player has earned
} pc;

pc player_classes[PCS] = {
  // Cleric
  {
    "Cleric",     // name
    "Cleric",     // role
    "Clerics are capable fighters, able to restore health, even during combat.",
    12,           // str       - strength
    12,           // dex       - dexterity
    14,           // con       - constitution
    10,           // intel     - intelligence
    16,           // wis       - wisdom
    14,           // cha       - charisma
    1,            // dmg       - innate damage bonus
    2,            // armor     - innate armor (defense) bonus
    6,            // max_hp    - max hp earned per level
    6,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
  },
  // Knight
  {
    "Knight",     // name
    "Knight",     // role
    "Knights are noble warriors, have the best armor and can smite their foes.",
    16,           // str       - strength
    12,           // dex       - dexterity
    16,           // con       - constitution
    10,           // intel     - intelligence
    14,           // wis       - wisdom
    14,           // cha       - charisma
    2,            // dmg       - innate damage bonus
    4,            // armor     - innate armor (defense) bonus
    8,            // max_hp    - max hp earned per level
    8,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
  },
  // Rogue
  {
    "Rogue",     // name
    "Rogue",     // role
    "Rogues are skilled combatants and have bonuses to coin, dodge, & evasion.",
    14,           // str       - strength
    16,           // dex       - dexterity
    12,           // con       - constitution
    14,           // intel     - intelligence
    12,           // wis       - wisdom
    14,           // cha       - charisma
    3,            // dmg       - innate damage bonus
    1,            // armor     - innate armor (defense) bonus
    6,            // max_hp    - max hp earned per level
    6,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    5,            // coin      - money
  },
  // Wizard
  {
    "Wizard",     // name
    "Wizard",     // role
    "Wizards can cast damaging spells and have a pet familiar.",
    8,            // str       - strength
    12,           // dex       - dexterity
    12,           // con       - constitution
    16,           // intel     - intelligence
    12,           // wis       - wisdom
    12,           // cha       - charisma
    0,            // dmg       - innate damage bonus
    0,            // armor     - innate armor (defense) bonus
    4,            // max_hp    - max hp earned per level
    4,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    16,           // max_mana  - max mana per level
    16,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
  }
};

char *class_list[PCS] = {"Cleric", "Knight", "Rogue", "Wizard"};
