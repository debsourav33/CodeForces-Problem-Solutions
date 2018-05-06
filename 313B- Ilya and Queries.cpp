#include<bits/stdc++.h>
using namespace std;




main(){
    int m,l,r,cnt=0;

    int dp[100005];
    string s;

    cin>>s>>m;

    for(int i=1;i<s.size();i++){

        if(s[i]==s[i-1])
            cnt++;

        dp[i]= cnt;

    }

    while(m--){
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<endl;
    }




}
