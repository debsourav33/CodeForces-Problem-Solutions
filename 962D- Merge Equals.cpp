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

struct node{
    i64 val, i;

    node(i64 v, i64 _i){
        val= v;
        i= _i;
    }
};

i64 n, a[1000006];
priority_queue <node> q;

bool operator <(node a, node b){
    if(a.val==b.val)
        return a.i > b.i;

    return a.val>b.val;
}

main(){
    sl(n);

    fr(n){
        sl(a[i]);
        q.push(node(a[i],i));
    }

    i64 last= q.top().val;
    i64 last_i= q.top().i;
    q.pop();

    i64 cnt= n;

    while(!q.empty()){
        i64 now= q.top().val;
        i64 now_i= q.top().i;
        q.pop();

        if(last==now){
            a[last_i]= -1;
            a[now_i]= 2*now;

            q.push(node(a[now_i],now_i));
            last= -1;
            cnt--;
        }
        else{
            last= now;
            last_i= now_i;
        }
    }

    cout<<cnt<<endl;

    i64 flag= 0;

    fr(n){
        if(a[i]!=-1){
            if(flag)
                printf(" %lld",a[i]);
            else{
                printf("%lld",a[i]);
                flag= 1;
            }
        }
    }

    puts("");
}
