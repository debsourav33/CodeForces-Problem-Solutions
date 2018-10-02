#include<bits/stdc++.h>
using namespace std;

//{
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

ll n, rDiag[10005], lDiag[10005], coin[3005][3005], f=0;
ll odd_max= -1, even_max= -1, o1, o2, e1, e2;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    fr(n){
        for(ll j=0;j<n;j++){
            cin>> coin[i][j];

            rDiag[n+i-j]+= coin[i][j];
            lDiag[i+j]+= coin[i][j];
        }
    }

    fr(n){
        for(ll j=0;j<n;j++){
            ll poll= rDiag[n+i-j]+ lDiag[i+j]- coin[i][j];

            if((i+j)&1){
                if(poll>odd_max){
                   odd_max= poll;
                   o1= i;
                   o2= j;
                }
            }
            else{
                if(poll>even_max){
                   even_max= poll;
                   e1= i;
                   e2= j;
                }
            }

        }
    }



    cout<<(even_max+odd_max)<<endl;
    cout<<o1+1<<" "<<o2+1<<" "<<e1+1<<" "<<e2+1<<" "<<endl;
}

/*
4
1 1 1 1
2 1 1 0
1 1 1 0
1 0 0 1

4
2 5 6 2
1 4 5 7
3 4 6 1
2 4 6 2
*/
