/*
 * File: submit.cpp
 * Created Date: Tuesday, September 17th 2019, 2:56:24 pm
 * Author: yusnows
 * -----
 * Last Modified: Fri Oct 11 2019
 * Modified By: yusnows
 * -----
 * Copyright (c) 2019 yusnows
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * Nope...we're doomed!
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

//include the headers that you need here.
#include <memory.h>
#include<cstdlib>
#include<assert.h>
#include<iostream>
using namespace std;
typedef struct
{
    int *buff;
    int size;
    int capacity;
} CArray;

void array_initial(CArray &array);

inline int array_capacity(CArray &array)
{
    return array.capacity;
}

inline int array_size(CArray &array)
{
    return array.size;
}

inline int &array_at(CArray &array, int index)
{
    return array.buff[index];
}

void array_initial(CArray &array)
{
    array.buff = NULL;
    array.size = 0;
    array.capacity = 0;
}

void array_recap(CArray &array, int capacity)
{
    if (capacity == array.capacity)
    {
        return;
    }

    int *buff = new int[capacity];
    array.capacity = capacity;
    array.size = capacity < array.size ? capacity : array.size;

    memcpy(buff, array.buff, array.size * sizeof(int));
    delete[] array.buff;

    array.buff = buff;
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
    _check_capacity(array, array.size + 1);

    array.buff[array.size++] = element;
}

void array_insert(CArray &array, int index, int element)
{
    _check_capacity(array, array.size + 1);

    for (int i = array.size; i > index; --i)
    {
        array.buff[i] = array.buff[i - 1];
    }
    array.buff[index] = element;
    array.size += 1;
}

void array_copy(CArray &src, CArray &dst)
{
    _check_capacity(dst, src.capacity);
    memcpy(dst.buff, src.buff, src.size * sizeof(int));
    dst.size = src.size;
}

bool array_compare(CArray &array1, CArray &array2)
{
    if (array2.size != array1.size)
    {
        return false;
    }
    return memcmp(array1.buff, array2.buff, array1.size) == 0;
}

void array_destroy(CArray &array)
{
    if (array.buff != NULL)
        delete[] array.buff;
    array.buff = NULL;
    array.capacity = 0;
    array.size = 0;
}

// int main(int argc, char *argv[])
// {
//     CArray array;
//     array_initial(array);
//     array_recap(array, 30);
//     // for(int i=0;i<10;++i){
//     //     cout<<array.x[i]<<endl;
//     // }
//     // cout<<endl;
//     assert(array_capacity(array) == 30);
    
//     for (int i = 0; i < 20; ++i)
//     {
//         array_append(array, i);
//         //cout<<array.x[i]<<endl;
//     }
//     assert(array_size(array) == 20);
//     for (int i = 0; i < array_size(array); ++i)
//     {
//         assert(array_at(array, i) == i);
//     }
//     cout<<"YES.1"<<endl;
    
//     CArray array2, array3;
//     array_initial(array2);
//     array_initial(array3);
//     array_copy(array, array2);
//     // for (int i = 0; i <= 20; ++i)
//     // {
//     //     cout<<array2.x[i]<<endl;
//     // }
//     assert(array_compare(array, array2) == true);
//     array_copy(array, array3);
//     assert(array_compare(array, array3) == true);
//     cout<<"YES.2"<<endl;

//     array_insert(array2, 2, 3);
//     // for (int i = 0; i <= 20; ++i)
//     // {
//     //     cout<<array2.x[i]<<endl;
//     // }
//     assert(array_compare(array, array2) == false);
//     cout<<"YES.3"<<endl;

//     array_at(array3, 2) = 5;
//     assert(array_compare(array, array3) == false);
//     // array_insert(array,2,3);
//     // assert(array_compare(array, array2) == true);
//     array_recap(array,20);
//     assert(array.capacity==20);
//     array_copy(array,array2);
//     assert(array_compare(array,array2) == true);
//     //assert(array2.capacity == 20);
//     cout<<"YES.4"<<endl;
    
//     array_recap(array3,100);
//     array_recap(array2,200);
//     assert(array_capacity(array2) == 200);
//     assert(array_capacity(array3) == 100);


//     array_initial(array);
//     assert(array_capacity(array) == 0);
//     array_recap(array,8);
//     assert(array_capacity(array) == 8);
//     array_append(array,2);
//     assert(array.buff[0] == 2);
//     array_insert(array,1,2);
//     assert(array.buff[1] == 2);
//     array_insert(array,1,3);
//     assert(array.buff[1] == 3);
//     assert(array.buff[2] == 2);
//     cout<<"YES!"<<endl;
//     array_destroy(array);
//     array_destroy(array2);
//     array_destroy(array3);
//     return 0;
// }

int main(int argc, char *argv[])
{
    CArray array;
    array_initial(array);
    array_recap(array, 10);
    assert(array_capacity(array) == 10);
    //////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; ++i)
    {
        array_append(array, i);
    }
    assert(array_size(array) == 20);
    for (int i = 0; i < array_size(array); ++i)
    {
        assert(array_at(array, i) == i);
    }
    //////////////////////////////////////////////////////////////////////////
    CArray array2, array3;
    array_initial(array2);
    array_initial(array3);
    array_copy(array, array2);
    assert(array_compare(array, array2) == true);
    array_copy(array, array3);
    assert(array_compare(array, array3) == true);
    //////////////////////////////////////////////////////////////////////////
    array_insert(array2, 2, 3);
    assert(array_compare(array, array2) == false);
    //////////////////////////////////////////////////////////////////////////
    array_at(array3, 2) = 5;
    assert(array_compare(array, array3) == false);
    //////////////////////////////////////////////////////////////////////////
    printf("YES\n");
    array_destroy(array);
    array_destroy(array2);
    array_destroy(array3);
    return 0;
}

