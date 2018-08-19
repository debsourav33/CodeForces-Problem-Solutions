#include<bits/stdc++.h>
using namespace std;


main(){
    int n, k, left=0, right=0;
    cin>>n>>k;

    char c;

    for(int i=0;i<n;i++){
        cin>>c;

        if(c=='(' && left<k/2){
            cout<<c;
            ++left;
        }

        if(c==')' && right<k/2){
            cout<<c;
            ++right;
        }


    }

    puts("");

}
