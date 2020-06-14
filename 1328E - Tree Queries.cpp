#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outiii(a,b,c) printf("%d %d %d\n",a,b,c)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int maxn= 2e5+5;

int vis[maxn], n, T[maxn], P[maxn][22], L[maxn], Dist[maxn];
vector<int> v[maxn];

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
    sets(T);
    L[1]= 0;
    dfs(1,-1);

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

int lca_query(int p, int q)
{
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

i64 getDist(int x, int y){
    int lc= lca_query(x,y);

    return L[x]+L[y]- 2*L[lc];
}

int getParent(int p, int no){
    no--;
    if(no==-1)  return p;

    int log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p])break;
        log++;

    }

    for(int i=log;i>=0;i--){
        if((1<<i)<=no) {
            p = P[p][i];
            no-= (1<<i);
        }
    }

    return P[p][0];
}

vector<int> q;

bool cmp(int a, int b){
    return L[a] < L[b];
}

bool solve(){
    fr(q.size()-1){
        int lca= lca_query(q[i],q[i+1]);

        if(getDist(q[i],lca) > 1 && getDist(q[i+1],lca) > 1 )  return false;
    }

    return true;
}

main(){
    int a, b, opt, cnt;
    sii(n,opt);

    fr1(n-1){
        sii(a,b);

        v[a].pb(b);
        v[b].pb(a);
    }

    init_LCA(n);


    while(opt--){
        q.clear();
        si(cnt);

        fr(cnt){
            si(a);
            q.pb(a);
        }

        sort(all(q),cmp);

        if(solve())  puts("YES");
        else  puts("NO");
    }


}

/*
9
1 2 1 3
2 4 2 5
3 8 3 9
4 6 4 7

 */