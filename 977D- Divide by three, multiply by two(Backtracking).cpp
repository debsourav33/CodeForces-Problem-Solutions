#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

bool taken[105];
bool flag;
ull n,a[105],tmp[105];
vector<ull> v;

void call(ull idx, ull pos){
    if(idx==n-1){
        flag=true;
        for(ull i=0;i<n-1;i++)
            v.push_back(tmp[i]);
    }

    for(ull i=0;i<n;i++){
            if(flag==false && taken[i]==false){
                if(a[pos]*2==a[i] || a[i]*3==a[pos]){
                    taken[i]=true;
                    tmp[idx]=a[i];

                    call(idx+1,i);
                    taken[i]=false;
                }

            }

    }



}

main(){
    memset(taken, false, sizeof taken);
    flag=false;
    cin>> n;

    for(ull i=0;i<n;i++)
        cin>>a[i];

    for(ull i=0;i<n;i++){
        call(0,i);
        if(flag==true){
            cout<<a[i];
            break;
        }
    }

    for(ull i=0;i<v.size();i++)
        cout<<" "<<v[i];

    puts("");

}
