#include <stdio.h>
#include "soe.h"

// Check pivot positions for 0s and reorder if needed 
void check_order(int nou, double mat[nou][nou + 1]) {
 for (int row = 0; row < nou; row++) {
  if (mat[row][row] == 0) {
   for (int ir = nou - 1; ir >= 0; ir--) {
    if (mat[ir][row] != 0) {
     swap_rows(nou, row, ir, mat);
     break;
    }
   }
  }
 }
}

void solve_matrix(int nou, double mat[nou][nou + 1]) {
 if (verbose) {
  printf("\n\n");
  display_matrix(nou, mat);
 }

 check_order(nou, mat);

 // Put matrix in row echelon form
 for (int col = 0; col < nou; col++) {
  for (int row =  col + 1; row < nou; row++) {
   if (mat[row][col] != 0 && mat[col][col] != 0) {
    add_rowmult(nou, row, col, -mat[row][col] / mat[col][col], mat);
   }
  }
 }

 // Transform to reduced echelon form
 for (int row = 0; row < nou; row++) {
  for (int col = row + 1; col < nou; col++) {
   if (mat[row][col] !=0 && mat[col][col] != 0) {
    add_rowmult(nou, row, col, -mat[row][col] / mat[col][col], mat);
   }
  }
 }

 // Scale pivots to 1
 for (int row = 0; row < nou; row++) {
  if (mat[row][row] > 1.00000001 || mat[row][row] < 0.9999999) {
   scale_row(nou, row, 1 / mat[row][row], mat);
  }
 }

 // Clean up the rounding errors
 for (int row = 0; row < nou; row++) {
  for (int col = 0; col <= nou; col++) {
   if (mat[row][col] < 0.00000001 && mat[row][col] > -0.00000001) {
    mat[row][col] = 0;
   }
  }
 }
}

