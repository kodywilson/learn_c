// functions and data for playable character types

char *player_classes[2] = {"Cleric", "Knight"};

char *class_descriptions[2] = {"Clerics are healers, able to restore health, even during combat. They are capable fighters as well.",
                               "Knights are noble warriors with the best armor and can periodically smite their foes."};

typedef struct Player {
  char name[33];
  char role[16];
  int  hp;
} pc;
