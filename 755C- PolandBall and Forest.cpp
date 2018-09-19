#include<bits/stdc++.h>
using namespace std;

//{
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

vector<int> v[100005];
int vis[100005], parent[100005], n, edges, cycle=0, a[100005], adj[100005];

void reset(){
    clr(vis);
    sets(parent);
}

void dfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            dfs(nd);
        }

        if(vis[nd]==1){
            cycle= 1;
            return;
        }
    }

    vis[u]= 2;
}

main(){
    reset();
    cin>>n;

    fr1(n){
        adj[i]= i;
        cin>>a[i];
    }

    fr1(n){
        int con= a[a[i]];
        if(con==i)  continue;

        v[adj[con]].pb(i);
        v[i].pb(adj[con]);

        adj[con]= i;
    }

    int cnt=0;

    fr1(n){
        int con= a[a[i]];

        if(con==i){
            v[adj[i]].pb(adj[a[i]]);
            ++cnt;
        }
    }

    cout<<cnt/2<<endl;

    fr1(n){
        cout<<i<<":";
        for(int k=0;k<v[i].size();k++)
            cout<<" "<<v[i][k];
        puts("");
    }

//    fr1(n){
//        if(vis[i]==0)
//            dfs(i);
//    }
}
