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
#define outis(a,sz) printf("%d",a[0]); for(int i=1;i<sz;i++) printf(" %d",a[i]); puts("")

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

struct node{
    int c, t, i;

    node(int cc, int tt, int ii){
        c= cc;
        t= tt;
        i= ii;
    }

    node(){}
}a[200005];

int n, T;
vector<int> v;

bool cmp(node n1, node n2){
    return n1.t<n2.t;
}

int can(int r){
    int cnt= 0, time= 0;

    fr(n){
        if(a[i].c<r)  continue;

        if(a[i].t+time>T)  break;

        cnt++;
        time+= a[i].t;
    }

    return cnt>= r;
}

void solve(int r){
    int cnt= 0, time= 0;

    fr(n){
        if(a[i].c<r)  continue;

        if(a[i].t+time>T)  break;

        v.pb(a[i].i+1);
        cnt++;
        time+= a[i].t;

        if(cnt==r)  return;
    }
}

int main(){
    int x, y;

    sii(n,T);

    fr(n){
        sii(x,y);

        a[i]= node(x,y,i);
    }

    sort(a,a+n,cmp);

    int lo= 0, hi= n;

    while(lo<hi){
        int mid= (lo+hi+1)/2;

        if(can(mid))  lo= mid;
        else  hi= mid-1;
    }

    outi(lo);
    outi(lo);

    if(lo==0)  return 0;

    solve(lo);
    printf("%d",v[0]); for(int i=1;i<v.size();i++) printf(" %d",v[i]); puts("");
}
