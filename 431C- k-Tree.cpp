#include<bits/stdc++.h>
using namespace std;

#define sets(a) memset(a,-1,sizeof(a))
#define fr1(n) for(int i=1;i<=n;i++)
#define INF 1000000007
typedef long long ll;

int n,k,d;
ll dp[105][3];

int call(int amount, bool flag){
    if(amount>n)  return 0;
    if(amount==n)  return flag;

    ll &ret= dp[amount][flag];
    if(ret!=-1) return ret;

    ll cnt= 0;

    fr1(k)
        cnt+= call(amount+i, flag||(i>=d)) % INF;

    return ret= cnt%INF;

}

main(){
    sets(dp);
    cin>>n>>k>>d;

    cout<<call(0,0);
}
