#include<iostream>
using std::cin;
using std::cout;
using std::endl;
void f0(){
    cout<<"0"<<endl;
}
void f1(){
    cout<<"1"<<endl;
}
typedef void (*FUNC_PTR)();
FUNC_PTR func_ptr ;
void reg(FUNC_PTR ptr){
    ptr();
}
int main(){
    func_ptr = f0;
    func_ptr();
    reg(f1);
    return 0;
}