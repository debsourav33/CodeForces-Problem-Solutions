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

const int N= 1e5+5, m= 1e9+9, p= 1e9+7;

int a[N], match[N];
i64 pre_hash[N], pow_p[N], mod_inv_p[N];
int n;
map <int, vector<int> > occ;

i64 compute_hash() {
    i64 hash_value = 0;
    i64 p_pow = 1;
    fr(n) {
        hash_value = (hash_value + (a[i]+1) * p_pow) % m;
        p_pow = (p_pow * p) % m;

        pre_hash[i]= hash_value;
    }
    return hash_value;
}

i64 exp(i64 b, i64 e, i64 M){
    i64 ans=1;

    while(e){
        if(e&1)  ans= (ans*b) % M;
        b= (b*b) % M;
        e/= 2;
    }

    return ans;
}

void pre_calc(){
    i64 curr_pow = 1;
    pow_p[0]= 1;

    fr1(n){
        curr_pow= (curr_pow*p)%m;
        pow_p[i]=  curr_pow;
    }

    fr(n+1){
        mod_inv_p[i]= exp(pow_p[i],m-2,m);
    }
}

i64 sub_hash(int i, int j){
    i64 x= 0, y= pre_hash[j];
    if(i!=0)  x= pre_hash[i-1];

    i64 diff= (y-x+m) % m;
    i64 sub_hashvalue= diff * mod_inv_p[i];

    return sub_hashvalue % m;
}


int mini= (int) 1e7, min_so_far[N];

void solve(){
    fr(n){
        occ[a[i]].pb(i);
    }

    fr(n){
        match[i]= INT_MAX;

        for(int j: occ[a[i]])
        {
            if(j<=i)  continue;

            int len= j-i;

            if(sub_hash(i,i+len-1)==sub_hash(j,j+len-1)){
                match[i]= len;
                break;
            }
        }
    }

    min_so_far[n]= -1;

    for(int i=n-1;i>=0;i--){
        if(match[i]<=mini){
            mini= match[i];
            min_so_far[i]= i;
        }
        else{
            min_so_far[i]= min_so_far[i+1];
        }
    }

    int st= min_so_far[0], cut= 0;

    while(st!=-1){
        int jmp= match[st];
        cut= jmp+st;

        st= min_so_far[cut];
    }

    outi(n-cut);
    for(int i=cut;i<n;i++)  outis(a[i]);
    puts("");
}

//18 1 9 6 3 5 3 5 3 5 9 7 4 9 7 4 8 0 6

main(){
    si(n);
    fr(n)  si(a[i]);

    i64 hash1= compute_hash();
    pre_calc();


    solve();
}
