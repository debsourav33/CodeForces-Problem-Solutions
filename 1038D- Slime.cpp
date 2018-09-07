#include<bits/stdc++.h>
using namespace std;

//{
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
//}

main(){
    long n, min_i, max_i;
    long mini= 10e9, maxi= -10e9;
    long a[500005];
    cin>>n;

    fr(n){
        cin>>a[i];
        if(a[i]<mini){
            mini= a[i];
            min_i= i;
        }
        if(a[i]>=maxi){
            maxi= a[i];
            max_i= i;
        }
    }

    ll sum= 0;

    fr(n){
        if(i!=max_i && i!=min_i)
            sum+= (ll) abs(a[i]);
    }

    if(max_i==min_i)
        cout<<maxi<<endl;
    else
        cout<<(ll)maxi+ sum- (ll)mini<<endl;
}
