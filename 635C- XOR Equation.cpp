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

i64 s, x;
i64 dp[62][2][2][2];

bool checkbit(i64 num, i64 pos){
    return num & (1LL<<pos);
}

i64 call(i64 pos, i64 cf, i64 flg1, i64 flg2){
    if(pos==60) return cf==0;

    i64 &ret= dp[pos][cf][flg1][flg2];
    if(ret!=-1)  return ret;

    i64 bitS= checkbit(s,pos);
    i64 bitX= checkbit(x,pos);

    i64 opt1=0, opt2= 0;

    if(!bitX){
        if(bitS==cf){
            opt1= call(pos+1,0,0,0);
            opt2= call(pos+1,1,0,0);
        }
    }
    else{
        if(bitS!=cf){
            if(flg1==flg2) opt1= call(pos+1,cf,0,1);
            else if(flg1) opt1= call(pos+1,cf,0,0);

            if(flg1==flg2) opt2= call(pos+1,cf,1,0);
            else if(flg2)  opt2= call(pos+1,cf,0,0);
        }
    }

    return ret= opt1+opt2;
}


main(){
    sets(dp);
    sll(s, x);


    outl(call(0, 0, 0, 0));
}
