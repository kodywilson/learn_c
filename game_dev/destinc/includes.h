#include "game_mechanics/dice.h"
#include "entities/mob.h"                // generic structure for both npc and pc
#include "entities/pc.h"                 // player characters
#include "entities/npc.h"                // non player characters (usually monsters)
#include "art/text.h"
#include <ncurses.h>
#include "art/letters.h"
#include "art/graphics.h"
#include "art/assets.h"
#include "game_mechanics/choices.h"
#include "game_mechanics/file.h"
#include "game_mechanics/character.h"
#include "game_mechanics/combat.h"
#include "entities/locations.h"
