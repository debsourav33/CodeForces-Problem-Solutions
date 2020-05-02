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

const int N= 2e5+5;

int n, k, x, y;
int a[N];
string s;
vector<string> v;

main(){
    int opt;
    cin>>opt;

    while(opt--){
        v.clear();

        sii(n,k);
        cin>>s;

        sort(all(s));

        int puts= 0, lim= k-1, i=0;

        fr(k)  v.pb("");

        int fl= 1;

        int cnt[27];
        clr(cnt);

        fr(n){
            cnt[s[i]-'a']++;
        }

        fr(k)  {v[i]+= s[i];  cnt[s[i]-'a']--;}

        if(k>1 && v[k-1][0]!=v[0][0]){
            cout<<v[k-1]<<endl; //if first letter of last string doesn't match, this will be the lexicographically max
            continue;
        }

        int mark[26], c=0;
        clr(mark);

        fr(26){
            if(cnt[i]) {
                if(!mark[i])  c++;

                mark[i]= 1;
            }
        }
        if(c>1)  fl= 0;

        if(!fl){
            /*
             * if fl==0, we have atleast 2 distinct characters remaining, for example b,b,b and c,c
             * so we can at best put c at as later as possible
             * i.e bbbcc
             */

            for(i=k;i<n;i++)  v[0]+= s[i];
            cout<<v[0]<<endl;
            continue;
        }

        /*otherwise we have only 1 distinct char remaining and we distribute it*/

        i= k;
        while(i<n){
            for(int j=0;j<=k-1;j++) {
                if(i==n)  break;

                v[j]+=(s[i]);
                i++;
                //cout<<j<<" "<<s[i]<<endl;
            }
        }


        sort(all(v));
        cout<<v[v.size()-1]<<endl;

    }
}