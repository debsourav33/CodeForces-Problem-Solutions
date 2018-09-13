#include<bits/stdc++.h>
using namespace std;

//{
#define ceil(n,k) ((n-1)/k+1)
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

vector<int> v[10004];
int visited[10004], color[10004], cycle=0;

void reset(){
    clr(visited);
    clr(color);
}

int dfs(int u, int col){
    visited[u]= 1;
    int cnt= 0;

    fr(v[u].size()){
        int node= v[u][i];

        if(!visited[node])
            cnt+= (1-(color[node]==col))+ dfs(node, color[node]);
    }

    visited[u]= 2;
    return cnt;
}

main(){
    reset();
    int p, n;

    cin>>n;

    for(int i=2;i<=n;i++){
        cin>>p;
        v[p].pb(i);
    }

    for(int i=1;i<=n;i++){
        cin>>color[i];
    }

    cout<<1+ dfs(1,color[1])<<endl;
}
