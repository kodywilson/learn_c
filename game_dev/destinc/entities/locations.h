// game locations - town, dungeon, tavern, etc.
// each location will start with a list of options

#define TOWN 3
#define TAVERN 4

// Town
char *town_list[TOWN] = {"The Dungeon", "Ye Olde Tavern", "Exit Game"};


// ## Tavern
char *tavern_list[TAVERN] = {
  "Buy some food.       | Cost: 1 coin",
  "Buy a drink.         | Cost: 1 coin",
  "Rest.                | Cost: 2 coins",
  "Leave the tavern."
};

// you are visiting the tavern
void tavern(WINDOW *game_text, WINDOW *select, pc *player) {
  int choice;

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "You enter the tavern. The air is thick with smoke, but the fire in the hearth is warm and inviting.");
  wrefresh(game_text);
  while(1) {
    //getch(); // DEBUG
    wclear(select);
    mvwprintw(select, 0, 0, "What would you like to do in the tavern, %s?", player->name);
    wrefresh(select);
    choice = choose(select, tavern_list, TAVERN);
    wclear(game_text);
    switch (choice) {
      case 0: mvwaddstr(game_text, 1, 1, tavern_table); break;
      case 1: mvwaddstr(game_text, 1, 1, "You buy a drink."); break;
      case 2: mvwaddstr(game_text, 1, 1, "You rest..."); break;
              //save_game(player); main_loop = 0; break;
      case 3: mvwaddstr(game_text, 1, 1, "Come back soon!"); break;
      default: break;
    }
    wrefresh(game_text);
    napms(500);
    if (choice == 3) break; // end tavern loop
  }
}

// later add more variety for what you can do at these locations
// like maybe you can chat with the barkeep, buy a drink, etc. at the bar
// order food, chat with waitress, examine room, etc. while seated at a table
// // ### Tavern - Table
// char *table_list[4] = {
//     "Buy some food.       | Cost: 1 coin",
//     "Buy a drink.         | Cost: 1 coin",
//     "Rest.                | Cost: 2 coins",
//     "Leave the tavern."
// };

// // ### Tavern - Bar
// char *bar_list[4] = {
//     "Buy some food.       | Cost: 1 coin",
//     "Buy a drink.         | Cost: 1 coin",
//     "Rest.                | Cost: 2 coins",
//     "Leave the tavern."
// };