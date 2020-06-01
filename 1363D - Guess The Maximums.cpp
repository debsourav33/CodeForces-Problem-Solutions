#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

#define outi(a) printf("%d\n",a)
#define outii(a,b) printf("%d %d\n",a,b)
#define outiii(a,b,c) printf("%d %d %d\n",a,b,c)
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 1e5+5, mod= 1e9+7;

int n, k, x, y, cnt, p[N], c=0, mark[1003];
vector<int> s[1003], v, t;
char str[105];

int query(){
    t.clear();
    for(int u: v){
        for(int nd: s[u])
            t.pb(nd);
    }

    printf("? %d",t.size());
    for(int nd: t)  outis(nd);
    puts("");
    fflush(stdout);

    int res;
    si(res);
    c++;

    return res;
}

main(){
    int opt;
    si(opt);

    while(opt--){
        c= 0;
        sii(n,k);
        clr(mark);
        fr(k){
            si(cnt);

            frj(cnt){
                si(x);
                s[i].pb(x);

                mark[x]= 1;
            }
        }

        fr1(n){
            if(!mark[i]){
                s[k].pb(i);
            }
        }

        int fl= 0;
        if(s[k].size()){
            k++;
            fl= 1;
        }

        int lo= 0, hi= k-1, res1;


        v.clear();
        fr(k)  v.pb(i);
        int maxi= query();

        if(k==1){

        }

        while(lo<hi){
            int mid= (lo+hi+1)/2;

            v.clear();
            fr(mid)  v.pb(i);
            res1= query();

            if(res1>=maxi)  hi= mid-1;
            else  lo= mid;
        }


        v.clear();
        fr(k){
            if(i==lo) continue;

            p[i]= maxi;
            v.pb(i);
        }

        int rem= query();
        p[lo]= rem;

        printf("!");
        fr(k-fl)  outis(p[i]);
        puts("");
        fflush(stdout);

        scanf("%s",str);

        fr(k)  s[i].clear();
        v.clear();
        t.clear();

    }
}
