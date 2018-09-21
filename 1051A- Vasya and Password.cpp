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

int n;

main(){
    cin>>n;

    while(n--){
    vector<int> cap;
    vector<int> low;
    vector<int> dig;




    int a[100005], l=0, c=0, d=0, clast, llast, dlast, cfast= -1, lfast= -1, dfast= -1;
    string str;
    cin>>str;

    fr(str.length()){
        if(str[i]>=65 && str[i]<=90){
            c++;
            cap.pb(i);
        }
        else if(str[i]>=97 && str[i]<=122){
            l++;
            low.pb(i);
        }
        else{
            d++;
            dig.pb(i);
        }
    }

    cap.pb(0);
    low.pb(0);
    dig.pb(0);

    int lc= low[0], cc= cap[0], dc= dig[0];

    if(c && l && d)
        cout<<str<<endl;
    else{
        if(c==0){
            if(l>=d){
                str[lc]= 'C';
                lc= low[1];
            }
            else{
                str[dc]= 'C';
                dc= dig[1];
            }
        }

        if(l==0){
            if(c>=d){
                str[cc]= 'c';
                cc= cap[1];
            }
            else{
                str[dc]= 'c';
                dc= dig[1];
            }
        }

        if(d==0){
            if(c>=l){
                str[cc]= '1';
                cc= cap[1];

            }
            else{
                str[lc]= '1';
                lc= low[1];
            }
        }

        cout<<str<<endl;

    }



    }
}
