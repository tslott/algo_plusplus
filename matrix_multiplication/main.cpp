#include <iostream>
#include "mat_mult.h"

using std::cout, std::cin;

int main()
{
    // Get size of matrices
    int n;
    cout << "Enter size of square matrices: ";
    cin >> n;

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

    print_mat(mat1[0], n);

    // Multiply matrices

    return 0;
}
