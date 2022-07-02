#include<bits/stdc++.h>
using namespace std;

long long n, x;
map<long long, long long> m;

set<long long> digits(long long x){
    set<long long> ret;

    while(x){
        ret.insert(x%10);
        x /= 10;
    }

    return ret;
}

long long length(long long x){
    int ret = 0;

    while(x){
        ret++;
        x /= 10;
    }

    return ret;
}



long long dfs(long long x){
    int l = length(x);
    if(l == n)  return 0;
    if(l > n )  return 1e9;
    if(m.count(x))  return m[x];
    //cout<< x<< endl;
    long long mini = 1e9;

    for(long long d: digits(x)){
        if(d==1 || d==0)  continue;

        mini = min(1 + dfs(x*d), mini);
    }

    return m[x] = mini;
}

int main(){
    cin>> n >> x;

    long long ans = dfs(x);

    if(ans == 1e9)  cout<<"-1"<<endl;
    else  cout<<ans<<endl;
}
