// Functions for creating and working with players

void create_character(pc *player) {
  strncpy(player->name, "Bob", 32);
  strncpy(player->role, "Knight", 16);
  player->hp = 8;
}

void save_game(pc player) {
  FILE *fp;
  int ch, pos = 0;

  if (file_there(save_file)) {
    fp = fopen(save_file, "w+");
    while ((ch = fgetc(fp)) != EOF) {
      pos++;
      if (ch == '+' || ch == '\n') break;
    }
    fseek(fp, pos, SEEK_SET);
    fprintf(fp, "\n=Name: %s, Role: %s, HP: %d _", player.name, player.role, player.hp);
    fclose(fp);
  }
}
