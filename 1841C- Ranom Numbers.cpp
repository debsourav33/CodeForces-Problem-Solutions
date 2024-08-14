/*
Time: O(n*5*2)
Space: O(n*5*2)

DP States: pos = Current position, maxi = maximum element found so far in the right, changed = if we have yet made the one change that can
Traverse from right, track the maximum element found so far, and at every position, try replacing that letter (if not the replacement has been done already) with every other letter to see if we get better result
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;
vector<int> v; 
const int d = 5;
vector<int> ps = {1, 10, 100, 1000, 10000};
int n;

int call(int pos, int maxi, bool changed){
    if(pos < 0)  return 0;
    int &mem = dp[pos][maxi][changed];
    if(mem !=-1)  return mem;
    
    int best = -1e9;
    for(int i=0;i<d;i++){
        if(changed && v[pos] != i)  continue;
        
        
        int sum;
        
        if(i >= maxi){
            sum = ps[i] + call(pos-1, max(i, maxi), changed || (i != v[pos]));
        }
        else{
            sum = -ps[i] + call(pos-1, max(i, maxi), changed || (i != v[pos]));
        }
        
        best = max(sum, best);
    }
    
    return mem = best;
}

int main()
{
    int m;
    
    scanf("%d",&m);
    
    while(m--){
        string s;
        cin >> s;
        n = s.length();
        //printf("%s %d\n",s,val);
        v.clear();
        for(auto c: s)  v.push_back(c-'A');
        
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(d, vector<int>(2, -1)));
        
        int val = call(n-1, 0, false);
        printf("%d\n",val);
    }
    

    return 0;
}
