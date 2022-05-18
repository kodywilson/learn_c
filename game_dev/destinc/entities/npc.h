// functions and data for non playable character types

#define MOBS 4     // number of mobs - change to monsters or something for now mobs and bosses

mob mobs[MOBS] = {
  // Rat - giant
  {
    "rat",     // name
    "rat",     // role
    "A smelly rat shrieks and races toward you!",
    7,            // str       - strength
    15,           // dex       - dexterity
    11,           // con       - constitution
    2,            // intel     - intelligence
    10,           // wis       - wisdom
    4,            // cha       - charisma
    2,            // dmg       - innate damage bonus - should be used for mobs only probably - need to add "to hit" and pass monsters damage dice
    2,            // armor     - innate armor (defense) bonus                                - store it like 1d4, better than hard coding values
    7,            // max_hp    - max hp earned per level
    7,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge
    4,            // max_mana  - max mana per level
    4,            // cur_mana  - current mana
    25,           // xp        - experience points
    1,            // level     - current level
    1,            // coin      - money
  },
  // Kobold
  {
    "Kobold",     // name
    "Kobold",     // role
    "A tiny kobold jumps out of the darkness and attacks!",
    7,            // str       - strength
    15,           // dex       - dexterity
    9,            // con       - constitution
    8,            // intel     - intelligence
    7,            // wis       - wisdom
    8,            // cha       - charisma
    1,            // dmg       - innate damage bonus
    2,            // armor     - innate armor (defense) bonus
    6,            // max_hp    - max hp earned per level
    6,            // cur_hp    - current hp
    1,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    25,           // xp        - experience points
    1,            // level     - current level
    1,            // coin      - money
  },
  // Skeleton
  {
    "Skeleton",     // name
    "Skeleton",     // role
    "You hear a clattering sound and see a skeleton approaching!",
    10,           // str       - strength
    14,           // dex       - dexterity
    15,           // con       - constitution
    6,            // intel     - intelligence
    8,            // wis       - wisdom
    5,            // cha       - charisma
    3,            // dmg       - innate damage bonus
    3,            // armor     - armor class - AC (defense) - armor scraps
    13,           // max_hp    - max hp earned per level
    13,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    50,           // xp        - experience points
    1,            // level     - current level
    2,            // coin      - money
  },
  // Bugbear
  {
    "Bugbear",     // name
    "Bugbear",     // role
    "A large bugbear bursts into the room and strides toward you!",
    15,           // str       - strength
    14,           // dex       - dexterity
    13,           // con       - constitution
    8,            // intel     - intelligence
    11,           // wis       - wisdom
    9,            // cha       - charisma
    6,            // dmg       - innate damage bonus // see notes above, need to add more stats - this guy will be rough in the meantime
    16,           // armor     - armor class - AC (defense) - hide armor + shield               - could make him a boss...
    27,           // max_hp    - max hp earned per level
    27,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    200,          // xp        - experience points
    1,            // level     - current level
    4,            // coin      - money
  }
};

