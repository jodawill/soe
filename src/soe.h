#include <stdio.h>

int verbose;

// common.c
void wait();
void eval_args(int argc, char *argv[]);
void display_matrix(int nou, double mat[nou][nou + 1]);
void display_result(int nou, double mat[nou][nou + 1]);

// ero.c
void swap_rows(int nou, int a, int b, double mat[nou][nou + 1]);
int scale_row(int nou, int r, double scale_factor, double mat[nou][nou + 1]);
void add_rowmult(int nou, int r1, int r2, double scale_factor, double mat[nou][nou + 1]);

// queries.c
int get_nou();
void fill_matrix(int nou, double mat[nou][nou + 1]);

// solver.c
void solve_matrix(int nou, double mat[nou][nou + 1]);
