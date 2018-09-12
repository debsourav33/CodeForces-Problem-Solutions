#include<bits/stdc++.h>
using namespace std;

//{
#define ceil(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define pb push_back
#define INF 10000007
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//}

main(){
    int zero, o;
    cin>>zero>>o;

    if(o<zero-1 || o>(2*zero+2)){
        cout<<"-1"<<endl;
        return 0;
    }

    if(o==zero-1){
        cout<<"0";
        fr(o)
            cout<<"10";
        puts("");
        return 0;
    }

    while(o>0 && zero>0){
        if(o<2*zero){
            cout<<"10";
            o--; zero--;
        }
        else{
            cout<<"110";
            o-=2; zero--;
        }
    }

    fr(o)
        cout<<"1";

    puts("");
}
