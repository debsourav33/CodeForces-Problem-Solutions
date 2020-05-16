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

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

const int N= 3e5+5;

i64 a, b, c, d, cover, nCover, nCon;

i64 cons_sum(i64 a, i64 b){
    return ((a+b)*(b-a+1))/2;

}

/* 13 15 20 21 */

main(){
    i64 ans= 0, st, n, rem;

    sll(a,b);
    sll(c,d);

    for(i64 i=b;i<=c;i++){
        st= max(a,c-i+1); //max(13,6)= 13
        if(st>b) continue;

        cover= min(d,st+i-1); //min(21,27)= 21

        nCover= cover-c+1; //21-20+1= 2

        nCon= min(b-st+1,d-cover+1);  //min(3,1)= 1

        i64 x= nCover, y= nCover+nCon-1;

        ans+= cons_sum(x,y); //(2,2)
        ans+= (b-st+1-nCon) * y; // 2 * 2
    }

    outl(ans);
}