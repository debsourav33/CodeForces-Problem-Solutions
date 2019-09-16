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
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define frj(n) for(int j=0;j<n;j++)
#define frj1(n) for(int j=1;j<=n;j++)
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

const int maxn= 2e5+5;

struct edge {
    int u, v;
    i64 w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int vis[maxn],n,m,k, par[maxn], T[maxn], P[maxn][22], L[maxn], Dist[maxn];
i64 Maxi[maxn][22], Mini[maxn][22];

vector<int> v[maxn];
vector<edge> edges, eds;
map<pii,i64> weight;

void reset(){
    fr1(n)  v[i].clear();
    edges.clear();
    clr(par);
}

int finds(int r)
{
    if (par[r]==r)
        return r;
    return par[r]= finds(par[r]);
}

i64 mst(int n)
{
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        par[i] = i;

    i64 count = 0, s = 0;
    for(edge e: edges){
        int x = finds(e.u);
        int y = finds(e.v);
        int w = e.w;

        if (x != y) {
            v[e.u].pb(e.v);
            v[e.v].pb(e.u);

            weight[mp(e.u,e.v)]= w;
            weight[mp(e.v,e.u)]= w;

            par[x] = y;
            count++;
            s += e.w;
            if (count == n - 1)
                break;
        }
    }

    return s;
}

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;

    for(int s: v[u]){
        if(s==T[u]) continue;

        dfs(s,u);
    }
}


void init_LCA(int n){
    sets(P);

    fr1(n){
        P[i][0]= T[i];

        if(P[i][0]!=-1) {
            Maxi[i][0] = weight[mp(i,T[i])];
            Mini[i][0] = weight[mp(i,T[i])];

        }
    }

    for(int j=1; (1<<j)<n;j++){
        fr1(n)
            if(P[i][j-1]!=-1) {
                P[i][j] = P[P[i][j - 1]][j - 1];
                Maxi[i][j]= max(Maxi[i][j-1], Maxi[P[i][j-1]][j-1]);
                Mini[i][j]= min(Mini[i][j-1], Mini[P[i][j-1]][j-1]);
            }
    }
}

i64 lca_query(int p, int q)
{
    i64 tmp, log, i, maxi= 0, mini= 1e6+6;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q]) {
            maxi= max(maxi,Maxi[p][i]);
            mini= min(mini,Mini[p][i]);

            p = P[p][i];
        }

    if (p == q)
        return maxi;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i]) {
            maxi= max(maxi,Maxi[p][i]);  maxi= max(maxi,Maxi[q][i]);
            mini= min(mini,Mini[p][i]);  mini= min(mini,Mini[q][i]);

            p = P[p][i], q = P[q][i];
        }

    maxi= max(maxi,Maxi[p][0]); maxi= max(maxi,Maxi[q][0]);
    mini= min(mini,Mini[p][0]); mini= min(mini,Mini[q][0]);

    return maxi;
}

void input(){
    sii(n,m);
    fr(m) {
        int x, y;
        i64 w;
        sii(x,y);  sl(w);
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        edges.pb(e);
        eds.pb(e);
    }


}

int main()
{

    reset();
    input();

    i64 wet= mst(n);

    L[1]= 0;
    dfs(1,-1);
    init_LCA(n);

    for(edge e: eds) {
        int a= e.u, b= e.v;

        i64 ws = lca_query(a,b);
        i64 ans= wet- ws+e.w;

        outl(ans);

    }

}
