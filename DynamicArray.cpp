#include "DynamicArray.h"
//#include <stdexcept>
#include <algorithm>
using namespace std;
template <typename T>
DynamicArray<T>::DynamicArray()
{
    arr = new T[2];
    capacity = 2;
    size = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

template <typename T>
void DynamicArray<T>::add(T element)
{
    if (size == capacity)
    {
        resize(2 * capacity);
    }
    arr[size] = element;
    size++;
}

template <typename T>
void DynamicArray<T>::Insert(int index, T element)
{
    if (index < 0 || index > size)
    {
        throw out_of_range("Index out of bounds");
    }
    if (size == capacity)
    {
        resize(2 * capacity);
    }
    copy_backward(arr + index, arr + size, arr + size + 1);
    arr[index] = element;
    size++;
}

template <typename T>
void DynamicArray<T>::Delete(int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of bounds");
    }
    copy(arr + index + 1, arr + size, arr + index);
    size--;
    if (size <= capacity / 4)
    {
        resize(capacity / 2);
    }
}

template <typename T>
void DynamicArray<T>::Remove()
{
    if (size > 0) {
        size--;
        if (size <= capacity / 4)
        {
            resize(capacity / 2);
        }
    }
}

template <typename T>
T DynamicArray<T>::access(int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of bounds");
    }
    return arr[index];
}

template <typename T>
void DynamicArray<T>::Clear()
{
    delete[] arr;
    arr = new T[2];
    size = 0;
    capacity = 2;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
    return size;
}

template <typename T>
void DynamicArray<T>::reverse_elements()
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        T temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

template <typename T>
void DynamicArray<T>::sort_array()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int DynamicArray<T>::linear_search(T e)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == e)
            return i;
    }
    return -1;
}

template <typename T>
int DynamicArray<T>::bin_search(T e)
{
    int l = 0;
    int h = size - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == e)
        {
            return mid;
        }
        else if (arr[mid] < e)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void DynamicArray<T>::display() const
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T &DynamicArray<T>::operator[](int index)
{
    if (index >= 0 && index < size)
        return arr[index];
    else
        throw out_of_range("Index out of range");
}
