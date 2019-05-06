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

const int maxn= 1e5+5;
const int maxk= 1e2+2;

vector<int> v[maxn], types[maxk], sorted_levels[maxn];
int n, vis[maxk][maxn], level[maxk][maxn], edges, parent[maxn], k, s;


void reset(){
    clr(vis);
    clr(level);
    sets(parent);
}

void bfs(int t){
    queue<int> q;
    clr(vis[t]);

    fr(types[t].size()) {
        q.push(types[t][i]);
        vis[t][types[t][i]] = 1;
    }


    while(!q.empty()){
        int u= q.front();
        q.pop();

        fr(v[u].size()){
            int node= v[u][i];

            if(!vis[t][node]){
                vis[t][node]= 1;
                level[t][node]= level[t][u]+ 1;

                q.push(node);
            }

        }

    }

}

main(){
    reset();
    int a, b;

    sii(n,edges);
    sii(k,s);

    fr1(n){
        si(a);
        types[a].pb(i);
    }



    fr1(edges){
        sii(a,b);

        v[a].pb(b);
        v[b].pb(a);
    }

    fr1(k){
        bfs(i);
    }

    fr1(n){
        frj1(k)
            sorted_levels[i].pb(level[j][i]);
    }

    fr1(n)
        sort(all(sorted_levels[i]));


    fr1(n){
        i64 sum= 0;
        for(int j=0; j<s; j++)
            sum+= sorted_levels[i][j];

        outls(sum);
    }

}