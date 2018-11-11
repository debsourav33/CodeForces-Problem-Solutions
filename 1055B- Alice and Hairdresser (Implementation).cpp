#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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

i64 a[100005], n, q, k;

int main(){
    i64 q;
    slll(n,q,k);

    i64 cnt= 0;

    fr1(n){
        sl(a[i]);

        if(a[i]>k && a[i-1]<=k){
            cnt++;
        }
    }

    //update(1,1,n,4,11);

    int x, p, r;
    fr(q) {
        si(x);

        if(!x){
            printf("%lld\n",cnt);
        }
        else{
            sii(p,r);

            int fl= a[p] > k;
            a[p]+=r;

            if(fl || a[p]<=k)
                continue;

            if(a[p-1]>k && a[p+1]>k)
                cnt--;
            else if(a[p-1]>k || a[p+1]>k)
                cnt= cnt;
            else
                cnt++;
        }
    }
}
