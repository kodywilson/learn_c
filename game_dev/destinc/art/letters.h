// Special text handling and printing functions
// NOTE: Currently, this only supports ASCII

#define DOOM 0     // assign index to font name - still needs lowercase to be added
//#define IVRIT 1  //  not set up yet
//#define LARRY3D  //  not set up yet

// font struct contains:    2d arrays of both capital and lowercase letters
// one array with heights:  height[upper, lower]
// one 2d array of widths:  [6, 7, 6, 6, ...] width of each uppercase character
typedef struct Font {   //  [5, 5, 6, 6, ...] width of each lowercase character
  char up[9][356];      //  uppercase letters
  //char low[9][356]; ; //  lowercase letters
  int height[2];        //  varies between upper and lowercase: height[upper][lower] ie. [6, 8]
  int width[2][26];     //  first array is width of uppercase, second is width of lowercase, each character
} font_t;

// see lower part of the file for font samples - they look weird in arrays because of the escape characters
// make sure to escape characters that need it like back slashes
// this font is not complete, needs lowercase letters added
font_t fonts[1] = {
  {    // Doom font
    {  // uppercase
      "  ___   ______   _____  ______   _____  ______   _____   _   _   _____     ___   _   __  _      ___  ___  _   _   _____  ______   _____  ______   _____   _____   _   _   _   _   _    _  __   __ __   __  ______",
      " / _ \\  | ___ \\ /  __ \\ |  _  \\ |  ___| |  ___| |  __ \\ | | | | |_   _|   |_  | | | / / | |     |  \\/  | | \\ | | |  _  | | ___ \\ |  _  | | ___ \\ /  ___| |_   _| | | | | | | | | | |  | | \\ \\ / / \\ \\ / / |___  /",
      "/ /_\\ \\ | |_/ / | /  \\/ | | | | | |__   | |_    | |  \\/ | |_| |   | |       | | | |/ /  | |     | .  . | |  \\| | | | | | | |_/ / | | | | | |_/ / \\ `--.    | |   | | | | | | | | | |  | |  \\ V /   \\ V /     / / ",
      "|  _  | | ___ \\ | |     | | | | |  __|  |  _|   | | __  |  _  |   | |       | | |    \\  | |     | |\\/| | | . ` | | | | | |  __/  | | | | |    /   `--. \\   | |   | | | | | | | | | |/\\| |  /   \\    \\ /     / /  ",
      "| | | | | |_/ / | \\__/\\ | |/ /  | |___  | |     | |_\\ \\ | | | |  _| |_  /\\__/ / | |\\  \\ | |____ | |  | | | |\\  | \\ \\_/ / | |     \\ \\/' / | |\\ \\  /\\__/ /   | |   | |_| | \\ \\_/ / \\  /\\  / / /^\\ \\   | |   ./ /___",
      "\\_| |_/ \\____/   \\____/ |___/   \\____/  \\_|      \\____/ \\_| |_/  \\___/  \\____/  \\_| \\_/ \\_____/ \\_|  |_/ \\_| \\_/  \\___/  \\_|      \\_/\\_\\ \\_| \\_| \\____/    \\_/    \\___/   \\___/   \\/  \\/  \\/   \\/   \\_/   \\_____/"
    },
    {6, 8}, // height [upper_case][lower_case] ie. [6][8]
    {//A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z      // enter width for each uppercase character
      {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 7, 7, 7},    // width uppercase
      {7, 7, 6, 7, 6, 5, 7, 7, 3, 5, 6, 3, 11, 7, 7, 7, 7, 6, 5, 5, 7, 7, 10, 6, 7, 5}   // width lowercase
    }//a, b, c, d, e, f, g, h, i, j, k, l,  m, n, o, p, q, r, s, t, u, v,  w, x, y, z    // enter width for each lowercase character
  }
};

//
// functions for manipulating ascii art characters

// pass letter to see if capital - is_capital('D')
// Many of my arrays are indexed such that capital is indexed 0. Use !is_capital() when you
// need to get back zero for capital.
int is_capital(int letter) {
  int result;
  if ( letter >= 65 && letter <= 90) result = 1;
  if ( letter >= 97 && letter <= 122) result = 0;
  return result;
}

