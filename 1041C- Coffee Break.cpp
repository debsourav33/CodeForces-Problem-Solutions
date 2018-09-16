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
#define INF 10000007

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int n, m, d, x, day[200005], mday[200005], comp, cind, last;
pii a[200005];

bool cmp(pii p1, pii p2){
    return p1.ff<p2.ff;
}

main(){
    cin>>n>>m>>d;

    fr(n){
        cin>>x;
        a[i]= mp(x,i);
    }

    if(n==1){
        cout<<"1"<<endl<<"1"<<endl;
        return 0;
    }

    sort(a,a+n,cmp);

    int low= a[0].ff, low_i= 0, high= 0;
    day[0]= 1;

    fr(n){
        if(a[i].ff-low> d){
            day[i]= day[low_i];
            mday[a[i].ss]= day[i];

            low_i= low_i+1;
            low= a[low_i].ff;
        }

        else{
            day[i]= ++high;
            mday[a[i].ss]= day[i];
        }
    }

    cout<<high<<endl;
    cout<<mday[0];
    fr1(n-1){
        cout<<" "<<mday[i];
    }
    puts("");
}
