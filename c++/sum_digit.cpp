#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum =1;
    while(n>0){
     int l = (n%10);
     n/=10;
      sum*=10+l;
    }
    cout<<sum;  
} 