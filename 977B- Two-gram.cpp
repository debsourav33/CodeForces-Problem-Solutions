#include<bits/stdc++.h>
using namespace std;

string str;

int call(string sub){
    int cnt=0,maxi=0;

    for(int i=0;i<str.size()-1;i++){
        if(str[i]==sub[0] && str[i+1]==sub[1])
            cnt++;


    }

    return cnt;


}

main(){
    int maxi=0,n;
    string gram;

    cin>>n;
    cin>>str;

    for(int i=0;i<str.size()-1;i++){
        string sub= str.substr(i,2); //substr(index, length)

        int temp= call(sub);

        if(temp>maxi){
            maxi= temp;
            gram= sub;
        }
    }

    cout<<gram<<endl;

}
