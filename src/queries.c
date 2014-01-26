#include <stdio.h>

static int const MAX_UNKNOWNS = 1024;

// Query for number of unknowns
int get_nou() {
 int nou;
 for (int check = 0; !check;) {
  printf("Enter the number of unknowns. ");
  scanf("%d", &nou);
  if (nou >= MAX_UNKNOWNS) {
   printf("Too many unknowns.\n");
  } else {
   check = 1;
  }
 }
 return nou;
}

// Query for equations array
void fill_matrix(int nou, double mat[nou][nou + 1]) {

 for (int c = 0; c < nou; c++) {
  printf("Enter the cofficients for the variables in equation #%d:\n", c + 1);

  for (int d = 0; d < nou; d++) {
   printf("c_%d = ", d + 1);
   scanf(" %lf", &mat[c][d]);
  }

  printf("Enter the right-hand side of equation #%d: ", c + 1);
  scanf(" %lf", &mat[c][nou]);
 }
}
