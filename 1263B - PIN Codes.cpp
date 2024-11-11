/*
Time: O(n)
Space: O(n)

Observation: Since there are max 10 locks, any of the position is enough to be different in order for all the locks to be different (having 10 values, 0 - 9)

So, we will maintain a count map, and try to change locks having count > 1 in the last position trying digits 0 - 9 until we get a value that has no count
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        vector<int> v;
        unordered_map<int,int> cnt;
        scanf("%d",&n);

        for(int i=0; i<n; i++){
            int x;
            scanf("%d",&x);
            v.push_back(x);
            cnt[x]++;
        }

        int ans = 0;
        for(auto &u: v){
            if(cnt[u] == 1)  continue; //this lock is unique
            
            //not unique, we need to make one operation 
            ans++;
            cnt[u]--; //this value is getting changed, so decrement its count
            
            //try to change locks having count > 1 in the last position trying digits 0 - 9 until we get a value that has no count
            for(int d=0;d<=9;d++){
                u = u/10;
                u = u*10 + d;

                if(cnt[u] == 0){ //found a unique value!
                    cnt[u] = 1; //increment count
                    break;
                }
            }
        }

        printf("%d\n",ans);
        for(auto u: v){
            string s = to_string(u);
            for(int i=0;s.length()<4;i++)  s= "0" + s;
            cout<<s<<endl;
        }
    }
}
