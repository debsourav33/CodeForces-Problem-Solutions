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

const int maxn= 1e5+5;

int caps, n;
vector<char> v;
string s, ans;

main(){
    fastIO();
    caps= 0;

    cin>>n;
    cin.ignore();
    getline(cin,ans);
    cin>>n;

    fr(n){
        cin>>s;

        if(s=="CapsLock")  caps= 1-caps;
        else if(s=="Backspace"){
            if(v.size())  v.pop_back();
        }
        else if(s=="Space"){
            v.pb(' ');
        }
        else{

            if(caps){
                if(s[0]>='a')  v.pb((char) (s[0]-32));
                else  v.pb(s[0]);
            }
            else{
                if(s[0]<'a')  v.pb((char) (s[0]+32));
                else  v.pb(s[0]);
            }
        }
    }

    int fl= 1;
    if(v.size()!=ans.size())  fl= 0;

    fr(v.size()) {
        if(ans[i]!=v[i])  fl= 0;
    }

    if(fl)  cout<<"Correct"<<endl;
    else  cout<<"Incorrect"<<endl;
}

/*
 2
Hello World
20
CapsLock
Backspace
h
CapsLock
e
l
l
o
Space
w
o
Backspace
Backspace
CapsLock
w
CapsLock
o
r
l
d
 */
