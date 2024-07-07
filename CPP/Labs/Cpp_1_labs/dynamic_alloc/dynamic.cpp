#include <iostream>

namespace DynamicAlloc
{
    void create2DArray(int **&arr, int rows, int cols)
    {
    

    // Allocate memory for the array of pointers to rows
    int** array = new int*[rows];

    // Allocate memory for each row
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    // Initialize the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = i * cols + j;
        }
    }

    // Use the allocated memory
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory for each row
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }

    // Deallocate memory for the array of pointers to rows
    delete[] array;
    }
}

int main()
{
    int **arr;
    DynamicAlloc::create2DArray(arr, 3, 4);
    return 0;
}