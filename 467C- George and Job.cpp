#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull a[5005], n, m, k, dp[5005][5005];

ull call(ull i, ull cnt){

    if(dp[i][cnt]!=-1)
        return dp[i][cnt];

    if(i>(n-m) || cnt>=k)
        return 0;

    ull opt1=0, opt2=0;

    for(ull v=i; v<i+m; v++){
        opt1+=a[v];
    }

    opt1= opt1+call(i+m, cnt+1);

    opt2= call(i+1, cnt);

    return dp[i][cnt]= max(opt1,opt2);


}

main(){
    cin>> n>> m>> k;
    memset(dp, -1, sizeof dp);

    for(ull i=0;i<n;i++)
        cin>>a[i];

    cout<< call(0,0) <<endl;


}
