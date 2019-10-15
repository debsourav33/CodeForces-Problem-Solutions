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

const int N= 1e5+5;

i64 n, k, tot, need, t[N], a[N], c,tms;

/*
 5 3 4
 5 8 3 10 7
 */

int can(i64 k){
    i64 cnt= 1, sum= 0, ex=0;

    fr(n){
        if(t[i]>k)  return 0;

        i64 need= cel(sum+a[i],tms);

        if(need > k){
            cnt++;
            sum= a[i];
        }
        else {
            sum += a[i];
        }
    }

    return cnt<=c;
}

int main() {
    slll(n,c,tms);

    fr(n){
        si(a[i]);
        t[i]= cel(a[i],tms);
    }

    i64 lo= 1, hi= 1e16;

    while(lo<hi){
        i64 mid= (lo+hi)/2;

        if(can(mid)){
            hi= mid;
        }
        else{
            lo= mid+1;
        }
    }

    outl(lo);
}
