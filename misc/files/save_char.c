#include<stdio.h>
#include<stdlib.h>

#define MAX_BUFFS 4

// shared struct for all mobs, pc and npc
typedef struct Mob {
  char name[32];  // mob name
  char role[16];  // mob class
  char desc[256]; // mob description
  int  str;       // --= Begin basic stat block
  int  dex;
  int  con;
  int  intel;
  int  wis;
  int  cha;       // End basic stat block =--
  int  dmg;       // innate damage bonus - mostly used for monsters
  int  armor;     // armor - AC - until we get equipment, it is armor and shield (if any)
  int  max_hp;    // max hit points (hp) per level - class specific + Con bonus
  int  cur_hp;    // current hit points
  int  dodge;     // class specific bonus to dodge -- may drop this at some point
  int  max_mana;  // max mana per level for spells and special attacks
  int  cur_mana;  // current mana
  int  xp;        // Experience points - earned when mob is defeated or amount a player has
  int  lvl;       // mob level, reflects relative power
  int  coin;      // money the player earns when mob is defeated or the amount a player has
  int  to_hit;    // modifier to chance to hit
  int  dice_dam;  // damage dice. 6 for 1d6, 12 for 1d12, etc.  -- used with dice_num (1d6) = (dice_num x dice_dam)
  int  dice_num;  // number of damage dice. 2 for 2d6, 1 for 1d8, etc. -- used with dice_dam
  int  buffs[MAX_BUFFS];  // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc.
  int  is_pc;     // is this a player character? combat calculations vary a bit so we need to know
  int  type;      // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
  int  alignment; // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
} mob;            // 3 = true neutral, 4 = chaotic good

mob wizard = {
    "Wizard",     // name
    "Wizard",     // role
    "Wizards can cast damaging spells and have a pet familiar.",
    8,            // str       - strength
    12,           // dex       - dexterity
    12,           // con       - constitution
    16,           // intel     - intelligence
    12,           // wis       - wisdom
    12,           // cha       - charisma
    0,            // dmg       - innate damage bonus
    0,            // armor     - innate armor (defense) bonus
    7,            // max_hp    - max hp earned per level (1d8 + Con modifier)
    7,            // cur_hp    - current hp
    0,            // dodge     - innate bonus to dodge
    16,           // max_mana  - max mana per level
    16,           // cur_mana  - current mana
    0,            // xp        - experience points
    1,            // level     - current level
    3,            // coin      - money
    2,            // modifier to chance to hit - proficiency bonus for players
    6,            // damage dice - 6 for quarterstaff
    1,            // number of damage dice. 1 for quarterstaff, so wizard can do 1d6 damage.
    {0, 0, 0, 0}, // start with 4 buff slots. Use lookup table for int values. 1 in 0 index = food buff, etc. See below!
    1,            // is this a player character? combat calculations vary a bit so we need to know
    0,            // 0 = humanoid, 1 = animal, 2 = undead, 3 = goblinoid, etc. Will use a look up table
    3             // 0 = lawful, good, 1 = lawful, neutral, 2 = lawful, evil, etc. Use look up table
};               // 3 = true neutral, 4 = chaotic good

// struct employee
// {
//     char name[50];
//     char designation[50];
//     int age;
//     float salary;
// } employee;

int main()
{
    int chars;
    FILE *fp;

    fp = fopen("wizard.txt", "wb");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Testing fwrite() function: \n\n");

    chars = fwrite(&wizard, sizeof(wizard), 1, fp);
    printf("Number of items written to the file: %d\n", chars);

    fclose(fp);
    return 0;
}
