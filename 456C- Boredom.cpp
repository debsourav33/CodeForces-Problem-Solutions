#include<bits/stdc++.h>
using namespace std;

//{
#define ceil(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//}

ll n, a[100005], sum[100005], dp[100005], MX= 100003;

main(){
    clr(sum);
    cin>>n;

    fr(n){
        cin>>a[i];
        sum[a[i]]+= a[i];
    }

    dp[0]= 0; dp[1]= sum[1];

    for(int i=2;i<=MX;i++)
        dp[i]= max(dp[i-1], sum[i]+dp[i-2]);

    cout<<dp[MX]<<endl;
}
