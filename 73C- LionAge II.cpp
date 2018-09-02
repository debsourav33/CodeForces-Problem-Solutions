#include<bits/stdc++.h>
using namespace std;

/*
winner 4
4
s e 7
o s 8
l o 13
o o 8
*/

string str;
int t, n, bonus[123][123];
int dp[102][123][102];

int call(int p, int c, int t){
    if(t<0) return -9999999;
    if(p>=n)   return 0;

    if(dp[p][c][t]!=-1) return dp[p][c][t];

    int maxi=-9999999, val=0;

    for(int i=97; i<=122;i++){
        val= call(p+1,i,t-(1-(i==str[p])))+ bonus[c][i];
        maxi= max(maxi,val);
    }

    return dp[p][c][t]= maxi;
}

main(){
    memset(dp, -1, sizeof dp);
    cin>>str;
    cin>>t;

    char f,s;
    int b,change;
    cin>>change;

    for(int i=0;i<change;i++){
        cin>>f>>s>>b;
        bonus[f][s]= b;
    }

    n= str.length();
    cout<<call(0,'#',t)<<endl;
}
