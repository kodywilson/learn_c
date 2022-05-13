// Letters to print out

// letter arrays - size according to font being used
typedef char letter_a[5][10];  // fits custom destiny letters I created
typedef char doom_a_up[6][8];   // Doom uppercase letter
typedef char doom_a_low[8][8];  // Doom lowercase letter

#define LETTERS 7  // number of big letters

// each letter struct will contain capital and lowercase versions of each font
typedef struct Letter {
  doom_a_up  doom_up;        // Doom font uppercase
  doom_a_low doom_low;       // Doom font lowercase
} letter_s;

// each font struct will contain capital and lowercase versions of each font
typedef struct Font {
  char up[9][356];      //  uppercase
  //char low[9][356]; ; //  lowercase
  int height[2];        // varies between upper and lowercase - height [upper][lower] ie. [6][8]
  int width[2][26];     // first array is width of uppercase, second is width of lowercase, each character
  //int size[2][2];       //  size y by size x - [6, 7] = uppercase dimensions 
} font;                 //                     [6, 7] = uppercase dimensions

font doom = {
  {
    "  ___   ______   _____  ______   _____  ______   _____   _   _   _____     ___   _   __  _      ___  ___  _   _   _____  ______   _____  ______   _____   _____   _   _   _   _   _    _  __   __ __   __  ______",
    " / _ \\  | ___ \\ /  __ \\ |  _  \\ |  ___| |  ___| |  __ \\ | | | | |_   _|   |_  | | | / / | |     |  \\/  | | \\ | | |  _  | | ___ \\ |  _  | | ___ \\ /  ___| |_   _| | | | | | | | | | |  | | \\ \\ / / \\ \\ / / |___  /",
    "/ /_\\ \\ | |_/ / | /  \\/ | | | | | |__   | |_    | |  \\/ | |_| |   | |       | | | |/ /  | |     | .  . | |  \\| | | | | | | |_/ / | | | | | |_/ / \\ `--.    | |   | | | | | | | | | |  | |  \\ V /   \\ V /     / / ",
    "|  _  | | ___ \\ | |     | | | | |  __|  |  _|   | | __  |  _  |   | |       | | |    \\  | |     | |\\/| | | . ` | | | | | |  __/  | | | | |    /   `--. \\   | |   | | | | | | | | | |/\\| |  /   \\    \\ /     / /  ",
    "| | | | | |_/ / | \\__/\\ | |/ /  | |___  | |     | |_\\ \\ | | | |  _| |_  /\\__/ / | |\\  \\ | |____ | |  | | | |\\  | \\ \\_/ / | |     \\ \\/' / | |\\ \\  /\\__/ /   | |   | |_| | \\ \\_/ / \\  /\\  / / /^\\ \\   | |   ./ /___",
    "\\_| |_/ \\____/   \\____/ |___/   \\____/  \\_|      \\____/ \\_| |_/  \\___/  \\____/  \\_| \\_/ \\_____/ \\_|  |_/ \\_| \\_/  \\___/  \\_|      \\_/\\_\\ \\_| \\_| \\____/    \\_/    \\___/   \\___/   \\/  \\/  \\/   \\/   \\_/   \\_____/"
  },
  {6, 8}, // height [upper][lower] ie. [6][8]
  {
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}, // width uppercase
    {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}  // width lowercase // set these
  }
};

// functions for manipulating ascii characters

// returns position in array where letter begins
// send letter, font you want - letter_position('A', doom)
// int letter_position(int letter, font *font) {

// }

letter_a a_up = {
    "    #    ",
    "   # #   ",
    "  #####  ",
    " #     # ",
    "#       #"
};

letter_a e_up = {
    "######## ",
    "#        ",
    "#####    ",
    "#        ",
    "######## "
};

letter_a s_up = {
    " ######  ",
    "#        ",
    " ######  ",
    "       # ",
    " ######  "
};

letter_a t_up = {
    " ####### ",
    "    #    ",
    "    #    ",
    "    #    ",
    "    #    "
};

letter_a i_up = {
    " ####### ",
    "    #    ",
    "    #    ",
    "    #    ",
    " ####### "
};

