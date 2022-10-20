#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int sub(int x){
    return x - 1;
}
class A{
    int x;
public:
    int u;
    int add(int x){
        return x+1;
    }
    void fix1(int *x){
        *x = sub(*x);
    }
private:
    void fix2(int *x){
        *x = 100;
    }
};

int main(){
    A mya;
    int t = 0;
    mya.u = 1;
    mya.fix1(&mya.u);
    cout<<mya.u<<endl;
    return 0;
}