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


const int N= 2e5+5;

int n;
i64 a[N], k, dp[N][2][2][2];

i64 call(int pos, int st_ev, int ev, int finish){
    if(pos==n)  return finish ? 0 : -1e17;  //finish==1 makes sure odd length sub_array was selected.
    if(dp[pos][st_ev][ev][finish]!=-1)  return  dp[pos][st_ev][ev][finish];


    i64 op1= 0, op2= 0;

    if(finish)  op1= ev? a[pos] + call(pos+1,st_ev,0,1) : a[pos] * 0 + call(pos+1,st_ev,1,1);
    else{
        op1=  ev? a[pos] * 0 + call(pos+1,st_ev,0,0) : a[pos] + call(pos+1,st_ev,1,0);
        if(ev!=st_ev)  op2=  ev? a[pos] * 0 + call(pos+1,st_ev,0,1) : a[pos] + call(pos+1,st_ev,1,1);  //if subarray has odd length, reversing has zero effect. So make sure sub_array is odd.
    }

    return dp[pos][st_ev][ev][finish]=  max(op1,op2);
}


int main()
{
    int q;
    si(q);

    while(q--) {
        si(n);
        fr(n) frj(2) for(int k=0;k<2;k++) for(int l=0;l<2;l++)  dp[i][j][k][l]= -1;

        fr(n) sl(a[i]);

        i64 maxi = 0, sum = 0;

        fr(n) {
            i64 s = call(i, (i % 2 == 0), (i % 2 == 0), 0);

            //if(maxi<sum+s)  outi(i);

            maxi = max(maxi, sum + s);
            sum = (i % 2) ? sum : sum + a[i];
        }

        maxi = max(maxi, sum);
        outl(maxi);
    }
}

