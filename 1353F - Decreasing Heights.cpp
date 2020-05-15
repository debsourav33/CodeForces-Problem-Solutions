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

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 1e2+5;

int n, k, x, y, m;
i64 a[N][N], b[N][N], dp[N][N];
pii dir[N][N];

i64 call(int i, int j){
    if(i==n && j==m)  return 0;
    if(dp[i][j]!=-1)  return dp[i][j];


    i64 op1= 1e18, op2= 1e18;
    i64 moves= (i-1) + (j-1);  //curr cell value should equal to a[1][1] +  moves
    i64 cur_val= a[1][1] + moves + 1; //so next cell value should be a[1][1] +  moves + 1


    if(i+1<=n && a[i+1][j]>=cur_val )  op1 = a[i + 1][j] - cur_val + call(i + 1, j);
    if(j+1<=m && a[i][j+1]>=cur_val )  op2 = a[i][j + 1] - cur_val + call(i, j + 1);


    dir[i][j] = (op1 < op2) ? mp(i + 1, j) : mp(i, j + 1);

    return dp[i][j]= min(op1,op2);
}

void print(){
    int i=1, j=1;
    while(i!=n || j!=m){
        outii(i,j);
        int tmp= i;
        i= dir[i][j].ff;
        j= dir[tmp][j].ss;

    }
}

void reset(){
    fr1(n)
        frj1(m)
            dp[i][j]= -1;
}

main(){
    int opt;
    si(opt);

    while(opt--) {
        sii(n,m);

        fr1(n){
            frj1(m){
                sl(b[i][j]);
                a[i][j]= b[i][j];
            }
        }


        i64 ans= 1e18;

        fr1(n)
        {
            frj1(m){
                reset();

                a[1][1]= b[i][j] - ((i-1)+(j-1));
                if(b[1][1]<a[1][1])  continue;

                ans= min(ans, call(1,1) + b[1][1]-a[1][1]);
            }

        }

        outl(ans);

    }
}
