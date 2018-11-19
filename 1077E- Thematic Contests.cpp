#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outis(a) printf(" %d",a)

#define outl(a) printf("%lld\n",a)
#define outll(a,b) printf("%lld %lld\n",a,b)
#define outls(a) printf(" %lld",a)

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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int a[100005], n;
map<int,int> cnts;
vector<int> b;


int call(int val, int pos){
    if(pos>=n)  return 0;
    int opt;

    int p= upper_bound(b.begin()+pos+1,b.end(),2*val-1)- b.begin();
    opt= val+ call(2*val,pos);

    return opt;
}

int main(){
    si(n);

    fr(n){
        si(a[i]);
        cnts[a[i]]++;
    }

    for(auto g: cnts)
        b.pb(g.ss);

    sort(all(b));

    fr(b.size())
        cout<<b[i]<<" ";

    int ans= -1;
    fr1(n){
        ans= max(ans,call(i,0));
    }

    outis(ans);
}
