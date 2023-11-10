#pragma once
#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
    T *array;
    unsigned int length;
public:
    Array() : array(new T[0]), length(0)
    {}

    Array(unsigned int n) : length(n)
    {
        array = new T[n];
    }

    Array(Array const &a)
    {
        length = a.length;
        array = new T[a.length];
        for (size_t i = 0; i < a.length; i++)
        {
            array[i] = a.array[i];
        }
    }

    unsigned int size() const
    {
        return length;
    }

    Array &operator=(Array const &other) const
    {
        if (this != &other)
        {
            delete [] array;
            array = new T[other.size()];
            for (size_t i = 0; i < other.size(); i++)
                array[i] = other.array[i];
        }
        return this;
    }

    class IndexOutOfBoundException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Index out of bound!";
        }
    };

    T &operator[](int index)
    {
        if (index >= 0 && (unsigned int)index < length)
            return array[index];
        else
            throw Array<T>::IndexOutOfBoundException();
    }

    ~Array()
    {
        delete[] array;
    }
};