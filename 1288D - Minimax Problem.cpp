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

const int N= 3e5+5;

int a[N][8], n, m, mark[270], allset;
vector<pii> v;

int setsbit(int mask, int pos){
    return mask | (1<<pos);
}

int getMask(int pos, int k){
    int mask= 0;

    fr(m){
        if(a[pos][i]>=k)  mask= setsbit(mask,i);
    }

    return mask;
}

pii can(int k){
    clr(mark);
    v.clear();

    fr(n){
        int mask= 0;
        mask= getMask(i,k);

        if(mask==allset)  return mp(i+1,i+1);

        if(!mark[mask]){
            v.pb(mp(mask,i+1));
            mark[mask]++;

        }

    }

    fr(v.size()){
        for(int j=i+1;j<v.size();j++){
            if((v[i].ff | v[j].ff) == allset){
                    return  mp(v[i].ss,v[j].ss);
            }
        }
    }

    return mp(0,0);
}

main(){
    sii(n,m);

    allset= setsbit(allset,m);
    --allset;

    fr(n){
        frj(m)  si(a[i][j]);
    }

    int lo= 0, hi= 1e9;

    while(lo<hi){
        int mid= (lo+hi+1)/2;

        pii p= can(mid);

        if(p.ff==0)  hi= mid-1;
        else  lo= mid;

    }

    pii p= can(lo);
    outii(p.ff,p.ss);



}
