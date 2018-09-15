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
int vis[100005], parent[100005], n, edges, cycle=0, evens= 0;

void reset(){
    clr(vis);
    sets(parent);
}

int dfs(int u){
    vis[u]= 1;
    int cnt= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            cnt+= dfs(nd);
        }
    }

    vis[u]= 2;
    if(cnt%2==0)  evens++; //we have found a even connected components
    return cnt;
}

main(){
    reset();
    int a, b;

    cin>>n;

    fr1(n-1){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    if(n%2==1){
        cout<<"-1"<<endl;
        return 0;
    }

    fr1(n){
        if(vis[i]==0)
            dfs(i);
    }


    //edge to cut is the number of connected components having even size - 1
    cout<<evens-1<<endl;
}
