#include<iostream>
using namespace std;
int fibo(int n){
    if(n<2 ) return n;
    return fibo(n-1)+ fibo(n-2);
}
int main(){ 
    int n;
    cout << "dalo";
    cin >> n;
    int val = fibo(n);
    cout << val;
}
 