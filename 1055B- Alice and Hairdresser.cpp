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

i64 n, a[100005], sum[400020], l_grt[400020], r_grt[400020], k;

void merge(i64 at){
    sum[at]= sum[lefts]+ sum[rights];
    l_grt[at]= l_grt[lefts];
    r_grt[at]= r_grt[rights];

    if(l_grt[rights]-r_grt[lefts]==1)
        sum[at]--;
}

void build(i64 at, i64 L, i64 R){
    if(L==R){
        sum[at]= a[L] > k;
        l_grt[at]= L;
        r_grt[at]= L;

        if(a[L]<=k) {
            l_grt[at] = -5;
            r_grt[at] = -5;
        }

        return;
    }

    i64 mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}


void update(i64 at, i64 L, i64 R, i64 pos, i64 val){
    if(L==R){
        a[L]+=val;
        sum[at]= a[L] > k;
        l_grt[at]= L;
        r_grt[at]= L;

        if(a[L]<=k) {
            l_grt[at] = -5;
            r_grt[at] = -5;
        }

        return;
    }

    i64 mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, val);
    else
        update(rights, mid+1, R, pos, val);

    merge(at);
}


i64 query(i64 at, i64 L, i64 R, i64 l, i64 r){
    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    i64 mid= (L+R)/2;

    i64 x= query(lefts, L, mid, l, r);
    i64 y= query(rights, mid+1, R, l, r);

    return x+y;
}

int main(){
    i64 q;
    slll(n,q,k);

    fr(n)
        sl(a[i]);

    build(1,0,n-1);

    //update(1,1,n,4,11);

    int x, a, b;
    fr(q) {
        si(x);

        if(!x){
            printf("%lld\n",query(1,0,n-1,0,n-1));
        }
        else{
            sii(a,b);
            update(1,0,n-1,a-1,b);
        }
    }
}
