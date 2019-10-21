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

const int N= 1e6+6;

i64 x, y, k, dp[N][4];
int n;

map<i64,i64> index, mark;
vector<i64> v, per[N];

i64 call(int pos, int taken){
    if(pos==v.size())  return 0;
    if(dp[pos][taken]!=-1)  return dp[pos][taken];

    i64 ind= index[v[pos]], prev= index[v[pos-1]];

    i64 maxi= 0;

    fr(per[ind].size()){
        frj(per[prev].size()){
            if(j==taken && per[prev].size()>1)  continue;

            i64 opt= abs(per[ind][i]-per[prev][j])+ call(pos+1,i);
            maxi= max(opt,maxi);
        }

    }

    return dp[pos][taken]= maxi;
}

main(){
    sets(dp);
    si(n);

    fr(n){
        sll(x,y);

        if(mark.count(x)==0){
            mark[x]= 1;
            v.pb(x);
            index[x]= v.size()-1;
        }

        i64 ind= index[x];
        per[ind].pb(y);
    }

    sort(all(v));

    fr(v.size()){
        i64 ind= index[v[i]];

        sort(all(per[ind]));
        if(per[ind].size()<=4) continue;

        i64 sz= per[ind].size();
        vector<i64> tmp;
        tmp.pb(per[ind][0]);
        tmp.pb(per[ind][1]);
        tmp.pb(per[ind][sz-2]);
        tmp.pb(per[ind][sz-1]);

        per[ind].clear();


        frj(tmp.size())  per[ind].pb(tmp[j]);
    }

    i64 ans= 0, ind= index[v[0]];

    fr(per[ind].size()){
        ans= max(ans, call(1,i));
    }

    outl(ans);
}