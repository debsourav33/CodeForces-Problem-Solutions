#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28
#define ll long long
#define ull unsigned long long

int call(int n, int cnt){
    if(cnt==0)
        return n;

    if(n%10!=0)
        call(n-1,cnt-1);

    else
        call(n/10,cnt-1);

}

main(){
    int n,k;
    cin>> n>>k;

    cout<<call(n,k)<<endl;

}
