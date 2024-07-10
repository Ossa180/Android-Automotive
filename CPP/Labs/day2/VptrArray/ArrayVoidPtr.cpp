#include <iostream>
#include <array>

enum class Type
{
    INT,
    FLOAT,
    DOUBLE
};

class ArrayVoidPtr
{
private:
    int size;
    void **array;
    Type type;

public:
    ArrayVoidPtr(int size) : size{size}
    {
        array = new void *[size];
    }

    ~ArrayVoidPtr()
    {
        delete[] array;
    }
    void setValue(int index, void *value, Type type)
    {
        switch (type)
        {
        case Type::INT:
            array[index] = static_cast<int *>(value);
            break;
        case Type::FLOAT:
            array[index] = static_cast<float *>(value);
            break;
        case Type::DOUBLE:
            array[index] = static_cast<double *>(value);
            break;
        }
    }
    void *getValue(int index)
    {
        return array[index];
    }
};