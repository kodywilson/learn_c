#if defined(_WIN32)
#define NUMS 13
#elif defined linux
#define NUMS 4
#endif

int numby(void) {
  return NUMS;
}

