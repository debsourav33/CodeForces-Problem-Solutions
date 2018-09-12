#include<bits/stdc++.h>
using namespace std;

//{
#define ceil(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//}

int n, a[100005], f[100005], sum, now;
ll ans;

main(){
    f[0]= ans= now= sum= 0;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+= a[i];
    }

    if(sum%3!=0){
        cout<<"0"<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++){
        now+= a[i];
        f[i]= f[i-1]+ (now*3==sum);
    }

    now= 0;

    for(int i=n;i>2;i--){
        now+= a[i];

        if(now*3==sum){
            if(sum==0)
                ans+=f[i-2];
            else
                ans+=f[i-1];
        }
    }

    cout<<ans<<endl;
}
