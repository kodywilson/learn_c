#include "game_mechanics/dice.h"
#include "entities/items.h"              // armor, weapons, jewelry, etc.
#include "entities/mob.h"                // generic structure for both npc and pc
#include "entities/pc.h"                 // player characters
#include "entities/npc.h"                // non player characters (usually monsters)
#include "art/text.h"
#include <ncurses.h>                     // console control api
#include <pthread.h>                     // concurrency for posix systems
#include "art/letters.h"                 // big ascii letters
#include "art/assets.h"                  // ascii art
#include "art/graphics.h"
#include "art/animations/animations.h"   // load animations
#include "game_mechanics/choices.h"      // handle making choices
#include "game_mechanics/file.h"         // create and setup game files
#include "game_mechanics/character.h"    // inventory, character creation, etc.
#include "game_mechanics/combat.h"       // fighting
#include "entities/locations.h"          // various places you can visit in the game
