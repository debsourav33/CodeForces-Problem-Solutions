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

vector<int> v[200005];
int vis[200005], col[200005], v_out[200005], parent[200005], n, edges, cycle=0, maxi= 1;

void reset(){
    clr(vis);
    sets(parent);
    clr(v_out);
}

void dfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;
        parent[nd]= u;

        for(int c=v_out[u]+1; ;c++){
            if(c!= col[u] && c!=col[parent[u]]){
                col[nd]= c;
                v_out[u]= c;
                maxi= max(c,maxi);
                break;

            }
        }

        dfs(nd);
    }

    vis[u]= 2;
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

    parent[1]= 0;
    col[1]= 1;
    col[0]= 0;
    dfs(1);

    cout<<maxi<<endl;
    cout<<col[1];
    for(int i=2;i<=n;i++){
        cout<<" "<<col[i];
    }

    puts("");
}
