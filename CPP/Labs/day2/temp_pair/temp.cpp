#include <iostream>

template <typename T>
class KeyValuePair
{
private:
    T key;
    T value;

public:
    KeyValuePair()
    {
    }
    KeyValuePair(T key, T value) : key{key}, value{value} {}

    void setKey(T key)
    {
        key = key;
    }
    void setValue(T value)
    {
        value = value;
    }
    T getKey()
    {
        return key;
    }
    T getValue()
    {
        return value;
    }
    void print()
    {
        std::cout << key << " : " << value << std::endl;
    }
};

int main()
{
    KeyValuePair<int> p1(1, 2);
    p1.print();
}
