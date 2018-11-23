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

i64 m;
struct node{
    int a,b;
    node(int _a, int _b){
        a=_a;
        b=_b;
    }
    node(){}
};

bool operator <(node n1, node n2){
        if((n1.b/n1.a) == (n2.b/n2.a))
            return (n1.b%n1.a) > (n2.b%n2.a);

        return (n1.b/n1.a) > (n2.b/n2.a);
}

priority_queue<node> q;

int a[10005], b[10005], n, k;

int main(){
    sii(n,k);

    fr(n)
        si(a[i]);
    fr(n)
        si(b[i]);

    fr(n){
        q.push(node(a[i],b[i]));
    }

    while(k){
        node nd= q.top();

        int d= nd.b/nd.a;
        int val= (d+1) * nd.a - nd.b;

        if(val>k)  break;

        k-= val, nd.b+= val;

        q.pop();
        q.push(node(nd.a,nd.b));
    }

    node nd= q.top();
    outi(nd.b/nd.a);
}
