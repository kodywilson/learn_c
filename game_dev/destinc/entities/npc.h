// functions and data for non playable character types

#define MOBS 6     // number of mobs - change to monsters or something for now mobs and bosses
#define BOSS 4     // number of boss type mobs

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
    4,            // modifier to chance to hit
    4,            // damage dice - 4 for rat
    1,            // number of damage dice. 1 for rat, so rat can do 1d4 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    1,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    3             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Kobold
  {
    "kobold",     // name
    "kobold",     // role
    "A tiny kobold jumps out of the darkness and attacks!",
    7,            // str       - strength
    15,           // dex       - dexterity
    9,            // con       - constitution
    8,            // intel     - intelligence
    7,            // wis       - wisdom
    8,            // cha       - charisma
    2,            // dmg       - innate damage bonus
    2,            // armor     - innate armor (defense) bonus
    6,            // max_hp    - max hp earned per level
    6,            // cur_hp    - current hp
    1,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    25,           // xp        - experience points
    1,            // level     - current level
    1,            // coin      - money
    4,            // modifier to chance to hit
    4,            // damage dice - 4 for kobold
    1,            // number of damage dice. 1 for kobold, so kobold can do 1d4 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Skeleton
  {
    "skeleton",     // name
    "skeleton",     // role
    "You hear a clattering sound and see a skeleton approaching!",
    10,           // str       - strength
    14,           // dex       - dexterity
    15,           // con       - constitution
    6,            // intel     - intelligence
    8,            // wis       - wisdom
    5,            // cha       - charisma
    2,            // dmg       - innate damage bonus
    3,            // armor     - armor class - AC (defense) - armor scraps
    13,           // max_hp    - max hp earned per level
    13,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    50,           // xp        - experience points
    1,            // level     - current level
    2,            // coin      - money
    4,            // modifier to chance to hit
    6,            // damage dice - 6 for skeleton
    1,            // number of damage dice. 1 for skeleton, so skeleton can do 1d6 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    2,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Bandit
  {
    "bandit",     // name
    "bandit",     // role
    "A filthy bandit grins and moves toward you.",
    11,           // str       - strength
    12,           // dex       - dexterity
    12,           // con       - constitution
    10,           // intel     - intelligence
    10,           // wis       - wisdom
    10,           // cha       - charisma
    1,            // dmg       - innate damage bonus // see notes above, need to add more stats - this guy will be rough in the meantime
    2,            // armor     - armor class - AC (defense) - hide armor + shield               - could make him a boss...
    11,           // max_hp    - max hp earned per level
    11,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    25,           // xp        - experience points
    1,            // level     - current level
    1,            // coin      - money
    3,            // modifier to chance to hit
    6,            // damage dice - 8 for bandit
    1,            // number of damage dice. 1 for bandit, so bandit can do 1d6 +1 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Goblin
  {
    "goblin",     // name
    "goblin",     // role
    "A muttering goblin looks up and heads toward you.",
    8,            // str       - strength
    14,           // dex       - dexterity
    10,           // con       - constitution
    10,           // intel     - intelligence
    8,            // wis       - wisdom
    8,            // cha       - charisma
    2,            // dmg       - innate damage bonus // see notes above, need to add more stats - this guy will be rough in the meantime
    5,            // armor     - armor class - AC (defense) - hide armor + shield               - could make him a boss...
    7,            // max_hp    - max hp earned per level
    7,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    50,           // xp        - experience points
    1,            // level     - current level
    2,            // coin      - money
    4,            // modifier to chance to hit
    6,            // damage dice - 8 for goblin
    1,            // number of damage dice. 2 for goblin, so goblin can do 1d6 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Zombie
  {
    "zombie",     // name
    "zombie",     // role
    "You see a rotting zombie shuffling toward you.",
    13,           // str       - strength
    6,            // dex       - dexterity
    16,           // con       - constitution
    3,            // intel     - intelligence
    6,            // wis       - wisdom
    5,            // cha       - charisma
    1,            // dmg       - innate damage bonus // see notes above, need to add more stats - this guy will be rough in the meantime
    -2,           // armor     - armor class - AC (defense) - hide armor + shield               - could make him a boss...
    22,           // max_hp    - max hp earned per level
    22,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    50,           // xp        - experience points
    1,            // level     - current level
    2,            // coin      - money
    3,            // modifier to chance to hit
    6,            // damage dice - 6 for zombie
    1,            // number of damage dice. 2 for zombie, so zombie can do 2d8 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  }               // 3 = true neutral, 4 = chaotic good
};

mob bosses[BOSS] = {
  // orc
  {
    "orc",     // name
    "orc",     // role
    "You smell something terrible and then see an orc approaching.",
    16,           // str       - strength
    12,           // dex       - dexterity
    16,           // con       - constitution
    7,            // intel     - intelligence
    11,           // wis       - wisdom
    10,           // cha       - charisma
    3,            // dmg       - innate damage bonus - should be used for mobs only probably - need to add "to hit" and pass monsters damage dice
    3,            // armor     - innate armor (defense) bonus                                - store it like 1d4, better than hard coding values
    15,           // max_hp    - max hp earned per level
    15,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    4,            // max_mana  - max mana per level
    4,            // cur_mana  - current mana
    100,          // xp        - experience points
    1,            // level     - current level
    4,            // coin      - money
    5,            // modifier to chance to hit
    12,           // damage dice - 12 for orc
    1,            // number of damage dice. 1 for orc, so orc can do 1d12 +3 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    1,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    6             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Hobgoblin
  {
    "hobgoblin",     // name
    "hobgoblin",     // role
    "A toadish hobgoblin races toward you!",
    13,           // str       - strength
    12,           // dex       - dexterity
    12,           // con       - constitution
    10,           // intel     - intelligence
    10,           // wis       - wisdom
    9,            // cha       - charisma
    1,            // dmg       - innate damage bonus
    8,            // armor     - innate armor (defense) bonus
    11,           // max_hp    - max hp earned per level
    11,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    100,          // xp        - experience points
    1,            // level     - current level
    4,            // coin      - money
    3,            // modifier to chance to hit
    8,            // damage dice - 8 for hobgoblin
    1,            // number of damage dice. 1 for hobgoblin, so hobgoblin can do 1d8 +1 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Gnoll
  {
    "gnoll",     // name
    "gnoll",     // role
    "You hear a barking sound and see a gnoll emerge from the darkness!",
    14,           // str       - strength
    12,           // dex       - dexterity
    11,           // con       - constitution
    6,            // intel     - intelligence
    10,           // wis       - wisdom
    7,            // cha       - charisma
    2,            // dmg       - innate damage bonus
    5,            // armor     - armor class - AC (defense) - armor scraps
    22,           // max_hp    - max hp earned per level
    22,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    100,          // xp        - experience points
    1,            // level     - current level
    4,            // coin      - money
    4,            // modifier to chance to hit
    6,            // damage dice - 6 for gnoll
    1,            // number of damage dice. 1 for gnoll, so gnoll can do 1d6 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    6             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  },               // 3 = true neutral, 4 = chaotic good
  // Bugbear -- this guy is way too tough, needs to be moved to boss section
  {
    "bugbear",     // name
    "bugbear",     // role
    "A large bugbear bursts into the room and strides toward you!",
    15,           // str       - strength
    14,           // dex       - dexterity
    13,           // con       - constitution
    8,            // intel     - intelligence
    11,           // wis       - wisdom
    9,            // cha       - charisma
    2,            // dmg       - innate damage bonus // see notes above, need to add more stats - this guy will be rough in the meantime
    6,            // armor     - armor class - AC (defense) - hide armor + shield               - could make him a boss...
    27,           // max_hp    - max hp earned per level
    27,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    200,          // xp        - experience points
    1,            // level     - current level
    5,            // coin      - money
    4,            // modifier to chance to hit
    8,            // damage dice - 8 for bugbear
    2,            // number of damage dice. 2 for bugbear, so bugbear can do 2d8 +2 (from dmg) damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
  }               // 3 = true neutral, 4 = chaotic good
};
