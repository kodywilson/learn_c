#include <stdio.h>

int main() {
  FILE *fp;
  float f = 100.13;
  float *f_p = &f;
  int arr[5]={100,320,4,678,220};

  fp = fopen("test.txt", "w");

  if (fp == NULL) {
    puts("file could not be opened");
    return 1;
  }

  //fwrite(arr, sizeof(arr), 1, fp);
  fwrite(f_p, sizeof(f_p), 1, fp);

  fclose(fp);

  return 0;
}
