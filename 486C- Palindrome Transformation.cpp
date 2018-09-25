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

int n, c, moves= 0;
string str;

vector<int> c1;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>c;
    --c;
    cin>>str;

    for(int i=0;i<=(n-1)/2;i++)
        if(str[i]!=str[n-1-i]){
           if(abs(str[i]-str[n-1-i])<=13)
             moves+= abs(str[i]-str[n-1-i]);
            else
             moves+= 26- abs(str[i]-str[n-1-i]);

            c1.pb(i);
        }

    if(c1.size()==0){
        cout<<0<<endl;
        return 0;
    }

    for(int i=1;i<c1.size();i++){
        moves+= c1[i]- c1[i-1];
    }

    if(c>(n-1)/2)
        c= n-1-c;
    moves+= min(abs(c-c1[0]), abs(c-c1[c1.size()-1]));

    cout<<moves<<endl;
}
