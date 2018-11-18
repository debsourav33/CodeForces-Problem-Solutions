#include<bits/stdc++.h>
using namespace std;

#define fr(n) for(int i=0;i<n;i++)

int power(int b, int n){
    int m=1;

    fr(n){
        m*= b;
    }

    return m;
}

int main(){
    int a, opt;
    cin>>opt;

    while(opt--) {
        cin >> a;
        cout << power(2,__builtin_popcount(a)) << endl;
    }
}
