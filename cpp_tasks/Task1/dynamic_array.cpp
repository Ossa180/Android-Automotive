#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic_array
{
    int* array;
    int size;
    int capacity;
} dynamic_array;

void init(dynamic_array* arr, int capacity)
{
    arr->array = (int*)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void PushBack(dynamic_array* arr, int element)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->array = (int*)realloc(arr->array, arr->capacity * sizeof(int));
        printf("capacity increased to %d\n", arr->capacity);
    }
    arr->array[arr->size++] = element;
}

void print(dynamic_array* arr)
{
    printf("elements of array are >>> ");
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->array[i]);
    }
    printf("\n");
}

void insert(dynamic_array* arr, int index, int element)
{

    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        arr->array = (int*)realloc(arr->array, arr->capacity * sizeof(int));
        printf("capacity increased to %d\n", arr->capacity);
    }
    for (int i = arr->size; i > index; i--)
    {
        arr->array[i] = arr->array[i - 1];
    }
    arr->array[index] = element;
    arr->size++;
}

void delete_element(dynamic_array* arr, int index)
{
    for (int i = index; i < arr->size - 1; i++)
    {
        arr->array[i] = arr->array[i + 1];
    }
    arr->size--;
}

void free_array(dynamic_array* arr)
{
    free(arr->array);
}

int main()
{
    dynamic_array arr;
    init(&arr, 5);        // initialize array with capacity 5
    PushBack(&arr, 1);
    PushBack(&arr, 2);
    PushBack(&arr, 3);
    PushBack(&arr, 4);
    PushBack(&arr, 5);
    print(&arr);
    insert(&arr, 2, 10);  // insert 10 at index 2
    print(&arr);
    delete_element(&arr, 2);
    print(&arr);
    free_array(&arr);
    return 0;
}
