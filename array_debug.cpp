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

/*************************************************************************
*下面是一个给你们方便在本地端测试的main函数
*实际上，我们OJ的测试面函数并不是这样的
*所以如果你在你的本地端用这个main函数测试通过了，并不代表在OJ上能够通过
***********************************************************************/


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
//     assert(array.x[0] == 2);
//     array_insert(array,1,2);
//     assert(array.x[1] == 2);
//     array_insert(array,1,3);
//     assert(array.x[1] == 3);
//     assert(array.x[2] == 2);
//     cout<<"YES!"<<endl;
//     array_destroy(array);
//     array_destroy(array2);
//     array_destroy(array3);
//     return 0;
// }