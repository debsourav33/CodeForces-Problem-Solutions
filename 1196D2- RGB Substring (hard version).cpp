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
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define frj(n) for(int j=0;j<n;j++)
#define frj1(n) for(int j=1;j<=n;j++)
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

i64 n, a[maxn], k;
char s[maxn];

int check(char c, int q){
    if((q==0 && c=='R')||(q==1 && c=='G')||(q==2 && c=='B'))
        return 1;

    return 0;
}

int call(int q){

    int diff=0, now=q;

    fr(k){
        if(!check(s[i],now))  diff++;
        now= (now+1)%3;
    }

    int ans= diff;

    for(int i=k;i<n;i++){
        int j= i-k;

        if(!check(s[j],(q+j)%3))  diff--;
        if(!check(s[i],now))  diff++;

        now= (now+1)%3;
        ans= min(ans,diff);
    }

    return ans;
}

main(){
    int opt;
    si(opt);

    while(opt--) {
        sll(n, k);
        scanf("%s", s);

        int ans = 1e6;

        fr(3) {
            ans = min(ans, call(i));
        }

        outi(ans);
    }
}