// returns position in English alphabet for letter
int letter_position(int letter) {
  int position;
  if (is_capital(letter)) position = letter - 'A';  // ie. D is 68, 68 - 65 = 3  Array indexing starts at 0
  if (!is_capital(letter)) position = letter - 'a'; // so 3 is returned which is the fourth array position
  return position;                                  // mathing our expectation as D is the 4th letter of the alphabet
}

// returns position in array where letter starts
// send letter and font you want - letter_start('A', doom)
int letter_start(int letter, font_t font) {
  int start = 0;
  int space= 1;       // later, change this to passed argument if there are fonts spaced differently
  if (is_capital(letter)) {    // this is a capital letter
    for (int i = 0; i < letter - 'A'; i++) start = start + font.width[0][i] + space;  // add up to target letter start
  } else {                     // this is a lowercase letter
    for (int i = 0; i < letter - 'a'; i++) start = start + font.width[1][i]  + space; // add up to target letter start
  }
  return start;
}

//void bigly(WINDOW *win, int font, char *text) {
void bigly(WINDOW *win, int font, char *text) {
  int ch, text_y, text_x, start, letter_width, win_y, win_x;

  getmaxyx(win, win_y, win_x);

  // where to start printing the letters - later, make these arguments
  text_y = (win_y / 2 - 5) / 2;
  text_x = (win_x - (strlen(text) * (fonts[font].width[0][0]) + 1)) / 2; // estimate size using 1st character

  // Iterate over text and print the letters
  for (int let = 0; text[let] != '\0'; let++) {
    ch            = text[let];
    letter_width  = fonts[font].width[!is_capital(ch)][letter_position(ch)];
    start         = letter_start(ch, fonts[font]);
    for (int i = start; i < start + letter_width; i++) {
      text_y = (win_y / 2 - 5) / 2;
      for (int j = 0; j < fonts[font].height[!is_capital(ch)]; j++) { // j < height
        if (is_capital(ch)) mvwaddch(win, text_y, text_x, fonts[font].up[j][i]);
        //else mvaddch(text_y, text_x, fonts[font].low[j][i + letter_width]); // need to add lowercase to font first
        text_y++;
      }
      text_x++;
    }
    text_x++; // accounts for space between each character

    wrefresh(win);
    napms(100);
  }
}

//
// FONT SAMPLES
//

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

// old code
// some notes on this old code :) So there are a number of ways to handle ascii art characters. I have now opted for the 
// array slice method where I store each alphabet in large arrays and slice off the letters as needed.
// Originally, I had an array of letter structs. The idea was to store uppercase, lowercase, and metadata from each font as letter
// structs in an array of 26 characters (for US English). That approach has definite advantages, making it very easy to ask the array
// for any particular letter [0] = a, [1] = b, and so on. However, the tedium of creating each letter drove me to try the array slice method...

// // letter arrays - size according to font being used
// typedef char letter_a[5][10];  // fits custom destiny letters I created
// typedef char doom_a_up[6][8];   // Doom uppercase letter
// typedef char doom_a_low[8][8];  // Doom lowercase letter

// // each letter struct will contain capital and lowercase versions of each font
// typedef struct Letter {
//   doom_a_up  doom_up;        // Doom font uppercase
//   doom_a_low doom_low;       // Doom font lowercase
// } letter_s;

// letter_a a_up = {
//     "    #    ",
//     "   # #   ",
//     "  #####  ",
//     " #     # ",
//     "#       #"
// };

// letter_a e_up = {
//     "######## ",
//     "#        ",
//     "#####    ",
//     "#        ",
//     "######## "
// };

// letter_a s_up = {
//     " ######  ",
//     "#        ",
//     " ######  ",
//     "       # ",
//     " ######  "
// };

// letter_a t_up = {
//     " ####### ",
//     "    #    ",
//     "    #    ",
//     "    #    ",
//     "    #    "
// };

// letter_a i_up = {
//     " ####### ",
//     "    #    ",
//     "    #    ",
//     "    #    ",
//     " ####### "
// };

// letter_a n_up = {
//     " ##    # ",
//     " # #   # ",
//     " #  #  # ",
//     " #   # # ",
//     " #    ## "
// };

