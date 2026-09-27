#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
         cout<<j <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
         cout<<i<<" ";
     }
     cout<<endl;
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<(char)(j+64)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++) {
              if (i%2==0){
                cout<<(char)(j+64)<<" ";
        }else{
            cout<<j<<" ";
        }
        }
        cout<<endl;
        
        int a=1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=i;j++) {
                cout<<a<<" ";
                a++;
            }
            cout<<endl;
        }
    }
    cout<<endl;

    //0101 print
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++){
            if((i+j)%2==0){
                cout<<1<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    //plus print
    int mid=n/2+1;
    for (int i=1;i<=9;i++){
        for (int j=1;j<=9;j++){
            if (i==mid || j==mid){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    //hollow
    
    for(int i = 1; i <= n; i++){
        cout << "* ";
    }
    cout<<endl;
     //priyanshuu 10 bar me with chat gpt
    for(int i = 1; i <= n-2; i++){
        for (int j=1;j<=n;j++){
           if(j == 1 || j == n){
            cout << "* ";
           }
           else{
               cout<<"  ";
           }
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        cout << "* ";
    }
    cout<<endl;
   //arshlan
    for (int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1|| j==1 || i==n || j==n){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    //ulta triangle
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    //rmbs
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

