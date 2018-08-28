#include<bits/stdc++.h>
using namespace std;

#define ll long long

main(){
    char ch;
    ll k, zeros=0, cnt=0;
    vector<ll> v;

    scanf("%lld\n",&k);

    while(1){
        scanf("%1c",&ch);

        if(ch=='1'){
            v.push_back(zeros);
            zeros=0;
        }
        else if(ch=='0')
            zeros++;
        else{
            break;
        }
    }

    v.push_back(zeros);

    for(int i=0;i<v.size();i++){
        if(i+k>=v.size())
            break;

        ll left= v[i];
        ll right= v[i+k];

        if(k==0)
            cnt+= left*(left+1)/2;
        else
            cnt+= (left* right+ left+ right+ 1);

    }

    cout<<cnt<<endl;
}
