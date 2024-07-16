#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

int main()
{
    // Open the input file for reading
    std::ifstream inputFile("input.txt");

    // Open the output file for writing
    std::ofstream outputFile("output.txt");

    // Check if the input file was opened
    if (!inputFile)
    {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    // Check if the output file was opened
    if (!outputFile)
    {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    // Vector to store the integers read from the file
    std::vector<int> numbers;
    int number;

    // Read integers from the input file and store them in the vector
    while (inputFile >> number)
    {
        numbers.push_back(number);
    }

    // Check if any numbers were read from the file
    if (numbers.empty())
    {
        std::cerr << "No numbers found in input file!" << std::endl;
        return 1;
    }

    // Initialize minVal and maxVal with the first value from the vector
    int sum = 0;
    int minVal = numbers[0];
    int maxVal = numbers[0];

    for (int num : numbers)
    {
        sum += num;
        if (num < minVal)
        {
            minVal = num;
        }
        if (num > maxVal)
        {
            maxVal = num;
        }
    }

    double avg = static_cast<double>(sum) / numbers.size();

    outputFile << "---------------------------------------------------------------" << std::endl;
    outputFile << "|   Sum   |    Avg    |   Min   |   Max   |" << std::endl;
    outputFile << "---------------------------------------------------------------" << std::endl;
    outputFile << "| " << std::setw(7) << sum << " | "
               << std::setw(8) << std::fixed << std::setprecision(2) << avg << " | "
               << std::setw(7) << minVal << " | "
               << std::setw(7) << maxVal << " |" << std::endl;
    outputFile << "---------------------------------------------------------------" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
