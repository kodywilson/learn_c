// functions and data for non playable character types

#define MOBS 6     // number of mobs - change to monsters or something for now mobs and bosses
#define BOSS 4     // number of boss type mobs

mob mobs[MOBS] = {
  // Rat - giant
  {
    "giant rat",     // name
    "giant rat",     // role
    "A large, smelly rat shrieks and races toward you!",
    7,            // str       - strength
    15,           // dex       - dexterity
    11,           // con       - constitution
    2,            // intel     - intelligence
    10,           // wis       - wisdom
    4,            // cha       - charisma
    2,            // dmg       - innate damage bonus - should be used for mobs only probably - need to add "to hit" and pass monsters damage dice
    2,            // armor     - innate armor (defense) bonus                                - store it like 1d4, better than hard coding values
    6,            // hit die   - how many HP you get per level - giant rat: 2d6
    2,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    1,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    3,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .125,         // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    5,            // hit die   - how many HP you get per level
    2,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .125,         // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    4,            // hit die   - how many HP you get per level - skeleton: 2d8+4
    5,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    2,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .25,          // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    1,            // dmg       - innate damage bonus
    2,            // armor     - armor class - AC (defense) - studded leather
    4,            // hit die   - how many HP you get per level
    4,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .25,          // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    2,            // dmg       - innate damage bonus
    5,            // armor     - armor class - AC (defense) - leather armor and shield
    6,            // hit die   - how many HP you get per level
    2,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .25,          // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
  // Zombie // later, add Zombie's Undead Fortitude ability!
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
    1,            // dmg       - innate damage bonus
    -2,           // armor     - armor class - AC (defense)
    3,            // hit die   - how many HP you get per level - zombie has 3d8+9
    11,           // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    5,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .25,          // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  }
};

// some notes on monsters
// Later, we will need to sort by CR most likely to make this more dynamic
// then you can randomly choose from within a CR range.
// Also, named bosses are needed for each level of the dungeon to proceed to the next level...
// monster hit points are normally dice rolls plus bonuses. I have adjusted the rolls to roughly
// fit what you would get taking the bonuses into account. (ie. 2d8+4 becomes 5d4, etc.)

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
    3,            // hit die   - how many HP you get per level - orc: 2d8+6
    8,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    1,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    6,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .5,           // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    5,            // hit die   - how many HP you get per level - hobgoblin: 2d8+2
    4,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .5,           // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
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
    8,            // hit die   - how many HP you get per level - gnoll: 5d8
    5,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    6,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    .5,           // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
  // Bugbear // toughest of the random bosses
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
    5,            // hit die   - how many HP you get per level - bugbear: 5d8+5
    9,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
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
    0,            // is this a player character? combat calculations vary a bit so we need to know
    3,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    2,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    1.0,          // challenge rating. Not really relevant for players, but very much so for monsters...
    {},           // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  }
};
