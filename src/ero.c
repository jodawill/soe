#include <stdio.h>
#include "soe.h"
int verbose;

// The following three functions perform the elementary row operations.
void swap_rows(int nou, int a, int b, double mat[nou][nou + 1]) {
 // Copy destination b to buffer
 double buffer[1][nou + 1];
 for (int c = 0; c <= nou; c++) {
  buffer[0][c] = mat[b][c];
 }

 // Replace row b with row a
 for (int c = 0; c <= nou; c++) {
  mat[b][c] = mat[a][c];
 }

 // Replace row a with buffer of row b
 for (int c = 0; c <= nou; c++) {
  mat[a][c] = buffer[0][c];
 }

 if (verbose) {
  printf("R%d <-> R%d\n", a + 1, b + 1);
  display_matrix(nou, mat);
 }
}

int scale_row(int nou, int r, double scale_factor, double mat[nou][nou + 1]) {
 if (scale_factor == 0) {
  printf("Error: Cannot scale a row by a factor of zero! Aborting operation.\n");
  return -1;
 }
 for (int c = 0; c <= nou; c++) {
  mat[r][c] *= scale_factor;
 }

 if (verbose) {
  printf("R%d -> R%d * %lf\n", r + 1, r + 1, scale_factor);
  display_matrix(nou, mat);
 }

 return 0;
}

void add_rowmult(int nou, int r1, int r2, double scale_factor, double mat[nou][nou + 1]) {
 if (scale_factor == 0) {
  printf("Adding a row scaled by 0 is pointless.\n");
  return;
 }
 for (int c = 0; c <= nou; c++) {
  mat[r1][c] += scale_factor * mat[r2][c];
 }

 if (verbose) {
  printf("R%d -> R%d + R%d * %lf\n", r1 + 1, r1 + 1, r2 + 1, scale_factor);
  display_matrix(nou, mat);
 }
}
