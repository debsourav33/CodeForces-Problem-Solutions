#include<bits/stdc++.h>
using namespace std;

//{
#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

ll n, a[100005];

ll sum_of_dig(ll n){
    int s=0;

    while(n){
        s+= n%10;
        n= n/10;
    }

    return s;
}

main(){
    fastIO();

    cin>>n;

    ll dig= log10(n);
    ll num1= max(0, ceil(pow(10,dig)-1));

    cout<<sum_of_dig(num1) + sum_of_dig(n-num1)<<endl;
}
