#include<bits/stdc++.h>
using namespace std;

#define ll long long

int mark[1000015];

void sieve(int n){

    int limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;


    for(int i=4; i<n; i+=2)
        mark[i]= 1;

    for(int i=3; i<n; i+=2){
        if(mark[i])
            continue;

        if(i<limit){
            for(int j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }

    }

}

main(){
    int n;
    cin>>n;

    sieve(1000005);


    ll chk;

    while(n--){
        cin>>chk;

        ll c= sqrt(chk);

        if(c*c==chk && !mark[c])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
