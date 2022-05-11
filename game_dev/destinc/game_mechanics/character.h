// Functions for creating and working with players

#define BUFF 256  // maximum size of character buffer

// fill out character stats, name, source (chosen) class, target player
// could have looped and sent data to update_character...
void build_character(char name[32], pc chosen_class, pc *player) {
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
}

// character selection
void create_character(WINDOW *game_text, WINDOW *select, WINDOW *input, pc *player) {
  int class_choice, y_n;
  char name[32];
  wclear(game_text);
  mvwaddstr(game_text, 3, 3, "Select your player's class or role. This will determine");
  mvwaddstr(game_text, 4, 3, "your unique skills and abilities.");
  wrefresh(game_text);
  // create loop so player can check out each class if they want
  class_choice = choose(select, class_list, PCS);
  mvwprintw(game_text, 6, 3, "%s", player_classes[class_choice].desc);
  mvwprintw(game_text, 9, 3, "Would you like to play as a %s?", player_classes[class_choice].name);
  wrefresh(game_text);
  y_n = choose(select, yes_no, 2);
  if (y_n == 0) {
    wclear(select);
    mvwprintw(select, 1, 1, "Please enter your character's name to get adventuring!");
    echo();    // allow player to see name they are entering
    wrefresh(select);
    napms(1000);
    mvwprintw(input, 1, 1, "Name: ");
    wgetnstr(input, name, 31);
    noecho();  // turn off key entry echo to terminal
    clear_box(input);
    // generate starting stats for the player
    build_character(name, player_classes[class_choice], player);
  }
}

// update character - name, role, stats, etc.
// tokens indicate what is being updated
void update_character(int token, char val[BUFF], pc *player) {
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
    default: break;
  }
}

// load character data into player struct
// future: send name and load that particular character
void load_game(pc *player) {
  FILE *fp;
  int ch, counter = 0, pos = 0, token = 0;
  char buffer[BUFF];

  if (file_there(save_file)) {
    fp = fopen(save_file, "r");
    while ((ch = fgetc(fp)) != EOF) {
      pos++; // might use this if I end up using fseek
      if (ch == ':') {  // very, very crude token parser
        while ((ch = fgetc(fp)) != ',') {
          if (ch == '_') break;
          buffer[counter] = ch;
          counter++;
        }
        buffer[counter] = '\0';
        update_character(token, buffer, player);
        token++;
        // send save info to struct
        for (int i = 0; i < BUFF; i++) buffer[i] = '\0'; // clear buffer for next token
        counter = 0; // reset counter for next buffer fill
      }
    }
  }
}

// write player data to save file
void save_game(pc player) {
  FILE *fp;
  //int ch, pos = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "w");
    // eventually this will support multiple saves
    // will need to read in all the data and rewrite it all - use array of structs with token parser
    /*while ((ch = fgetc(fp)) != EOF) {
      pos++;
      if (ch == '+' || ch == '\n') break;
    }
    fseek(fp, pos, SEEK_SET);*/
    fprintf(fp,
    "=name:%s,role:%s,desc:%s,str:%d,dex:%d,con:%d,intel:%d,wis:%d,cha:%d,dmg:%d,armor:%d,max_hp:%d,cur_hp:%d,dodge:%d,max_mana:%d,cur_mana:%d,xp:%d,lvl:%d,coin:%d,_",
    player.name, player.role, player.desc, player.str, player.dex, player.con, player.intel, player.wis, player.cha,
    player.dmg, player.armor, player.max_hp, player.cur_hp, player.dodge, player.max_mana, player.cur_mana, player.xp, player.lvl, player.coin);
    fclose(fp);
  }
}
