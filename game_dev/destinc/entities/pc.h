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
    2,            // dmg       - innate damage bonus (this is going to be more of a proficiency bonus)
    5,            // armor     - armor class - AC (defense) = Chain shirt + shield
    10,           // max_hp    - max hp earned per level (1d8 + Con modifier)
    10,           // cur_hp    - current hp
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
    10,           // dex       - dexterity
    16,           // con       - constitution
    10,           // intel     - intelligence
    14,           // wis       - wisdom
    14,           // cha       - charisma
    2,            // dmg       - innate damage bonus
    6,            // armor     - armor (defense) - ring mail + shield
    13,           // max_hp    - max hp earned per level (1d10 + Con modifier)
    13,           // cur_hp    - current hp
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
    16,           // dex       - dexterity       - also adds to AC
    12,           // con       - constitution
    14,           // intel     - intelligence
    12,           // wis       - wisdom
    14,           // cha       - charisma
    3,            // dmg       - innate damage bonus
    1,            // armor     - armor (defense) - leather armor gives +1 AC
    9,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    9,            // cur_hp    - current hp
    2,            // dodge     - innate bonus to dodge   - might drop this at some point
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
    2,            // dmg       - innate damage bonus
    1,            // armor     - innate armor (defense) bonus
    7,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    7,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    16,           // max_mana  - max mana per level
    16,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
  }
};

char *class_list[PCS] = {"Cleric", "Knight", "Rogue", "Wizard"};
