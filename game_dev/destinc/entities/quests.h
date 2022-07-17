// functions and data for quests

// Quest Struct
// players will have quest slots and these will track active quests
// I need to figure out how to best store completed quests...perhaps each has a unique id
typedef struct Quest {
  char name[64];      // Quest name
} quest;
