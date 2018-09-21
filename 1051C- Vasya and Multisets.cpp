/*I made the following observations:

1. If  no. of classy numbers in S is even, then answer is YES. We can easily split them evenly in A and B.

2. Else if no. of classy numbers in S is odd, and there is a number in S with frequency of 3 or more
   (lets call it x) , answer is YES. Lets see why:

   Let no. of classy numbers in S= n (n is odd). We can keep  n/2 of them in A and n/2+1 of them in B.
   A has 1 short right? Take 1 x in A, all other x's and non classy numbers in B. Hence, A now has n/2+1
   classy numbers, so does B! (because all other non classy numbers (they appear in B more than once)
   don't increase the count for B)

3. Else, there's NO solution possible.*/


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

int n, a[100005], cnt[105], c=0;

main(){
    clr(cnt);
    cin>>n;

    bool f=false, f2=false;

    fr(n){
        cin>>a[i];
        cnt[a[i]]++;
        if(cnt[a[i]]>2)  f= true;
    }


    fr(103){
        if(cnt[a[i]]==1)
            c++;
    }


    if(c%2==0){
        f= true;
        f2= true;
    }

    if(!f){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    int k=0;

    fr(n){
        if(cnt[a[i]]==1){
            ++k;
            if(k<=c/2)
                cout<<"A";
            else
                cout<<"B";
        }

        else if(cnt[a[i]]>2 && !f2){
            cout<<"A";  f2= true;
        }
        else
            cout<<"B";
    }

    puts("");
}
