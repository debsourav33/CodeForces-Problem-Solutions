#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outis(a) printf(" %d",a)

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define frj(n) for(int j=0;j<n;j++)
#define frj1(n) for(int j=1;j<=n;j++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const i64 mod= 1e9+9;

i64 ans, n, m, k;

bool check(int x){
    int dist= k-1;

    int used= x+ cel(x,dist);
    int need= m-x;
    int rem= n-used;

    return rem>=need;
}

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return (ans-2+mod)%mod;
}

main(){
    slll(n,m,k);

    i64 lo=0, hi= m;

    while(lo<hi) {
        int mid= (lo+hi+1)/2;

        if (check(mid))  lo= mid;
        else  hi= mid-1;
    }

    i64 cont= m- lo;
    
    ans= (k* exp(2,cont/k+1,mod) + lo+ cont%k) % mod;

    //doubling when we reach multiple of k result in pattern k*(2+4+8+...2^n)= k * [2^(n+1)-2]

    outl(ans);
}