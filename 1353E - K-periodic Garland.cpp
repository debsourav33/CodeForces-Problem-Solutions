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

const int N= 1e6+5;

int n, k, x, y;
int a[N], sum[N], dp[N], stop[N];

//bottom up DP
void call(int st){
    int r= min(n+1,st+k);

    dp[st]= sum[r-1]-sum[st] + (1-a[st]);  //option 1: make value 1 in index st, make all the values equal to 0 from st+1 to st+k-1 [used cumalive sum for this]
    if(st+k<n)  dp[st]+= dp[st+k]; //and then adding the dp result of index st+k

    int rem= sum[n]-sum[st];
    dp[st]= min(dp[st],rem); //option 2: make all index values equal to 0 from st+1 to n [again used cumulative sum]
}

void solve(){
    int ans= 1e9;

    for(int i=1;i<=n;i++){
        int rem= sum[i-1]- sum[0];

        ans= min(ans,dp[i]+rem);  //dp[i]+rem is the best result if we place first 1 in index i [hence has to remove all rem 1s from 1 to i-1]
    }

    outi(ans);
}

main(){
    int opt;
    si(opt);

    while(opt--) {
        sii(n,k);

        sum[0]= 0;
        fr1(n){
            scanf("%1d",&a[i]);
            sum[i]= sum[i-1] + a[i];
        }


        for(int i=n;i>=0;i--)
            call(i);

        solve();

    }
}
