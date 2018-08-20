#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull ceil(ull n,ull i){
    if(n==0)
        return 0;
    return (n-1)/i+1;
}

main(){

    ull n,q,i,j;
    cin>> n>> q;

    while(q--){
        cin>>i>>j;

        ull res= (i-1)* ceil(n,2) + ceil(j,2)+ ceil(n*n,2) * ((i+j)%2)- (i-1)/2* (1-(i+j)%2)*(n%2)- ceil(i-1,2) * ((i+j)%2)* (n%2);

        cout<<res<<endl;
    }

}
