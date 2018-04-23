#include<bits/stdc++.h>
using namespace std;

string getMax(int n, int num){
    if(n==1 & num==0)
        return "0";

    if(num==0)
        return "-1";

    string str;

    long long sum=0;
    for(int i=0;i<n;i++){
        str.push_back(min(9,num)+'0');
        num-=min(9,num);
    }

    if(num>0)
        return "-1";

    return str;
}

string getMin(int n, int num){
    if(n==1 & num==0)
        return "0";
    if(num==0)
        return "-1";
    string str;

    for(int i=0;i<n;i++){

        if(i==n-1){
            str.insert(str.begin(),(min(9,num)+'0'));
            num-=min(9,num);
        }
        else{
            str.insert(str.begin(),(min(9,num-1)+'0'));
            num-=min(9,num-1);
        }

    }

    if(num>0)
        return "-1";

    return str;
}


main(){
    long long n, num;
    cin>> n>> num;

    cout<< getMin(n,num) <<" "<< getMax(n,num)<<endl;
    //printf("%s %s\n",getMin(n,num),getMax(n,num));
}
