// functions and data for playable character types

#define PCS 4  // number of playable classes

mob player_classes[PCS] = {
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
    0,            // dmg       - innate damage bonus (this is going to be more of a proficiency bonus)
    5,            // armor     - armor class - AC (defense) = Chain shirt + shield
    10,           // max_hp    - max hp earned per level (1d8 + Con modifier)
    10,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    12,           // max_mana  - max mana per level
    12,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    300,          // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    6,            // damage dice - 6 for mace
    1,            // number of damage dice. 1 for mace, so cleric can do 1d6 damage.
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    0,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {0},          // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  },
  // Knight
  {
    "Knight",     // name
    "Knight",     // role
    "Knights are noble warriors, have the best armor and can smite their foes.",
    16,           // str       - strength
    10,           // dex       - dexterity
    16,           // con       - constitution
    10,           // intel     - intelligence
    14,           // wis       - wisdom
    14,           // cha       - charisma
    0,            // dmg       - innate damage bonus -- May use this to tweak survivability
    6,            // armor     - armor (defense) - ring mail + shield
    13,           // max_hp    - max hp earned per level (1d10 + Con modifier)
    13,           // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    8,            // max_mana  - max mana per level
    8,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3000,         // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    8,            // damage dice - 8 for longsword
    1,            // number of damage dice. 1 for longsword, so knight can do 1d8 damage.
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    0,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {0},          // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
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
    1,            // dmg       - innate damage bonus
    1,            // armor     - armor (defense) - leather armor gives +1 AC
    9,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    9,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge   - might drop this at some point
    6,            // max_mana  - max mana per level
    6,            // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    200,          // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    8,            // damage dice - 8 for rapier
    1,            // number of damage dice. 1 for rapier, so rogue can do 1d8 damage.
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    4,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {0},          // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
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
    0,            // dmg       - innate damage bonus
    0,            // armor     - innate armor (defense) bonus
    7,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    7,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    16,           // max_mana  - max mana per level
    16,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    6,            // damage dice - 6 for quarterstaff
    1,            // number of damage dice. 1 for quarterstaff, so wizard can do 1d6 damage.
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    3,            // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
    {0},          // 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
    {0},          // 3 worn inventory slots. 1st is Armor, 2nd Main Hand, 3rd Off Hand
    {}            // 20 backpack slots.
  }
};

char *class_list[PCS] = {"Cleric", "Knight", "Rogue", "Wizard"};
