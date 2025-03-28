/*
Time: O(logk)
Space: O(1)


For k = 3;

*
**
***
**
*

For messages (m) <= k, the total emote count is m*(m+1)/2, i.e. sum of first m numbers sum(m)
For messages (m) >= k, let say diff = m-k, the emote count per line is is k-1, k-2, ..., k-diff (which is sum(k-1) - sum(k-diff))

Do binary search to find out number of messages sent without getting banned

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll nsum(ll n){
    return n*(n+1)/2;
}

ll sum(ll a, ll b){
    return nsum(b) - nsum(a-1);
}

ll emotes(ll k, ll m){
    ll val;

    if(m<=k)  val = nsum(m); //For messages (m) <= k, the total emote count is m*(m+1)/2, i.e. sum of first m numbers sum(m)
    else{
        ll diff = m-k;
        val = nsum(k) + sum(k-diff,k-1); //For messages (m) >= k, diff = m-k, the emote count per line is is k-1, k-2, ..., k-diff (which is sum(k-1) - sum(k-diff))
    }

    return val;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        ll k, x;
        cin>>k>>x;
        
        //binary search to find out number of messages sent without getting banned
        ll lo = 0, hi = 2*k-1; //there can be 0 messages sent without getting banned

        while(lo<hi){
            ll mid = (lo+hi+1)/2;
            if(emotes(k,mid)<x)  lo = mid;
            else hi = mid-1;
        }

        // lo + 1 because we have to count the message that got us banned
        cout<<min(2*k-1,lo+1)<<endl;
    }

}