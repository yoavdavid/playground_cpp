#pragma once

#include <stdexcept>
#include <cstring>

template<typename T>
class Array
{
public:
    Array() : current_size{ 0 }, max_size{0}
    {
        arr = new T[max_size + 1];
    }

private:
    struct iterator
    {
    public:
        iterator& operator++()
        {
            if (++index > end)
            {
                throw std::out_of_range("");
            }

            return *this;
        }

        iterator& operator++(int)
        {
            return ++(*this);
        }

        iterator& operator--()
        {
            if (index-- == 0)
            {
                throw std::out_of_range("");
            }

            return *this;
        }

        iterator& operator--(int)
        {
            return --(*this);
        }

        T& operator*()
        {
            if (index == end)
            {
                throw std::out_of_range("");
            }

            return *(arr + index);
        }

        bool operator==(const iterator& other) const
        {
            return (arr + index) == (other.arr + other.index);
        }

        bool operator!=(const iterator& other) const
        {
            return !(*this == other);
        }

    private:
        iterator(T* arr, size_t index, size_t end) : arr{ arr }, index{ index }, end{ end }{}

        T* arr;
        size_t index{};
        size_t end{};

        friend Array;
    };

public:

    T& operator[](int index)
    {
        if ( (index < 0) || (index > (current_size - 1)))
        {
            throw std::out_of_range("");
        }

        return *(arr + index);
    }

    void push_back(const T& element)
    {
        if (current_size == max_size)
        {
            resize();
        }

        arr[current_size++] = element;
    }

    void clear()
    {
        if (arr)
        {
            delete[] arr;
            current_size = max_size = 0;
        }
    }

    bool empty()
    {
        return current_size == 0;
    }

    iterator begin()
    {
        return iterator{ arr, 0, max_size };
    }

    iterator end()
    {
        return iterator{ arr, max_size, max_size };
    }

private:
    void resize()
    {
        if (empty())
        {
            delete[]arr;
            max_size = realloc_multiplier;
            arr = new T[max_size + 1];
        }
        else
        {
            max_size *= 2;
            T* temp = new T[max_size + 1];
            std::memcpy(temp, arr, current_size * sizeof(T));
            delete[] arr;
            arr = temp;
        }
    }

    const size_t realloc_multiplier = 2;
    size_t current_size;
    size_t max_size;
    T* arr;

};
