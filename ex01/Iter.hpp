#pragma once
#include <string>


template <typename T>

void iter(T *arr,size_t arr_s, void (*f)(T&))
{
    if(arr == NULL || f ==NULL )
        return;
    for(size_t i = 0;i < arr_s;i++)
    {
        f(arr[i]);
    }
}

template <typename T>
void iter(const T *arr, size_t arr_s, void (*f)(const T &))
{
    if (arr == NULL || f == NULL)
        return;
    for (size_t i = 0; i < arr_s; i++)
        f(arr[i]);
}