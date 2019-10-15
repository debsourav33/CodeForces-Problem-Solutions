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

#define lefts 2*at
#define rights 2*at+1

const int N= 1e5+5;

int n, T[N], P[N][22], L[N], subTree[N];
int chainHead[N], chain[N], chainSize[N], chainPos[N], no;
int BaseTree[N], posInBase[N], cnt[4*N], lazy[4*N], baseIndex;

vector<int> v[N];
vector<pii> edges;

void dfs(int u, int p){
    T[u]= p;
    L[u]= (p>-1) ? L[p]+1 : 0;
    subTree[u]= 1;

    for(int nd: v[u]){
        if(nd==p)  continue;
        dfs(nd,u);
        subTree[u]+= subTree[nd];
    }
}

void hld(int u, int p){
    if(chainHead[no]==-1)  chainHead[no]= u;
    chain[u]= no;
    chainSize[no]++;
    chainPos[u]= chainSize[no]-1;

    posInBase[u]= baseIndex;
    BaseTree[baseIndex++]=  u;

    int ind= -1, sz= -1;
    fr(v[u].size()) {
        int nd= v[u][i];
        if(nd==p) continue;

        if (subTree[nd]>sz)  ind= i, sz= subTree[nd];
    }

    if(ind!=-1)  hld(v[u][ind],u);

    fr(v[u].size()){
        if(v[u][i]==p) continue;

        if(i!=ind){
            no++;
            hld(v[u][i],u);
        }
    }
}

void init_LCA(int n){
    sets(P);

    fr(n){
        P[i][0]= T[i];
    }

    for(int j=1; (1<<j)<n;j++){
        fr(n){
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

void build(int at, int l, int r){
    if(l==r){
        lazy[at]= 0;
        return;
    }

    int mid= (l+r)/2;

    build(lefts,l,mid);
    build(rights,mid+1,r);
}

void upd(int at, int x){
    cnt[at]+= x;
    lazy[at]+= x;
}

void propagate(int at){
    upd(lefts, lazy[at]);
    upd(rights, lazy[at]);

    lazy[at]= 0;
}

void update(int at, int l, int r, int x, int y){
    if(x>y)  return;
    if(x<=l && r<=y){
        lazy[at]++;
        cnt[at]++;

        return;
    }

    if(x>r || y<l)  return;

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    update(lefts,l,mid,x,y);
    update(rights,mid+1,r,x,y);
}

int query(int at, int l, int r, int x){
    if(l==r)  return cnt[at];

    if(lazy[at]) propagate(at);

    int mid= (l+r)/2;

    if(x<=mid)  return query(lefts,l,mid,x);
    else  return query(rights,mid+1,r,x);
}

void updateUp(int u, int v){
    if(u==v)  return;
    int uchain= chain[u], vchain, ans= 0;

    while(1){
        vchain= chain[v];

        if(uchain==vchain){
            update(1,0,n-1, posInBase[u]+1,posInBase[v]);
            break;
        }

        int head= chainHead[vchain];
        update(1,0,n-1, posInBase[head],posInBase[v]);  //update v's chain

        v= T[head]; //change chain
    }
}

void updateQuery(int u, int v){
    int lca= lca_query(u,v);

    updateUp(lca,u);
    updateUp(lca,v);
}

void reset(int n){
    fr(n)  v[i].clear();
    edges.clear();
    sets(chainHead);
    clr(chainSize);  clr(chain);
    no= baseIndex= 0;
}

main(){
    baseIndex= no= 0;
    sets(chainHead);

    int a, b, opt;

    si(n);
    fr(n - 1) {
        sii(a,b);
        --a, --b;

        v[a].pb(b);
        v[b].pb(a);

        edges.pb(mp(a, b));
    }

    dfs(0, -1);
    hld(0, -1);
    init_LCA(n);
    build(1, 0, n - 1);

    si(opt);
    while(opt--){
        sii(a,b);
        --a;
        --b;

        updateQuery(a,b);
    }

    fr(edges.size()){
        a= edges[i].ff, b=edges[i].ss;

        int ans;

        if(a==T[b]){
             ans= query(1,0,n-1,posInBase[b]);
        }
        else{
            ans= query(1,0,n-1,posInBase[a]);
        }

        outi(ans);
    }
}
