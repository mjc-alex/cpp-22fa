////include the headers that you need here.
#include<cstdlib>
#include<assert.h>
#include<iostream>
using namespace std;
typedef struct
{
    int cnt;
    int capacity;
    int *x;
} CArray;

void array_initial(CArray &array)//对数组结构进行初始化
{
    array.cnt = 0;
    array.capacity = 0;
    array.x = NULL;
}

inline int array_capacity(CArray &array)//返回数组结构的容量
{
    int cnt = 0;
    while(*(array.x+cnt)!=-1){
        ++cnt;
    }
    array.capacity = cnt;
    return cnt;
}

inline int array_size(CArray &array)//返回数组结构包含的元素个数
{
    
}

void array_recap(CArray &array, int capacity)//重新对数组结构申请空间
{
    int *p = new int[capacity];
    array.x = p;
    array.x[capacity] = -1;
}

inline int &array_at(CArray &array, int index)//返回对应位置的元素(的引用)
{
    return *(array.x+index);
}

void array_append(CArray &array, int element)//在数组结构后面加入一个元素
{
    *(array.x+1) = element;
}
void array_insert(CArray &array, int index, int element)//在数组结构给定的位置插入一个元素
{
    int num = array_size(array);
    while(num > index){
        *(array.x + num) = *(array.x + num-1);
        --num;
    }
    *(array.x+index) = element;
}

void array_copy(CArray &src, CArray &dst)//复制一个数组结构到另一个数组结构
{
    
}

bool array_compare(CArray &array1, CArray &array2)//比较两个数组结构是否相同，这里的相同是指里面的元素相同
{
}

void array_destroy(CArray &array)//销毁一个数组结构
{
    delete[] array.x;
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
    // for (int i = 0; i < 20; ++i)
    // {
    //     array_append(array, i);
    // }
    // assert(array_size(array) == 20);
    // for (int i = 0; i < array_size(array); ++i)
    // {
    //     assert(array_at(array, i) == i);
    // }
    //////////////////////////////////////////////////////////////////////////
    // CArray array2, array3;
    // array_initial(array2);
    // array_initial(array3);
    // array_copy(array, array2);
    // assert(array_compare(array, array2) == true);
    // array_copy(array, array3);
    // assert(array_compare(array, array3) == true);
    //////////////////////////////////////////////////////////////////////////
    // array_insert(array2, 2, 3);
    // assert(array_compare(array, array2) == false);
    //////////////////////////////////////////////////////////////////////////
    // array_at(array3, 2) = 5;
    // assert(array_compare(array, array3) == false);
    //////////////////////////////////////////////////////////////////////////
    array_destroy(array);
    // array_destroy(array2);
    // array_destroy(array3);
    return 0;
}

