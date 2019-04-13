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

bool mark[10000007];
int in[10000007], cnt[10000007], a[1000006], n;
vector <int> primes;

void sieve(int n){
    int limit= sqrt(n)+2;
    mark[0]= mark[1]= 1;

    primes.pb(2);

    for(int i=4; i<n; i+=2)
        mark[i]= 1;

    for(int i=3; i<n; i+=2){
        if(mark[i])
            continue;

        primes.pb(i);

        if(i<limit){
            for(int j=i*i; j<n; j+=i*2){
                mark[j]=1;
            }
        }

    }

}

void getDiv(){
    for(int i=0;i<primes.size();i++){
        int p= primes[i];
        for(int j=p;j<=1e7;j+=p){

            cnt[p]+= in[j];
        }
    }

}

main(){
    sieve(10000007);
    clr(a);

    si(n);

    fr(n){
        si(a[i]);
        in[a[i]]+= 1;

    }

    getDiv();

    fr1(1e7){
        cnt[i]= cnt[i-1]+ cnt[i];
    }

    int q, x, y;
    si(q);

    while(q--){
        sii(x,y);
        if(x>= 1e7){
            puts("0");
            continue;
        }

        if(y>= 1e7)  y= 1e7;

        outi(cnt[y]- cnt[x-1]);
    }


}
