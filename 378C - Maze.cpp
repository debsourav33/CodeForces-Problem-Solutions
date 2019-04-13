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

const int maxn= 505;

int m, n, vis[maxn][maxn], level[maxn][maxn], edges;
vector<pii> v;
char c[maxn][maxn];

int dr[]= {1,0,-1,0};
int dc[]= {0,1,0,-1};

void reset(){
    clr(vis);
    clr(level);

}

bool isValid(int x, int y){
    return !vis[x][y]  && x>=0 && y>=0 && x<n && y<m && c[x][y]=='.';
}

void bfs(int x, int y){
    queue<pii> q;
    q.push(mp(x,y));
    vis[x][y]= 1;

    v.pb(mp(x,y));

    while(!q.empty()){
        x= q.front().ff;
        y= q.front().ss;


        q.pop();

        fr(4){
            int cx= x+ dr[i];
            int cy= y+ dc[i];

            if(isValid(cx,cy)){
                vis[cx][cy]= 1;
                level[cx][cy]= level[x][y]+ 1;

                v.pb(mp(cx,cy));
                q.push(mp(cx,cy));
            }

        }

    }

}


main(){
    fastIO();
    reset();
    int a, b, k;

    cin>>n>>m>>k;

    pii start= mp(-1,-1);

    fr(n){
        for(int j=0; j<m; j++){
            cin>>c[i][j];

            if(c[i][j]=='.' && start.ff==-1){
                start= mp(i,j);
            }
        }
    }

    bfs(start.ff,start.ss);

    fr(v.size()){
        c[v[i].ff][v[i].ss]= '.';

        if(i>=v.size()-k)  c[v[i].ff][v[i].ss]= 'X';
    }

    fr(n){
        for(int j=0; j<m; j++){
            cout<<c[i][j];
        }
        cout<<endl;
    }


}
