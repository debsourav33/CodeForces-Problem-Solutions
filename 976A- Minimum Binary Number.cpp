#include<bits/stdc++.h>
using namespace std;

#define ll long long

main(){

    ll n, zero=0, one=0;
    cin>>n;
    char s[105];
    cin>> s;

    for(int i=0;i<n;i++){

        if(s[i]=='0')
            zero++;
        else
            one++;
    }

    if(one>0)
        cout<<"1";

    for(int i=0;i<zero;i++){
        cout<<"0";
    }

    puts("");


}

