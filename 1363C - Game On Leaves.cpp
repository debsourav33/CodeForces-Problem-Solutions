#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outiii(a,b,c) printf("%d %d %d\n",a,b,c)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 1e5+5, mod= 1e9+7;

int a[N], n, m, k, x, y, sz[N];
vector<int> v[N];


void dfs(int u, int p){
    sz[u]= 1;

    for(int nd: v[u]){
        if(nd==p) continue;
        dfs(nd,u);

        sz[u]+= sz[nd];
    }
}

main(){
    int opt;
    si(opt);

    while(opt--){
        sii(n,k);

        fr(n-1){
            sii(x,y);
            v[x].pb(y);
            v[y].pb(x);
        }

        dfs(k,-1);

        int fl= 0, sub_sz=0;

        if(v[k].size()<=1)  fl= 1;


        for(int nd: v[k]){
            //outii(nd, sz[nd]-1);
            sub_sz+= sz[nd];
        }

        sub_sz-= 2;

        if(sub_sz&1)  fl= 1;

        if(fl)  puts("Ayush");
        else  puts("Ashish");

        fr1(n){
            sz[i]= 0;
            v[i].clear();
        }
    }
}

//1 12 3 3 1 3 7 1 2 1 4 4 5 7 8 7 9 7 12 8 10 9 11 2 6