letter_a n_up = {
    " ##    # ",
    " # #   # ",
    " #  #  # ",
    " #   # # ",
    " #    ## "
};

letter_a y_up = {
    " #     # ",
    "   # #   ",
    "    #    ",
    "    #    ",
    "    #    "
};

/*** Doom
 *      ___   ______   _____  ______   _____  ______   _____   _   _   _____     ___   _   __  _      ___  ___  _   _   _____  ______   _____  ______   _____   _____   _   _   _   _   _    _  __   __ __   __  ______
 *     / _ \  | ___ \ /  __ \ |  _  \ |  ___| |  ___| |  __ \ | | | | |_   _|   |_  | | | / / | |     |  \/  | | \ | | |  _  | | ___ \ |  _  | | ___ \ /  ___| |_   _| | | | | | | | | | |  | | \ \ / / \ \ / / |___  /
 *    / /_\ \ | |_/ / | /  \/ | | | | | |__   | |_    | |  \/ | |_| |   | |       | | | |/ /  | |     | .  . | |  \| | | | | | | |_/ / | | | | | |_/ / \ `--.    | |   | | | | | | | | | |  | |  \ V /   \ V /     / / 
 *    |  _  | | ___ \ | |     | | | | |  __|  |  _|   | | __  |  _  |   | |       | | |    \  | |     | |\/| | | . ` | | | | | |  __/  | | | | |    /   `--. \   | |   | | | | | | | | | |/\| |  /   \    \ /     / /  
 *    | | | | | |_/ / | \__/\ | |/ /  | |___  | |     | |_\ \ | | | |  _| |_  /\__/ / | |\  \ | |____ | |  | | | |\  | \ \_/ / | |     \ \/' / | |\ \  /\__/ /   | |   | |_| | \ \_/ / \  /\  / / /^\ \   | |   ./ /___
 *    \_| |_/ \____/   \____/ |___/   \____/  \_|      \____/ \_| |_/  \___/  \____/  \_| \_/ \_____/ \_|  |_/ \_| \_/  \___/  \_|      \_/\_\ \_| \_| \____/    \_/    \___/   \___/   \/  \/  \/   \/   \_/   \_____/
 *                                                                                                                                                                                                                     
 *                                                                                                                                                                                                                     
 *             _                  _           __           _       _     _   _      _                                                            _                                                                     
 *            | |                | |         / _|         | |     (_)   (_) | |    | |                                                          | |                                                                    
 *      __ _  | |__     ___    __| |   ___  | |_    __ _  | |__    _     _  | | __ | |  _ __ ___    _ __     ___    _ __     __ _   _ __   ___  | |_   _   _  __   __ __      __ __  __  _   _   ____                  
 *     / _` | | '_ \   / __|  / _` |  / _ \ |  _|  / _` | | '_ \  | |   | | | |/ / | | | '_ ` _ \  | '_ \   / _ \  | '_ \   / _` | | '__| / __| | __| | | | | \ \ / / \ \ /\ / / \ \/ / | | | | |_  /                  
 *    | (_| | | |_) | | (__  | (_| | |  __/ | |   | (_| | | | | | | |   | | |   <  | | | | | | | | | | | | | (_) | | |_) | | (_| | | |    \__ \ | |_  | |_| |  \ V /   \ V  V /   >  <  | |_| |  / /                   
 *     \__,_| |_.__/   \___|  \__,_|  \___| |_|    \__, | |_| |_| |_|   | | |_|\_\ |_| |_| |_| |_| |_| |_|  \___/  | .__/   \__, | |_|    |___/  \__|  \__,_|   \_/     \_/\_/   /_/\_\  \__, | /___|                  
 *                                                  __/ |              _/ |                                        | |         | |                                                        __/ |                        
 *                                                 |___/              |__/                                         |_|         |_|                                                       |___/                         
 */


