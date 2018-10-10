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

struct node{
    ll ver, cost;
    node(ll v, ll w){
        ver= v;
        cost= w;
    }
};

bool operator <(node a, node b){
    return a.cost>b.cost;
}

vector<node> v[100005];
ll n, vis[100005], dist[100005], edges, parent[100005], cnt=0;

void reset(){
    clr(vis);
    sets(parent);
}

void dijakstra(ll source){
    priority_queue <node> q;
    q.push(node(source,0));

    fr1(n)
        dist[i]= 10e18;

    dist[source]= 0;
    vis[source]= 1;

    while(!q.empty()){
        cnt++;
        ll u= q.top().ver;
        q.pop();

        for(ll i=0;i<v[u].size();i++){
            ll nd= v[u][i].ver;

            if(dist[u]+ v[u][i].cost < dist[nd]){
                vis[nd]= 1;
                dist[nd]= dist[u]+ v[u][i].cost;
                parent[nd]= u;
                q.push(node(nd,dist[nd]));
            }

        }

    }

}

void print_path(ll node){
    if(parent[node]==-1){
        cout<<node;
        return;
    }

    print_path(parent[node]);
    cout<<" "<<node;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    reset();
    ll a, b, w;

    cin>>n>>edges;

    fr1(edges){
        cin>>a>>b>>w;

        v[a].pb(node(b,w));
        v[b].pb(node(a,w));
    }

    dijakstra(1);

    if(parent[n]==-1){
        cout<<"-1"<<endl;
        return 0;
    }

    print_path(n);
    cout<<endl;


}

/*
8 11
1 2 7
1 4 2
4 4 5
2 5 5
2 5 4
3 4 1
3 5 2
5 6 3
5 6 2
5 7 6
7 8 11
*/
