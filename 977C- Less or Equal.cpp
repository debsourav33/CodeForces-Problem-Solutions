#include<bits/stdc++.h>
using namespace std;

string str;
int a[200005];

main(){
    int maxi=0,n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    if(k==0 && a[0]>1)
        cout<<"1"<<endl;

    else if(k==0 && a[0]==1)
        cout<<"-1"<<endl;

    else if(k<=n-1){
        if(a[k-1]!=a[k])
            cout<<a[k-1]<<endl;
        else
            cout<<"-1"<<endl;
    }

    else if(k==n)
        cout<<a[k-1]<<endl;




}

