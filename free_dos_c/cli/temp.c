#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void print_usage() {
  printf("Usage: temp.out -c <temp> | temp.out -f <temp> \n");
  exit(2);
}

void print_fahrenheit(float temp) {
  float f = ((temp * 9) / 5) + 32;
  printf("%.2f centigrade is %.2f fahrenheit\n", temp, f);
}

void print_centigrade(float temp) {
  float f = ((temp - 32) * 5) / 9;
  printf("%.2f fahrenheit is %.2f centigrade\n", temp, f);
}

int main(int argc, char **argv) {
  if (argc < 3) print_usage();
  int option;
  int cflag = 0, fflag = 0;

  while ((option = getopt(argc, argv, "c:f:")) != -1) {
    switch (option) {
      case 'c': 
        if (cflag) print_usage();
        else {
          cflag++;
          fflag++;
        }
        print_fahrenheit(atof(optarg)); break;
      case 'f': 
        if (fflag) print_usage();
        else {
          fflag++;
          cflag++;
        }
        print_centigrade(atof(optarg)); break;
      default: printf("Usage: %s -c or -f temp_to_convert\n", argv[0]);
    }
  }

  return 0;
}
