
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

const int N= 2e5+5;

#define lefts 2*at
#define rights 2*at+1

int n, a[N], maxi[4*N];
pii p[N];

vector<int> v[3];

bool cmp(pii p1, pii p2){
    if(p1.ff==p2.ff)  return p1.ss>p2.ss;
    else  return p1.ff<p2.ff;
}

void merge(int at){
    maxi[at]= max(maxi[lefts], maxi[rights]);
}

void build(int at, int L, int R){
    if(L==R){
        maxi[at]= 0;
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

void update(int at, int L, int R, int pos, int val){
    if(L==R){
        maxi[at]= val;
        return;
    }

    int mid= (L+R)/2;
    if(pos<=mid)
        update(lefts, L, mid, pos, val);
    else
        update(rights, mid+1, R, pos, val);

    merge(at);
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return maxi[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return max(x,y);
}

main(){
    int n, n1, n2, n3, q, x;
    siii(n1,n2,n3);
    n= n1+n2+n3;

    frj(n1){
        si(x);
        v[0].pb(x);
    }
    frj(n2){
        si(x);
        v[1].pb(x);
    }
    frj(n3){
        si(x);
        v[2].pb(x);
    }

    fr(3)  sort(all(v[i]));

    int cnt= 0;
    fr(3) {
        for(int u: v[i]) {
            p[cnt] = mp(u, cnt);
            cnt++;
        }
    }

    sort(p,p+n,cmp);

    build(1,0,n-1);

    int maxi= 0;

    fr(n){
        int tmp= query(1,0,n-1,0,p[i].ss-1);
        //outii(p[i].ff,tmp+1);

        maxi= max(maxi, tmp+1);

        update(1,0,n-1,p[i].ss,tmp+1);
    }

    outi(n-maxi);
}
