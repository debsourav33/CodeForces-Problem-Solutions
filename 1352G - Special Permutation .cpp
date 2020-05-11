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

const int N= 2e5+5;

int n, k, c;
vector<int> p;


void do5(int offset){
    int a[]= {1,3,5,2,4};
    fr(5) p.pb(offset+a[i]);
}

void do6(int offset){
    do5(offset);
    p.pb(offset+6);
}

void do7(int offset){
    int a[]= {1,3,7,5,2,4,6};
    fr(7) p.pb(offset+a[i]);
}

void do8(int offset){
    do7(offset);
    p.pb(offset+8);
}

void do9(int offset){
    do5(offset);

    int a[]= {8,6,9,7};
    fr(4) p.pb(offset+a[i]);
}

void solve_corner_cases(){
    if(n<=3)  outi(-1);
    else{
        puts("2 4 1 3");
    }
}

int checker(){
    int mark[1003];
    clr(mark);

    fr(p.size()-1){
        if(abs(p[i]-p[i+1]) > 4 || abs(p[i]-p[i+1]) < 2)  {
            outii(p[i],p[i+1]);
            return 0;
        }

        mark[p[i]]++;
    }

    mark[p[p.size()-1]]++;

    fr1(n)  if(mark[i]!=1)  return 0;

    return 1;
}


main(){
    int opt;
    si(opt);

    while(opt--) {
        p.clear();
        si(n);

        if(n<5) {
            solve_corner_cases();
            continue;
        }

        int i=0;

        for(i=0;i<=n-10;i+=5){
            do5(i);
        }

        if(n-i==5)  do5(i);
        if(n-i==6)  do6(i);
        if(n-i==7)  do7(i);
        if(n-i==8)  do8(i);
        if(n-i==9)  do9(i);

        for(int u: p)  outis(u);  puts("");

    }
}
