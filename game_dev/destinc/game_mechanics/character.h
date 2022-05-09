// Functions for creating and working with players

// character selection
void create_character(WINDOW *game_text, WINDOW *select, pc *player) {
  int class_choice, y_n;
  char name[32];
  clear_box(game_text);
  mvwaddstr(game_text, 3, 3, "Select your player's class or role. This will determine");
  mvwaddstr(game_text, 4, 3, "your unique skills and abilities.");
  wrefresh(game_text);
  // create loop so player can check out each class if they want
  class_choice = choose(select, player_classes, 2);
  mvwprintw(game_text, 6, 3, "%s", class_descriptions[class_choice]);
  mvwprintw(game_text, 7, 3, "Would you like to play as a %s?", player_classes[class_choice]);
  wrefresh(game_text);
  y_n = choose(select, yes_no, 2);
  if (y_n == 0) {
    clear_box(select);
    mvwprintw(select, 1, 1, "Please enter your character's name: ");
    echo();    // allow player to see name they are entering
    wrefresh(select);
    wgetnstr(select, name, 31);
    noecho();  // turn off key entry echo to terminal
    strncpy(player->name, name, 32);
    strncpy(player->role, player_classes[class_choice], 16);
    player->hp = 8;
  }
}

// update character - name, role
// tokens indicate what is being updated
void update_character(int token, char val[64], pc *player) {
  switch (token) {
    case 1: strncpy(player->name, val, 32); break;
    case 2: strncpy(player->role, val, 16); break;
    case 3: player->hp = atoi(val); break;
    default: break;
  }
}

/*
// update character - attributes and stats
// tokens indicate what is being updated
void update_character(int token, int val, pc *player) {
  switch (token) {
    case 1: strncpy(player->name, buffer, 32); break;
    case 2: strncpy(player->role, buffer, 16); break;
    case 3: player->hp = atoi(buffer); break;
    default: break;
  }
}*/

// load character data into player struct
// future: send name and load that particular character
void load_game(pc *player) {
  FILE *fp;
  int ch, counter = 0, pos = 0, token = 0;
  char buffer[64];

  if (file_there(save_file)) {
    fp = fopen(save_file, "r");
    while ((ch = fgetc(fp)) != EOF) {
      pos++; // might use this if I end up using fseek
      if (ch == ':') {
        token++;
        while ((ch = fgetc(fp)) != ',') {
          if (ch == '_') break;
          buffer[counter] = ch;
          counter++;
        }
        buffer[counter] = '\0';
        update_character(token, buffer, player);
        // send save info to struct
        for (int i = 0; i < 64; i++) buffer[i] = '\0'; // clear buffer for next token
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
    fprintf(fp, "\n=Name:%s,Role:%s,HP:%d,_", player.name, player.role, player.hp);
    fclose(fp);
  }
}
