#include <stdio.h>
#include "soe.h"

void solve_matrix(int nou, double mat[nou][nou + 1]) {
 // Put matrix in row echelon form
 for (int col = 0; col < nou; col++) {
  for (int row =  col + 1; row < nou; row++) {
   add_rowmult(nou, row, col, -mat[row][col] / mat[col][col], mat);
  }
 }

 // Transform to reduced echelon form
 for (int row = 0; row < nou; row++) {
  for (int col = row + 1; col < nou; col++) {
   add_rowmult(nou, row, col, -mat[row][col] / mat[col][col], mat);
  }
 }

 // Scale pivots to 1
 for (int row = 0; row < nou; row++) {
  scale_row(nou, row, 1 / mat[row][row], mat);
 }

 // Clean up the rounding errors
 for (int row = 0; row < nou; row++) {
  for (int col = 0; col < nou; col++) {
   if (mat[row][col] < 0.00000001 && mat[row][col] > -0.00000001) {
    mat[row][col] = 0;
   }
  }
 }
}

