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

int n, a, neg=0, pos=0;
pii p[200005];

bool cmp(pii p1, pii p2){
    return p1.ff<p2.ff;
}

main(){
    int limit, i, last=-1, now=1;
    cin>>n;

    fr1(n){
        cin>>a;
        p[i]= mp(a,i);
        if(a<0)
            ++neg;
        else if(a>0)
            ++pos;
    }

    sort(p+1,p+n+1,cmp);

    if(neg%2==1)  limit= neg-1;
    else limit= neg;

    for(i=2; i<=limit; i++){
        cout<<"1 "<<p[i-1].ss<<" "<<p[i].ss<<endl;
        last= p[i].ss; now= i+1;
    }



    for(int k=now; k<n; k++){
        if(p[k+1].ff>0) break;
        cout<<"1 "<<p[k].ss<<" "<<p[k+1].ss<<endl;
        ++now;
    }

    if(p[now].ff<=0 && now<=n){
        if(neg<=1 && pos==0){
        }
        else{
            cout<<"2 "<<p[now].ss<<endl;
            ++now;
        }
    }

    for(i=now; i<=n;i++){
        if(last!=-1)
            cout<<"1 "<<last<<" "<<p[i].ss<<endl;
        last= p[i].ss;
    }


}

/*
5
-3 -2 0 1 5
6
-5 -3 -2 -1 0 0
3
-5 0 0
3
-5 1 3
3
2 3 4
*/
