// game locations - town, dungeon, tavern, etc.
// each location will start with a list of options

#define TOWN 3
#define TAVERN 4

// Town
char *town_list[TOWN] = {"The Dungeon", "Ye Olde Tavern", "Exit Game"};


// Tavern
char *tavern_list[] = {
    "Buy some food.       | Cost: 1 coin",
    "Buy a drink.         | Cost: 1 coin",
    "Rest.                | Cost: 2 coins",
    "Leave the tavern."};