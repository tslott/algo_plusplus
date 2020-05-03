#include "mat_mult.h"

void mat_mult(const int* mat1, const int* mat2, int* mat3, int size)
{

}

void print_mat(const int mat[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << mat[size * j + i] << " ";
        }
        cout << "\n";
    }
}
