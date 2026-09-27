#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int rev = 0;
    while(n!=0) {
        int ls=n%10;
        rev*=10;
        rev+=ls ;
        n/=10;
    }
    cout<<rev;

}