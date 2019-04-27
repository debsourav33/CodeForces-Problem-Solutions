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

const int maxn= 2e5+5;
int a[maxn], l, r, lgain[maxn], rgain[maxn], n, prevs= -1;
string ans;

void precalc(){
    rgain[0]= 1;

    fr1(n-1){
        if(a[i-1]>a[i])
            rgain[i]= rgain[i-1]+1;
        else
            rgain[i]= 1;
    }

    lgain[n-1]= 1;

    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1])
            lgain[i]= lgain[i+1]+1;
        else
            lgain[i]= 1;
    }

    /*fr(n)  outis(lgain[i]);
    puts("");
    fr(n)  outis(rgain[i]);*/

}

void insL(){
    ans += "L";
    prevs= a[l++];
}

void insR(){
    ans += "R";
    prevs= a[r--];
}

void solve(){
    precalc();

    while(l<=r) {
        int maxi= max(a[l],a[r]);
        if(maxi<=prevs)  break;

        if (a[l] == a[r]) {
            if (lgain[l] > rgain[r]) {
                insL();
            } else {
                insR();
            }
        }
        else if (a[l] < a[r] && a[l]>prevs)
            insL();
        else if (a[r] < a[l] && a[r]>prevs)
            insR();
        else if(a[l]>prevs)
            insL();
        else
            insR();
    }

    outi(ans.size());
    fr(ans.size())  printf("%c",ans[i]);
    puts("");

}

main(){
    si(n);
    l= 0, r=n-1;

    fr(n)  si(a[i]);

    solve();
}

