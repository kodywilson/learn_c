// armor, weapons, jewelry, etc.

// shared struct for items
typedef struct Item {
  int  name;          // item name - connect to name table (this is the index) so weapon_name[0] might be "longsword"
  int  desc;          // item description - connect to description table (this is the index) so weapon_desc[0] might be "A beautiful blade"
  int  category;      // 0 = armor, 1 = weapon, 2 = shield, 3 = jewelry, 4 = adventure gear, 5 = treasure
  int  type;          // 0 = light, 1 = heavy, 2 = ring, 3 = earring, 4 = bracer, 5 = necklace
  int  group;         // 0 = simple, 1 = martial, 2 = magical (for jewelry)
  int  slot;          // 0 = main hand, 1 = off hand, 2 = armor, 3 = finger, 4 = neck
  int  cost;          // cost of the item in coin (later gold when the currency change goes live)
  int  versa;         // 0 = not usable held, 1 = 1 hand only (weapons), 2 = 2 hand only (weapons), 3 = versatile, use either 1 or 2 handed
  int  weight;        // Weight in pounds
  int  dmg_dice;      // range of roll, ie. d6
  int  dice_num;      // How many dmg_dice? ie. 2d6
  int  armor_val;     // How much armor is added to the base AC. (2 for studded leather, etc.)
  int  bonus;         // +1, +2, etc. For armor adds to AC while weapons get + to hit and + damage
  int  resistance;    // acid, poison, fire, cold resistance, etc. Use higher numbers for combos (acid plus fire resistance)
  int  stealth;       // 0 = no impact, 1 = disadvantage for stealth checks
  int  str_req;       // Minimum strength to equip. 0 = no requirement, 13, 15, etc.
  int  finesse;       // 0 = no finesse, 1 = finesse (can use dex to hit and damage)
  int  range;         // Ranged weapon? 0 = no, 1 = yes.
  int  dam_type;      // 0 = untyped, 1 = slash, 2 = bludgeon, 3 = pierce, 4 = fire, 5 = cold, etc.
  int  damaged;       // Gear dropped from monsters is likely damaged and sells for much less... 0 = no, 1 = yes
  int  alignment;     // 0 = no restrictions, 1 = lawful, good, 2 = lawful, neutral, 3 = lawful, evil, etc. Use look up table
} item;
