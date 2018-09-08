#include<bits/stdc++.h>
using namespace std;

//{
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
//}

vector<int> v[100005];
stack<int> topos;
int visited[100005], vertices[100005], cycle=0;

void reset(){
    clr(visited);
}

void dfs(int u){
    visited[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];

        if(!visited[node])
            dfs(node);
    }

    visited[u]= 2;
}

void topsort(int u){
    visited[u]= 1;

    fr(v[u].size()){
        int node= v[u][i];

        if(!visited[node]){
            topsort(node);
        }
    }
    topos.push(u);
    visited[u]= 2;
}

ll gold[100005], cost=0;
bool cmp(int a, int b){
    return gold[a] < gold[b];
}

main(){
    reset();
    int a, b, n, edges;
    cin>>n>>edges;

    for(int i=1;i<=n;i++)
        cin>>gold[i];

    for(int i=1;i<=n;i++)
        vertices[i]= i;
    sort(vertices+1,vertices+n+1,cmp);

    fr(edges){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=1;i<=n;i++){
        int u= vertices[i];
        if(visited[u]==0){
            topsort(u);
        }
    }

    reset();
    while(!topos.empty()){
        int i= topos.top();
        topos.pop();

        if(visited[i]==0){
            cost+= gold[i];
            dfs(i);
        }
    }

    cout<<cost<<endl;
}
