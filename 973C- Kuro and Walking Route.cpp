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

vector<int> v[300005];
int visited[300005], f, f_in= -1, b, nodes=0;
ll n, f_left=0;

void reset(){
    clr(visited);
}

void dfs(int u, int k, int flag){
    visited[u]= 1;
    nodes++;

    if(u==f){
        f_in= k;
        flag= 1;
    }
    if(flag==1)
        f_left++;

    fr(v[u].size()){
        int node= v[u][i];

        if(!visited[node])
            dfs(node, k, flag);
    }

    visited[u]= 2;
}

main(){
    reset();
    int x,y;
    cin>>n>>f>>b;

    fr(n-1){
        cin>>x>>y;

        v[x].pb(y);
        v[y].pb(x);
    }

    ll b_right=1;
    visited[b]= 1;

    fr(v[b].size()){
        nodes= 0;
        int nd= v[b][i];
        dfs(nd,i,0);
        if(i!=f_in)
            b_right+= nodes;
    }

    ll reachable= n*(n-1)-(f_left*b_right);
    cout<<reachable<<endl;
}

/*
6 1 3
9 1
1 2
2 3
3 4
3 7
*/
