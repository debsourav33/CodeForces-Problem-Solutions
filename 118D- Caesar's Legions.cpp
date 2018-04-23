#include<bits/stdc++.h>
using namespace std;

#define MOD 100000000

int succFootman, succHorseman;

int dp[101][101][11][11];

int call(int footman, int horseman, int i1, int i2){
    if(dp[footman][horseman][i1][i2]!=-1)
        return dp[footman][horseman][i1][i2];

    if(footman+horseman==0)
        return 1;

    int opt1=0, opt2=0;


    if(i1<succFootman && footman>0)
        opt1= call(footman-1, horseman, i1+1,0)%MOD;

    if(i2<succHorseman && horseman>0)
        opt2= call(footman,horseman-1,0,i2+1)%MOD;

    return dp[footman][horseman][i1][i2]=(opt1+opt2)%MOD;

}

main(){
    int footman, horseman;

    memset(dp,-1,sizeof dp);

    cin>> footman>> horseman>> succFootman>> succHorseman;

    cout<< call(footman,horseman,0,0)<< endl;


}
