#include<bits/stdc++.h>
using namespace std;

int a[200005];
map <int, int> dp;

void solution(int endi, int pos){
    if(pos<0)
        return;

    if(a[pos]==endi){
        solution(endi-1,pos-1);
        cout<<pos+1<<" ";
    }

    else
        solution(endi, pos-1);
}

main(){
    int n, maxi=0,endi,endi_index;
    cin>> n;

    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=0;
    }

    for(int i=0; i<n; i++){
        dp[a[i]]= dp[a[i]-1]+1;

        if(dp[a[i]]>maxi){
            endi_index=i;
            endi= a[i];
            maxi=dp[a[i]];
        }

    }

    cout<<maxi<<endl;


    solution(endi-1,endi_index-1);
    cout<<endi_index+1<<endl;
}
