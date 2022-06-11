// Functions for creating and working with players

#define BUFF 256  // maximum size of character buffer
#define SAVE_SLOTS 4

mob saved_games[SAVE_SLOTS];

int class_choices() {
  int num_choices = 0;

  for (int i = 0; i < PCS; i++) {
    strncpy(choices[num_choices], class_list[i], MAX_CHOICE_LEN); choice_key[num_choices] = num_choices; num_choices++;
  }

  return num_choices;
}

// fill out character stats, name, source (chosen) class
void build_character(char name[32], mob chosen_class, mob *player) {
  
  /*strncpy(player->name, name, 32);
  strncpy(player->role, chosen_class.role, 16);
  strncpy(player->desc, chosen_class.desc, 256);
  player->str       = chosen_class.str;
  player->dex       = chosen_class.dex;
  player->con       = chosen_class.con;
  player->intel     = chosen_class.intel;
  player->wis       = chosen_class.wis;
  player->cha       = chosen_class.cha;
  player->dmg       = chosen_class.dmg;
  player->armor     = chosen_class.armor;
  player->max_hp    = chosen_class.max_hp;
  player->cur_hp    = chosen_class.cur_hp;
  player->dodge     = chosen_class.dodge;
  player->max_hp    = chosen_class.max_hp;
  player->max_mana  = chosen_class.max_mana;
  player->cur_mana  = chosen_class.cur_mana;
  player->xp        = chosen_class.xp;
  player->lvl       = chosen_class.lvl;
  player->coin      = chosen_class.coin;
  player->to_hit    = chosen_class.to_hit;
  player->dice_dam  = chosen_class.dice_dam;
  player->dice_num  = chosen_class.dice_num;
  player->is_pc     = chosen_class.is_pc;
  player->type      = chosen_class.type;
  player->alignment = chosen_class.alignment;
  for (int i = 0; i < MAX_BUFFS; i++) player->buffs[i] = 0;
  //for (int i = 0; i < WORN_SLOTS; i++) player->worn_items[i] = 0;
  //for (int i = 0; i < BAG_SLOTS; i++) player->backpack[i] = 0;*/
}

 // update player name
void update_name(WINDOW *select, WINDOW *input, mob *player) {
  char name[32];

  wclear(select);
  mvwprintw(select, 1, 1, "Please enter your character's name to get adventuring!");
  echo();    // allow player to see name they are entering
  wrefresh(select);
  napms(500);
  mvwprintw(input, 1, 1, "Name: ");
  wgetnstr(input, name, 31);
  noecho();  // turn off key entry echo to terminal
  clear_box(input);
  strncpy(player->name, name, 32);
  player->worn_items[0] = armors[0];
  for (int i = 1; i < WORN_SLOTS; i++) player->worn_items[i] = empty_slot;
  for (int i = 0; i < BAG_SLOTS; i++) player->backpack[i] = empty_slot;
}

// character selection
int choose_class(WINDOW *game_text, WINDOW *select) {
  int class_choice, choice;
  char class_prompt[64];

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "Your character's class (role or profession) will determine");
  mvwaddstr(game_text, 2, 1, "the unique skills and abilities available to you.");
  wrefresh(game_text);
  // create loop so player can check out each class if they want
  while(1) {
    reset_choices();
    num_choices = class_choices();
    class_choice = choose(select, num_choices, "Choose class:");
    
    wclear(game_text);
    mvwprintw(game_text, 1, 1, "%s", player_classes[class_choice].desc);
    snprintf(class_prompt, 63, "Would you like to play as a %s?", player_classes[class_choice].name);
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, class_prompt);
    if (choice == 0) {
      break;
    } else {
      mvwaddstr(game_text, 5, 1, "Right on, please make another choice:");
      wrefresh(game_text);
    }
  }
  
  return class_choice;
}

