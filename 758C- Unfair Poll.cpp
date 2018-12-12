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

int main(){
    i64 a[105][105], ans, n, m, k, x, y;
    clr(a);

    sll(n,m);
    slll(k,x,y);

    i64 steps= n*m + max(0,(n-2)*m);

    ans= k/ steps;
    steps= k % steps;


    for(int j=0; j<m; j++){
        a[0][j]= ans;
        a[n-1][j]= ans;
    }

    fr1(n-2){
        for(int j=0; j<m; j++){
            a[i][j]= ans * 2;
        }
    }

    fr(n){
        for(int j=0; j<m; j++){
            if(steps--<=0)  break;

            a[i][j]++;
        }
    }

    for(int i= n-2; i>= 0; i--){
        for(int j=0; j<m; j++){
            if(steps--<=0)  break;

            a[i][j]++;
        }
    }



    i64 maxi= -1, mini= 1e18;
    fr(n){
        for(int j=0; j<m; j++){
            maxi= max(maxi,a[i][j]);
            mini= min(mini,a[i][j]);
        }
    }

    printf("%lld %lld %lld\n",maxi,mini,a[x-1][y-1]);

}
