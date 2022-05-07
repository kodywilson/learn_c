// Functions for creating and working with players

void create_character(pc *player) {
  strncpy(player->name, "Bob", 32);
  strncpy(player->role, "Knight", 16);
  player->hp = 8;
}

void load_game(pc *player) {
  FILE *fp;
  int ch, counter = 0, pos = 0, token = 0;
  char buffer[64];

  if (file_there(save_file)) {
    fp = fopen(save_file, "r");
    while ((ch = fgetc(fp)) != EOF) {
      pos++;
      if (ch == ':') {
        token++;
        while ((ch = fgetc(fp)) != ',') {
          if (ch == '_') break;
          buffer[counter] = ch;
          counter++;
        }
        buffer[counter] = '\0';
        switch (token) {
          case 1: strncpy(player->name, buffer, 32); break;
          case 2: strncpy(player->role, buffer, 16); break;
          case 3: player->hp = atoi(buffer); break;
          default: break;
        }
        for (int i = 0; i < 64; i++) buffer[i] = '\0'; // clear buffer for next token
        counter = 0; // reset counter for next buffer fill
      }
    }
  }
}

void save_game(pc player) {
  FILE *fp;
  //int ch, pos = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "w");
    // eventually this will support multiple saves
    /*while ((ch = fgetc(fp)) != EOF) {
      pos++;
      if (ch == '+' || ch == '\n') break;
    }
    fseek(fp, pos, SEEK_SET);*/
    fprintf(fp, "\n=Name:%s,Role:%s,HP:%d,_", player.name, player.role, player.hp);
    fclose(fp);
  }
}
