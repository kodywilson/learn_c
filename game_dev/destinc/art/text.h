#include <string.h>

#define INTRO_TEXT 8
#define BOSS_TEXT 9
#define MOVE_TEXT 12

char *intro_scene_text[MOVE_TEXT] = 
  {"DREAM", "AGAIN", "FLAMES", "TERROR",
   "AWAKE", "ALIVE", "HOPE",
   "DESTINY"};

char *rand_move_text[MOVE_TEXT] = 
  {"You hear rats feet scampering across broken glass.", "Fresh air mixes with foul as your torch flickers...", "You smell something terrible.", "The smell of rotting flesh fills your lungs.",
   "You hear a faint groan in the distance.", "A howl of wind passes over you and your torch flickers.", "You notice strange markings on the walls.",
   "Your torch flickers briefly, and you hear the sound of water.", "You hear the sound of water dripping.", "A breeze causes your torch to flicker.",
   "Fear grips your heart as you step into this area.", "You feel an eerie sensation..."};

char *rand_boss_text[MOVE_TEXT] = 
  {"The moment you enter this area, you feel a keen sense of dread...", "Your nose is assailed by a gut wrenching smell.",
   "It is quite. Too quite...", "A low and gutteral sounds meets your ears.", "You hear something and it does not sound good. Not at all.",
   "Is your torch flickering or is that your hand shaking in fear?", "You can hardly believe what rushes toward you!",
   "You knew this day would come, are you ready?", "All your hard work has made you ready for this. Was it enough?"};

char *tavern_table = "You find a seat at an open table and the waiter approaches to take your order.\n\nThe waiter tells you the food is so darn good, that it will help sustain your health as you travel in the dungeon.\n\nYou order and enjoy a delicious meal, you really do feel swell!";

char *tavern_bar = "You sally up to the bar and the barkeep approaches to take your order.\n\nThe barkeep tells you the wine is so fancy, that it will help sustain your mana as you travel in the dungeon.\n\nYou swirl the wine, sniff, then take a sip, you really do feel superior!";

char *tavern_rest = "You pay for a small room and get a good night of rest.";
