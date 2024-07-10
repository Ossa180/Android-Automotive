#include <iostream>

class pair
{

private:
    int first;
    int second;

public:
    pair() : first{}, second{} {}
    pair(int first, int second) : first{first}, second{second} {}
    void set_first(int first)
    {
        first = first;
    }
    void set_second(int second)
    {
        second = second;
    }
    int get_first()
    {
        return first;
    }
    int get_second()
    {
        return second;
    }
    void set_pair(int first, int second)
    {
        first = first;
        second = second;
    }
    void swap(pair &p)
    {
        std::swap(p.first, p.second);
    }
    void print(pair &p)
    {
        std::cout << "First: " << p.first << " Second: " << p.second << std::endl;
    }
};

int main()
{
    pair p;
    p.print(p);

    pair p2(10, 20);
    std::cout << "before swap: ";
    p2.print(p2);
    p2.swap(p2);
    std::cout << "after swap: ";
    p2.print(p2);
}