// letter_a y_up = {
//     " #     # ",
//     "   # #   ",
//     "    #    ",
//     "    #    ",
//     "    #    "
// };

// letter_s letters[LETTERS] = {
//   // A
//   {
//     { // Doom upper A
//       "  ___  ",
//       " / _ \\ ",
//       "/ /_\\ \\",
//       "|  _  |",
//       "| | | |",
//       "\\_| |_/"
//     },
//     { // Doom lower a
//       "       ",
//       "       ",
//       "  __ _ ",
//       " / _` |",
//       "| | | |",
//       "\\_| |_/",
//       "       ",
//       "       "
//     }
//   },
//   // B
//   {
//     { // Doom upper B
//       "______ ",
//       "| ___ \\",
//       "| |_/ /",
//       "| ___ \\",
//       "| |_/ /",
//       "\\____/ "
//     },
//     { // Doom lower b
//       " _     ",
//       "| |    ",
//       "| |    ",
//       "| '_ \\ ",
//       "| | | |",
//       "|_.__/ ",
//       "       ",
//       "       "
//     }
//   }/*,
//   // S
//   {
//     {
//       " ######  ",
//       "#        ",
//       " ######  ",
//       "       # ",
//       " ######  "
//     },
//     1                // capital, set to 1 for true
//   },
//   // T
//   {
//     {
//       " ####### ",
//       "    #    ",
//       "    #    ",
//       "    #    ",
//       "    #    "
//     },
//     1                // capital, set to 1 for true
//   },
//   // I
//   {
//     {
//       " ####### ",
//       "    #    ",
//       "    #    ",
//       "    #    ",
//       " ####### "
//     },
//     1                // capital, set to 1 for true
//   },
//   // N
//   {
//     {
//       " ##    # ",
//       " # #   # ",
//       " #  #  # ",
//       " #   # # ",
//       " #    ## "
//     },
//     1                // capital, set to 1 for true
//   },
//   // Y
//   {
//     {
//       " #     # ",
//       "   # #   ",
//       "    #    ",
//       "    #    ",
//       "    #    "
//     },
//     1                // capital, set to 1 for true
//   }
//   // D
//   {
//     {
//       " ######  ",
//       "#      # ",
//       "#       #",
//       "#      # ",
//       "#######  "
//     },
//     1                // capital, set to 1 for true
//   },
//   // E
//   {
//     {
//       "######## ",
//       "#        ",
//       "#####    ",
//       "#        ",
//       "######## "
//     },
//     1                // capital, set to 1 for true
//   },
//   // S
//   {
//     {
//       " ######  ",
//       "#        ",
//       " ######  ",
//       "       # ",
//       " ######  "
//     },
//     1                // capital, set to 1 for true
//   },
//   // T
//   {
//     {
//       " ####### ",
//       "    #    ",
//       "    #    ",
//       "    #    ",
//       "    #    "
//     },
//     1                // capital, set to 1 for true
//   },
//   // I
//   {
//     {
//       " ####### ",
//       "    #    ",
//       "    #    ",
//       "    #    ",
//       " ####### "
//     },
//     1                // capital, set to 1 for true
//   },
//   // N
//   {
//     {
//       " ##    # ",
//       " # #   # ",
//       " #  #  # ",
//       " #   # # ",
//       " #    ## "
//     },
//     1                // capital, set to 1 for true
//   },
//   // A
//   {
//     {
//       " #     # ",
//       "   # #   ",
//       "    #    ",
//       "    #    ",
//       "    #    "
//     },
//     1                // capital, set to 1 for true
//   }*/
// };

// // letter letters[26];
// // letters[0] = d_up;

// // void bigly(char ch) {
// //     int destiny_y;
// //     int let;

// //     switch (ch) {
// //         case 'D': let = 0;
// //         case 'e': let = 1;
// //         case 's': let = 2;
// //         case 't': let = 3;
// //         case 'i': let = 4;
// //         case 'n': let = 5;
// //         case 'y': let = 6;
// //         //default: let = a_up; // no
// //     };
// //     for (int j = 0; j < 10; j++) {
// //       destiny_y = 4 + i;
// //       mvaddstr(destiny_y, 10, letters[let][j]);
// //     }
// // }
