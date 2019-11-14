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

const int maxn= 1e5+5;

int sub_tree[maxn], n, T[maxn], P[maxn][22], L[maxn], par[maxn], CL[maxn], nn;
char col[maxn];
vector<int> leveled[22];
set<int> adj[maxn];

void lca_dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;

    for(int s: adj[u]){
        if(s==p) continue;

        lca_dfs(s,u);
    }
}

void sub_dfs(int u, int p){
    //T[u]= p;
    nn++;
    sub_tree[u]= 1;

    for(int nd: adj[u]){
        if(nd==p) continue;

        sub_dfs(nd,u);
        sub_tree[u]+= sub_tree[nd];
    }
}

int getCentroid(int u, int p){
    for(int nd: adj[u]){
        if(nd==p) continue;

        if(sub_tree[nd]>nn/2)
            return getCentroid(nd, u);
    }

    return u;
}

void decompose(int u, int p){
    nn= 0;
    sub_dfs(u,-1);

    int centroid= getCentroid(u,-1);
    par[centroid]= p;

    //outi(centroid);

    for(int nd: adj[centroid]){
        adj[nd].erase(centroid);

        if(nd==p) continue;

        decompose(nd,centroid);
    }

    adj[centroid].clear();
}

void init_LCA(int n){
    sets(P);

    L[1]= 0;
    lca_dfs(1,-1);

    fr1(n){
        P[i][0]= T[i];
    }

    for(int j=1; (1<<j)<n;j++){
        fr1(n){
            if(P[i][j-1]!=-1)
                P[i][j]= P[P[i][j-1]][j-1];
        }
    }
}

int lca_query(int p, int q) {
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

int getDist(int p, int q){
    int lca= lca_query(p,q);

    return L[p]+L[q]-2*L[lca];
}

int vis[maxn];

void getCL(int u){
    if(vis[u])  return;
    vis[u]= 1;

    if(par[u]==-1){
        CL[u]= 0;
        leveled[CL[u]].pb(u);
        return;
    }

    getCL(par[u]);
    CL[u]= CL[par[u]]+1;
    leveled[CL[u]].pb(u);
}

main(){
    int a,b, m;
    si(n);

    fr(n-1){
        sii(a,b);

        adj[a].insert(b);
        adj[b].insert(a);
    }

    init_LCA(n);

    decompose(1,-1);
    fr1(n)  if(!vis[i])  getCL(i);

    int c=0;

    fr(22){
        for(int u: leveled[i])  col[u]= (char) ('A'+c);

        c++;
    }

    fr1(n)  printf("%c\n",col[i]);
}

/*
15
1 2 2 3 2 4
2 5 5 6 6 7
8 5 8 9
9 10 9 13
10 11 10 12
13 14 13 15
*/
