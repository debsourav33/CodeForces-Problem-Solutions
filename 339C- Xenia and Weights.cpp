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

struct node{
    int d, l, c, t;

    node(){}

    node(int dd, int ll, int cc, int tt){
        d= dd;
        l= ll;
        c= cc;
        t= tt;
    }
};

vector<int> v, sa, sb;
int n, a;

int dp[11][11][1003][2];
node dir[11][11][1003][2];

int call(int diff, int last, int cnt, int turn){
    if(cnt==n)  return 1;
    if(dp[diff][last][cnt][turn]!=-1)  return dp[diff][last][cnt][turn];

    int opt= 0;

    fr(v.size()){
        if(v[i]>diff && v[i]!=last){
            dir[diff][last][cnt][turn]= node(v[i]-diff, v[i], cnt+1, 1-turn);
            opt= call(v[i]-diff, v[i], cnt+1, 1-turn);

            if(opt==1)  return dp[diff][last][cnt][turn]= 1;
        }
    }

    return dp[diff][last][cnt][turn]= 0;
}

void solution(int diff, int last, int cnt, int turn){
    node nd= dir[diff][last][cnt][turn];

    outis(nd.l);

    if(nd.c==n)  return;

    solution(nd.d, nd.l, nd.c, nd.t);

}

main() {
    sets(dp);
    fr1(10) {
        scanf("%1d", &a);
        if (a) v.pb(i);
    }

    si(n);

    if (!v.size()) {
        puts("NO");
        return 0;
    }

    if(call(0,0,0,0))
        puts("YES");
    else{
        puts("NO");
        return 0;
    }

    solution(0,0,0,0);
    puts("");
}
