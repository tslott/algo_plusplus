#include <iostream>
#include "mat_mult.h"

using std::cout, std::cin;

int main()
{
    // Get size of matrices
    int n = 500;
    // cout << "Enter size of square matrices: ";
    // cin >> n;

    // Initialize matrices
    int mat1[n][n], mat2[n][n], mat3[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat1[i][j] = i+j;
            mat2[i][j] = i+j;
        }
    }

    // print_mat(mat1[0], n);
    // cout << "X\n";
    // print_mat(mat2[0], n);
    // cout << "=\n";

    // Multiply matrices
    // mat_mult(mat1[0], mat2[0], mat3[0], n);
    mat_mult_multithread(mat1[0], mat2[0], mat3[0], n);

    // print_mat(mat3[0], n);

    return 0;
}
