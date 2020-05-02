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

i64 n, k, x, y;
int a[N];
vector<i64> v;

main(){
    int opt;
    si(opt);

    while(opt--){
        sl(n);
        v.clear();

        v.pb(1);
        n--;

        i64 cur= 1;

        /*
         * if we have 4 bacterias, if we split 0 of them, mass will increase by 1 for each --> by total 4
         * if we split 1 of them into 2, the 2 will add up to the parent's mass at day
         * but at the night time, both of them will increase by 1 --> total increase 2
         * whereas if we didn't split the parent bacteria, it would have increased by 1 mass, splitting results in increase of 2
         * that means splitting 1 bacteria adds the increase by 1
         * we can split upto cur no. of bacterias (4 here)
         * so we can have increase between cur to 2*cur (4, 5, 6, 7, 8)
         */


        while(n){
            i64 dob= cur*2;

            if(n<=dob) cur= n; //n is in our range of cur to cur*2
            else if(n-dob >= dob)  cur= dob; //if n-cur*2 is smaller than cur*2 and then in next day we have cur doubled, it will exceed remaining n
            else cur= n/2; //n/2 is in range of cur to cur*2 (since n-cur*2 < cur*2), we will need just 1 more day after it

            n-= cur;
            v.pb(cur);
        }


        outi(v.size()-1);
        fr1(v.size()-1)  outls(v[i]-v[i-1]);
        puts("");
    }
}