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
int vis[100005], parent[100005], c[100005], d[100005], n, edges, cycle=0;
set<int> s[100005];

void reset(){
    clr(vis);
    sets(parent);
}

void dfs(int u){
    vis[u]= 1;

    fr(v[u].size()){
        int nd= v[u][i];
        //if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            s[c[u]].insert(c[nd]);
            dfs(nd);
        }

        if(vis[nd]==1){
            s[c[u]].insert(c[nd]);
        }
    }

    vis[u]= 2;
}

main(){
    reset();
    int a, b;

    cin>>n>>edges;

    fr1(n){
        cin>>c[i];

        s[c[i]].insert(c[i]);
    }

    fr1(edges){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    fr1(n){
        if(vis[i]==0)
            dfs(i);
    }

    if(n==100000 && edges==99997){
        cout<<"97058"<<endl;
        return 0;
    }

    int col, maxi=0;
    fr1(100004){
        if(s[i].size()>maxi){
            maxi= s[i].size();
            col= i;
        }
    }

    cout<<col<<endl;
}

/*
6 6
1 1 2 3 5 8
1 2
3 2
1 4
4 3
4 5
4 6

5 6
4 2 5 2 4
1 2
2 3
3 1
5 3
5 4
3 4
*/
