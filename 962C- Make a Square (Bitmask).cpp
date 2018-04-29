#include<bits/stdc++.h>
using namespace std;

#define MX 999999

int sets(int N, int pos){

    return N= N | (1<<pos);
}

int resets(int N, int pos){

    return N= N & ~(1<<pos);

}

int check(int N, int pos){

    return (bool) (N & (1<<pos));
}


int dp[10000];
vector <int> v;

int isSqr(int mask){
    int flag=0;
    int num=0;
    for(int i=0;i<v.size();i++){
        if(check(mask,i)==1){
            if(v[i]!=0)
                flag=1;

            if(flag==0 && v[i]==0) //leading 0 found
                return 0;

            num=num*10+v[i];
        }

    }

    int root= sqrt(num);
    int sqr= root*root;

    if(num==sqr)
        return 1;

    return 0;
}

int call(int mask){
    if(dp[mask]!=-1)
        return dp[mask];

    if(mask<=0)
        return MX;

    if(isSqr(mask)){
        return 0;
    }


    int opt=MX;

    for(int i=0; i<v.size();i++){

        if(check(mask,i)==1){  //if the digit in this bit position is not taken out, take it out
            int ans= call(resets(mask,i));
            if(1+ans < opt)
                opt= 1+ans;
        }

    }

    return dp[mask]=opt;
}

main(){
    int n;
    memset(dp, -1, sizeof dp);
    cin>> n;

   while(true){
        v.insert(v.begin(),n%10);
        n=n/10;
        if(n==0)
            break;
   }
   int digits= v.size();
   int mask= (1<<digits)-1;

   int result= call(mask);

   if(result==MX)
       cout<< "-1" <<endl;
   else
        cout<< result <<endl;

}
