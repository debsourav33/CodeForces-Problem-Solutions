#include<bits/stdc++.h>
using namespace std;

//{
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int vis[303][303], n, m, k;

void reset(){
    clr(vis);
}

bool is_valid(int x, int y){
    return x<m && y<n && x>=0 && y>=0 && vis[x][y]==0;
}

pii nexts;
int dc[]= {1,-1,0,0};
int dr[]= {0,0,1,-1};
int flag= 0;

void dfs(int x, int y, int cnt){
    if(cnt==0){
        flag= 1;
        return;
    }

    vis[x][y]= 1;

    cout<<" "<<x+1<<" "<<y+1;

    fr(4){
        int nxt_x= x+dr[i], nxt_y= y+dc[i];

        if(is_valid(nxt_x, nxt_y)){
            nexts= mp(nxt_x, nxt_y);
            dfs(nxt_x,nxt_y,cnt-1);
            if(flag)  return;
        }

    }
}

main(){
    reset();
    int a, b;

    cin>>m>>n>>k;

    int rem= m*n;
    nexts= mp(0,0);

    while(rem){
        flag= 0;
        int i= nexts.ff;
        int j= nexts.ss;
        if(k>1){
            cout<<2;  rem-=2, k--;
            dfs(i,j,2);
            puts("");

        }

        else{
            cout<<rem;
            dfs(i,j,rem);
            puts("");
            rem-=rem;
        }


    }
}
