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

int a[100005], b[100005], dp[100005], n;
pii p[100005];

bool cmp(pii p1, pii p2){
    return p1.ff<p2.ff;
}

int call(int pos){
    if(pos<=0)  return 0;
    if(dp[pos]!=-1)  return dp[pos];

    int p= upper_bound(a,a+n,a[pos]-b[pos]-1) - a;

    int cnt;
    cnt= pos-p +call(p-1);

    return dp[pos]= cnt;
}

int main(){
    sets(dp);

    int x, y;
    si(n);
    fr(n) {
        sii(x, y);
        p[i]= mp(x,y);
    }

    sort(p,p+n,cmp);

    fr(n){
        a[i]= p[i].ff;
        b[i]= p[i].ss;
    }

    int ans= 1e7;

    for(int i=n-1;i>=0;i--)
        ans= min(ans, call(i)+ n-1-i);

    outi(ans);
}
