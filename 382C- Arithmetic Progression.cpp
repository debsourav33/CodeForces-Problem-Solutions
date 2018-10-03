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

ll n, a[100005], f=0;
set<ll> s;

void update(ll f, ll diff){
    if(f==0){
        cout<<"-1"<<endl;
    }
    if(f==1){
        s.insert(a[0]-diff);
        s.insert(a[n-1]+diff);

        if(n==2 && (diff&1)==0){
            s.insert(a[0]+diff/2);
            cout<<"3"<<endl;
        }

        else
            cout<<"2"<<endl;
    }

    if(f==2){
        cout<<"1"<<endl;
    }
}

void solution(){
    cout<<*s.begin();
    s.erase(s.begin());
    while(!s.empty()){
        cout<<" "<<*s.begin();
        s.erase(s.begin());
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    cin>>a[0];
    for(ll i=1;i<n;i++){
        cin>>a[i];
        if(a[i-1]!=a[i])
            f=1;
    }

    if(n==1){
        cout<<"-1"<<endl;
        return 0;
    }

    if(!f){
        cout<<"1"<<endl;
        cout<<a[0]<<endl;
        return 0;
    }

    sort(a,a+n);
    ll diff= a[1] - a[0];

    for(ll i=2;i<n;i++){
        ll t= a[i]- a[i-1];

        if(t==diff*2){
            ++f;
            s.insert(a[i]-diff);
        }

        else if(diff==t*2){

            if(i>2){
                cout<<"0"<<endl;
                return 0;
            }

            ++f;
            diff= t;
            s.insert(a[i-1]-t);
        }

        else if(t!=diff){
            cout<<"0"<<endl;
            return 0;
        }

        if(f>2){
            cout<<"0"<<endl;
            return 0;
        }
    }


    update(f,diff);
    solution();

}
