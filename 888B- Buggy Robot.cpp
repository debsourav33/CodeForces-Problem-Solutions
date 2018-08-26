#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, l=0, u=0;
    char c;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>c;

        if(c=='L')
            l++;
        else if(c=='R')
            l--;
        else if(c=='U')
            u++;
        else if(c=='D')
            u--;


    }

    cout<<n-abs(l)- abs(u)<<endl;

}
