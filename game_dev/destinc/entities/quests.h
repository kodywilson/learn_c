// functions and data for quests

// Quests will be obtained in the tavern and from other events and places

// Quest Struct
// players will have quest slots and these will track active quests
// I need to figure out how to best store completed quests...perhaps each has a unique id
// that way I can track in progress, not yet attempted, and completed
typedef struct Quest {
  char name[64];      // Quest name
} quest;
