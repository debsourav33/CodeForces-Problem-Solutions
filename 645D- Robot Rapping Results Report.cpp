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
#define outis(a,sz) printf("%d",a[0]); for(int i=1;i<sz;i++) printf(" %d",a[i]); puts("")

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int maxn= 1e5+5;

vector<int> v[maxn];
int vis[maxn], n, m;
pii edge[maxn];

stack<int> st;
void topsort(int u){
    vis[u]= 1;
    fr(v[u].size()){
        int nd= v[u][i];

        if(!vis[nd]){
            topsort(nd);
        }
    }

    st.push(u);
}

int metall(){
    int mark[maxn];
    clr(mark);

    int s= st.top();
    mark[s]= 1;
    st.pop();

    while(!st.empty()){
        int fl= 0;
        int t= st.top();
        mark[t]= 1;

        fr(v[s].size()){
            if(v[s][i]==t)
                fl= 1;
        }

        if(!fl)  return 0;
        s= t;
        st.pop();
    }

    fr(n)
        if(!mark[i])  return 0;

    return 1;
}

int can(int r){
    clr(vis);
    while(!st.empty())  st.pop();
    fr(maxn)  v[i].clear();

    int x, y;
    fr(r){
        x= edge[i].ff, y= edge[i].ss;

        v[x].pb(y);
    }

    fr(n){
        if(!vis[i])
            topsort(i);
    }

    return metall();
}

int main(){
    int u, v;
    sii(n,m);
    fr(m){
        sii(u,v);
        edge[i].ff= u-1;
        edge[i].ss= v-1;

    }

    int lo= 1, hi= m+1;

    while(lo<hi){
        int mid= (lo+hi)/2;
        if(can(mid))  hi= mid;
        else  lo= mid+1;
    }

    if(lo==m+1)  puts("-1");
    else  outi(lo);
}
