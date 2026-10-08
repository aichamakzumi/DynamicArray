#include "DynamicArray.h"
#include <cstdlib>

DynamicArray::DynamicArray() : ptr(nullptr), size(0) {}

DynamicArray::DynamicArray(int S) : ptr(nullptr), size(0)
{
    if (S > 0)
    {
        size = S;
        ptr = new int[S]{ 0 };
    }
}

DynamicArray::DynamicArray(int S, int defaultValue) : ptr(nullptr), size(0)
{
    if (S > 0)
    {
        size = S;
        ptr = new int[S];
        for (int i = 0; i < size; ++i)
            ptr[i] = defaultValue;
    }
}

DynamicArray::DynamicArray(const DynamicArray& other) : ptr(nullptr), size(other.size)
{
    if (size > 0)
    {
        ptr = new int[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = other.ptr[i];
    }
}

DynamicArray::~DynamicArray()
{
    delete[] ptr;
    ptr = nullptr;
    size = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] ptr;
        size = other.size;
        if (size > 0)
        {
            ptr = new int[size];
            for (int i = 0; i < size; ++i)
                ptr[i] = other.ptr[i];
        }
        else
        {
            ptr = nullptr;
        }
    }
    return *this;
}

int DynamicArray::GetSize() const
{
    return size;
}

int* DynamicArray::GetPointer() const
{
    return ptr;
}

void DynamicArray::Input(int minVal, int maxVal)
{
    int range = maxVal - minVal + 1;
    for (int i = 0; i < size; ++i)
        ptr[i] = minVal + rand() % range;
}

void DynamicArray::Output() const
{
    if (size == 0 || ptr == nullptr)
    {
        std::cout << "[ empty ]\n";
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < size; ++i)
        std::cout << ptr[i] << (i + 1 < size ? ", " : " ");
    std::cout << "] size = " << size << "\n";
}

void DynamicArray::ReSize(int newSize)
{
    if (newSize < 0 || newSize == size)
        return;

    if (newSize == 0)
    {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
        return;
    }

    int* temp = new int[newSize]{ 0 };
    for (int i = 0; i < size && i < newSize; ++i)
        temp[i] = ptr[i];

    delete[] ptr;
    ptr = temp;
    size = newSize;
}

void DynamicArray::Sort()
{
    if (size <= 1 || ptr == nullptr) return;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (ptr[j] > ptr[j + 1])
            {
                int tmp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = tmp;
            }
        }
    }
}

int DynamicArray::Search(int a) const
{
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] == a)
            return i;
    }
    return -1;
}

void DynamicArray::Reverse()
{
    if (size <= 1 || ptr == nullptr) return;

    for (int i = 0; i < size / 2; ++i)
    {
        int tmp = ptr[i];
        ptr[i] = ptr[size - 1 - i];
        ptr[size - 1 - i] = tmp;
    }
}

DynamicArray DynamicArray::operator+(int n) const
{
    DynamicArray result(*this);
    result.ReSize(size + n);
    return result;
}

DynamicArray DynamicArray::operator-(int n) const
{
    DynamicArray result(*this);
    if (size > n)
        result.ReSize(size - n);
    return result;
}

DynamicArray DynamicArray::operator*(int n) const
{
    DynamicArray result(*this);
    for (int i = 0; i < result.size; ++i)
        result.ptr[i] *= n;
    return result;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) const
{
    DynamicArray result(size + other.size);
    for (int i = 0; i < size; ++i)
        result.ptr[i] = ptr[i];
    for (int i = 0; i < other.size; ++i)
        result.ptr[size + i] = other.ptr[i];
    return result;
}

DynamicArray& DynamicArray::operator++()
{
    ReSize(size + 1);
    return *this;
}

DynamicArray& DynamicArray::operator--()
{
    if (size > 0)
        ReSize(size - 1);
    return *this;
}
