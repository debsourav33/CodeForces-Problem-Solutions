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

int n, k, x, y;
int a[N];
vector<int> sums, v, t;
main(){
    int opt;
    si(opt);

    while(opt--){
        sii(n,k);

        fr(n)  si(a[i]);

        sums.clear();
        v.clear();
        t.clear();

        for(int i=0;i<n/2;i++)  sums.pb(a[i]+a[n-1-i]);
        sort(all(sums));

        for(int i=0;i<n/2;i++)  v.pb(max(a[i],a[n-1-i]));
        sort(all(v));

        for(int i=0;i<n/2;i++)  t.pb(min(a[i],a[n-1-i]));
        sort(all(t));

        int lo= 2, hi= 2*k;

        int ans= 0;
        int mini= n+1, id;

        for(int target=lo;target<=hi;target++){
            ans= n/2;
            ans-= upper_bound(all(sums),target)- lower_bound(all(sums),target);
            ans+= upper_bound(all(v),(target-k-1))-v.begin();
            ans+= t.size()- (upper_bound(all(t),(target-1)) -t.begin());

            if(mini>ans)  id= target;
            mini= min(mini, ans);

        }

        outi(mini);
    }


}
=======
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

int n, k, x, y;
int a[N];
vector<int> sums, v, t;
main(){
    int opt;
    si(opt);

    while(opt--){
        sii(n,k);

        fr(n)  si(a[i]);

        sums.clear();
        v.clear();
        t.clear();

        for(int i=0;i<n/2;i++)  sums.pb(a[i]+a[n-1-i]);
        sort(all(sums));

        for(int i=0;i<n/2;i++)  v.pb(max(a[i],a[n-1-i]));
        sort(all(v));

        for(int i=0;i<n/2;i++)  t.pb(min(a[i],a[n-1-i]));
        sort(all(t));

        int lo= 2, hi= 2*k;

        int ans= 0;
        int mini= n+1, id;

        for(int target=lo;target<=hi;target++){
            ans= n/2;
            ans-= upper_bound(all(sums),target)- lower_bound(all(sums),target);
            ans+= upper_bound(all(v),(target-k-1))-v.begin();
            ans+= t.size()- (upper_bound(all(t),(target-1)) -t.begin());

            if(mini>ans)  id= target;
            mini= min(mini, ans);

        }

        outi(mini);
    }


}

