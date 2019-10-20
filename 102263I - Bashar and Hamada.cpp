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
#define fr(n) for(i64 i=0;i<n;i++)
#define fr1(n) for(i64 i=1;i<=n;i++)
#define frj(n) for(i64 j=0;j<n;j++)
#define frj1(n) for(i64 j=1;j<=n;j++)
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

const int N= 3e5+5;

i64 a[N], n, l, r, pre[N], suff[N], F[N];

i64 left_gain(i64 i){
    return l*a[i]-pre[l-1] + suff[n-1-r+1]-r*a[i];
}

i64 right_gain(i64 i){
    return l*a[i]-pre[l-1] + suff[n-1-r+1]-r*a[i];
}

main(){
    si(n);

    fr(n)  si(a[i]);
    sort(a,a+n);

    pre[0]=a[0], suff[n-1]=a[n-1];
    fr1(n-1)  pre[i]= pre[i-1]+a[i];
    for(int i= n-2;i>=0;i--)  suff[i]= suff[i+1]+ a[i];

    l=0, r=0;
    l++, r++;

    i64 i=1, j=n-2, cnt=3;
    F[2]= a[n-1]-a[0];

    while(i<=j){
        if(left_gain(i)>right_gain(j)) {
            F[cnt] = F[cnt - 1] + left_gain(i);
            i++;
            l++;
        }
        else {
            F[cnt] = F[cnt - 1] + right_gain(i);
            j--;
            r++;
        }

        cnt++;
    }

    for(int i=2;i<=n;i++)  outls(F[i]);
}
