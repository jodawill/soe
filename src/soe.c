/*
 * =====================================================================================
 *
 *       Filename:  soe.c
 *
 *    Description:  System of Equations Solver
 *
 *        Version:  1.0
 *        Created:  01/16/2014 17:29:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Josh Williams (jodawill), jodawill@iuk.edu
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "soe.h"

void sort_matrix(int nou, double mat[nou][nou + 1]) {
}

int main(int argc, char *argv[]) {
 // Handle arguments if there are any
 if (argc > 0) {
  eval_args(argc, argv);
 }

 // Query for number of unknowns
 int nou = get_nou();

 // Fill matrix array `mat` with coefficents
 double mat[nou][nou + 1];
 fill_matrix(nou, mat);

 solve_matrix(nou, mat);

 display_result(nou, mat);

 return 0;
}
