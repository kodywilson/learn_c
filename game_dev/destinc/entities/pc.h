// functions and data for playable character types

char *player_classes[5] = {"Cleric", "Knight", "Monk", "Rogue", "Wizard"};

char *class_descriptions[2] = {"Clerics are healers, able to restore health, even during combat. They are capable fighters as well.",
                               "Knights are noble warriors with the best armor and can periodically smite their foes."};

typedef struct Player {
  char name[33];
  char role[16];
  int  hp;
} pc;
