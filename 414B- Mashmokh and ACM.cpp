#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28
#define MOD 1000000007
#define ll long long
#define ull unsigned long long


ull n, k, dp[2005][2005];

ull call(ull i, ull cnt){
    if(dp[i][cnt]!=-1)
       return dp[i][cnt];

    if(i>n)
        return 0;

    if(cnt==k)
        return 1;

    ull opt1=0;

    for(ull opt=1;i*opt<=n;opt++){
        if(i*opt<=n)
            opt1+= call(i*opt, cnt+1) % MOD;
    }




    return dp[i][cnt]= opt1 % MOD;


}



main(){

    memset(dp,-1,sizeof dp);

    cin>> n>> k;
    ull sum=0;

    for(ull i=1;i<=n;i++){
      sum+= call(i,1)  % MOD;
    }

    cout<< sum%MOD<<endl;

}
