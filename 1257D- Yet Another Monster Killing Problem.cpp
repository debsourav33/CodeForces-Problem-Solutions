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

#define lefts 2*at
#define rights 2*at+1

int n, m, a[N], maxi[4*N], maxi_from[N], p[N], s[N];
vector<int> endur[N];

void merge(int at){
    maxi[at]= max(maxi[lefts], maxi[rights]);
}

void build(int at, int L, int R){
    if(L==R){
        maxi[at]= a[L];
        return;
    }

    int mid= (L+R)/2;

    build(lefts,L,mid);
    build(rights,mid+1,R);

    merge(at);
}

int query(int at, int L, int R, int l, int r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return maxi[at];

    int mid= (L+R)/2;

    int x= query(lefts, L, mid, l, r);
    int y= query(rights, mid+1, R, l, r);

    return max(x,y);
}

int can(int curr, int k) {
    int mon_maxi = query(1, 0, n - 1, curr, curr + k - 1);
    int maxi = maxi_from[k];

    if(maxi >= mon_maxi)
        return 1;
    else
        return 0;
}

void solve(){
    int curr= 0, cnt= 0;

    while(curr<n){
        int lo=1, hi= n-curr;

        while(lo<hi){
            int mid= (lo+hi+1)/2;

            if(can(curr,mid))  lo= mid;
            else  hi= mid-1;
        }

        //outi(lo);
        curr+=lo;
        cnt++;
    }

    outi(cnt);
}

main(){
    int q;
    si(q);

    while(q--) {
        si(n);

        fr(n)  si(a[i]);

        build(1,0,n-1);

        si(m);

        fr(m){
            sii(p[i],s[i]);

            endur[s[i]].pb(p[i]);
        }

        fr1(n)  sort(all(endur[i]));

        int maxi= -1;
        for(int i=n;i>=1;i--){
            if(endur[i].size()){
                int curr_max= endur[i][endur[i].size()-1];

                if(curr_max>maxi) {
                    maxi= curr_max;
                }
            }

            maxi_from[i]= maxi;
        }

        //fr1(n)  outii(i,maxi_from[i]);

        int mon_maxi= query(1,0,n-1,0,n-1);

        if(maxi<mon_maxi){
            puts("-1");
            fr1(n)  maxi_from[i]= -1;
            fr1(n) endur[i].clear();
            continue;
        }

        solve();

        fr1(n)  maxi_from[i]= -1;
        fr1(n) endur[i].clear();
    }
}
