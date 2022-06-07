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

// fill out character stats, name, source (chosen) class, target player
// could have looped and sent data to update_character...
void build_character(char name[32], mob chosen_class, mob *player) {
  strncpy(player->name, name, 32);
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
  for (int i = 0; i < 4; i++) player->buffs[i] = 0;
}

// character selection
void create_character(WINDOW *game_text, WINDOW *select, WINDOW *input, mob *player) {
  int class_choice, choice;
  char name[32], class_prompt[64];

  wclear(game_text);
  mvwaddstr(game_text, 1, 1, "Your character's class (role or profession) will determine");
  mvwaddstr(game_text, 2, 1, "the unique skills and abilities available to you.");
  wrefresh(game_text);
  // create loop so player can check out each class if they want
  while(1) {
    reset_choices();
    num_choices = class_choices();
    class_choice = choose(select, num_choices, "Choose class:");
    //choice_key[choice]
    wclear(game_text);
    mvwprintw(game_text, 1, 1, "%s", player_classes[class_choice].desc);
    snprintf(class_prompt, 63, "Would you like to play as a %s?", player_classes[class_choice].name);
    wrefresh(game_text);
    reset_choices();
    num_choices = y_n();
    choice = choose(select, num_choices, class_prompt);
    if (choice == 0) {
      wclear(select);
      mvwprintw(select, 1, 1, "Please enter your character's name to get adventuring!");
      echo();    // allow player to see name they are entering
      wrefresh(select);
      napms(500);
      mvwprintw(input, 1, 1, "Name: ");
      wgetnstr(input, name, 31);
      noecho();  // turn off key entry echo to terminal
      clear_box(input);
      // generate starting stats for the player
      build_character(name, player_classes[class_choice], player);
      break;
    } else {
      mvwaddstr(game_text, 5, 1, "Right on, please make another choice:");
      wrefresh(game_text);
    }
  }
  
}

