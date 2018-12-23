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

vector<pii> v;
pii a[3];

bool comp(pii p1, pii p2){
    return p1.ff<p2.ff;
}

int main() {
    int x,y;
    fr(3){
        sii(x,y);
        a[i]= mp(x,y);
    }

    sort(a,a+3,comp);

    int cx= a[0].ff, dx= a[1].ff, mini= abs(a[2].ss-a[0].ss), iy=a[0].ss;

    v.pb(mp(cx,a[0].ss));

    while(cx!=dx){
        cx++;
        v.pb(mp(cx,a[0].ss));
    }

    int cy= a[0].ss, dy= a[1].ss;
    int inc;

    if(a[1].ss > a[0].ss)
        inc= 1;
    else
        inc= -1;

    while(cy!=dy){
        cy+= inc;
        v.pb(mp(cx,cy));

        if(abs(a[2].ss-cy)<mini){
            mini= abs(a[2].ss-cy);
            iy= cy;
        }
    }

    dx= a[2].ff, dy= a[2].ss;

    while(cx!=dx){
        cx++;
        v.pb(mp(cx,iy));
    }

    if(a[2].ss > iy)
        inc= 1;
    else
        inc= -1;

    while(iy!=dy){
        iy+= inc;
        v.pb(mp(cx,iy));
    }

    outi(v.size());

    for(pii p: v)
        outii(p.ff,p.ss);
}
