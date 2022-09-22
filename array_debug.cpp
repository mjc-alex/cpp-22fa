////include the headers that you need here.
#include<cstdlib>
#include<assert.h>
#include<iostream>
using namespace std;
typedef struct CArray
{
    int val;
    CArray *next;
} CArray;

void array_initial(CArray &array)//对数组结构进行初始化
{
    CArray* head=NULL;
}

inline int array_capacity(CArray &array)//返回数组结构的容量
{
    int cnt = 0;
    while(array.x+cnt!=NULL){
        ++cnt;
    }
    return cnt;
}

inline int array_size(CArray &array)//返回数组结构包含的元素个数
{
    
}

void array_recap(CArray &array, int capacity)//重新对数组结构申请空间
{
    int *p = new int[capacity];
    
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