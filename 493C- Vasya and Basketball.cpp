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
#define outis(a,sz) printf("%d",a[0]); for(int i=1;i<sz;i++) printf(" %d",a[i]); puts("")

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

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

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

i64 a[200005], b[200005], n, m;

int main(){
    sl(n);
    fr(n)
        sl(a[i]);

    sl(m);
    fr(m)
        sl(b[i]);

    sort(a,a+n);
    sort(b,b+m);

    i64 maxi, d;

    if(n>=m){
        maxi= n-m;
        d= 1;
    }
    else{
        maxi= 0;
        d= 2e9+1;
    }

    for(int i=n-1;i>=0;i--){
        i64 p= upper_bound(b,b+m,a[i]-1)- b;

        i64 diff= n-i - (m-p);

        if(diff>=maxi){
            maxi= diff;
            d= a[i];
        }
    }

    i64 sc1= n*2, sc2=m*2;

    i64 p= upper_bound(a,a+n,d-1)- a;
    sc1+= n-p;

    i64 q= upper_bound(b,b+m,d-1)- b;
    sc2+= m-q;

    printf("%lld:%lld\n",sc1,sc2);
}

/*
6
1 2 6 7 8 9

5
1 2 6 10 11

*/
