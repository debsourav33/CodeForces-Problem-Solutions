#include<bits/stdc++.h>
using namespace std;

//{
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b);
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b);
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

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
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long i64;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

i64 n;
stack <int> st;
char s[100005];
int m= 0;

int mind[100005];

main(){
    scanf("%s",s);
    n= strlen(s);

    char mini= s[n-1];
    mind[n-1]= n-1;

    for(int i=n-2;i>=0;i--){
        mind[i]= mind[i+1];
        if(s[i]<=mini){
            mini= s[i];
            mind[i]= i;
        }
    }

    while(m<n){
        if(st.empty()){
            st.push(m++);
            continue;
        }

        while(m<n && st.top()< mind[st.top()])
            st.push(m++);

        if(st.top()==mind[ st.top() ]){
            printf("%c",s[st.top()]);
            st.pop();

            if(st.empty())  continue;

            if(s[mind[m]] < s[st.top()])
                mind[st.top()]= mind[m];
            else
                mind[st.top()]= st.top();
        }
    }

    while(!st.empty()){
        printf("%c",s[st.top()]);
        st.pop();
    }

    puts("");


}

//figggfidibbbjcdggccfjechddgccij
//jfigggfidibbbjcdggccfjechddgcci

