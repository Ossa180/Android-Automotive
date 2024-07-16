#include <iostream>
#include <vector>

// function to transpose a matrix

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    // create a new matrix with the dimensions swapped
    std::vector<std::vector<int>> result(cols, std::vector<int>(rows, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> result = transpose(matrix);

    std::cout << "Original matrix: " << std::endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}