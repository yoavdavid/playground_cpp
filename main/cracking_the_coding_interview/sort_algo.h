#pragma once

template<typename T>
void merge(T* arr1, int size1, T* arr2, int size2, T* res)
{
    T* temp = new T[size1 + size2];

    int curr_index = 0, i = 0, j = 0;
    while(i < size1 && j < size2 )
    {
        if (arr1[i] < arr2[j])
        {
            temp[curr_index++] = arr1[i++];
        }
        else
        {
            temp[curr_index++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        temp[curr_index++] = arr1[i++];
    }

    while (j < size2)
    {
        temp[curr_index++] = arr2[j++];
    }

    for (int i = 0; i < size1 + size2; i++)
    {
        res[i] = temp[i];
    }

    delete[] temp;
}


template<typename T>
void mergesort(T* arr, int size)
{
    if (!arr || size <= 1)
    {
        return;
    }

    int middle = size / 2;
    mergesort<T>(arr, middle);
    mergesort<T>(arr + middle, size - middle);
    merge<T>(arr, middle, arr + middle, size - middle, arr);
}