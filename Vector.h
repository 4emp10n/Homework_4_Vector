#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	
	T* arr;
	int size = 0;
	int capacity = 1;

public:
	Vector() { arr = new T[capacity]; }
	explicit Vector(const Vector& v);
	Vector(Vector&& v);
	Vector(const int& size, const T& defaultElem);
	Vector& operator=(const Vector& v);
	void reserve(const int& newCap);
	void resize(const int& newSize, const T& value);
	void push_back(const T& elem);
	void pop_back();
	int getCapacity() { return capacity; }
	int getSize() { return size; }
	void printVec();
	T& operator[](const int& elem);
	~Vector() { delete[] arr; }
};

template<typename T>
Vector<T>::Vector(const Vector& v)
{
    capacity = v.capacity;
    size = v.size;
    arr = new T[capacity];


    for (int i = 0; i < size; i++)
    {
        arr[i] = v.arr[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& v)
{
    size = v.size;
    v.size = 0;
    capacity = v.capacity;
    v.capacity = 1;
    arr = v.arr;
    v.arr = nullptr;
}

template<typename T>
Vector<T>::Vector(const int& size, const T& defaultElem)
{
    resize(size);

    arr = new T[capacity];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v)
{
    delete[] arr;
    capacity = v.capacity;
    size = v.size;
    arr = new T[capacity];


    for (int i = 0; i < size; i++)
    {
        arr[i] = v.arr[i];
    }
    return *this;
}

template<typename T>
void Vector<T>::reserve(const int& newCap)
{
    if (newCap <= capacity) return;
    
    T* newarr = new T[newCap];
    
    for (int i = 0; i < size; i++)
    {
        newarr[i] = arr[i];
    }

    delete[] arr;

    arr = newarr;
    capacity = newCap;

}

template<typename T>
void Vector<T>::resize(const int& newSize, const T& value)
{
    if (newSize > capacity) reserve(newSize);

    for (int i = 0; i < newSize; i++)
    {
        if (i >= size)
        {
            arr[i] = value;
        }
        
    }
    size = newSize; 
}

template<typename T>
void Vector<T>::push_back(const T& elem)
{
    if (capacity == size) reserve(capacity * 2);
    arr[size] = elem;
    size++;
}

template<typename T>
void Vector<T>::pop_back()
{
    if (size > 0)
    {
        size--;
        (arr + size)->~T();
    }
    else
    {
        cout << "Size can't be negative!\n";
    }
    
}

template<typename T>
void Vector<T>::printVec()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
T& Vector<T>::operator[](const int& elem)
{
    if (elem > size - 1)
    {
        cout << "Wrong Index";
        throw 1;
    }

    return arr[elem];
}