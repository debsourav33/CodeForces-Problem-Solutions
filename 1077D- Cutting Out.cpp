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

int a[200005], c[200005], n, k;
vector<pii> cnt;
vector<int> solt;

int can(int r){
    int rem= k;

    for(pii p: cnt){
        rem-= p.ss/r;
        if(rem<=0)  return 1;
    }

    return 0;
}

void solve(int r){
    int rem= k;

    for(pii p: cnt){
        int c= p.ss/r;

        fr(c){
            solt.pb(p.ff);
            if(solt.size()==k)  return;
        }
    }
}

int main(){
    sll(n,k);

    fr(n) {
        si(a[i]);
        c[a[i]]++;
    }

    fr(200005){
        if(c[i])
            cnt.pb(mp(i,c[i]));
    }

    int lo= 0, hi= 2e6;

    while(lo<hi){
        int mid= (lo+hi+1)/2;

        if(can(mid))  lo= mid;
        else  hi= mid-1;
    }

    //outl(lo);
    solve(lo);

    printf("%d",solt[0]);
    fr1(solt.size()-1)
        printf(" %d",solt[i]);
    puts("");
}
