// functions and data for playable character types

#define PCS 5  // number of playable classes

typedef struct Player {
  char name[33];
  char role[16];
  int  str;       // Begin basic stat block 
  int  dex;
  int  con;
  int  intel;
  int  wis;
  int  cha;       // End basic stat block
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
    "Cleric",
    "Cleric",

  }
}

char *player_classes[PCS] = {"Cleric", "Knight", "Monk", "Rogue", "Wizard"};

char *class_descriptions[PCS] = {"Clerics are healers, able to restore health, even during combat. They are capable fighters as well.",
                               "Knights are noble warriors with the best armor and can periodically smite their foes."};
