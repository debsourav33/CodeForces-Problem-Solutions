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

vector<int> v[maxn], conn;
int vis[maxn], c[maxn], n, edges, cycle=0;

void reset(){
    clr(vis);
}

void dfs(int u){
    vis[u]= 1;
    conn.pb(u);

    fr(v[u].size()){
        int nd= v[u][i];

        if(!vis[nd]){
            dfs(nd);

        }
    }

}

bool comp(int a, int b){
    return c[a]>c[b];
}

int solve(int u){
    conn.clear();
    dfs(u);

    sort(all(conn),comp);

    int match= 1, maxi= 1;

    fr1(conn.size()-1){
        if(c[conn[i]]!=c[conn[i-1]])
            match= 0;

        maxi= max(maxi,++match);

    }

    return conn.size()-maxi;
}

main(){
    reset();
    int a, b, k;

    siii(n,edges,k);

    fr1(n)
        si(c[i]);

    fr(edges){
        sii(a,b);

        v[a].pb(b);
        v[b].pb(a);
    }

    int ans= 0;

    fr1(n){
        if(vis[i]==0)
            ans+= solve(i);
    }

    outi(ans);
}
