#include<stdio.h>
#include<string.h>
#include<map>

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

const int N= 1e5+5, m[]= {1e9+9,1e9+7}, p= {31,51};

char s[N], t[N];
i64 pre_hash[N][2][2], pow_p[N][2], mod_inv_p[N][2];
int n1, n2;

i64 compute_hash(char s[], int k) {
    i64 hash_value = 0;
    i64 p_pow = 1;
    int n= strlen(s);
    fr(n) {
        char c= s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;

        pre_hash[i][k][cnt]= hash_value;
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
    pow_p[1]= 1;

    fr1(1e5+2){
        curr_pow= (curr_pow*p[0])%m;
        pow_p[i][0]=  curr_pow;
    }

    curr_pow = 1;

    fr1(1e5+2){
        curr_pow= (curr_pow*p[1])%m;
        pow_p[i][1]=  curr_pow;
    }

    fr(1e5+3){
        mod_inv_p[i][0]= exp(pow_p[i][0],m-2,m);
    }

    fr(1e5+3){
        mod_inv_p[i][1]= exp(pow_p[i][1],m-2,m);
    }
}

i64 sub_hash(char s[], int i, int j, int k){
    i64 a= 0, b= pre_hash[j][k];
    if(i!=0)  a= pre_hash[i-1][k];

    i64 diff= (b-a+m) % m;
    i64 sub_hashvalue= diff * mod_inv_p[i];

    return sub_hashvalue % m;
}

map<int,int> mark;

int can(int k){
    mark.clear();

    for(int i=0; i+k<n2; i++){
        int val= sub_hash(t,i,i+k,1);

        mark[val]= 1;
    }

    for(int i=0; i+k<n1; i++){
        int val= sub_hash(s,i,i+k,0);

        if(mark.count(val))  return true;
    }

    return false;
}

main(){
    scanf("%s",s);
    scanf("%s",t);
    n1= strlen(s);
    n2= strlen(t);

    i64 hash1= compute_hash(s,0,0);  i64 hash2= compute_hash(s,0,1);
    i64 hash3= compute_hash(t,1,0);  i64 hash4= compute_hash(t,1,1);
    pre_calc();

    int lo=-1, hi= 1e5+5;

    while(lo<hi){
        int mid= (lo+hi+1)/2;

        if(can(mid)) lo= mid;
        else  hi= mid-1;
    }

    outi(lo+1);
}
