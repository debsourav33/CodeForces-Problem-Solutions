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
    int n, k, a[27], mini= MX;
    memset(a, 0, sizeof a);
    cin>>n>>k;

    char ch;
    fr(i,0,n){
        cin>>ch;
        int c= ch- 'A';
        a[c]++;
    }

    fr(i,0,k){
        mini= min(mini,a[i]);
    }

    cout<<k*mini<<endl;
}
