#include <stdio.h>
#include <stdlib.h>

typedef int* (*callback_func)(int**, int, int*);

int* sum_avg(int** array, int size, int* row_size) {

    int* res = (int*)malloc(2 * sizeof(int));
    int sum = 0;
    int totalElements = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < row_size[i]; j++) {
            sum += array[i][j];
            totalElements++;
        }
    }

    int avg = totalElements > 0 ? sum / totalElements : 0;
    res[0] = sum;
    res[1] = avg;
    return res;
}

int* f_ptr(int** array, int size, int* row_size, callback_func func) {
    return func(array, size, row_size);
}

int main() {
    int rows = 3;
    int row_size[] = {3, 2, 4};

    // Allocate memory for the 2D array
    int** array = (int**)malloc(rows * sizeof(int*));

    // Initialize each row with dynamically allocated memory
    for (int i = 0; i < rows; i++) {

        array[i] = (int*)malloc(row_size[i] * sizeof(int));
        
        for (int j = 0; j < row_size[i]; j++) {
            array[i][j] = i * row_size[i] + j; // Assigning values to the array
        }
    }

    // Process the 2D array to calculate the sum and average
    int* result = f_ptr(array, rows, row_size, sum_avg);
    printf("Sum: %d, Average: %d\n", result[0], result[1]);

    // Free allocated memory
    free(result);
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
