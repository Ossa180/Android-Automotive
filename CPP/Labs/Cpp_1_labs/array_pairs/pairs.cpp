#include <iostream>
#include <utility>

namespace ArrayPairs
{
    auto createArray(int size)
    {
        std::pair<int, double>* arr= new std::pair<int, double>[size];
        return arr;
    }
    void deleteArray(std::pair<int,double>* arr)
    {
        delete[] arr;
    }
    void SetPair(std::pair<int,double>* arr, int index, int first, double sec)
    {
        arr[index] = std::make_pair(first, sec);
    }
    void getPair(std::pair<int,double>* arr, int index)
    {
        std::cout << arr[index].first << " " << arr[index].second << std::endl;
    }
    void printArray(std::pair<int,double>* arr, int size)
    {
        for(int i = 0; i < size; i++)
        {
            std::cout << arr[i].first << " " << arr[i].second << std::endl;
        }
    }
}

int main()
{
    int size = 5;
    auto arr = ArrayPairs::createArray(size);
    // Set pairs(array, index, first, second)
    ArrayPairs::SetPair(arr, 0, 1, 1.1);
    ArrayPairs::SetPair(arr, 1, 2, 2.2);
    ArrayPairs::SetPair(arr, 2, 3, 3.3);
    ArrayPairs::SetPair(arr, 3, 4, 4.4);
    ArrayPairs::SetPair(arr, 4, 5, 5.5);
    ArrayPairs::printArray(arr, size);
    ArrayPairs::deleteArray(arr);
    return 0;
}