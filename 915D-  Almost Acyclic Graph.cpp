#include<bits/stdc++.h>
using namespace std;

//{
#define ceil(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//}

vector<int> v[505];
vector<pii> c;
int visited[505], cycle, edged[505][505], edges, n;

void reset(){
    clr(visited);
    clr(edged);
    cycle=0;
}

void get_cycle(int u){
    visited[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];

        if(!visited[node]){
            c.pb(mp(u,node));
            get_cycle(node);
            if(cycle)  return;
        }

        if(visited[node]==1){
            c.pb(mp(u,node));
            cycle= 1;
            return;
        }
    }

    visited[u]= 2;
}

void dfs(int u){
    visited[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];
        if(edged[u][node])  continue;

        if(!visited[node]){
            dfs(node);
            if(cycle)  return;
        }

        if(visited[node]==1){
            cycle= 1;
            return;
        }
    }

    visited[u]= 2;
}

main(){
    reset();
    int a, b;
    cin>>n>>edges;

    fr(edges){
        cin>>a>>b;
        v[a].pb(b);
    }

    for(int i=1;i<=n;i++){
        if(!cycle && !visited[i])
            get_cycle(i);
    }

    if(!cycle){
        cout<<"YES"<<endl;
        return 0;
    }

    fr(c.size()){
        int f=c[i].ff, s=c[i].ss;

        edged[f][s]= 1;
        clr(visited);
        cycle=0;

        for(int u=1; u<=n; u++)
            if(!visited[u])
                dfs(u);

        if(!cycle){
            cout<<"YES"<<endl;
            return 0;
        }

        edged[f][s]= 0;
    }

    cout<<"NO"<<endl;
}
