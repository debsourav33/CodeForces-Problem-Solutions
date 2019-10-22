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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

const int N= 3e3+5;

struct node{
    i64 ver, cost, prevs;
    node(i64 v, i64 w, i64 u){
        ver= v;
        cost= w;
        prevs= u;
    }

    bool operator<(const node& a) const {
        return cost > a.cost;
    }
};

struct triplet{
    i64 a,b,c;
    triplet(i64 aa, i64 bb, i64 cc){
        a= aa;
        b= bb;
        c= cc;
    }

    bool operator<(const triplet& ax) const {
        if(a!=ax.a)  return a > ax.a;
        if(b!=ax.b)  return b > ax.b;
        return c>ax.c;
    }
};

map<triplet,i64> m;

vector<node> v[N];
i64 n, dist[N][N], edges, k, d;
pll parents[N][N];


void dijakstra(i64 source){
    priority_queue <node> q;
    q.push(node(source,0,0));

    fr1(n)
        frj1(N)
            dist[i][j]= (i64) 1e17;

    fr1(n)
        frj1(n)
            parents[i][j]= mp(-1LL,-1LL);

    dist[source][0]= 0;

    while(!q.empty()){
        i64 u= q.top().ver, u_prev= q.top().prevs, cost= q.top().cost;
        q.pop();

        if(dist[u][u_prev]!=cost)  continue;

        fr(v[u].size()){
            i64 nd= v[u][i].ver, weight= v[u][i].cost;

            triplet trp= triplet(u_prev,u,nd);
            if(m.count(trp))  continue;

            if(dist[u][u_prev]+ weight < dist[nd][u]){
                dist[nd][u]= dist[u][u_prev]+ weight;
                q.push(node(nd,dist[nd][u],u));

                parents[nd][u]= pll(u,u_prev);
            }
        }
    }
}

void track_parent(i64 u, i64 prevs){
    if(parents[u][prevs].ff<=0){
        outls(u);
        return;
    }

    pll p= parents[u][prevs];

    track_parent(p.ff,p.ss);
    outls(u);

}

main(){
    i64 a, b, c, w;

    slll(n, edges,k);

    fr1(edges) {
        sll(a, b);

        v[a].pb(node(b, 1, 0));
        v[b].pb(node(a, 1, 0));
    }

    fr(k){
        slll(a,b,c);

        triplet nds= triplet(a,b,c);
        m[nds]= 1;
    }

    dijakstra(1);

    i64 mini = 1e17, prevs= -1;
    fr1(n) {
        if(dist[n][i]<mini)  prevs= i;

        mini = min(mini, dist[n][i]);
    }

    if(mini==1e17)  puts("-1");
    else {
        outl(mini);
        track_parent(n,prevs);
        puts("");
    }
}
