// Functions for creating and working with players

#define BUFF 256  // maximum size of character buffer
#define SAVE_SLOTS 4

pc saved_games[SAVE_SLOTS];

int class_choices() {
  int num_choices = 0;

  for (int i = 0; i < PCS; i++) {
    strncpy(choices[num_choices], class_list[i], MAX_CHOICE_LEN); choice_key[num_choices] = num_choices; num_choices++;
  }

  return num_choices;
}

int calc_mod(int stat) {
  
  return ((stat - 10) / 2);

}

 // update player name
void update_name(WINDOW *select, WINDOW *input, pc *player) {
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

// send player and which item slot to unequip
void next_pack_slot(pc *player, int slot_worn) {
  for (int i = 0; i < BAG_SLOTS; i++) {
    if (strcmp(player->backpack[i].name, "- empty -") == 0) {
      player->backpack[i] = player->worn_items[slot_worn]; // move existing worn item to first open slot in backpack
      player->worn_items[slot_worn] = empty_slot;          // empty out worn slot
      break; // exit loop
    }
  }
}

// look in backpack for items compatible with desired slot
void change_item(WINDOW *game_text, WINDOW *select, pc *player, int slot_worn, int slot_item) {
  int choice = 0, num_choices = 0;

  wclear(game_text);
  reset_choices();
  if (strcmp(player->worn_items[slot_worn].name, "- empty -") != 0) {
    strncpy(choices[num_choices], "Keep current item...", MAX_CHOICE_LEN); choice_key[num_choices] = 50; num_choices++;
    strncpy(choices[num_choices], "Unequip current item...", MAX_CHOICE_LEN); choice_key[num_choices] = 51; num_choices++;
  }
  
  // build item choices (if any)
  for (int i = 0; i < BAG_SLOTS; i++) {
    if (player->backpack[i].slot == slot_item) {
      strncpy(choices[num_choices], player->backpack[i].name, MAX_CHOICE_LEN);
      choice_key[num_choices] = i;
      num_choices++;
    }
  }
  if (num_choices > 0) {
    choice = choose(select, num_choices, "Please choose: ");
    if (choice_key[choice] == 50) {
      mvwprintw(game_text, 0, 0, "Right on, %s, keeping %s on for now.", player->name, player->worn_items[slot_worn].name);
    }
    if (choice_key[choice] == 51) {
      mvwprintw(game_text, 0, 0, "Removing %s and placing in backpack.", player->worn_items[slot_worn].name);
      next_pack_slot(player, slot_worn); // put item in first available pack slot
    }
    if (choice_key[choice] < BAG_SLOTS )  {
      if (strcmp(player->worn_items[slot_worn].name, "- empty -") == 0) {
        mvwprintw(game_text, 0, 0, "Equipping %s.", player->backpack[choice_key[choice]].name);
      } else {
        mvwprintw(game_text, 0, 0, "Equipping %s and moving %s to your backpack.", player->backpack[choice_key[choice]].name, player->worn_items[slot_worn].name);
      }
      next_pack_slot(player, slot_worn); // put item in first available pack slot
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
void view_worn(WINDOW *game_text, WINDOW *select, pc *player) {
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
  mvwprintw(game_text, 2, 28, "  -=|=-  AC:   %d", player->worn_items[0].armor_val);
  mvwprintw(game_text, 3, 0, "Main Hand:  %s", player->worn_items[1].name);
  mvwprintw(game_text, 3, 28, "  -=|=-  Dice: %dd%d", player->worn_items[1].dice_num, player->worn_items[1].dmg_dice);
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
void view_pack(WINDOW *game_text, WINDOW *select, pc *player) {

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

void level_up(WINDOW *game_text, WINDOW *select, pc *player) {
  int can_level = 0;

  wclear(game_text); // better put a level cap here!
  switch (player->lvl) {
    case 1: if (player->xp >= 300) can_level = 1; break;
    case 2: if (player->xp >= 900) can_level = 1; break;
    case 3: if (player->xp >= 2700) can_level = 1; break;
    case 4: if (player->xp >= 6500) can_level = 1; break;
    case 5: if (player->xp >= 14000) can_level = 1; break;
    case 6: if (player->xp >= 23000) can_level = 1; break;
    case 7: if (player->xp >= 34000) can_level = 1; break;
    case 8: if (player->xp >= 48000) can_level = 1; break;
    case 9: if (player->xp >= 64000) can_level = 1; break;
    case 10: if (player->xp >= 85000) can_level = 1; break;
    default: break;
  }
  if (can_level > 0) {
    mvwprintw(game_text, 0, 0, "Congratulations %s. You have enough xp to level up!", player->name);
    player->lvl++;
    player->hit_die_num = player->lvl;
    player->max_hp = (player->hit_die * player->lvl) + (calc_mod(player->con) * player->lvl);
    player->cur_hp = player->max_hp;
    player->max_mana+=4;
    player->cur_mana = player->max_mana;
  } else {
    mvwprintw(game_text, 0, 0, "%s, you need a little more xp to level up.", player->name);
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
void character_sheet(WINDOW *game_text, WINDOW *select, WINDOW *stats, pc *player) {
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
    mvwprintw(game_text, 9, 0, "Current HP: %d  |  Max HP: %d", player->cur_hp, player->max_hp);
    mvwprintw(game_text, 10, 0, "Current XP: %d", player->xp);
    mvwaddstr(game_text, 11, 0, "          ");
    mvwprintw(game_text, 12, 0, "Armor Class (AC): %d", 10 + player->worn_items[0].armor_val + player->worn_items[1].armor_val + player->worn_items[2].armor_val);
    snprintf(buff_string, 64, "Buffs - Food: %c | Drink: %c | Class: %c", (player->buffs[0] == 1) ? 'Y' : 'N', (player->buffs[1] == 1) ? 'Y' : 'N', (player->buffs[2] == 1) ? 'Y' : 'N');
    mvwaddstr(game_text, 13, 0, "          ");
    mvwaddstr(game_text, 14, 0, buff_string);
    wattroff(game_text, COLOR_PAIR(5));
    wrefresh(game_text);

    // Set up choices around viewing inventory
    choice = num_choices = 0;
    reset_choices();
    strncpy(choices[num_choices], "View Worn Inventory", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "View Backpack", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "Level up", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "Go back...", MAX_CHOICE_LEN); num_choices++;
    choice = choose(select, num_choices, "Please choose: ");
    switch (choice) {
      case 0: view_worn(game_text, select, player); break;
      case 1: view_pack(game_text, select, player); break;
      case 2: level_up(game_text, select, player); break;
      case 3: break;
      default: break;
    }
    refresh_stats(stats, player);
    if (choice == 3) break; // head back to town choices
  }
}

// load all saved character data into saved games array
int load_saves() {
  FILE *fp;
  int count = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "rb");
    // Add all saves to array of saved games
    count = fread(saved_games, sizeof(pc), SAVE_SLOTS, fp);
  }

  return count;
}

// choose a saved game from the list of saves
int choose_save(WINDOW *game_text, WINDOW *select, int saves) {
  int choice, num_choices = 0;
  char save_text[96];

  reset_choices();

  for (int i = 0; i < saves; i++) {
    snprintf(save_text, 95, "Slot: %d | Name: %s | Class: %s | Level: %d | Time: %s", i + 1, saved_games[i].name, 
    saved_games[i].role, saved_games[i].lvl, ctime(&(saved_games[i].date_time)));
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
int save_game(WINDOW *game_text, WINDOW *select, pc player, int saves) {
  int save_slot = 0;
  FILE *fp;

  // get time and store in player struct to show with list of saves
  time_t unix_time = time(NULL);
  if (unix_time == -1) {
    mvwaddstr(game_text, 0, 0, "The time() function failed, unable to record time with player save...");
    wrefresh(game_text);
    pause_text(select);
  } else {
    player.date_time = unix_time;
  }

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
    fwrite(saved_games, sizeof(pc), saves, fp);
    //fwrite(&player, sizeof(pc), 1, fp);
    fclose(fp);
  }

  return saves;
}
