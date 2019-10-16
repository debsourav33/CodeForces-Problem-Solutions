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

const int N= 1e3+5;
int m, n;

char s[N][N];

int hor_check(int i, int j){
    if(j+2>=n)  return 0;

    if(s[i][j]=='w' && s[i][j+1]=='b' && s[i][j+2]=='w')  return 1;

    return 0;
}

int ver_check(int i, int j){
    if(i+2>=m)  return 0;

    if(s[i][j]=='w' && s[i+1][j]=='b' && s[i+2][j]=='w')  return 1;

    return 0;
}

int getHorChoice(int i, int x, int c){
    char ch= c+'A';

    for(int j=x; j<x+3;j++){
        if(j>0 && s[i][j-1]==ch)  return 0;
        if(j<n-1 && s[i][j+1]==ch)  return 0;

        if(i>0 && s[i-1][j]==ch)  return 0;
        if(i<m-1 && s[i+1][j]==ch)  return 0;
    }

    return 1;
}

int getVerChoice(int x, int j, int c){
    char ch= c+'A';

    for(int i=x; i<x+3;i++){
        if(j>0 && s[i][j-1]==ch)  return 0;
        if(j<n-1 && s[i][j+1]==ch)  return 0;

        if(i>0 && s[i-1][j]==ch)  return 0;
        if(i<m-1 && s[i+1][j]==ch)  return 0;
    }

    return 1;
}


main(){
    sii(m,n);

    fr(m){
        scanf("%s",s[i]);
    }

    fr(m){
        frj(n){
            if(s[i][j]=='b'){
                puts("NO");
                return 0;
            }

            if(s[i][j]!='w') continue;

            int c= -1;

            if(hor_check(i,j)){
                for(int k=0;k<4;k++){
                    if(getHorChoice(i,j,k))  c=k;
                }

                if(c==-1){
                    puts("NO");  //outii(i,j);
                    return 0;
                }
                else{
                    char ch= (char)('A'+c);

                    s[i][j]= ch, s[i][j+1]= ch, s[i][j+2]= ch;
                }
            }
            else if(ver_check(i,j)){

                for(int k=0;k<4;k++){
                    if(getVerChoice(i,j,k))  c=k;
                }

                if(c==-1){
                    return 0;
                }
                else{
                    char ch= (char)('A'+c);

                    s[i][j]= ch, s[i+1][j]= ch, s[i+2][j]= ch;

                }
            }
            else{
                puts("NO");  //outii(i,j);
                return 0;
            }
        }
    }

    fr(m)
        frj(n)
            if(s[i][j]>='A' && s[i][j]<='D')  s[i][j]= (char) (s[i][j]+32);


    puts("YES");
    fr(m)
        printf("%s\n",s[i]);

}
