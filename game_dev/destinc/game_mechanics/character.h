// Functions for creating and working with players

void create_character(pc *player) {
  strncpy(player->name, "Bob", 32);
  strncpy(player->role, "Knight", 16);
  player->hp = 8;
}
