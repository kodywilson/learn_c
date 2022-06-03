// armor, weapons, jewelry, etc.

//#define ALL_ARMOR 13
#define ALL_ARMOR 2 // test with just a couple at first

// shared struct for items
typedef struct Item {
  int  name;          // item name - connect to name table (this is the index) so weapon_name[0] might be "longsword"
  int  desc;          // item description - connect to description table (this is the index) so weapon_desc[0] might be "A beautiful blade"
  int  category;      // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
  int  type;          // item type: 0 = light, 1 = heavy, 2 = ring, 3 = earring, 4 = bracer, 5 = necklace
  int  group;         // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry)
  int  slot;          // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
  int  cost;          // cost of the item in coin (later gold when the currency change goes live)
  int  versa;         // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
  int  weight;        // Weight in pounds
  int  dmg_dice;      // range of roll, ie. d6
  int  dice_num;      // How many dmg_dice? ie. 2d6
  int  armor_val;     // How much armor is added to the base AC. (2 for studded leather, etc.)
  int  bonus;         // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
  int  resistance;    // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
  int  stealth;       // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
  int  str_req;       // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
  int  finesse;       // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
  int  max_dex_mod;   // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
  int  range;         // Ranged weapon? 0 = no, 1 = yes.
  int  dam_type;      // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
  int  damaged;       // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
  int  alignment;     // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
} item;

char *armors_names[ALL_ARMOR] = {"clothes", "padded"};
char *armors_descs[ALL_ARMOR] = {"Simple clothing, better than nothing.", "Stiffly padded clothing. Slightly better than plain clothes."};

item armors[ALL_ARMOR] = {
  // No armor, just plain clothes
  {
    0,                  // item name - connect to name table (this is the index) so weapon_name[0] might be "longsword"
    0,                  // item description - connect to description table (this is the index) so weapon_desc[0] might be "A beautiful blade"
    4,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    6,                  // item type: 0 = light, 1 = heavy, 2 = ring, 3 = earring, 4 = bracer, 5 = necklace, 6 = outfit
    3,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    2,                  // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    3,                  // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0,                  // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Padded armor
  {
    1,                  // item name - connect to name table (this is the index) so weapon_name[0] might be "longsword"
    1,                  // item description - connect to description table (this is the index) so weapon_desc[0] might be "A beautiful blade"
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = heavy, 2 = ring, 3 = earring, 4 = bracer, 5 = necklace, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    8,                  // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    1,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0,                  // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  }
};