// look in backpack for items compatible with desired slot
void change_item(WINDOW *game_text, WINDOW *select, mob *player, int slot_worn, int slot_item) {
  int choice = 0, num_choices = 0;

  wclear(game_text);
  reset_choices();
  strncpy(choices[num_choices], "Keep current item...", MAX_CHOICE_LEN);
  num_choices++;

  for (int i = 0; i < BAG_SLOTS; i++) {
    if (player->backpack[i].slot == slot_item) {
      strncpy(choices[num_choices], player->backpack[i].name, MAX_CHOICE_LEN);
      choice_key[num_choices] = i;
      num_choices++;
    }
  }
  if (num_choices > 1) {
    choice = choose(select, num_choices, "Please choose: ");
    if (choice == 0) {
      mvwprintw(game_text, 0, 0, "Right on, %s, keeping %s on for now.", player->name, player->worn_items[slot_worn].name);
    } else {
      if (strcmp(player->worn_items[slot_worn].name, "- empty -") == 0) {
        mvwprintw(game_text, 0, 0, "Equipping %s.", player->backpack[choice_key[choice]].name);
      } else {
        mvwprintw(game_text, 0, 0, "Equipping %s and moving %s to your backpack.", player->backpack[choice_key[choice]].name, player->worn_items[slot_worn].name);
      }
      for (int i = 0; i < BAG_SLOTS; i++) {
        if (strcmp(player->backpack[i].name, "- empty -") == 0) {
          player->backpack[i] = player->worn_items[slot_worn]; // move existing item to first open slot in backpack
          break; // exit loop
        }
      }
      player->worn_items[slot_worn] = player->backpack[choice_key[choice]]; // move new item to worn slot
      player->backpack[choice_key[choice]] = empty_slot;                    // empty out slot with chosen item
    }
  } else {
    mvwprintw(game_text, 0, 0, "%s, it doesn't look like you have anything in your backpack that would work there...", player->name);
  }

  wrefresh(game_text);
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// Show Items Currently Being Worn
void view_worn(WINDOW *game_text, WINDOW *select, mob *player) {
  int choice = 0, num_choices = 0;

  wclear(game_text);
  wattron(game_text, COLOR_PAIR(5) | A_BOLD);
  mvwprintw(game_text, 0, 0, "---==| %s's Worn Items |==---", player->name);
  wattroff(game_text, COLOR_PAIR(5) | A_BOLD);
  wattron(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwprintw(game_text, 0, 7, "%s's Worn Items", player->name);
  wattroff(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(game_text, 1, 0, "          ");
  wattron(game_text, COLOR_PAIR(5));
  mvwprintw(game_text, 2, 0, "Armor:      %s", player->worn_items[0].name);
  mvwprintw(game_text, 3, 0, "Main Hand:  %s", player->worn_items[1].name);
  mvwprintw(game_text, 4, 0, "Off Hand:   %s", player->worn_items[2].name);
  wattroff(game_text, COLOR_PAIR(5));
  wrefresh(game_text);
  
  // Set up choices around changing inventory
  choice = num_choices = 0;
  reset_choices();
  strncpy(choices[num_choices], "Change Armor", MAX_CHOICE_LEN); num_choices++;
  strncpy(choices[num_choices], "Change Main Hand Weapon", MAX_CHOICE_LEN); num_choices++;
  strncpy(choices[num_choices], "Change Off Hand Weapon/Shield", MAX_CHOICE_LEN); num_choices++;
  strncpy(choices[num_choices], "Back to Character Sheet", MAX_CHOICE_LEN); num_choices++;
  choice = choose(select, num_choices, "Please choose: ");
  switch (choice) {
    case 0: change_item(game_text, select, player, 0, 2); break; // 0, 2 = first worn slot, item slot type 2 (armor)
    case 1: change_item(game_text, select, player, 1, 0); break;
    case 2: change_item(game_text, select, player, 2, 1); break;
    case 3: break;
    default: break;
  }
}

// Show Items in Backpack
void view_pack(WINDOW *game_text, WINDOW *select, mob *player) {

  wclear(game_text);
  wattron(game_text, COLOR_PAIR(5) | A_BOLD);
  mvwprintw(game_text, 0, 0, "              ---==| %s's Backpack |==---", player->name);
  wattroff(game_text, COLOR_PAIR(5) | A_BOLD);
  wattron(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwprintw(game_text, 0, 21, "%s's Backpack", player->name);
  wattroff(game_text, COLOR_PAIR(6) | A_BOLD);
  mvwaddstr(game_text, 1, 0, "          ");
  for (int i = 0; i < BAG_SLOTS; i++) {
    if (i < 10) {
      wattron(game_text, COLOR_PAIR(6));
      mvwprintw(game_text, 2 + i, 0, "[%d]: ", i + 1);
      wattroff(game_text, COLOR_PAIR(6));
      wattron(game_text, COLOR_PAIR(5));
      mvwprintw(game_text, 2 + i, 7, "%s", player->backpack[i].name);
      wattroff(game_text, COLOR_PAIR(5));
    } else {
      wattron(game_text, COLOR_PAIR(6));
      mvwprintw(game_text, 2 + i - 10, 50, "[%d]: ", i + 1);
      wattroff(game_text, COLOR_PAIR(6));
      wattron(game_text, COLOR_PAIR(5));
      mvwprintw(game_text, 2 + i - 10, 57, "%s", player->backpack[i].name);
      wattroff(game_text, COLOR_PAIR(5));
    }
  }
  wrefresh(game_text);
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// color stats according to level of bonus (or negative if relevant)
void format_stat(WINDOW *win, char *text, int stat, int y_pos) {
  wattron(win, COLOR_PAIR(5));
  mvwaddstr(win, y_pos, 0, text);
  wattroff(win, COLOR_PAIR(5));
  if (stat < 9) wattron(win, COLOR_PAIR(1) | A_BOLD);
  if ((stat >= 9) && (stat <= 11)) wattron(win, COLOR_PAIR(5) | A_BOLD);
  if (stat > 11) wattron(win, COLOR_PAIR(7) | A_BOLD);
  mvwprintw(win, y_pos, 14, "%d", stat);
  wattroff(win, COLOR_PAIR(5) | COLOR_PAIR(1) | COLOR_PAIR(7) | A_BOLD);
}

// Show character sheet - ability scores, etc.
// calculate AC
void character_sheet(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int choice = 0, num_choices = 0;
  char buff_string[64];

  while (1) {
    wclear(game_text);
    wattron(game_text, COLOR_PAIR(5) | A_BOLD);
    mvwprintw(game_text, 0, 0, "---==| %s's Character Sheet |==---", player->name);
    wattroff(game_text, COLOR_PAIR(5) | A_BOLD);
    wattron(game_text, COLOR_PAIR(6) | A_BOLD);
    mvwprintw(game_text, 0, 7, "%s's Character Sheet", player->name);
    wattroff(game_text, COLOR_PAIR(6) | A_BOLD);
    mvwaddstr(game_text, 1, 0, "          ");
    format_stat(game_text, "Strength: ", player->str, 2);
    format_stat(game_text, "Dexterity: ", player->dex, 3);
    format_stat(game_text, "Constitution: ", player->con, 4);
    format_stat(game_text, "Intelligence: ", player->intel, 5);
    format_stat(game_text, "Wisdom: ", player->wis, 6);
    format_stat(game_text, "Charisma: ", player->cha, 7);
    mvwaddstr(game_text, 8, 0, "          ");
    wattron(game_text, COLOR_PAIR(5));
    mvwprintw(game_text, 9, 0, "Armor Class (AC): %d", 10 + player->worn_items[0].armor_val + player->worn_items[1].armor_val + player->worn_items[2].armor_val);
    snprintf(buff_string, 64, "Buffs - Food: %c | Drink: %c | Class: %c", (player->buffs[0] == 1) ? 'Y' : 'N', (player->buffs[1] == 1) ? 'Y' : 'N', (player->buffs[2] == 1) ? 'Y' : 'N');
    mvwaddstr(game_text, 10, 0, "          ");
    mvwaddstr(game_text, 11, 0, buff_string);
    wattroff(game_text, COLOR_PAIR(5));
    wrefresh(game_text);

    // Set up choices around viewing inventory
    choice = num_choices = 0;
    reset_choices();
    strncpy(choices[num_choices], "View Worn Inventory", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "View Backpack", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "Go back...", MAX_CHOICE_LEN); num_choices++;
    choice = choose(select, num_choices, "Please choose: ");
    switch (choice) {
      case 0: view_worn(game_text, select, player); break;
      case 1: view_pack(game_text, select, player); break;
      case 2: break;
      default: break;
    }
    if (choice == 2) break; // head back to town choices
  }
}

// load all saved character data into saved games array
int load_saves() {
  FILE *fp;
  int count = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "rb");
    // Add all saves to array of saved games
    count = fread(saved_games, sizeof(mob), SAVE_SLOTS, fp);
  }

  return count;
}

// choose a saved game from the list of saves
int choose_save(WINDOW *game_text, WINDOW *select, int saves) {
  int choice, num_choices = 0;
  char save_text[96];

  reset_choices();

  for (int i = 0; i < saves; i++) {
    snprintf(save_text, 95, "Slot: %d | Name: %s | Class: %s | Level: %d", i + 1, saved_games[i].name, saved_games[i].role, saved_games[i].lvl);
    strncpy(choices[num_choices], save_text, 96);
    num_choices++;
    memset(save_text, 0, 96);
  }

  choice = choose(select, num_choices, "Please choose a saved game: \n");

  return choice;
}

int check_saves() {
  int numfound = 0;

  numfound = load_saves();

  return numfound;
}

// write player data to save file
int save_game(WINDOW *game_text, WINDOW *select, mob player, int saves) {
  int save_slot = 0;
  FILE *fp;

  // determine if we need to overwrite a saved game
  if (saves >= SAVE_SLOTS) {
    save_slot = choose_save(game_text, select, saves);
  } else {
    if ((saves >= 0) && (saves < SAVE_SLOTS)) {
      saves++;
      save_slot = saves - 1; // index properly into array
    }
  }

  // now update array of structs using save_slot
  saved_games[save_slot] = player;
  
  // write out saved_games array to our save file
  if (file_there(save_file)) {
    fp = fopen(save_file, "wb");
    fwrite(saved_games, sizeof(mob), saves, fp);
    //fwrite(&player, sizeof(mob), 1, fp);
    fclose(fp);
  }

  return saves;
}
