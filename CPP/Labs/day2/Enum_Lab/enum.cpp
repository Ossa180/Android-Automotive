#include <iostream>

enum class errors
{
    bad_request = 400,
    not_found = 404,
    server_error = 500,
    gateway_timeout = 504

};

void PrintError(errors n)
{
    switch (n)
    {
    case errors::bad_request:
        std::cout << "Bad Request\n";
        break;
    case errors::not_found:
        std::cout << "Not Found\n";
        break;
    case (errors::server_error):
        std::cout << "Server Error\n";
        break;
    case (errors::gateway_timeout):
        std::cout << "Gateway Timeout\n";
        break;
    }
}

int main()
{

    int input;
    std::cout << "Enter error code : ";
    std::cin >> input;
    std::cout << "\n";
    errors e = static_cast<errors>(input);
    PrintError(e);
}