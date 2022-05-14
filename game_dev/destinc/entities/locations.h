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
void tavern(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player) {
  int choice, drink_cost, food_cost, rest_cost;
  char tavern_prompt[96];

  drink_cost = player->lvl * 1;  // tweak these at some point
  food_cost  = player->lvl * 1;  // later this will give buff, for now restore health
  rest_cost  = player->lvl * 2;  // later this will give buff, for now restore mana

  snprintf(tavern_prompt, 95, "What would you like to do in the tavern, %s?", player->name);

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "You enter the tavern. The air is thick with smoke, but the fire in the hearth is warm and inviting.");
  wrefresh(game_text);
  while(1) {
    //getch(); // DEBUG
    choice = choose(select, tavern_list, TAVERN, tavern_prompt);
    wclear(game_text);
    switch (choice) {
      case 0: if (player->coin >= food_cost) {
        mvwaddstr(game_text, 1, 1, tavern_table);
        player->cur_hp = player->max_hp * player->lvl; // food restores health
        player->coin-=food_cost;  // pay for food
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford a meal! Go to the dungeon and earn some money!");
      } break;
      case 1: if (player->coin >= drink_cost) {
        mvwaddstr(game_text, 1, 1, tavern_bar);
        player->cur_mana = player->max_mana * player->lvl; // drink restores mana
        player->coin-=drink_cost;  // pay for drink
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford wine, you churl! Go to the dungeon and earn some money!");
      } break;
      case 2: if (player->coin >= rest_cost) {
        mvwaddstr(game_text, 1, 1, tavern_rest);
        player->cur_hp = player->max_hp * player->lvl; // resting restores health
        player->cur_mana = player->max_mana * player->lvl; // resting restores mana
        player->coin-=rest_cost;  // pay for room
      } else {
        mvwaddstr(game_text, 1, 1, "You can't afford a room! Hit the dungeon and earn some money!");
      } break;
      case 3: mvwaddstr(game_text, 1, 1, "Feeling much better, you step out of the tavern and back into town. Come back soon!"); break;
      default: break;
    }
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    napms(500);
    if (choice == 3) break; // end tavern loop
  }
}

// DUNGEON

char dungeon_map[4][4] = {
  "####",
  "#$$#",
  "E$##",
  "####"
};

// send current position and direction you are testing
// directions are 0 = north, 1 = east, 2 = south, 3 = west
int can_move(int y, int x, int direction) {
  int test_y = 0, test_x = 0;

  switch (direction) {
    case 0: test_y = y - 1; break;
    case 1: test_x = x + 1; break;
    case 2: test_y = y + 1; break;
    case 3: test_x = x - 1; break;
    default: break;
  }
  // now test potential move - would be better to see if potential move is in a list of valid moves
  if (dungeon_map[test_y][test_x] == '$' || dungeon_map[test_y][test_x] == 'E') return 1;
  else return 0;
}

// dungeon key: E = entrance, # = wall, $ = path

// you are visiting the dungeon
void dungeon(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player) {
  int choice, num_choices, y_pos = 3, x_pos = 0; // starting position in the dungeon
  char dungeon_prompt[96];
  char choices[6][64];
  char **choices_p;
  choices_p = &choices;
  //char *choices[6];
  int  choice_key[6];

  snprintf(dungeon_prompt, 95, "Where to now, %s?", player->name);

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "Stepping into the dungeon, you prepare for adventure.");
  wrefresh(game_text);
  getch();
  while(1) {
    //getch(); // DEBUG
    // clear previous list of choices - this could probably be a function
    num_choices = 0;
    for (int i = 0; i < 6; i++) {
      strncpy(choices[i], "", 2); // null each array
      //getch();
      //for (int j = 0; j < 64; j++) choices[i] = '\0';
      choice_key[i] = 99;           // "null" array
    }
    getch();
    // build choices based on current position - test each direction
    for (int i = 0; i < 4; i++) {    // directions: 0 = north, 1 = east, 2 = south, 3 = west
      if (can_move(y_pos, x_pos, i)) {
        switch (i) {
          case 0: strncpy(choices[num_choices], "North", 63); choice_key[num_choices] = 0; num_choices++; break;
          case 1: strncpy(choices[num_choices], "East", 63);  choice_key[num_choices] = 0; num_choices++; break;
          case 2: strncpy(choices[num_choices], "South", 63); choice_key[num_choices] = 0; num_choices++; break;
          case 3: strncpy(choices[num_choices], "West", 63);  choice_key[num_choices] = 0; num_choices++; break;
          default: break;
        }
      }
    }
    choice = choose(select, choices_p, num_choices, dungeon_prompt);
    wclear(game_text);
    switch (choice_key[choice]) {
      case 0: y_pos--; break;
      case 1: x_pos++; break;
      case 2: y_pos++; break;
      case 3: x_pos--; break;
      case 4: mvwaddstr(game_text, 1, 1, "Great choice!"); break;
      case 5: mvwaddstr(game_text, 1, 1, "Great choice!"); break;
      default: break;
    }
    refresh_stats(stats, player); // update stats window
    wrefresh(game_text);
    napms(500);
    if (dungeon_map[y_pos][x_pos] == 'E') {
      choice = choose(select, yes_no, Y_N, "You are at the dungone entrance. Would you like to leave?");
      if (choice == 0) break; // end dungeon loop
    }
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