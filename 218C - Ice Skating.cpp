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

const int maxn= 1003;

int m, n, vis[maxn][maxn], level[maxn][maxn], edges;
vector<pii> v, sx[1003], sy[1003];

void reset(){
    clr(vis);
    clr(level);

}


void bfs(int x, int y){
    queue<pii> q;
    q.push(mp(x,y));
    vis[x][y]= 1;


    while(!q.empty()){
        x= q.front().ff;
        y= q.front().ss;

        q.pop();

        fr(sx[x].size()){

            int cx= sx[x][i].ff;
            int cy= sx[x][i].ss;

            if(!vis[cx][cy]){
                vis[cx][cy]= 1;
                level[cx][cy]= level[x][y]+ 1;

                q.push(mp(cx,cy));
            }

        }

        fr(sy[y].size()){

            int cx= sy[y][i].ff;
            int cy= sy[y][i].ss;

            //outii(cx,cy);

            if(!vis[cx][cy]){
                vis[cx][cy]= 1;
                level[cx][cy]= level[x][y]+ 1;

                q.push(mp(cx,cy));
            }

        }

    }

}


main(){
    reset();
    si(n);

    int x,y;
    fr(n){
        sii(x,y);
;
        v.push_back(mp(x,y));
        sx[x].pb(mp(x,y));
        sy[y].pb(mp(x,y));
    }


    //fr(sy[1].size())  outii(sy[1][i].ff,sy[1][i].ss);

    int cnt= 0;
    fr(v.size()){
        x= v[i].ff;
        y= v[i].ss;

        if(!vis[x][y]){
            cnt++;
            bfs(x,y);
        }
    }

    outi(cnt-1);
}
