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
    int n;
    cin>>n;

    if(n<=2){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes"<<endl;

    cout<<n-1;
    for(int i=1;i<=n-1;i++)
        cout<<" "<<i;
    puts("");

    cout<<"1 "<<n<<endl;
}
