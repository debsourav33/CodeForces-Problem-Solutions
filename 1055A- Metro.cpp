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

int main(){
    int a[10004], b[10004], s, n;

    sii(n,s);
    s--;

    fr(n)
        si(a[i]);

    fr(n)
        si(b[i]);

    if(!a[0]) {
        puts("NO");
        return 0;
    }

    if(a[s]){
        puts("YES");
        return 0;
    }
    else if(!b[s]){
        puts("NO");
        return 0;
    }

    int flag= 0;
    for(int i=s;i<n;i++){
        if(a[i] && b[i]) flag=1;
    }

    if(flag)  puts("YES");
    else puts("NO");
}
