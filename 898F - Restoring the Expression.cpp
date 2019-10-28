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

const int N= 1e6+5, m= 1e9+9, p= 10;

char s[N], t[N];
i64 pre_hash[N], pow_p[N], mod_inv_p[N];
int n;

i64 compute_hash(char s[]) {
    i64 hash_value = 0;
    i64 p_pow = 1;
    for(int i=n-1;i>=0;i--) {
        char c= s[i];
        hash_value = (hash_value + (c - '0') * p_pow) % m;
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

    fr1(n){
        curr_pow= (curr_pow*p)%m;
        pow_p[i]=  curr_pow;
    }

    fr(n+1){
        mod_inv_p[i]= exp(pow_p[i],m-2,m);
    }
}

i64 sub_hash(char s[], int i, int j){
    i64 a= pre_hash[i], b= 0;
    if(j<n-1)  b= pre_hash[j+1];

    i64 diff= (a-b+m) % m;
    i64 sub_hashvalue= diff * mod_inv_p[n-j-1];

    return sub_hashvalue % m;
}

int Try(int part1, int part2, int part3){
    if(part1<=0 ||part2<=0 || part3<=0)  return 0;
    if(part3-max(part1,part2)<0 || part3-max(part1,part2)>1)  return 0;
    if((s[part1]=='0' && part2>1) || (s[part1+part2]=='0' && part3>1))  return 0;

    i64 hash1= sub_hash(s,0,part1-1);
    i64 hash2= sub_hash(s,part1,part1+part2-1);
    i64 hash3= sub_hash(s,part1+part2,n-1);

    if((hash1+hash2)%m== hash3){
        return 1;
    }

    return 0;
}

bool flag= 0;

void print(int part1, int part2, int part3){
    frj(part1)  printf("%c",s[j]);
    printf("+");
    for(int j=part1;j<part1+part2;j++)  printf("%c",s[j]);
    printf("=");
    for(int j=part1+part2;j<n;j++)  printf("%c",s[j]);
    puts("");

}

void solve(){
    fr1(n){
        int part1= i, part2, part3;
        part2= (n-i)/2;
        part3= cel(n-i,2);

        //outii(part2,part3);

        if(Try(part1,part2,part3)){
            print(part1,part2,part3);
            return;
        }

        part3= i, part2= n-i-i;
        //outii(part2,part3);

        if(Try(part1,part2,part3)){
            print(part1,part2,part3);
            return;
        }

        part3= i+1, part2= n-i-i-1;
        //outii(part2,part3);

        if(Try(part1,part2,part3)){
            print(part1,part2,part3);
            return;
        }
    }
}

main(){
    scanf("%s",s);
    n= strlen(s);

    i64 hash1= compute_hash(s);
    pre_calc();



    solve();
}
