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

i64 n, left_a[1000006], right_a[1000006], le_a[1000006], rig_a[1000006], x;
i64 lefts=0, rights=0;

main(){
    sl(n);
    char q;

    fr1(n){
        scanf("\n%c %lld",&q,&x);
        //cin>>q>>x;
        if(q=='L'){
            rig_a[x]= lefts;
            lefts++;
            left_a[x]= lefts;
        }
        else if(q=='R'){
            le_a[x]= rights;
            rights++;
            right_a[x]= rights;

        }
        else{
            i64 ans= min(rig_a[x]+rights- right_a[x], le_a[x]+ lefts-left_a[x]);
            printf("%lld\n",ans);
        }

        /***
        if a book is placed on L (left),
        all the Rs before and after it are on its right and right_a[x]=0

        rights- right_a[x]= books on its right

        Add to that the previously inserted Ls
        we keep track of previously inserted ls by rig_a[x]

        so,
        rig_a[x]+rights- right_a[x]= total book elimination needed from right

        Similar explanation for books placed on R (right)
        ***/

    }
}

/*
100
L 1
L 2
L 3
L 4
L 5
? 2
*/
