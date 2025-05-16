#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
//#include <stdexcept>
#include <algorithm> // for copy and copy_backward
using namespace std;
template <typename T>
class DynamicArray
{
private:
    T *arr;
    int capacity;
    int size;
    void resize(int newCapacity)
    {
        T *temp = new T[newCapacity];
        copy(arr, arr + size, temp);
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    DynamicArray();
    ~DynamicArray();
    void add(T element);
    void Insert(int index, T element);
    void Delete(int index);
    void Remove();
    T access(int index);
    void Clear();
    int getSize() const;
    void reverse_elements();
    void sort_array();
    int linear_search(T e);
    int bin_search(T e);
    void display() const;
    T &operator[](int index);
};

#endif // DYNAMICARRAY_H
