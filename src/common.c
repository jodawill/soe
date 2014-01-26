#include <stdio.h>
#include <string.h>
#include <soe.h>

void wait() {
 printf("Press <Enter> to continue.\n");
 fpurge(stdin);
 getchar();
}

void eval_args(int argc, char *argv[]) {
 for (int c = 1; c < argc; c++) {
  if (strcmp(argv[c], "-v") == 0) {
   verbose = 1;
  }
 }
}

void display_matrix(int nou, double mat[nou][nou + 1]) {
 for (int c = 0; c < nou; c++) {
  printf(" | ");
  for (int d = 0; d <= nou; d++) {
   printf(" %lf ", mat[c][d]);
  }
  printf(" | \n");
 }
 printf("\n\n");
}

void display_result(int nou, double mat[nou][nou + 1]) {
 printf("\nResult:\n");
 for (int row = 0; row < nou; row++) {
  printf("x_%d = %lf\n", row + 1, mat[row][nou]);
 }
}
