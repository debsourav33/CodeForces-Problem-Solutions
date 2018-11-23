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

const int maxn= 2e5+5;
int a[maxn];

i64 n,m;
set<int,greater<int> > s;

int main(){
    int rem;
    sii(n,m);
    int nxt=-1;

    fr(n) {
        si(a[i]);
        nxt= max(nxt, a[i]);
    }

    sort(a,a+n,greater<int>());

    i64 cnt= 0, i=0, fl=0;
    rem= n;

    a[n]= 0;
    for( ;i<n;i++){
        if(nxt<=1) {
            fl = 1;
            break;
        }

        if(nxt<=a[i+1])
            cnt+= a[i]-1, nxt--;
        else if(nxt>a[i+1]){
            cnt+= a[i]-nxt + a[i+1];
            nxt= a[i+1];
        }
    }

    if(fl) {
        for(;i<n;i++)
            cnt += a[i]-1;
    }

    outl(cnt);

}
