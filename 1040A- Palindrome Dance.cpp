#include<bits/stdc++.h>
using namespace std;

//{
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define MX 10000007
#define all(v) v.begin(),v.end()
//}

main(){
    int n, w, b;
    int a[100];

    cin>>n>>w>>b;
    fr(i,0,n)
        cin>>a[i];

    int mini, maxi;
    if(w<=b){
        mini= w;
        maxi= b;
    }
    else{
        mini= b;
        maxi= w;
    }

    int st=0, endi=n-1, cost=0;

    while(st<=endi){

        if(a[st]==a[endi] && a[st]==2){
            if(st!=endi)
                cost+= 2*mini;
            else
                cost+= mini;
        }

        if(a[st]!=a[endi]){

            if(a[st]!=2 && a[endi]!=2){
                cout<<"-1"<<endl;
                return 0;
            }

            if(a[st]==0|| a[endi]==0)
                cost+= w;
            else if(a[st]==1|| a[endi]==1)
                cost+= b;

        }

        st++; endi--;
    }

    cout<<cost<<endl;
}
