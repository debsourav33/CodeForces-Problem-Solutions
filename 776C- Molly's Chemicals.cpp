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

#define left 2*at
#define right 2*at+1

const int maxn= 1e5+5;

i64 a[maxn], pre[maxn], n, k;
vector<i64> tree[4*maxn];

void marge(i64 at){
    tree[at].clear();
    i64 i=0, ls= tree[left].size();
    i64 j=0, rs= tree[right].size();

    while(i<ls && j<rs){
        if(tree[left][i]<tree[right][j])  tree[at].pb(tree[left][i++]);
        else  tree[at].pb(tree[right][j++]);
    }

    for(i=i;i<ls; )  tree[at].pb(tree[left][i++]);
    for(j=j;j<rs; )  tree[at].pb(tree[right][j++]);
}

void build(i64 at, i64 l, i64 r){
    if(l==r){
        tree[at].clear();
        tree[at].pb(pre[l]);
        return;
    }

    i64 mid= (l+r)/2;

    build(left,l,mid);
    build(right,mid+1,r);
    marge(at);
}

i64 query(i64 x, i64 y, i64 at, i64 l, i64 r, i64 val){
    if(l>=x && r<=y){
        i64 p= upper_bound(all(tree[at]),val)- tree[at].begin();
        i64 t= upper_bound(all(tree[at]),val-1)- tree[at].begin();

        return p-t;
    }

    if(l>y || r<x)  return 0;

    i64 mid= (l+r)/2;
    i64 a= query(x,y,left,l,mid,val);
    i64 b= query(x,y,right,mid+1,r,val);

    return a+b;
}

vector<i64> v;

int main(){
    i64 k;
    sll(n,k);

    pre[0]= 0;

    fr1(n) {
        sl(a[i]);
        pre[i]= pre[i-1]+ a[i];
    }

    i64 t= 1;

    if(k==-1)
        v.pb(1), v.pb(-1);
    else if(k==1)
        v.pb(1);
    else {
        while (abs(t) <= 1e14) {
            v.pb(t);

            t *= k;
        }
    }

    build(1,1,n);

    i64 ans= 0;

    for(i64 p: v) {
        fr1(n) {
            ans += query(i, n, 1, 1, n, pre[i - 1] + p);
        }
    }

    outl(ans);
}
