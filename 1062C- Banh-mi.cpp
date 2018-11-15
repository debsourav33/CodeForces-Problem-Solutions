#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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

#define lefts 2*at
#define rights 2*at+1

const int maxn= 1e5+5;

int n, a[maxn], sum[4*maxn];

void merge(int at){
    sum[at]= sum[lefts]+ sum[rights];
}

void build(int at, int L, int R){
    if(L==R){
        sum[at]= a[L];
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

int query(int at, int L, int R, int l, int r){
    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return x+y;
}

const i64 MOD= 1e9+7;
i64 geo[100005];

void genGeo(int n){
    i64 a= 1, r= 1;

    geo[0]= 1;
    for(int i=1;i<n;i++){
        geo[i]= (geo[i-1]*2) % MOD;
    }
}

i64 geoSum(int n, int a){
    return a*(1-geo[n])/(1-2);
}

int main(){
    int n, q;
    sii(n,q);

    fr(n)
        scanf("%1d",&a[i]);

    build(1,0,n-1);
    genGeo(100005);

    int a, b;
    fr(q) {
        sii(a,b);
        int ones= query(1,0,n-1,a-1,b-1);
        int zeros= b-a+1-ones;

        i64 ans= geoSum(ones,1) % MOD;
        ans= (ans+ geoSum(zeros,ans)) % MOD;

        printf("%lld\n",ans);
    }

}
