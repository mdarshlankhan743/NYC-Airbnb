#include<iostream>
using namespace std;
//n to 1;
void print(int n){
    if (n==0) return;//base case
    cout<<n<<endl; // work
    print(n-1); //call 
   
}
int main(){
    int n;
    print(3);
}

