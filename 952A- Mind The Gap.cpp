#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28

main(){
    int n,s, h, m, a[1000];
    cin>>n>>s;

    int time=0;
    a[0]=0;

    for(int i=1; i<=n;i++){
        cin>>h>>m;
        int t= h*60+m;
        a[i]=t;
    }

    for(int i=1; i<n;i++){
        if((a[i+1]-a[i])>=(2*s+2)){ //landing time 1 min+ takeoff time 1 min
            time= a[i]+s+1;
            break;
        }
    }

    if(time==0)
        time=a[n]+s+1;

    if((a[1]-a[0])>=(s+1)) //no landing time.. takeoff time 1 min
            time= 0;

    int t_h= (time/60);
    int t_m=time%60;

    cout<<t_h<<" "<<t_m<<endl;



}
