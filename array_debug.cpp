////include the headers that you need here.
#include<iostream>
#include<assert.h>
using namespace std;
typedef struct
{
    int cnt;
    int capacity;
    int *x;
} CArray;

void array_initial(CArray &array)
{
    array.cnt = 0;
    array.capacity = 0;
    array.x = NULL; 
}

inline int array_capacity(CArray &array)
{
    return array.capacity;
}

inline int array_size(CArray &array)
{
    return array.cnt;
}

void array_recap(CArray &array, int capacity)
{
    if (capacity == array.capacity) return;
    int* p = new int[capacity];
    array.cnt = array.cnt > capacity ? capacity : array.cnt;
    for (int i = 0; i < array.cnt; ++i){
        p[i] = array.x[i];
    }
    delete []array.x;
    array.x = p;
    array.capacity = capacity;
}

inline int &array_at(CArray &array, int index)
{
    return array.x[index];
}
void _check_capacity(CArray &array, int minimal)
{
    if (minimal <= array.capacity)
    {
        return;
    }

    int capacity = int(array.capacity * 2);
    array_recap(array, capacity < minimal ? minimal : capacity);
}
void array_append(CArray &array, int element)
{
    // if(array.capacity < array.cnt + 1)
    //     array_recap(array,array.cnt + 1 > array.capacity*2 ? array.cnt : array.capacity*2);
    _check_capacity(array,array.cnt + 1);
    array.x[array.cnt] = element;
    array.cnt += 1;
}
void array_insert(CArray &array, int index, int element)
{
    // if(array.capacity < array.cnt + 1)
    //     array_recap(array,array.cnt + 1 > array.capacity*2 ? array.cnt : array.capacity*2);
    _check_capacity(array,array.cnt + 1);
    for(int i = array.cnt; i > index; --i){
        array.x[i] = array.x[i-1];
    }
    array.x[index] = element;
    array.cnt += 1;
}

void array_copy(CArray &src, CArray &dst)
{
//    if(dst.capacity < src.capacity)
//         array_recap(dst,src.capacity > dst.capacity*2 ? src.capacity : dst.capacity*2);
    _check_capacity(dst,src.capacity);
    for(int i=0; i< src.cnt; ++i){
        dst.x[i] = src.x[i];
    }
    dst.cnt = src.cnt;
}

bool array_compare(CArray &array1, CArray &array2)
{
    if(array1.cnt != array2.cnt)    return false;
    for(int i = 0; i < array1.cnt; ++i){
        if(array1.x[i] != array2.x[i])
            return false;
    }
    return true;
}


void array_destroy(CArray &array)
{
    delete []array.x;
}