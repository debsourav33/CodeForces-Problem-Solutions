#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<ll, ll> rights, lefts;
ll a[200005];

main(){
    ll n, k,ans=0;
    cin>>n>>k;

    for(ll i=0;i<n;i++){
        cin>>a[i];
        rights[a[i]]++;
    }

    for(ll i=0;i<n;i++){
        ll k1=0, k2=0;

        if(a[i]%k==0)
            k1=lefts[a[i]/k];

        rights[a[i]]--;

        k2= rights[a[i]*k];

        ans+= k1*k2;

        lefts[a[i]]++;
    }

    cout<<ans<<endl;
}
