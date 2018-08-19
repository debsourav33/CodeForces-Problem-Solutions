/*Divisibilty by 8 Rule for any number ending with i1i2i3*/

/*if i1 is even, i2i3 % 8= 0
if i1 is odd, (i2i3+4) % 8= 0*/

#include<bits/stdc++.h>
using namespace std;

string str;
int flag= 0, dp[140][140];

int to_int(int i1, int i2){
    int num= (str[i1]-48)*10+ (str[i2]-48);
    return num;

}

int to_int(int i1){
    int num= str[i1]-48;
    return num;
}

int check_odd(int pos){
    for(int i=0;i<pos;i++){
        if(to_int(i)%2==1){
            puts("YES");
            cout<<to_int(i);
            return 1;
        }
    }

    return 0;

}

int call(int i1, int i2){
    if(dp[i1][i2]!=-1)
        return dp[i1][i2];

    if(i1<0)    return 0;
    if(i2<=i1)  return 0;

    if(to_int(i1,i2)%8==0){
        puts("YES");
        cout<<to_int(i1,i2)<<endl;
        flag=1;
        return 1;
    }

    if((to_int(i1,i2)+4) %8== 0){
        if(check_odd(i1)){
            cout<<to_int(i1,i2)<<endl;
            flag=1;
            return 1;
        }
    }

    int opt1=0, opt2=0;

    opt1= call(i1-1,i2);    if(flag==1) return 1;
    opt2= call(i1,i2-1);

    return dp[i1][i2]= opt1||opt2;
}

main(){
    memset(dp,-1,sizeof dp);
    cin>>str;

    for(int i=0;i<str.length();i++){
        int num= str[i]-48;
        if(num%8==0){
            cout<<"YES"<<endl;
            cout<<num<<endl;
            return 0;
        }
    }

    int num= call(str.length()-2,str.length()-1);

    if(num==0)
        cout<<"NO"<<endl;
}
