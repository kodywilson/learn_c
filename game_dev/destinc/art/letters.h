// Letters to print out

typedef char letter_a[5][10];

#define LETTERS 1  // number of big letters

typedef struct Letter {
  letter_a let;       // will store the letter
  int  capital;   // set to 1 for true
} letter_s;

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
    "    #    ",
};

letter_a i_up = {
    " ####### ",
    "    #    ",
    "    #    ",
    "    #    ",
    " ####### ",
};

letter_a n_up = {
    " ##    # ",
    " # #   # ",
    " #  #  # ",
    " #   # # ",
    " #    ## ",
};

letter_a y_up = {
    " #     # ",
    "   # #   ",
    "    #    ",
    "    #    ",
    "    #    ",
};

letter_s letters[LETTERS] = {
  // D
  {
    {
      " ######  ",
      "#      # ",
      "#       #",
      "#      # ",
      "#######  "
    },
    1          // capital, set to 1 for true
  }
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