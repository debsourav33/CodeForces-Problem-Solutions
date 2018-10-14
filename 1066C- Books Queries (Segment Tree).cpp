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

i64 n, a[400010], sum[1600020], lefts= 2e5+1, rights= 2e5+1;

void build(i64 at, i64 L, i64 R){
    if(L==R){
        sum[at]= 0;
        return;
    }

    i64 mid= (L+R)/2;

    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at]= sum[at*2]+ sum[at*2+1];
}

void update(i64 at, i64 L, i64 R, i64 pos){
    if(L==R){
        sum[at]= 1;
        return;
    }

    i64 mid= (L+R)/2;
    if(pos<=mid)
        update(at*2, L, mid, pos);
    else
        update(at*2+1, mid+1, R, pos);

    sum[at]= sum[at*2]+ sum[at*2+1];
}

i64 query(i64 at, i64 L, i64 R, i64 l, i64 r){

    if(r<L || l>R)  return 0;
    if(l<=L && r>=R)  return sum[at];

    i64 mid= (L+R)/2;

    i64 x= query(at*2, L, mid, l, r);
    i64 y= query(at*2+1, mid+1, R, l, r);

    return x+y;
}

main(){
    fastIO();
    i64 range= 4e5+10;
    char q;
    int x;

    //sl(n);
    cin>>n;
    build(1,0,range);

    fr1(n){
        //scanf("\n%c %lld",&q,&x);
        cin>>q>>x;
        if(q=='L'){
            lefts--;
            update(1,0,range,lefts);

            a[x]= lefts;
        }
        else if(q=='R'){
            rights++;
            update(1,0,range,rights);

            a[x]= rights;
        }
        else{
            i64 ans= min(query(1,0,range,0,a[x]-1), query(1,0,range,a[x]+1,range));
            //printf("%lld\n",ans);
            cout<<ans<<endl;
        }
    }
}

/*
100
L 5
L 4
L 3
R 6
R 7
? 5
*/
