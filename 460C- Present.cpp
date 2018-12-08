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

const int maxn= 100005;

#define lefts 2*at
#define rights 2*at+1

i64 lazy[4*maxn], a[maxn], n;

struct node{
    i64 val, pos;

    node(i64 v, i64 ii){
        val= v;
        pos= ii;
    }

    node(){}
} mini[4*maxn];

void merge(i64 at){
    if(mini[lefts].val<=mini[rights].val)
        mini[at]= node(mini[lefts].val,mini[lefts].pos);
    else
        mini[at]= node(mini[rights].val,mini[rights].pos);
}

void build(i64 at, i64 l, i64 r){
    if(l==r){
        mini[at]= node(a[l],l);
        return;
    }

    i64 mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
    merge(at);
}

void upd(i64 at, i64 x){
    lazy[at]+= x;
    mini[at]= node(mini[at].val+x, mini[at].pos);
}

void propagate(i64 at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(i64 at, i64 l, i64 r, i64 x, i64 y){
    if(x<=l && r<=y){
        lazy[at]++;
        mini[at]= node(mini[at].val+1, mini[at].pos);
        return;
    }
    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    i64 mid= (l+r)/2;

    update(lefts,l,mid,x,y);
    update(rights,mid+1,r,x,y);
    merge(at);
}

node query(i64 at, i64 l, i64 r, i64 x, i64 y){
    if(x<=l && r<=y)  return  mini[at];
}

int main(){
    i64 m, w;
    slll(n,m,w);

    fr(n)
        si(a[i]);

    build(1,0,n-1);


    while(m--) {
        i64 curr= query(1, 0, n - 1, 0, n - 1).pos;

        update(1, 0, n - 1, curr, min(n-1,curr+w-1));
    }


    outl(query(1, 0, n - 1, 0, n - 1).val);
}
