#include<bits/stdc++.h>
using namespace std;

long n, a[100005], dp[100005][3];

long call(long i, long flag){
    if(i>n) return 0;
    if(dp[i][flag]!=-1) return dp[i][flag];

    long opt1=-999999999, opt2=-999999999, opt3=-999999999;

    long mul= 1;
    if(flag==1)
        mul= -1;

    opt1= mul*a[i]+ call(i+1,flag);

    if(flag!=2)
        opt2= mul*a[i]+ call(i+1,1);

    opt3= mul*a[i]+ call(i+1,2);

    return dp[i][flag]= max(max(opt1, opt2), opt3);
}

main(){
    memset(dp,-1,sizeof dp);
    cin>>n;
    a[0]= 0;

    for(long i=1;i<=n;i++){
        cin>>a[i];
        a[i]*= -1;
    }

    cout<< call(0,0) <<endl;
}
