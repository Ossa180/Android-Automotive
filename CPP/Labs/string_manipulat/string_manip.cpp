#include <iostream>
#include <string>

int main()
{
    std::string text{"the cycle of life is a cycle of cycles"};
    while (text.find("cycle") != std::string::npos)
    {
        text.replace(text.find("cycle"), 5, "circle");
    }
    std::cout << "after replacing >> " << text << "\n";
    text.insert((text.find("circle") - 1), " great ");
    std::cout << "\n";
    std::cout << "after insert great  >> " << text << "\n";
    int count = 0;

    text.insert(text.find("circle", (text.find("circle") + 1)), "BEFORE THE SECOND WORD ");

    std::cout << "\n";
    std::cout << "after insert second  >> " << text << "\n";
    return 0;
}