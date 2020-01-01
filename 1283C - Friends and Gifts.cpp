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

const int N= 2e5+5;
int a[N], mark[N], n, k;

vector<int> in, outs;

main(){
    si(n);

    fr1(n){
        si(a[i]);
        if(a[i]==0)  outs.pb(i);
        mark[a[i]]= 1;
    }

    fr1(n)  if(!mark[i])  in.pb(i);

    fr(outs.size()){
        int curr= outs[i];


        int matches= in[in.size()-1];
        in.pop_back();

        if(curr!=matches)  a[curr]= matches;
        else if(!in.size()){
            if(matches!=outs[i-1]){
                a[curr]=  a[outs[i-1]];
                a[outs[i-1]]= matches;
            }
            else{
                a[curr]=  a[outs[i-2]];
                a[outs[i-2]]= matches;
            }
        }
        else{
            int matches2= in[in.size()-1];
            in.pop_back();
            a[curr]= matches2;

            in.pb(matches);
        }
    }

    fr1(n)  outis(a[i]);

}
