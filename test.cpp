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
int main(){
    int x[2];
    x[1]=1;
    x[0]=0;
    int* p=x;
    CArray a;
    array_initial(a);
    cout<<a.x<<endl;
    // cout<<p<<endl<<p+1<<endl<<p+2; 
    // cout<<endl<<*p<<endl<<*(p+1);
    p=NULL;
    cout<<p<<endl;
    return 0;
}