// later this will we broken out into different categories
// for now it will be weapons, spell effects, mobs, etc.

#define FRAME_HEIGHT 7
#define FRAME_WIDTH  12

typedef char frame[FRAME_HEIGHT][FRAME_WIDTH];

// Wizard animated frames
frame wizard_frames[2] = {
  {
    "            ",
    "            ",
    "    _^_     ",
    "    (\")   . ",
    "  __| |\\_/  ",
    "   /  \\     ",
    "  /_|_|_    "
  },
  {
    "            ",
    "            ",
    "    _^_     ",
    "    (\")     ",
    "   \\| |\\___.",
    "   /  \\     ",
    "  /_/_/_    "
  }
};

/*
      _^_
      (")   .
    __| |\_/
     /  \
    /_|_|_


       _^_
       (")
     \/ /\___.
     /  \
    /_/_/_

char wizard[PIC_HEIGHT][PIC_WIDTH] = {
  "            ",
  "            ",
  "    _^_     ",
  "    (\")   . ",
  "  __| |\\_/  ",
  "   /  \\     ",
  "  /_|_|_    "
};*/