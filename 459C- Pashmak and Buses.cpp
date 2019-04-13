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

int a[1003][1003], c[1003][1003], n, d, k;

void generate(){
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));

    fr1(n-1){
        a[i][d-1]= (a[i-1][d-1]+1) % k;
        c[i][d-1]= (a[i-1][d-1]+1) / k;
    }

    fr1(n-1){
        for(int j=d-2; j>=0; j--){
            a[i][j]= (a[i-1][j]+ c[i][j+1]) % k;
            c[i][j]= (a[i-1][j]+ c[i][j+1]) / k;
        }
    }
}

void print(){
    frj(d){
        fr(n)
            outis(a[i][j]+1);
        puts("");
    }
}

main() {
    siii(n,k,d);

    i64 pows= 1;

    fr1(d){
        pows*= k;

        if(pows>1e6)  break;
    }

    if(n>pows){
        puts("-1");
        return 0;
    }

    generate();
    print();
}
