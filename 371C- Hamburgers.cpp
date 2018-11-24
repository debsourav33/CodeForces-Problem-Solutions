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

i64 a[3], p[3], r[3], n, m, k;
char s[103];

int can(i64 q){
    i64 rem= k;

    fr(3){
        i64 rs= q*r[i]- a[i];
        rs= max(0,rs);

        i64 req= rs*p[i];

        if(rem<req)  return 0;
        rem-= req;
    }

    return 1;
}

int main(){
    scanf("%s",s);

    fr(strlen(s)){
        if(s[i]=='B')
            r[0]++;
        else if(s[i]=='S')
            r[1]++;
        else
            r[2]++;
    }

    fr(3)
        sl(a[i]);
    fr(3)
        sl(p[i]);

    sl(k);

    i64 lo= 0, hi= 1e14;

    while(lo<hi){
        i64 mid= (lo+hi+1)/2;

        if(can(mid))  lo= mid;
        else  hi= mid-1;
    }

    outl(lo);
}
