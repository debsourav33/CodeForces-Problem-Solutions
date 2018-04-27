#include<bits/stdc++.h>
using namespace std;

#define MX -999999
int step,d,endi,starti;

//struct direct{
//    int s, t;
//    direct(){
//    }
//
//    direct(int _s, int _t){
//        s=_s;
//        t=_t;
//    }
//
//}dir[10000][10000];

int dp[1000][1000];

int call(int start, int t){

    if(start-(step-t)*d>endi)
        return MX;

    if(dp[start][t]!=-1)
        return dp[start][t];

    int maxi=MX;

    if(t>=step && start==endi)
        return 0;
    if(t>=step)
        return MX;


    for(int i=start;i<=start+d;i++){
        if(i+call(i,t+1)>maxi){
            maxi=i+call(i,t+1);
//            dir[start][t]= direct(i,t+1);
        }
    }

    for(int i=start;i>=start-d;i--){
        if(i>0){
            if(i+call(i,t+1)>maxi){
                maxi=i+call(i,t+1);
//                dir[start][t]= direct(i,t+1);
            }
        }
    }

    return dp[start][t]=maxi;

}

//void print_path(int s,int t){
//    if(dir[s][t].s==-1)
//        return;
//
//    int next_s= dir[s][t].s;
//    int next_i=dir[s][t].t;
//
//    cout<<next_s<<endl;
//
//    print_path(next_s, next_i);
//
//
//}

main(){
    cin>> starti>> endi>>step>>d;
//    memset(dir, -1, sizeof dir);
    memset(dp, -1, sizeof dp);

    int dist= starti+ call(starti,1);


//    cout<<starti<<endl;
//    print_path(starti,1);
    cout<< dist<< endl;


}
