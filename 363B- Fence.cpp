#include<bits/stdc++.h>
using namespace std;

int a[1000005];

main(){
    int h, sum=0, mini, ind, n, k;

    cin>> n>> k;

    for(int i=0;i<k;i++){
        cin>>a[i];
        sum+=a[i];
    }

    mini= sum;
    ind= 0;

    for(int i=k; i<n; i++){
        cin>>a[i];

        sum= sum- a[i-k]+ a[i];

        if(sum<mini){
            mini= sum;
            ind= i-k+1;
        }
    }

    cout<<ind+1<<endl;

}
