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

i64 x, y, k;
vector<i64> a, b;
i64 dp[30][2][2][2][10];

struct node{
    i64 pos, f1, f2, f, nxt;

    node(){}

    node(i64 p, i64 _f1, i64 _f2, i64 _f, i64 _nxt){
        pos= p;
        f1= _f1;
        f2= _f2;
        f= _f;
        nxt= _nxt;
    }
}dir[30][2][2][2][12];

i64 call(i64 pos, i64 f1, i64 f2, i64 f, i64 nxt){
    if(pos==b.size())  return f;
    i64 &ret= dp[pos][f1][f2][f][nxt];
    if(ret!=-1)  return ret;


    i64 st= a[pos], lim=b[pos];

    if(f1)  st= 0;
    if(f2)  lim= 9;

    //cout<<"for pos: "<<pos<<" st= "<<st<<" lim= "<<lim<<endl;

    i64 opt1=-5, opt2=-5, maxi= -5;

    for(i64 i=st;i<=lim;i++){
        if(!f && !i)  opt1= call(pos+1,f1||(i>a[pos]),1,0,0);
        opt2= i * call(pos+1,f1||(i>a[pos]),f2||(i<b[pos]),1,i);

        if(opt1>maxi)
            dir[pos][f1][f2][f][nxt]= node(pos+1,f1||i>a[pos],1,0,0);
        else if(opt2>maxi)
            dir[pos][f1][f2][f][nxt]= node(pos+1,f1||i>a[pos],f2||i<b[pos],1,i);

        maxi= max(maxi,max(opt1,opt2));
    }

    return ret= maxi;
}

i64 solve(i64 x, i64 y){
    sets(dp);
    a.clear();
    b.clear();

    while(x){
        a.pb(x%10);
        x/=10;
    }

    while(y){
        b.pb(y%10);
        y/=10;
    }

    while(a.size()<b.size())
        a.pb(0);

    reverse(all(a));
    reverse(all(b));

    i64 ans= call(0,0,0,0,0);
    return ans;
}

void solution(i64 pos, i64 f1, i64 f2, i64 f, i64 nxt){
    if(pos==b.size()){
       puts("");
       return;
    }

    node nd= dir[pos][f1][f2][f][nxt];

    if(nd.f)
        printf("%d",nd.nxt);

    solution(pos+1,nd.f1,nd.f2,nd.f,nd.nxt);
}

main(){
    sll(x, y);

    i64 maxi= solve(x, y);
    solution(0,0,0,0,0);
}
