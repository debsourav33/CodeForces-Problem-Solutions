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

int n, m, k, x, y, edge;
i64 sz[N], cont[N], p[N];
vector<int> v[N];

void dfs(int u, int p){
    sz[u]= 1;

    for(int nd: v[u]){
        if(nd==p)  continue;
        dfs(nd,u);

        sz[u]+= sz[nd];
    }
}

/*
 * Contribution of a edge= how many times it will appear between the paths between all pair of vertices
 *                       = no. of vertices in one side of the edge * no. of vertices in other side of the edge
 */

void sort_contribution(){
    fr1(n){
        cont[i]= sz[i] * (n-sz[i]);
    }

    sort(cont+1,cont+n+1,greater<i64>());

    //fr1(n)  outl(cont[i]);
}

/*
 Do your math: try to assign as much weight as possible to the edge having most contribution (while minimizing no. of weight=1 in all edges)
 */

void solve(){
    int can= max(1,m-edge+1), pos= 0;

    i64 dist_index= 0, mul= 1;

    //outl(cont[1]);
    fr(can){
        //outls(p[pos]);
        mul*= p[pos++];
        mul%= mod;
    }
    //puts("");

    dist_index+= cont[1] * mul;
    dist_index%= mod;

    for(int i=2;i<=edge;i++){
        //outll(cont[i],p[pos]);

        dist_index+= cont[i] * p[pos++];
        dist_index%= mod;
    }

    outl(dist_index);

}

void reset(){
    fr1(n)  v[i].clear();
}

main(){
    int q;
    si(q);

    while(q--) {
        si(n);

        fr(n-1){
            sii(x,y);

            v[x].pb(y);
            v[y].pb(x);
        }

        edge= n-1;

        si(m);
        fr(m)  sl(p[i]);
        for(int i=m;i<=edge;i++)  p[i]= 1;

        int tot_m= m;

        if(edge>tot_m)  tot_m= edge;

        sort(p,p+tot_m,greater<i64>());

        //fr(tot_m)  outls(p[i]);  puts("");

        dfs(1,-1);
        sort_contribution();

        reset();

        solve();

    }

}
/*
 1
 7
6 1
2 3
4 6
7 3
5 1
3 6

 9
 7 5 13 3 11 2 2 5 7
 */
