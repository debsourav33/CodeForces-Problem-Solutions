#include<bits/stdc++.h>
using namespace std;

int position=0, flag[200];
string str;

int call(int i){
    position++;

    if(str[i]<97)
        return 0;

    if(flag[str[i]]==1)
        return call(i+1);

    int tmp=0;
    if(flag[str[i]]==0){

       flag[str[i]]=1;
       tmp= 1+call(i+1);
       flag[str[i]]=0; //backtracking

    }

    return tmp;

}

main(){
    int len,maxi=0,tmp;
    cin>>len>>str;

    while(position<str.length()){
        tmp= call(position);

        if(tmp>maxi)
            maxi=tmp;
    }

    cout<<maxi<<endl;

}