letter_s letters[LETTERS] = {
  // A
  {
    { // Doom upper A
      "  ___  ",
      " / _ \\ ",
      "/ /_\\ \\",
      "|  _  |",
      "| | | |",
      "\\_| |_/"
    },
    { // Doom lower a
      "       ",
      "       ",
      "  __ _ ",
      " / _` |",
      "| | | |",
      "\\_| |_/",
      "       ",
      "       "
    }
  },
  // B
  {
    { // Doom upper B
      "______ ",
      "| ___ \\",
      "| |_/ /",
      "| ___ \\",
      "| |_/ /",
      "\\____/ "
    },
    { // Doom lower b
      " _     ",
      "| |    ",
      "| |    ",
      "| '_ \\ ",
      "| | | |",
      "|_.__/ ",
      "       ",
      "       "
    }
  }/*,
  // S
  {
    {
      " ######  ",
      "#        ",
      " ######  ",
      "       # ",
      " ######  "
    },
    1                // capital, set to 1 for true
  },
  // T
  {
    {
      " ####### ",
      "    #    ",
      "    #    ",
      "    #    ",
      "    #    "
    },
    1                // capital, set to 1 for true
  },
  // I
  {
    {
      " ####### ",
      "    #    ",
      "    #    ",
      "    #    ",
      " ####### "
    },
    1                // capital, set to 1 for true
  },
  // N
  {
    {
      " ##    # ",
      " # #   # ",
      " #  #  # ",
      " #   # # ",
      " #    ## "
    },
    1                // capital, set to 1 for true
  },
  // Y
  {
    {
      " #     # ",
      "   # #   ",
      "    #    ",
      "    #    ",
      "    #    "
    },
    1                // capital, set to 1 for true
  }
  // D
  {
    {
      " ######  ",
      "#      # ",
      "#       #",
      "#      # ",
      "#######  "
    },
    1                // capital, set to 1 for true
  },
  // E
  {
    {
      "######## ",
      "#        ",
      "#####    ",
      "#        ",
      "######## "
    },
    1                // capital, set to 1 for true
  },
  // S
  {
    {
      " ######  ",
      "#        ",
      " ######  ",
      "       # ",
      " ######  "
    },
    1                // capital, set to 1 for true
  },
  // T
  {
    {
      " ####### ",
      "    #    ",
      "    #    ",
      "    #    ",
      "    #    "
    },
    1                // capital, set to 1 for true
  },
  // I
  {
    {
      " ####### ",
      "    #    ",
      "    #    ",
      "    #    ",
      " ####### "
    },
    1                // capital, set to 1 for true
  },
  // N
  {
    {
      " ##    # ",
      " # #   # ",
      " #  #  # ",
      " #   # # ",
      " #    ## "
    },
    1                // capital, set to 1 for true
  },
  // A
  {
    {
      " #     # ",
      "   # #   ",
      "    #    ",
      "    #    ",
      "    #    "
    },
    1                // capital, set to 1 for true
  }*/
};

// letter letters[26];
// letters[0] = d_up;

// void bigly(char ch) {
//     int destiny_y;
//     int let;

//     switch (ch) {
//         case 'D': let = 0;
//         case 'e': let = 1;
//         case 's': let = 2;
//         case 't': let = 3;
//         case 'i': let = 4;
//         case 'n': let = 5;
//         case 'y': let = 6;
//         //default: let = a_up; // no
//     };
//     for (int j = 0; j < 10; j++) {
//       destiny_y = 4 + i;
//       mvaddstr(destiny_y, 10, letters[let][j]);
//     }
// }

