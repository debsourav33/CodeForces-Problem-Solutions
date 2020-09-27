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

const int N= 1e5+5;

int n, t, x, y, a[N], ans[N];
map<int,int> last;

void pre_process(){

}

void input(){
    sii(n,t);

    fr(n){
        si(a[i]);
    }

    fr(n) ans[i]= -1;
}

void solve(){
    fr(n){
        if(ans[i]!=-1)  continue;

        int x= a[i];
        int need= t-x;

        if(need<0)  continue;

        if(last.count(need)!=0){
            int lst= last[need];

            last[a[i]]= 1-lst;
            ans[i]= 1-lst;
        }
        else{
            last[a[i]]= 0;
            ans[i]= 0;
        }
    }

    fr(n)  outis(ans[i]);  puts("");
}

void post_process(){

}

int main(){
    int q;
    si(q);

    while(q--) {
        pre_process();
        input();
        solve();
        post_process();
    }


}
