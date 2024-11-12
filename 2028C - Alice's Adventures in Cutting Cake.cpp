/*
Time: O(n)
Space: O(n)

- Calculate prefix sum
- For each index i from n-1 to 0 (from the end), calculate how many groups we can accomdate from n-1 to i. Lets call it pos_of_piece.
- Now start from 0, for each index i from 0 to n-1, calculate how many groups we can accomdate so far, and how many more needed.
  Find pos_of_piece[needed], that index will give us which suffix we need to take for the groups. The gap between i and pos_of_piece[needed] are extra, and can be taken by Alice herself.
  The biggest such gap (found by subtracting the prefix sum) is the answer.
*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);

        int a[n];
        for(int i=0;i<n;i++)  scanf("%d",&a[i]);

        long long pref[n];
        pref[0] = a[0];
        for(int i=1;i<n;i++)  pref[i] = pref[i-1] + a[i];

        unordered_map<long long,int> pos_of_piece;
        long long sum = 0, cnt = 0;

        //For each index i from n-1 to 0 (from the end), calculate how many groups we can accomdate from n-1 to i. Lets call it pos_of_piece.
        pos_of_piece[0] = n;
        for(int i=n-1;i>=0;i--){
            sum += a[i];

            if(sum >= k){
                cnt++;
                pos_of_piece[cnt] = i;

                //cout<<cnt<< " "<<i<<endl;
                sum = 0;
            }
        } 

        long long ans = -1;
        if(pos_of_piece.count(m)){
            int p = pos_of_piece[m];
            if(p > 0)  ans = pref[p-1];
        }

      //Now start from 0, for each index i from 0 to n-1, calculate how many groups we can accomdate so far, and how many more needed.
      
        sum = 0, cnt = 0;
        for(int i=0;i<n;i++){
            sum += a[i];

            if(sum >= k){
                cnt++;
                int need = max(0LL, m - cnt);
                
              //Find pos_of_piece[needed], that index will give us which suffix we need to take for the groups. The gap between i and pos_of_piece[needed] are extra, and can be taken by Alice herself.
                if(pos_of_piece.count(need)){
                    int p = pos_of_piece[need];
                    if(p > i)  ans = max(ans, pref[p-1]-pref[i]);
                    //cout<<cnt<<": "<<pref[p-1]<<"-"<<pref[i]<<endl;
                }

                sum = 0;
            }
        }

        printf("%lld\n",ans);
    }
    
}
