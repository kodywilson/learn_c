// functions and data for playable character types

#define PCS 4  // number of playable classes

pc player_classes[PCS] = {
  // Cleric
  {
    "Cleric",     // name
    "Cleric",     // role
    "Clerics are capable fighters, able to restore health, even during combat.",
    12,           // str       - strength
    10,           // dex       - dexterity
    14,           // con       - constitution
    10,           // intel     - intelligence
    16,           // wis       - wisdom
    14,           // cha       - charisma
    8,            // hit_die   - how many HP you get per level
    1,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
    10,           // max_hp    - max hp earned per level (1d8 + Con modifier)
    10,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    3000,            // xp        - experience points
    1,            // level     - current level
    3000,          // coin      - money
    2,            // proficiency bonus
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    0,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    0,            // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
  // Paladin (LoH at lvl 1, smite at lvl 2)
  {
    "Paladin",     // name
    "Paladin",     // role
    "Paladins are noble warriors, have access to the best armor and can smite their foes.",
    16,           // str       - strength
    10,           // dex       - dexterity
    16,           // con       - constitution
    10,           // intel     - intelligence
    14,           // wis       - wisdom
    14,           // cha       - charisma
    10,           // hit die   - how many HP you get per level
    1,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
    13,           // max_hp    - max hp earned per level (1d10 + Con modifier)
    13,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3000,         // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    0,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    0,            // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
  // Rogue
  {
    "Rogue",     // name
    "Rogue",     // role
    "Rogues are skilled combatants and have bonuses to coin, dodge, & evasion.",
    14,           // str       - strength
    16,           // dex       - dexterity       - also adds to AC
    12,           // con       - constitution
    14,           // intel     - intelligence
    12,           // wis       - wisdom
    14,           // cha       - charisma
    8,            // hit die   - how many HP you get per level
    1,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
    9,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    9,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge   - might drop this at some point
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    200,          // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    4,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    0,            // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
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
    6,            // hit die   - how many HP you get per level
    1,            // hit_die_num  - how many Hit Dice (for players, will equal lvl)
    7,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    7,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    16,           // max_mana  - max mana per level
    16,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    3,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    0,            // store datetime - use to track saves + later could be used for mob spawns
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {},           // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  }
};

char *class_list[PCS] = {"Cleric", "Paladin", "Rogue", "Wizard"};
