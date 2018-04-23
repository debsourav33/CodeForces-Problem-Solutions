#include<bits/stdc++.h>
#define MX 999999
using namespace std;

    int dp[10000][10000];
int getNum(vector <int> v){

    int s=0;
    for(int j=0;j<v.size();j++){
        s=s*10+v[j];
    }

    return s;

}

int call(vector <int> v, int i, int num){
    if(num==0)
        return 0;

    if(v.size()==0 || v[0]==0)
        return MX;


    int opt1= 9999, opt2=9999, opt3=9999, opt4=9999, no;

    no= getNum(v);

    //if(dp[no][num]!=-1)
       // return dp[no][num];

    if(num>=no)
        opt1= 1+ call(v,i,num-no);

    vector <int> tmp, tmp2;

    for(int i=0; i<v.size(); i++){
        tmp.push_back(v[i]);
        tmp2.push_back(v[i]);

    }

    tmp.erase(tmp.begin()+tmp.size()-1);
    no= getNum(tmp);

    if(i>0)
        opt2= call(tmp,i-1,num);

    if(i>0)
        opt3= call(tmp2,i-1,num);

    if(i>0){
        tmp2[i-1]=0;
        no= getNum(tmp2);

        opt4= call(tmp2,i-1,num);
    }
    return dp[no][num]=min(min(opt1,opt2),min(opt3,opt4));





}

main(){
    while(true){
   int a,b,c,x, n, digits;
    vector <int> v;

    cin>> n;

    digits= log10(n)+1;

    for(int i=0;i<10000;i++){
             for(int j=0;j<10000;j++)
                dp[i][j]=-1;
    }

    for(int i=0;i<digits;i++){
        v.push_back(1);
    }

    cout<< call(v, digits, n) << endl;
    }


}
