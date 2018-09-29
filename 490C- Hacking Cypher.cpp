/*
     (a* 10+ r) % b
   = (a* 10%b + r%b) % b
*/

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

ll n, mark[1000006], rem[1000006], a, b;
string str;

void solution(ll mid){
    cout<<"YES"<<endl;
    fr(mid)
        cout<<str[i];
    cout<<endl;

    for(int i=mid;i<n;i++)
        cout<<str[i];
    cout<<endl;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clr(mark);
    ll s= 0;

    cin>>str;
    cin>>a>>b;

    n= str.length();

    fr(str.length()-1){
        ll num= str[i]- '0';
        s= (s*10+ num) % a;

        if(s==0 && str[i+1]!='0')
            mark[i]= 1;

    }

    ll p=1, mid= -1;
    rem[n-1]= (str[n-1]- '0') % b;

    if(rem[n-1]==0 && mark[n-2])  mid= n-1;

    for(int i=n-2;i>0;i--){
        ll num= str[i]- '0';

        p=(p*10)%b;
        rem[i]= (num*p+ rem[i+1])%b;

        if(rem[i]==0 && mark[i-1]){
            mid= i;
        }

    }

    if(mid==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    solution(mid);
}

/*
116401024
97 1024

284254589153928171911281811000
1009 1000

120
12 1

123288
1 16
*/
