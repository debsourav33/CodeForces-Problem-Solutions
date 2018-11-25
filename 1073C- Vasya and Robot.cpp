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

int n;
char s[200005];
pii dest;

pii getPos(pii p, int i){
    if(s[i]=='R')
        p.ff++;
    if(s[i]=='L')
        p.ff--;
    if(s[i]=='U')
        p.ss++;
    if(s[i]=='D')
        p.ss--;

    return p;
}

pii getRev(pii p, int i){
    if(s[i]=='R')
        p.ff--;
    if(s[i]=='L')
        p.ff++;
    if(s[i]=='U')
        p.ss--;
    if(s[i]=='D')
        p.ss++;

    return p;
}

int can(int r){
    pii cur= mp(0,0);

    for(int i=r; i<n; i++)
        cur= getPos(cur,i);

    if(abs(cur.ff-dest.ff)+abs(cur.ss-dest.ss)<=r)
        return 1;

    for(int i=0; i+r<n;i++){
        cur= getPos(cur,i);
        cur= getRev(cur,i+r);

        if(abs(cur.ff-dest.ff)+abs(cur.ss-dest.ss)<=r){
            //cout<<"success for r: "<<r<<" i:"<<i<<endl;
            return 1;
        }
    }


    return 0;
}


main(){
    int x,y;

    si(n);
    scanf("%s",s);
    sii(x,y);

    dest= mp(x,y);


    if(!can(n) || (abs(dest.ff)+abs(dest.ss))%2!=(n%2)){
        puts("-1");
        return 0;
    }

    int lo= 0, hi= n;

    while(lo<hi){
        int mid= (lo+hi)/2;

        if(can(mid))  hi= mid;
        else  lo= mid+1;
    }

    cout<<lo<<endl;
}
