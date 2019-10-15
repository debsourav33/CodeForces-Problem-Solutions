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

const int N= 2e5+5;

i64 n,a,b,sz, likes[N], no_of_likes, no_of_hates;
vector<i64> v[N];
map<i64,i64> cnt[3];
map<i64,i64> mark;

main(){
    sl(n);

    fr(n){
        sll(a,sz);

        likes[i]= a;

        if(a==1)  no_of_likes++;
        else  no_of_hates++;

        frj(sz){
            sl(b);

            if(cnt[a].count(b)==0)  cnt[a][b]= 0;
            cnt[a][b]++;

            v[i].pb(b);
        }
    }

    if(no_of_likes==0){
        i64 dis= 0;

        fr(n)
        {
            for(i64 num: v[i]){
                if(mark.count(num)) continue;
                dis++;
                mark[num]= 1;
            }
        }

        i64 ans= 1000000000000000000 - dis;
        outl(ans);

        return 0;
    }

    i64 ans= 0;

    fr(n)
    {
        if(likes[i]==1)
        {
            for(i64 num: v[i]){
                if(mark.count(num)) continue;

               if(cnt[1][num]>=no_of_likes && cnt[2].count(num)==0) ans++;

               mark[num]= 1;
            }

        }

    }


    outl(ans);
}
