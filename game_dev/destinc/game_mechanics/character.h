// Functions for creating and working with players

#define BUFF 256  // maximum size of character buffer

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

// load character data into player struct
// future: load all saves and then let player choose one
void load_game(mob *player) {
  FILE *fp;
  //int counter = 0;
  mob save;

  if (file_there(save_file)) {
    fp = fopen(save_file, "rb");
    while(fread(&save, sizeof(mob), 1, fp) == 1)
    {
      strncpy(player->name, save.name, 32);
      strncpy(player->role, save.role, 16);
      strncpy(player->desc, save.desc, 256);
      player->str       = save.str;
      player->dex       = save.dex;
      player->con       = save.con;
      player->intel     = save.intel;
      player->wis       = save.wis;
      player->cha       = save.cha;
      player->dmg       = save.dmg;
      player->armor     = save.armor;
      player->max_hp    = save.max_hp;
      player->cur_hp    = save.cur_hp;
      player->dodge     = save.dodge;
      player->max_hp    = save.max_hp;
      player->max_mana  = save.max_mana;
      player->cur_mana  = save.cur_mana;
      player->xp        = save.xp;
      player->lvl       = save.lvl;
      player->coin      = save.coin;
      player->to_hit    = save.to_hit;
      player->dice_dam  = save.dice_dam;
      player->dice_num  = save.dice_num;
      player->is_pc     = save.is_pc;
      player->type      = save.type;
      player->alignment = save.alignment;
      for (int i = 0; i < MAX_BUFFS; i++) player->buffs[i] = save.buffs[i];
      //count++;
    }
  }
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
