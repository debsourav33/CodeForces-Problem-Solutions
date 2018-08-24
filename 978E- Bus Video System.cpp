#include<bits/stdc++.h>
using namespace std;

#define ll long long

main(){
    ll n, w, rec, s=0, mini=0, maxi=0;
    cin>>n>>w;

    while(n--){
        cin>>rec;

        s+=rec;
        mini= min(mini,s);
        maxi= max(maxi,s);
    }

    ll ways= w-maxi+mini+1;

    if(maxi>w || mini<(-1*w) || ways>(w+1) || ways<0)
        cout<<"0"<<endl;
    else
        cout<<ways<<endl;

}
