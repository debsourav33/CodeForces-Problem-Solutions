/*
Time: O(n)
Space: O(1) (= O(26))

Group same characters together. This will result in maximum substrings being palindrome (all adjacent combination among each group will be a palindrome)

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    unordered_map<char,int> cnt;
    for(auto c: s)  cnt[c]++;

    //Group same characters together. This will result in maximum substrings being palindrome
    string ans = "";
    for(auto &p: cnt){
        while(p.second--){
            ans += p.first;
        }
    }
    
    cout<<ans<<endl;
}
