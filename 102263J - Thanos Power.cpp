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

int i, j, n;

//vector<int> v, t;
int a[maxn], t[maxn], dp[maxn][2];
string s, ss, tt;


// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    if(str[str.length()-1]=='0')  str.pop_back();
    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

int call(int i, int curr){
    if(i==n)  return 0;
    if(dp[i][curr]!=-1)  return dp[i][curr];

    int o1, o2;

    if(curr==0) {
        o1 = a[i]+ call(i+1,curr);
        o2= 1+t[i]+ call(i+1,1-curr);
    }
    else{
        o1 = t[i]+ call(i+1,curr);
        o2= 1+a[i]+ call(i+1,1-curr);
    }

    return dp[i][curr]= min(o1,o2);
}

main(){
    sets(dp);
    cin>>s;
    n=s.length();

    if(n==1){
        int x= s[0]-'0';

        outi(min(x,10-x+1));
        return 0;

    }

    ss.push_back('1');
    fr(n)  ss.pb('0');

    tt= findDiff(ss,s);

    fr(n)  a[i]= s[i]-'0';
    fr(n)  t[i]= tt[i]-'0';

    a[n]= 0, t[n]=0;

    outi(call(0,0));
    //outl(c);
}
