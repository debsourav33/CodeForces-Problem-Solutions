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

int n, m, x, a[100005], s[100005], b[100005];
int taken[100005];

int can(int r){
    fr1(n)
        b[i]= a[i];

    stack<int> st;
    clr(taken);

    taken[0]= 1;

    for(int i=r;i>=1;i--){
        if(!taken[s[i]]){
            st.push(s[i]);
            taken[s[i]]= 1;
            continue;
        }

        if(!st.empty()){
            b[st.top()]--;

            if(b[st.top()]==0)  st.pop();
        }
    }

    fr1(n)
        if(b[i])  return 0;
    return 1;
}

int main(){
    sii(n,m);

    fr1(n)
        si(s[i]);

    fr1(m)
        si(a[i]);

    int lo= 1, hi= n+1;

    while(lo<hi){
        int mid= (lo+hi)/2;

        if(can(mid))  hi= mid;
        else  lo= mid+1;
    }

    if(lo==n+1)  puts("-1");
    else  outi(lo);
}
