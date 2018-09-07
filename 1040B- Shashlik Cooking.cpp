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
    int n, k;
    cin>>n>>k;

    int mini= k+1, maxi= 2*k+1;

    int steps= (n-1)/maxi+1;
    cout<<steps<<endl;

    int f= n%maxi, diff;

    if(f==0)
        diff= 1+k;
    else if(f<=mini)
        diff= 1;
    else
        diff= 1+f-mini;

    cout<<diff;
    steps--;

    while(steps--){
        diff+= maxi;
        cout<<" "<<diff;
    }

    puts("");
}
