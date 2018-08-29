#include<bits/stdc++.h>
using namespace std;

main(){
    int n,w[200005], h[200005], max_i, sec_i, total_width=0;
    cin>>n;

    for(int i=0;i<2;i++){
        cin>>w[i]>>h[i];
        total_width+= w[i];
    }

    if(h[0]>=h[1]){
        max_i= 0;
        sec_i= 1;
    }
    else{
        max_i= 1;
        sec_i= 0;
    }

    for(int i=2;i<n;i++){
        cin>>w[i]>>h[i];
        total_width+= w[i];

        if(h[i]> h[max_i]){
            sec_i= max_i;
            max_i= i;
        }
        else if(h[i]>= h[sec_i])
            sec_i= i;
    }


    for(int i=0;i<n-1;i++){
        int wid= total_width- w[i];
        if(i==max_i)
            cout<<(wid*h[sec_i])<<" ";
        else
            cout<<(wid*h[max_i])<<" ";
    }

    int wid= total_width- w[n-1];
    if(n-1==max_i)
        cout<<(wid*h[sec_i])<<endl;
    else
        cout<<(wid*h[max_i])<<endl;
}