// Show Items in Backpack
void view_pack(WINDOW *game_text, WINDOW *select, mob *player) {
  wclear(game_text);
  mvwprintw(game_text, 0, 0, "---==| %s's Worn Items |==---", player->name);
  mvwaddstr(game_text, 1, 0, "          ");
  mvwprintw(game_text, 2, 0, "Armor: %s", armors[player->worn_items[0]].name);
  mvwprintw(game_text, 3, 0, "Main Hand: %s", "Club");
  mvwprintw(game_text, 4, 0, "Off Hand: %s", "");
  wrefresh(game_text);
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// Show Items Currently Being Worn
void view_worn(WINDOW *game_text, WINDOW *select, mob *player) {
  wclear(game_text);
  mvwprintw(game_text, 0, 0, "---==| %s's Backpack |==---", player->name);
  mvwaddstr(game_text, 1, 0, "          ");
  // would it be better to have the arrays in each struct be arrays of item type instead of ints?
  // then you could just iterate over the bag printing out the name of each item...player->backpack[i].name
  // it would use a lot more memory, but that might not be too significant...
  // for (int i = 0; i < BAG_SLOTS; i++) {
  //   mvwprintw(game_text, 2, 0, "Slot: %s", armors[player->worn_items[0]].name);
  // }
  // mvwprintw(game_text, 2, 0, "Slot: %s", armors[player->worn_items[0]].name);
  // mvwprintw(game_text, 3, 0, "Main Hand: %s", "Club");
  // mvwprintw(game_text, 4, 0, "Off Hand: %s", "");
  wrefresh(game_text);
  wclear(select);
  mvwaddstr(select, 0, 0, "Press any key to continue...");
  wrefresh(select);
  getch();
}

// Show character sheet - ability scores, etc.
// calculate AC
void character_sheet(WINDOW *game_text, WINDOW *select, WINDOW *stats, mob *player) {
  int choice = 0, num_choices = 0;
  char buff_string[64];

  while (choice != 2) {
    wclear(game_text);
    mvwprintw(game_text, 0, 0, "---==| %s's Character Sheet |==---", player->name);
    mvwaddstr(game_text, 1, 0, "          ");
    mvwprintw(game_text, 2, 0, "Strength: %d", player->str);
    mvwprintw(game_text, 3, 0, "Dexterity: %d", player->dex);
    mvwprintw(game_text, 4, 0, "Constitution: %d", player->con);
    mvwprintw(game_text, 5, 0, "Intelligence: %d", player->intel);
    mvwprintw(game_text, 6, 0, "Wisdom: %d", player->wis);
    mvwprintw(game_text, 7, 0, "Charisma: %d", player->cha);
    mvwaddstr(game_text, 8, 0, "          ");
    snprintf(buff_string, 64, "Buffs - Food: %c | Drink: %c | Class: %c", (player->buffs[0] == 1) ? 'Y' : 'N', (player->buffs[1] == 1) ? 'Y' : 'N', (player->buffs[2] == 1) ? 'Y' : 'N');
    mvwaddstr(game_text, 9, 0, buff_string);
    wrefresh(game_text);

    // Set up choices around viewing inventory
    reset_choices();
    strncpy(choices[num_choices], "View Worn Inventory", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "View Backpack", MAX_CHOICE_LEN); num_choices++;
    strncpy(choices[num_choices], "Back to Town", MAX_CHOICE_LEN); num_choices++;
    choice = choose(select, num_choices, "Please choose: ");
    switch (choice) {
      case 0: view_worn(game_text, select, player); break;
      case 1: view_pack(game_text, select, player); break;
      case 2: break;
      default: break;
    }
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

// load chosen saved game into player struct
void load_save(int slot, mob *player) {

  strncpy(player->name, saved_games[slot].name, 32);
  strncpy(player->role, saved_games[slot].role, 16);
  strncpy(player->desc, saved_games[slot].desc, 256);
  player->str       = saved_games[slot].str;
  player->dex       = saved_games[slot].dex;
  player->con       = saved_games[slot].con;
  player->intel     = saved_games[slot].intel;
  player->wis       = saved_games[slot].wis;
  player->cha       = saved_games[slot].cha;
  player->dmg       = saved_games[slot].dmg;
  player->armor     = saved_games[slot].armor;
  player->max_hp    = saved_games[slot].max_hp;
  player->cur_hp    = saved_games[slot].cur_hp;
  player->dodge     = saved_games[slot].dodge;
  player->max_hp    = saved_games[slot].max_hp;
  player->max_mana  = saved_games[slot].max_mana;
  player->cur_mana  = saved_games[slot].cur_mana;
  player->xp        = saved_games[slot].xp;
  player->lvl       = saved_games[slot].lvl;
  player->coin      = saved_games[slot].coin;
  player->to_hit    = saved_games[slot].to_hit;
  player->dice_dam  = saved_games[slot].dice_dam;
  player->dice_num  = saved_games[slot].dice_num;
  player->is_pc     = saved_games[slot].is_pc;
  player->type      = saved_games[slot].type;
  player->alignment = saved_games[slot].alignment;
  for (int i = 0; i < MAX_BUFFS; i++) player->buffs[i] = saved_games[slot].buffs[i];
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

// put current player data into saved_games in chosen save slot
void update_saved_games(int slot, mob player) {

  // zap the strings before copying new data
  memset(saved_games[slot].name, 0, 32);  // zap name
  memset(saved_games[slot].role, 0, 16);  // zap role
  memset(saved_games[slot].desc, 0, 256);  // zap description
  // Now update everything
  strncpy(saved_games[slot].name, player.name, 32);
  strncpy(saved_games[slot].role, player.role, 16);
  strncpy(saved_games[slot].desc, player.desc, 256);
  saved_games[slot].str       = player.str;
  saved_games[slot].dex       = player.dex;
  saved_games[slot].con       = player.con;
  saved_games[slot].intel     = player.intel;
  saved_games[slot].wis       = player.wis;
  saved_games[slot].cha       = player.cha;
  saved_games[slot].dmg       = player.dmg;
  saved_games[slot].armor     = player.armor;
  saved_games[slot].max_hp    = player.max_hp;
  saved_games[slot].cur_hp    = player.cur_hp;
  saved_games[slot].dodge     = player.dodge;
  saved_games[slot].max_hp    = player.max_hp;
  saved_games[slot].max_mana  = player.max_mana;
  saved_games[slot].cur_mana  = player.cur_mana;
  saved_games[slot].xp        = player.xp;
  saved_games[slot].lvl       = player.lvl;
  saved_games[slot].coin      = player.coin;
  saved_games[slot].to_hit    = player.to_hit;
  saved_games[slot].dice_dam  = player.dice_dam;
  saved_games[slot].dice_num  = player.dice_num;
  saved_games[slot].is_pc     = player.is_pc;
  saved_games[slot].type      = player.type;
  saved_games[slot].alignment = player.alignment;
  for (int i = 0; i < MAX_BUFFS; i++) saved_games[slot].buffs[i] = player.buffs[i];
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
  update_saved_games(save_slot, player);
  
  // write out saved_games array to our save file
  if (file_there(save_file)) {
    fp = fopen(save_file, "wb");
    fwrite(saved_games, sizeof(mob), saves, fp);
    //fwrite(&player, sizeof(mob), 1, fp);
    fclose(fp);
  }

  return saves;
}