/*** Doom
 *      ___   ______   _____  ______   _____  ______   _____   _   _   _____     ___   _   __  _      ___  ___  _   _   _____  ______   _____  ______   _____   _____   _   _   _   _   _    _  __   __ __   __  ______
 *     / _ \  | ___ \ /  __ \ |  _  \ |  ___| |  ___| |  __ \ | | | | |_   _|   |_  | | | / / | |     |  \/  | | \ | | |  _  | | ___ \ |  _  | | ___ \ /  ___| |_   _| | | | | | | | | | |  | | \ \ / / \ \ / / |___  /
 *    / /_\ \ | |_/ / | /  \/ | | | | | |__   | |_    | |  \/ | |_| |   | |       | | | |/ /  | |     | .  . | |  \| | | | | | | |_/ / | | | | | |_/ / \ `--.    | |   | | | | | | | | | |  | |  \ V /   \ V /     / / 
 *    |  _  | | ___ \ | |     | | | | |  __|  |  _|   | | __  |  _  |   | |       | | |    \  | |     | |\/| | | . ` | | | | | |  __/  | | | | |    /   `--. \   | |   | | | | | | | | | |/\| |  /   \    \ /     / /  
 *    | | | | | |_/ / | \__/\ | |/ /  | |___  | |     | |_\ \ | | | |  _| |_  /\__/ / | |\  \ | |____ | |  | | | |\  | \ \_/ / | |     \ \/' / | |\ \  /\__/ /   | |   | |_| | \ \_/ / \  /\  / / /^\ \   | |   ./ /___
 *    \_| |_/ \____/   \____/ |___/   \____/  \_|      \____/ \_| |_/  \___/  \____/  \_| \_/ \_____/ \_|  |_/ \_| \_/  \___/  \_|      \_/\_\ \_| \_| \____/    \_/    \___/   \___/   \/  \/  \/   \/   \_/   \_____/
 *                                                                                                                                                                                                                     
 *                                                                                                                                                                                                                     
 *             _                  _           __           _       _     _   _      _                                                            _                                                                     
 *            | |                | |         / _|         | |     (_)   (_) | |    | |                                                          | |                                                                    
 *      __ _  | |__     ___    __| |   ___  | |_    __ _  | |__    _     _  | | __ | |  _ __ ___    _ __     ___    _ __     __ _   _ __   ___  | |_   _   _  __   __ __      __ __  __  _   _   ____                  
 *     / _` | | '_ \   / __|  / _` |  / _ \ |  _|  / _` | | '_ \  | |   | | | |/ / | | | '_ ` _ \  | '_ \   / _ \  | '_ \   / _` | | '__| / __| | __| | | | | \ \ / / \ \ /\ / / \ \/ / | | | | |_  /                  
 *    | (_| | | |_) | | (__  | (_| | |  __/ | |   | (_| | | | | | | |   | | |   <  | | | | | | | | | | | | | (_) | | |_) | | (_| | | |    \__ \ | |_  | |_| |  \ V /   \ V  V /   >  <  | |_| |  / /                   
 *     \__,_| |_.__/   \___|  \__,_|  \___| |_|    \__, | |_| |_| |_|   | | |_|\_\ |_| |_| |_| |_| |_| |_|  \___/  | .__/   \__, | |_|    |___/  \__|  \__,_|   \_/     \_/\_/   /_/\_\  \__, | /___|                  
 *                                                  __/ |              _/ |                                        | |         | |                                                        __/ |                        
 *                                                 |___/              |__/                                         |_|         |_|                                                       |___/                         
 */

