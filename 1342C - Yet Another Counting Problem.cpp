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

const int N= 1e6+5;


i64 n, k, x, y, lc;
int a[N];

/*
 * suppose a= 8, b= 12.. Their lcm is 24
 * then for any x between interval 0 to 11, 24 to 33, 48 to 51, we have (x%a)%b= (x%b)%a
 * formally, interval i*lcm to i*lcm+b-1 (i=0 to d= r/lc)
 * 0 to d is d+1 intervals.. so ans= (d+1)* b
 * suppose r is 48.. we have calculated it till 51 .. we calculated till lim= d*lc+y-1 = 51,
 * so we subtract the extra 3
 *
 * we calculate in range (0,r) and (0,l-1).. since ans for range (l,r)= (0,r)- (0,l-1)
*/

i64 get(i64 r){
    i64 d= r/lc;

    i64 ans= (d+1)*y;

    i64 lim= d*lc+y-1;

    if(lim>r)
        ans-=  lim-r;

    return ans;
}


main(){
    int opt;
    si(opt);

    while(opt--) {
        i64 q;
        slll(x,y,q);

        if(x>y)  swap(x,y);

        lc= (x*y)/__gcd(x,y);

        while(q--){
            i64 l, r;

            sll(l,r);

            i64 same= get(r)-get(l-1);
            i64 not_same= (r-l+1)-same;

            outl(not_same);
        }
    }
}
