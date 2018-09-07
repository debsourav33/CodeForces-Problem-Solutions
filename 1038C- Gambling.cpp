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
    int n, a[100005], b[100005];

    cin>>n;
    fr(i,0,n)
        cin>>a[i];
    fr(i,0,n)
        cin>>b[i];

    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());

    ll A=0, B=0;
    int cA=0, cB=0, i=0;

    while(cA<n || cB<n){

        if(i%2==0){
            if(cA<n && (cB>=n || a[cA]>=b[cB])){
                A+= a[cA];
                cA++;
            }
            else{
                cB++;
            }
        }
        else{
            if(cB<n && (cA>=n || a[cA]<=b[cB])){
                B+= b[cB];
                cB++;
            }
            else{
                cA++;
            }
        }

        i++;
    }

    cout<<(A-B)<<endl;
}
