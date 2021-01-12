    #include <algorithm>  
    #include <iostream>  
    #include <sstream>  
    #include <string>  
    #include <vector>  
    #include <queue>  
    #include <set>  
    #include <map>  
    #include <cstdio>  
    #include <cstdlib>  
    #include <cctype>  
    #include <cmath>  
    #include <cstring>
    #include <list>  
    #include <cassert>
    #include <climits>
    using namespace std;  
     
    #define PB push_back  
    #define MP make_pair  
    #define SZ(v) ((int)(v).size())  
    #define FOR(i,a,b) for(int i=(a);i<(b);++i)  
    #define REP(i,n) FOR(i,0,n)  
    #define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
    #define REPE(i,n) FORE(i,0,n)  
    #define FORSZ(i,a,v) FOR(i,a,SZ(v))  
    #define REPSZ(i,v) REP(i,SZ(v))  
    typedef long long ll;  
    int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
     
    const int MAXN=100000;
     
    int n,cap;
    int a[MAXN],b[MAXN];
     
    int c[MAXN];
     
    void run() {
    	scanf("%d%d",&n,&cap); REP(i,n) scanf("%d%d",&a[i],&b[i]);
    	
    	REP(i,n) c[i]=a[i]-b[i]; sort(c,c+n); reverse(c,c+n);
    	ll sum=0; REP(i,n) sum+=a[i];
    	int at=0; while(at<n&&sum>cap) sum-=c[at++];
    	printf("%d\n",sum<=cap?at:-1);
    }
     
    int main() {
    	run();
    	return 0;
    }
