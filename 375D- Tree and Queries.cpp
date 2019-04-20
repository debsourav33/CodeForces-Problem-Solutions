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

#define BLOCK 1000 // ~sqrt(N)
const int maxn= 1e5+5;
const int A= 1e5+5;

vector<int> v[maxn], begins;
int vis[maxn], parent[maxn], d[maxn], f[maxn], n, times= 0;
int cnt[A], freq[maxn], a[maxn], ans[A], k;


void reset(){
    clr(vis);
    sets(parent);
}

void dfs(int u){
    vis[u]= 1;
    d[u]= ++times;

    begins.pb(u);

    fr(v[u].size()){
        int nd= v[u][i];
        if(nd==parent[u]) continue;

        if(!vis[nd]){
            parent[nd]= u;
            dfs(nd);
        }
    }

    f[u]= times;
}

struct node {
    int L, R, i, k;
}q[A];

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        // different blocks, so sort by block.
        return x.L/BLOCK < y.L/BLOCK;
    }
    // same block, so sort by R value
    return x.R < y.R;
}



void add(int position) {
    int u= begins[position];
    int color= a[u];

    cnt[color]++;

    freq[cnt[color]]++;

}

void remove(int position) {
    int u= begins[position];
    int color= a[u];

    freq[cnt[color]]--;

    cnt[color]--;

}

void MO(int m){
    fr(m){
        int u;
        sii(u, q[i].k);
        q[i].L= d[u]-1; q[i].R= f[u]-1;
        q[i].i = i;
    }

    sort(q, q + m, cmp);


    int currentL = 0, currentR = 0;
    fr(m) {
        int L = q[i].L, R = q[i].R;
        while(currentR <= R) {
            add(currentR);
            currentR++;
        }

        while(currentL > L) {
            add(currentL-1);
            currentL--;
        }

        while(currentL < L) {
            remove(currentL);
            currentL++;
        }

        while(currentR > R+1) {
            remove(currentR-1);
            currentR--;
        }

        ans[q[i].i] = freq[q[i].k];
    }

    fr(m)
        outi(ans[i]);
}

main(){
    reset();
    int x, y, m;

    sii(n,m);

    fr1(n){
        si(a[i]);
    }

    fr1(n-1){
        sii(x,y);

        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    MO(m);

}

/*
7 6

1 5 1 6
6 7 6 4
4 3 4 2

*/
