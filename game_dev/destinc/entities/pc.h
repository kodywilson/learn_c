// functions and data for playable character types

char *player_classes[2] = {"Cleric", "Knight"};

typedef struct Player {
  char name[33];
  char role[16];
  int  hp;
} pc;
