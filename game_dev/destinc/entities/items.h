// armor, weapons, jewelry, etc.

#define ALL_ARMOR 13
#define ALL_SHIELDS 3
#define ALL_WEAPONS 27
#define ITEM_TYPES 7
#define ITEM_GROUPS 3
#define ITEM_VERSAS 4

// Lookup tables
char *item_types[ITEM_TYPES] = {"light", "medium", "heavy", "ring", "earring", "bracer", "outfit"};
char *item_groups[ITEM_GROUPS] = {"simple", "martial", "magical jewelry"};
char *item_versas[ITEM_VERSAS] = {"not usable held", "one hand only", "two hand only", "one or two hands"};

// shared struct for items
typedef struct Item {
  char name[32];      // item name - connect to name table (this is the index) so weapon_name[0] might be "longsword"
  char desc[256];     // item description - connect to description table (this is the index) so weapon_desc[0] might be "A beautiful blade"
  int  category;      // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
  int  type;          // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
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

// "empty" item. Trying this for initializing all slots with a placeholder
item empty_slot = {
  "- empty -",    // item name
  "This slot has nothing in it.", // item description
  99,                 // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
  99,                 // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
  99,                 // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
  99,                 // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
  0,                  // cost of the item in coin (later gold when the currency change goes live)
  0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
  0,                  // Weight in pounds
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
  0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
};

//char *armors_names[ALL_ARMOR] = {"clothes", "padded"};
//char *armors_descs[ALL_ARMOR] = {"Simple clothing, better than nothing.", "Stiffly padded clothing. Slightly more armor than plain clothes."};

item armors[ALL_ARMOR] = {
  // No armor, just plain clothes
  {
    "Plain Clothes",    // item name
    "Simple clothing, better than nothing.", // item description
    4,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    6,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
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
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Padded Armor
  {
    "Padded Armor",     // item name
    "Stiffly padded clothing. Slightly more armor than plain clothes but difficult to move around in.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
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
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Leather Armor
  {
    "Leather Armor",    // item name
    "Stiffened leather, similar protection as padded, but easier to move around in.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    10,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    1,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Studded Leather
  {
    "Studded Leather", // item name
    "Made from tough, flexible leather reinforced with metal studs.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    45,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    13,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    2,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Hide Armor
  {
    "Hide Armor",       // item name
    "Crude armor made from thick furs and pelts.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    12,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    2,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    2,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Chain Shirt
  {
    "Chain Shirt",      // item name
    "Made of interlocking metal rings, provides modest protection and good mobility.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    50,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    20,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    3,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    2,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Scale Mail
  {
    "Scale Mail",       // item name
    "Coat and leggings of leather covered with overlapping pieces of metal.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    50,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    45,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    4,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    2,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Breastplate
  {
    "Breastplate",      // item name
    "Fitted metal chest piece worn with supple leather. Good protection and mobility.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    400,                // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    20,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    4,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    2,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Half Plate
  {
    "Half Plate",       // item name
    "Shaped metal plates that cover most of the body. Provides good protection, but less mobility.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    750,                // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    40,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    5,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    2,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Ring Mail
  {
    "Ring Mail",        // item name
    "Leather armor with heavy metal rings swen into it.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    30,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    40,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    4,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    0,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Chain Mail
  {
    "Chain Mail",       // item name
    "Made of interlocking metal rings with quilted fabric underneath.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    75,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    55,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    6,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    13,                 // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    0,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Splint Mail
  {
    "Splint Mail",      // item name
    "Vertical strips of metal riveted to leather worn over cloth padding.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    200,                // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    60,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    7,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    15,                 // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    0,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Plate Armor
  {
    "Plate Armor",      // item name
    "Shaped, interlocking metal plates that cover the entire body.", // item description
    0,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    2,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1500,               // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    65,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    8,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    1,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    15,                 // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    0,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    0,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  }
};

item shields[ALL_SHIELDS] = {
  // Plain Wooden Shield
  {
    "Wooden Shield",    // item name
    "Simple wooden shield with a few iron straps to reinforce it.", // item description
    2,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    1,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    1,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Iron Shield
  {
    "Iron Shield",    // item name
    "Simple iron shield with a stout, leather wrapped grip.", // item description
    2,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    1,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    6,                  // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    2,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  {
    "Heavy Iron Shield",    // item name
    "Well crafted iron shield with an additional iron plate and superior arm guard.", // item description
    2,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    1,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    500,                // cost of the item in coin (later gold when the currency change goes live)
    0,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    10,                 // Weight in pounds
    0,                  // range of roll, ie. d6
    0,                  // How many dmg_dice? ie. 2d6
    3,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    13,                 // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    0,                  // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  }
};

item weapons[ALL_WEAPONS] = {
  // Club
  {
    "Club",             // item name
    "Crude wooden club.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    4,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Dagger
  {
    "Dagger",             // item name
    "A simple iron dagger with a leather wrapped grip.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    2,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    1,                  // Weight in pounds
    4,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    1,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Greatclub
  {
    "Greatclub",        // item name
    "Crude, large, two-handed wooden club.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1,                  // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    10,                 // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Handaxe
  {
    "Handaxe",          // item name
    "A light handaxe, balanced for fighting.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Light Hammer
  {
    "Light Hammer",     // item name
    "A small iron hammer.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    2,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    4,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Mace
  {
    "Mace",             // item name
    "Heavy iron mace with a long leather grip.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Quarterstaff
  {
    "Quarterstaff",     // item name
    "Iron tipped, stout oak quarterstaff.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1,                  // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Sickle
  {
    "Sickle",             // item name
    "A simple iron sickle with a gleaming, curved blade.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    4,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Spear
  {
    "Spear",             // item name
    "A simple wooden spear with a sharp iron tip.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    0,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    1,                  // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    3,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Battleaxe
  {
    "Battleaxe",        // item name
    "A hefty iron axe designed for one or two hand use.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Flail
  {
    "Flail",            // item name
    "A spiked, iron ball dangles from a chain connected to a stout handle.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Glaive
  {
    "Glaive",           // item name
    "A heavy, wicked looking blade.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    20,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    6,                  // Weight in pounds
    10,                 // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Greataxe
  {
    "Greataxe",         // item name
    "This large, double sided greataxe looks like it could do some serious damage.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    30,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    7,                  // Weight in pounds
    12,                 // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Greatsword
  {
    "Greatsword",       // item name
    "A huge, elegant iron blade made to swing with both hands.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    20,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    6,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    2,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Halberd
  {
    "Halberd",          // item name
    "An iron battleaxe mounted on a long wooden pole.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    20,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    6,                  // Weight in pounds
    10,                 // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Lance
  {
    "Lance",           // item name
    "Looks like a long spear with an extra large spearhead.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    20,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    6,                  // Weight in pounds
    12,                 // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Longsword
  {
    "Longsword",           // item name
    "Polished iron blade with an ornately figured hilt.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    15,                 // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    3,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Maul
  {
    "Maul",           // item name
    "A huge, heavy hammer built to crush.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    10,                 // Weight in pounds
    6,                  // range of roll, ie. d6
    2,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Morningstar
  {
    "Morningstar",      // item name
    "A heavy mace with large iron spikes protruding from the head.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    15,                 // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Pike
  {
    "Pike",             // item name
    "A long spear with a leaf shaped iron point.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    2,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    2,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    18,                 // Weight in pounds
    10,                 // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Rapier
  {
    "Rapier",           // item name
    "A slender sword with an extremely sharp point.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    25,                 // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    1,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Scimitar
  {
    "Scimitar",           // item name
    "A sword with a sharp, curved blade.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    25,                 // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    3,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    1,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Shortsword
  {
    "Shortsword",       // item name
    "Somewhere between a long sword and a dagger lies the shortsword.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    0,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    10,                 // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    1,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Trident
  {
    "Trident",          // item name
    "A spear with three fishhook shaped tips.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    4,                  // Weight in pounds
    6,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // War pick
  {
    "War pick",         // item name
    "Similar to a mining pick, but designed for battle.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    5,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    3,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Warhammer
  {
    "Warhammer",        // item name
    "This hammer has been balanced and weighted for combat.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    15,                 // cost of the item in coin (later gold when the currency change goes live)
    3,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    2,                  // Weight in pounds
    8,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    0,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    2,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  },
  // Whip
  {
    "Whip",           // item name
    "A long leather whip with metal blades sewn into the tip.", // item description
    1,                  // item category: 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
    1,                  // item type: 0 = light, 1 = medium, 2 = heavy, 3 = ring, 4 = earring, 5 = bracer, 6 = outfit
    1,                  // item group: 0 = simple, 1 = martial, 2 = magical (for jewelry), 3 = plain clothes, 4 = costume
    0,                  // slot (where you can equip): 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
    2,                  // cost of the item in coin (later gold when the currency change goes live)
    1,                  // Versatility: 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
    3,                  // Weight in pounds
    4,                  // range of roll, ie. d6
    1,                  // How many dmg_dice? ie. 2d6
    0,                  // How much armor is added to the base AC. (2 for studded leather, etc.)
    0,                  // Bonus. +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
    0,                  // Resistance? 0 = none, 1 = acid, 2 = poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
    0,                  // Disadvantage on stealth rolls? 0 = no impact, 1 = disadvantage for stealth checks
    0,                  // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
    1,                  // Finesse? 0 = no finesse, 1 = finesse (can use dex to hit and damage)
    20,                 // Max dex modifier. 0 = none at all (heavy armor), 2 (for medium armors), 20 for light armors
    0,                  // Ranged weapon? 0 = no, 1 = yes.
    1,                  // Damage type: 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
    0,                  // Damaged? Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
    0                   // Alignment required? 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
  }
};
