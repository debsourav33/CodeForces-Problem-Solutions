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

const int maxn= 1e3+5;

vector<int> v[maxn];
int n, vis[maxn], s_dist[maxn], d_dist[maxn], edge[maxn][maxn], parent[maxn], dest, path;

void reset(){
    clr(vis);
    sets(parent);
}

void bfs(int source){
    queue<int> q;
    q.push(source);

    clr(vis);

    s_dist[source]= 0;
    vis[source]= 1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int node= v[u][i];

            if(!vis[node]){
                vis[node]= 1;
                s_dist[node]= s_dist[u]+ 1;  if(node==dest)  path= s_dist[node];
                parent[node]= u;

                q.push(node);
            }
        }
    }

}

void dbfs(int source){
    queue<int> q;
    q.push(source);

    clr(vis);

    d_dist[source]= 0;
    vis[source]= 1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int node= v[u][i];

            if(!vis[node]){
                vis[node]= 1;
                d_dist[node]= d_dist[u]+ 1;
                parent[node]= u;

                q.push(node);
            }
        }
    }

}

int solve(){
    int opt= 0, d;

    fr1(n){
        for(int j=i+1;j<=n;j++){
            if(edge[i][j]) continue;

            if(d_dist[i] > d_dist[j])
                d= d_dist[j]+ 1+ s_dist[i];
            else
                d= d_dist[i]+ 1+ s_dist[j];


            //outii(i,j);
            //outi(d);

            if(d>=path)
                opt++;
        }
    }

    return opt;
}


main(){
    reset();
    int a, b, edges, src;

    sii(n,edges);
    sii(src,dest);

    fr1(edges){
        sii(a,b);

        edge[a][b]= edge[b][a]= 1;
        v[a].pb(b);
        v[b].pb(a);
    }

    bfs(src); dbfs(dest);

    outi(solve());
}
