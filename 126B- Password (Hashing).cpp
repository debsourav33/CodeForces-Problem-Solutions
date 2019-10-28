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

const int N= 1e6+5, m= 1e9+9, p= 31;

char s[N], t[N];
int n;
i64 pre_hash[N], pow_p[N], mod_inv_p[N];
vector<int> v;

i64 compute_hash(char s[]) {
    i64 hash_value = 0;
    i64 p_pow = 1;
    int n= strlen(s);
    fr(n) {
        char c= s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
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
    int n= strlen(s);

    i64 curr_pow = 1;
    pow_p[0]= 1;

    fr1(n-1){
        curr_pow= (curr_pow*p)%m;
        pow_p[i]=  curr_pow;
    }

    fr(n){
        mod_inv_p[i]= exp(pow_p[i],m-2,m);
    }
}

i64 sub_hash(char s[], int i, int j){
    i64 a= 0, b= pre_hash[j];
    if(i!=0)  a= pre_hash[i-1];

    //outl(a);
    //outl(b);

    i64 diff= (b-a+m) % m;
    i64 sub_hashvalue= diff * mod_inv_p[i];

    return sub_hashvalue % m;
}

int can(int k){
    i64 hash1= sub_hash(s,0,k-1);

    for(int i=1; i<n-k; i++) {
        i64 hash2= sub_hash(s, i, i + k - 1);
        if (hash1==hash2)  return 1;
    }

    return 0;
}

void getMatch(){
    fr(n){
        i64 hash1= sub_hash(s,0,i);
        i64 hash2= sub_hash(s,n-1-i,n-1);

        if(hash1==hash2)  v.pb(i+1);
    }
}

void solve(){
    int lo=0, hi=v.size()-1, ans= 0;
    while(lo<hi){
        int mid= (lo+hi+1)/2;

        if(can(v[mid]))   lo=mid, ans= v[mid];
        else  hi= mid-1;
    }

    if(lo==0){
        if(v.size() &&  can(v[0]))  ans= v[0];
    }

    if(ans==0){
        puts("Just a legend");
        return;
    }


    fr(ans)  printf("%c",s[i]);
    puts("");
}

main(){
    scanf("%s",s);
    n= strlen(s);

    i64 hash1= compute_hash(s);
    pre_calc();
    getMatch();

    solve();
}
