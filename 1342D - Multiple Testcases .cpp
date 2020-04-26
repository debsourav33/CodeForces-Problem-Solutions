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

int n, k, x, y, lc;
int a[N], m[N], lim[N];
vector<int> v[N];


int isValid(int q){
    fr(q){
        int cnt= 0;
        for(int sz: v[i]){
            cnt++;

            if(cnt>lim[sz])  return 0;
        }

    }

    return 1;
}

int can(int k){
    int put= 0;

    for(int i=n-1; i>=0; i--){
        v[put].pb(m[i]);

        put+=1;
        put%= k;
    }

    return isValid(k);


}


main(){
    sii(n,k);
    fr(n)  si(m[i]);
    sort(m,m+n);

    fr1(k)  si(lim[i]);

    int lo= 1, hi= n;

    while(lo<hi){
        int mid= (lo+hi)/2;

        if(can(mid))  hi= mid;
        else lo= mid+1;

        fr(mid)  v[i].clear();
    }

    can(lo);
    outi(lo);

    fr(lo){
        printf("%d",v[i].size());
        for(int sz: v[i])  outis(sz);
        puts("");
    }

}