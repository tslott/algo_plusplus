#ifndef MAT_MULT_GUARD
#define MAT_MULT_GUARD
#include <iostream>
#include <vector>
#include <thread>

using std::cout;
using std::vector;
using std::thread;

void mat_mult(const int* mat1, const int* mat2, int* mat3, const int size);
void mat_mult_single_row(const int* mat1, const int* mat2, int* mat3, int size, int row);
void mat_mult_multithread(const int* mat1, const int* mat2, int* mat3, const int size);
void print_mat(const int mat[], const int size);

#endif
