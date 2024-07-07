#include <iostream>
#include <cmath>
#include <string>
namespace MathFunction
{
    void print(double n)
    {
        auto res = sqrt(n);
        std::cout<<"sqrt = "<<res<<"\n";
    }
}

namespace StringFunction
{
    void print(char *arr)
    {
        std::cout<<"1) lower case \n2) upper case\n";
        bool choice;
        std::cin>>choice;
        if (choice == 1)
        {
            for (int i = 0; arr[i] != '\0'; i++)
            {
                arr[i] = tolower(arr[i]);
            }
            std::cout<<arr<<"\n";
        }
        else if (choice == 2)
        {
            for (int i = 0; arr[i] != '\0'; i++)
            {
                arr[i] = toupper(arr[i]);
            }
            std::cout<<arr<<"\n";
            
        }
    }
}

// reverse array
namespace ArrayFunction
{
    void print(int arr[], int n)
    {
        for (int i = 0; i < n/2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
    }
}

int main()
{   
    std::cout<<"math function\n";
    MathFunction::print(25);
    char arr[] = "HELLO";
    std::cout<<"string function\n";
    StringFunction::print(arr);
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout<<"array function\n";
    ArrayFunction::print(arr1, 5);
    return 0;
}
