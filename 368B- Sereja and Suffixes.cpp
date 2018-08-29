#include<bits/stdc++.h>
using namespace std;

int m, n, dp[100005], a[100005], mark[100005];

int call(int pos){
    if(dp[pos]!=-1) return dp[pos];
    if(pos>=n)  return 0;

    int tmp= call(pos+1);

    if(!mark[a[pos]]){
        mark[a[pos]]=1;
        return dp[pos]= 1+tmp;
    }

    return dp[pos]= tmp;
}

main(){
    memset(dp, -1, sizeof dp);
    memset(mark, 0, sizeof mark);

    cin>>n>>m;

    for(int i=0;i<n;i++)
        cin>>a[i];

    int st;
    while(m--){
        cin>>st;
        cout<<call(st-1)<<endl;
    }


}
