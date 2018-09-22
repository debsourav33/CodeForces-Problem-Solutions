#include<bits/stdc++.h>
using namespace std;

//{
#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 1000000010

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int m, n, a[300005], b[300005], cnt=0, i=0, j=0;
ull s1, s2;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m;
    fr(m)
       cin>>a[i];

    cin>>n;
    fr(n)
        cin>>b[i];

    s1= a[0]; s2= b[0];

    while(i<m && j<n){
        if(s1==s2){
            ++cnt;
            s1= a[++i];
            s2= b[++j];

            continue;
        }

        if(s1<s2)
            s1+= a[++i];

        else
            s2+= b[++j];
    }

    if(i!=m || j!=n){
        cout<<"-1"<<endl;
        return 0;
    }

    cout<<cnt<<endl;
}
