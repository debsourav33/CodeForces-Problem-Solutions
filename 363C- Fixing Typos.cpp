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

int f[200005];
main(){
    string str;
    cin>>str;

    f[0]= 1;
    for(int i=1;i<str.length();i++){
        if(str[i]==str[i-1])
            f[i]= f[i-1]+1;
        else
            f[i]= 1;
    }

    int last=0, plast=0;
    cout<<str[0];

    for(int i=1; i<str.length(); i++){
        if(f[i]==1){
            cout<<str[i];
            plast= last;
            last= i;
        }

        if(f[i]==2 && f[plast]==1){
            cout<<str[i];
            plast= last;
            last= i;
        }
    }

    puts("");
}
