#include<iostream>
using namespace std;

int main(){
    int i=1;
    int x[10];
    for (int j=0;j<10;++j) x[j]=0;
    x[i++]=1;
    cout<<x[1]<<endl<<x[2]<<endl;
    return 0;
}