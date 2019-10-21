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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

const int N= 4e3+5;

int a[N][N], pre[N][N], m, n;
vector<int> points;
vector<pii> v;

void calc(){
    clr(pre);

    fr1(N-2)
        frj1(N-2)
            pre[i][j]= pre[i][j-1]+ pre[i-1][j]- pre[i-1][j-1]+ a[i][j];
}

int get_sum(int a, int b, int c, int d){
    return pre[c][d]- pre[a-1][d]- pre[c][b-1]+ pre[a-1][b-1];
}

bool cmp(pii p1, pii p2){
    return p1.ff<p2.ff;
}

int check(int x, int y, int c, int d){
    if(get_sum(x,y,c,d)!=4)  return 0;

    if(x==c || y==d)  return 0;

    if(a[x][d] && a[c][y])  return 1;

    return 0;
}

main(){
    clr(a);
    si(n);

    int x,y;
    fr(n) {
        sii(x,y);
        v.pb(mp(x,y));

        points.pb(x);
        points.pb(y);
    }

    sort(all(points));

    fr(n){
        x= v[i].ff, y= v[i].ss;

        x= upper_bound(all(points),x)- points.begin();
        y= upper_bound(all(points),y)- points.begin();

        v[i]= mp(x,y);
        a[x][y]= 1;
    }

    calc();

    sort(all(v),cmp);

    i64 ans= 0;

    fr(n){
      int c= v[i].ff, d= v[i].ss;

      frj(i){
        x= v[j].ff, y= v[j].ss;

        ans+= check(x,y,c,d);

      }
    }


    outl(ans);
}
