#include<bits/stdc++.h>
#include<string.h>
using namespace std;

map<string,int> my_map;


void feedBack(string email){

    if(my_map[email]==0){
        cout<<"OK"<<endl;
        my_map[email]++;
        return;
    }

    stringstream ss;
    ss<< my_map[email];
    string tmp= email+ ss.str();
    cout<<tmp<<endl;
    my_map[email]++;
}


main(){
    int n;
    string email;

    cin>>n;

    while(n--){
        cin>>email;
        feedBack(email);
    }


}

