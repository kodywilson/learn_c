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

// update character - name, role, stats, etc.
// tokens indicate what is being updated
// another valid approach would be to have two functions, one for
// strings and one for ints
void update_character(int token, char val[BUFF], mob *player) {
  switch (token) {
    case 0: strncpy(player->name, val, 32); break;
    case 1: strncpy(player->role, val, 16); break;
    case 2: strncpy(player->desc, val, 256); break;
    case 3:  player->str       = atoi(val); break;
    case 4:  player->dex       = atoi(val); break;
    case 5:  player->con       = atoi(val); break;
    case 6:  player->intel     = atoi(val); break;
    case 7:  player->wis       = atoi(val); break;
    case 8:  player->cha       = atoi(val); break;
    case 9:  player->dmg       = atoi(val); break;
    case 10: player->armor     = atoi(val); break;
    case 11: player->max_hp    = atoi(val); break;
    case 12: player->cur_hp    = atoi(val); break;
    case 13: player->dodge     = atoi(val); break;
    case 14: player->max_mana  = atoi(val); break;
    case 15: player->cur_mana  = atoi(val); break;
    case 16: player->xp        = atoi(val); break;
    case 17: player->lvl       = atoi(val); break;
    case 18: player->coin      = atoi(val); break;
    case 19: player->to_hit    = atoi(val); break;
    case 20: player->dice_dam  = atoi(val); break;
    case 21: player->dice_num  = atoi(val); break;
    case 22: player->is_pc     = atoi(val); break;
    case 23: player->type      = atoi(val); break;
    case 24: player->alignment = atoi(val); break;
    default: break;
  }
}

// load all saved character data into saved games array
int load_saves() {
  FILE *fp;
  int count = 0;
  mob save;

  if (file_there(save_file)) {
    fp = fopen(save_file, "rb");
    // Add all saves to array of saved games
    while(fread(&save, sizeof(mob), 1, fp) == 1)
    {
      strncpy(saved_games[count].name, save.name, 32);
      strncpy(saved_games[count].role, save.role, 16);
      strncpy(saved_games[count].desc, save.desc, 256);
      saved_games[count].str       = save.str;
      saved_games[count].dex       = save.dex;
      saved_games[count].con       = save.con;
      saved_games[count].intel     = save.intel;
      saved_games[count].wis       = save.wis;
      saved_games[count].cha       = save.cha;
      saved_games[count].dmg       = save.dmg;
      saved_games[count].armor     = save.armor;
      saved_games[count].max_hp    = save.max_hp;
      saved_games[count].cur_hp    = save.cur_hp;
      saved_games[count].dodge     = save.dodge;
      saved_games[count].max_hp    = save.max_hp;
      saved_games[count].max_mana  = save.max_mana;
      saved_games[count].cur_mana  = save.cur_mana;
      saved_games[count].xp        = save.xp;
      saved_games[count].lvl       = save.lvl;
      saved_games[count].coin      = save.coin;
      saved_games[count].to_hit    = save.to_hit;
      saved_games[count].dice_dam  = save.dice_dam;
      saved_games[count].dice_num  = save.dice_num;
      saved_games[count].is_pc     = save.is_pc;
      saved_games[count].type      = save.type;
      saved_games[count].alignment = save.alignment;
      for (int i = 0; i < MAX_BUFFS; i++) saved_games[count].buffs[i] = save.buffs[i];
      count++;
    }
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
void choose_save(WINDOW *game_text, WINDOW *select, mob *player, int saves) {
  int choice, num_choices = 0;

  for (int i = 0; i < MAX_CHOICES; i++) {
    memset(choices[i], 0, MAX_CHOICE_LEN);    // "null" array
    choice_key[i] = 99;                       // "null" array
  }

  for (int i = 0; i < saves; i++) {
    char save_text[96];
    snprintf(save_text, 95, "Slot: %d | Name: %s | Class: %s | Level: %d", i + 1, saved_games[i].name, saved_games[i].role, saved_games[i].lvl);
    strncpy(choices[num_choices], save_text, 96);
    choice_key[num_choices] = 0;
    num_choices++;
  }

  choice = choose(select, num_choices, "Please choose a saved game to load: \n");

  load_save(choice, player);
}

int check_saves() {
  int numfound = 0;

  numfound = load_saves();

  return numfound;
}

// write player data to save file
void save_game(mob player) {
  FILE *fp;
  //int count = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "wb");
    fwrite(&player, sizeof(mob), 1, fp);
    fclose(fp);
  }
}