/*** Ivrit
 *         _      ____     ____   ____    _____   _____    ____   _   _   ___       _   _  __  _       __  __   _   _    ___    ____     ___    ____    ____    _____   _   _  __     __ __        __ __  __ __   __  _____
 *        / \    | __ )   / ___| |  _ \  | ____| |  ___|  / ___| | | | | |_ _|     | | | |/ / | |     |  \/  | | \ | |  / _ \  |  _ \   / _ \  |  _ \  / ___|  |_   _| | | | | \ \   / / \ \      / / \ \/ / \ \ / / |__  /
 *       / _ \   |  _ \  | |     | | | | |  _|   | |_    | |  _  | |_| |  | |   _  | | | ' /  | |     | |\/| | |  \| | | | | | | |_) | | | | | | |_) | \___ \    | |   | | | |  \ \ / /   \ \ /\ / /   \  /   \ V /    / / 
 *      / ___ \  | |_) | | |___  | |_| | | |___  |  _|   | |_| | |  _  |  | |  | |_| | | . \  | |___  | |  | | | |\  | | |_| | |  __/  | |_| | |  _ <   ___) |   | |   | |_| |   \ V /     \ V  V /    /  \    | |    / /_ 
 *     /_/   \_\ |____/   \____| |____/  |_____| |_|      \____| |_| |_| |___|  \___/  |_|\_\ |_____| |_|  |_| |_| \_|  \___/  |_|      \__\_\ |_| \_\ |____/    |_|    \___/     \_/       \_/\_/    /_/\_\   |_|   /____|
 *              _                  _           __           _       _     _   _      _                                                            _                                                                        
 *       __ _  | |__     ___    __| |   ___   / _|   __ _  | |__   (_)   (_) | | __ | |  _ __ ___    _ __     ___    _ __     __ _   _ __   ___  | |_   _   _  __   __ __      __ __  __  _   _   ____                     
 *      / _` | | '_ \   / __|  / _` |  / _ \ | |_   / _` | | '_ \  | |   | | | |/ / | | | '_ ` _ \  | '_ \   / _ \  | '_ \   / _` | | '__| / __| | __| | | | | \ \ / / \ \ /\ / / \ \/ / | | | | |_  /                     
 *     | (_| | | |_) | | (__  | (_| | |  __/ |  _| | (_| | | | | | | |   | | |   <  | | | | | | | | | | | | | (_) | | |_) | | (_| | | |    \__ \ | |_  | |_| |  \ V /   \ V  V /   >  <  | |_| |  / /                      
 *      \__,_| |_.__/   \___|  \__,_|  \___| |_|    \__, | |_| |_| |_|  _/ | |_|\_\ |_| |_| |_| |_| |_| |_|  \___/  | .__/   \__, | |_|    |___/  \__|  \__,_|   \_/     \_/\_/   /_/\_\  \__, | /___|                     
 *                                                  |___/              |__/                                         |_|         |_|                                                       |___/                            
 */

 /*** Larry 3d
 *     ______      ____        ____        ____        ____        ____        ____        __  __      ______       _____      __  __      __                       __  __      _____       ____        _____       ____        ____        ______      __  __      __  __      __      __      __   __      __    __      ________     
 *    /\  _  \    /\  _`\     /\  _`\     /\  _`\     /\  _`\     /\  _`\     /\  _`\     /\ \/\ \    /\__  _\     /\___ \    /\ \/\ \    /\ \          /'\_/`\    /\ \/\ \    /\  __`\    /\  _`\     /\  __`\    /\  _`\     /\  _`\     /\__  _\    /\ \/\ \    /\ \/\ \    /\ \  __/\ \    /\ \ /\ \    /\ \  /\ \    /\_____  \    
 *    \ \ \L\ \   \ \ \L\ \   \ \ \/\_\   \ \ \/\ \   \ \ \L\_\   \ \ \L\_\   \ \ \L\_\   \ \ \_\ \   \/_/\ \/     \/__/\ \   \ \ \/'/'   \ \ \        /\      \   \ \ `\\ \   \ \ \/\ \   \ \ \L\ \   \ \ \/\ \   \ \ \L\ \   \ \,\L\_\   \/_/\ \/    \ \ \ \ \   \ \ \ \ \   \ \ \/\ \ \ \   \ `\`\/'/'   \ `\`\\/'/    \/____//'/'   
 *     \ \  __ \   \ \  _ <'   \ \ \/_/_   \ \ \ \ \   \ \  _\L    \ \  _\/    \ \ \L_L    \ \  _  \     \ \ \        _\ \ \   \ \ , <     \ \ \  __   \ \ \__\ \   \ \ , ` \   \ \ \ \ \   \ \ ,__/    \ \ \ \ \   \ \ ,  /    \/_\__ \      \ \ \     \ \ \ \ \   \ \ \ \ \   \ \ \ \ \ \ \   `\/ > <      `\ `\ /'          //'/'    
 *      \ \ \/\ \   \ \ \L\ \   \ \ \L\ \   \ \ \_\ \   \ \ \L\ \   \ \ \/      \ \ \/, \   \ \ \ \ \     \_\ \__    /\ \_\ \   \ \ \\`\    \ \ \L\ \   \ \ \_/\ \   \ \ \`\ \   \ \ \_\ \   \ \ \/      \ \ \\'\\   \ \ \\ \     /\ \L\ \     \ \ \     \ \ \_\ \   \ \ \_/ \   \ \ \_/ \_\ \     \/'/\`\     `\ \ \         //'/'___  
 *       \ \_\ \_\   \ \____/    \ \____/    \ \____/    \ \____/    \ \_\       \ \____/    \ \_\ \_\    /\_____\   \ \____/    \ \_\ \_\   \ \____/    \ \_\\ \_\   \ \_\ \_\   \ \_____\   \ \_\       \ \___\_\   \ \_\ \_\   \ `\____\     \ \_\     \ \_____\   \ `\___/    \ `\___x___/     /\_\\ \_\     \ \_\        /\_______\
 *        \/_/\/_/    \/___/      \/___/      \/___/      \/___/      \/_/        \/___/      \/_/\/_/    \/_____/    \/___/      \/_/\/_/    \/___/      \/_/ \/_/    \/_/\/_/    \/_____/    \/_/        \/__//_/    \/_/\/ /    \/_____/      \/_/      \/_____/    `\/__/      '\/__//__/      \/_/ \/_/      \/_/        \/_______/
 *                                                                                                                                                                                                                                                                                                                                      
 *                                                                                                                                                                                                                                                                                                                                      
 *               __                          __                     ___                  __                              __           ___                                                                                              __                                                                                               
 *              /\ \                        /\ \                  /'___\                /\ \          __          __    /\ \         /\_ \                                                                                            /\ \__                                                                                            
 *       __     \ \ \____        ___        \_\ \         __     /\ \__/          __    \ \ \___     /\_\        /\_\   \ \ \/'\     \//\ \         ___ ___         ___         ___       _____          __       _ __         ____   \ \ ,_\      __  __      __  __      __  __  __       __  _      __  __      ____                 
 *     /'__`\    \ \ '__`\      /'___\      /'_` \      /'__`\   \ \ ,__\       /'_ `\   \ \  _ `\   \/\ \       \/\ \   \ \ , <       \ \ \      /' __` __`\     /' _ `\      / __`\    /\ '__`\      /'__`\    /\`'__\      /',__\   \ \ \/     /\ \/\ \    /\ \/\ \    /\ \/\ \/\ \     /\ \/'\    /\ \/\ \    /\_ ,`\               
 *    /\ \L\.\_   \ \ \L\ \    /\ \__/     /\ \L\ \    /\  __/    \ \ \_/      /\ \L\ \   \ \ \ \ \   \ \ \       \ \ \   \ \ \\`\      \_\ \_    /\ \/\ \/\ \    /\ \/\ \    /\ \L\ \   \ \ \L\ \    /\ \L\ \   \ \ \/      /\__, `\   \ \ \_    \ \ \_\ \   \ \ \_/ |   \ \ \_/ \_/ \    \/>  </    \ \ \_\ \   \/_/  /_              
 *    \ \__/.\_\   \ \_,__/    \ \____\    \ \___,_\   \ \____\    \ \_\       \ \____ \   \ \_\ \_\   \ \_\      _\ \ \   \ \_\ \_\    /\____\   \ \_\ \_\ \_\   \ \_\ \_\   \ \____/    \ \ ,__/    \ \___, \   \ \_\      \/\____/    \ \__\    \ \____/    \ \___/     \ \___x___/'     /\_/\_\    \/`____ \    /\____\             
 *     \/__/\/_/    \/___/      \/____/     \/__,_ /    \/____/     \/_/        \/___L\ \   \/_/\/_/    \/_/     /\ \_\ \   \/_/\/_/    \/____/    \/_/\/_/\/_/    \/_/\/_/    \/___/      \ \ \/      \/___/\ \   \/_/       \/___/      \/__/     \/___/      \/__/       \/__//__/       \//\/_/     `/___/> \   \/____/             
 *                                                                                /\____/                        \ \____/                                                                   \ \_\           \ \_\                                                                                          /\___/                       
 *                                                                                \_/__/                          \/___/                                                                     \/_/            \/_/                                                                                          \/__/                        
 */

