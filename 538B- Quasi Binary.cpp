#include<bits/stdc++.h>
using namespace std;
#define MX 999999
#define mxSIZE 1000000

vector <int> bins, v;
int dp[mxSIZE+1][66];


struct direct{
    int i;
    int num;

    direct(int _i, int _num){
        i=_i;
        num=_num;
    }

    direct(){
    }

}dir[mxSIZE+1][66];

int call(int num, int i){
    if(num==0)
        return 0;

    if(dp[num][i]!=-1)
        return dp[num][i];

    int opt1=MX, opt2= MX;

    if(num>=bins[i])
        opt1= 1+ call(num-bins[i],i);

    if(i>0)
        opt2= call(num,i-1);


    if(opt1<=opt2)
        dir[num][i]= direct(i, num-bins[i]);
    else
        dir[num][i]= direct(i-1, num);

    return dp[num][i]=min(opt1,opt2);

}


int getBin(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

void solution(int num, int i){

    if(dir[num][i].i==-1)
        return;

    int direct_i= dir[num][i].i;
    int direct_num= dir[num][i].num;



    if(direct_i==i){
        if(dir[direct_num][direct_i].i==-1)
            cout<< bins[direct_i]<<endl;
        else
            cout<< bins[direct_i]<<" ";
    }

    solution(direct_num, direct_i);

}

main(){
    int num;
    cin>> num;

    memset(dp,-1,sizeof dp);
    memset(dir,-1, sizeof dir);


    int digits= log10(num)+1;

    int border= ceil(pow(2,digits))-1;


    for(int i=1; i<=border; i++)
        bins.push_back(getBin(i));

    cout<< call(num,bins.size()-1) <<endl;

    solution(num, bins.size()-1);

}
