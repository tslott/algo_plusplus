#include "mat_mult.h"

void mat_mult(const int* mat1, const int* mat2, int* mat3, int size)
{
    // Initialize resulting matrix with zeros
    for (int i = 0; i < size*size; i++) mat3[i] = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                mat3[size * j + i] += mat1[size * j + k] * mat2[size * k + i];
            }
        }
    }
}

void mat_mult_single_row(const int* mat1, const int* mat2, int* mat3, int size, int row)
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            mat3[size * row + i] += mat1[size * row + k] * mat2[size * k + i];
        }
    }
}

void mat_mult_multithread(const int* mat1, const int* mat2, int* mat3, int size)
{
    // Initialize resulting matrix with zeros
    for (int i = 0; i < size*size; i++) mat3[i] = 0;

    // Use multithreading
    vector<thread> threads;

    for (int i = 0; i < size; i++)
        threads.push_back(thread(mat_mult_single_row, mat1, mat2, mat3, size, i));

    for (auto& th : threads) th.join();
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
