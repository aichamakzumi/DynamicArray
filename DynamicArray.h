#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicArray
{
private:
    int* ptr;
    int size;

public:
    DynamicArray();
    explicit DynamicArray(int S);
    DynamicArray(int S, int defaultValue);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    int GetSize() const;
    int* GetPointer() const;

    void Input(int minVal = 0, int maxVal = 99);
    void Output() const;

    void ReSize(int newSize);
    void Sort();
    int Search(int a) const;
    void Reverse();

    DynamicArray operator+(int n) const;
    DynamicArray operator-(int n) const;
    DynamicArray operator*(int n) const;
    DynamicArray operator+(const DynamicArray& other) const;
    DynamicArray& operator++();
    DynamicArray& operator--();
};

#endif
