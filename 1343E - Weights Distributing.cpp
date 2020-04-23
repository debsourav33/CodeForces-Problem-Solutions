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

const int N= 2e5+5;

int n, m, a, b, c, x, y , vis[N][3], level[N][3], vertices[N];
i64 pre[N], p[N];

vector<int> v[N];

void bfs(int id){
    int source= vertices[id];

    queue<int> q;
    q.push(source);
    vis[source][id]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int node: v[u])
        {
            if(!vis[node][id]){
                vis[node][id]= 1;
                level[node][id]= level[u][id]+ 1;

                q.push(node);
            }
        }

    }

}


main(){
    int opt;
    si(opt);

    while(opt--){
        sii(n,m);
        //siii(a,b,c);

        fr(3)  si(vertices[i]);

        fr(m)  sl(p[i]);
        sort(p,p+m);

        pre[0]= 0;
        fr(m)  {pre[i+1]= pre[i]+p[i]; };



        fr(m){
            sii(x,y);
            v[x].pb(y);
            v[y].pb(x);
        }

        fr(3){
            bfs(i);
        }

        i64 mini= 1e18;


        fr1(n){
            i64 twice= level[i][1];

            i64 once= level[i][0] + level[i][2];

            if(once+twice > m)  continue;

            i64 tot= 2*pre[twice];
            tot+= pre[twice+once]- pre[twice];

            mini= min(tot,mini);
        }


        outl(mini);

        fr(n+1) v[i].clear();

        fr(n+1){
            frj(3) {
                level[i][j]= vis[i][j]= 0;
            }

        }

    }


}
