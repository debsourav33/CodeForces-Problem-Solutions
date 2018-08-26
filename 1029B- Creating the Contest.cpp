#include<bits/stdc++.h>
using namespace std;

#define ll long long

main(){
    int n, a, maxi=0, cnt=0;

    cin>>n;
    cin>>a;

    int t_a=a;

    for(int i=1;i<n;i++){
        cin>>a;

        if(a<=2*t_a){
            cnt++;
            maxi= max(maxi,cnt);
        }

        else
            cnt=0;

        t_a= a;

    }


    cout<< maxi+1<< endl;

}
