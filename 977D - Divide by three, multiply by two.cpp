#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull n;
ull a[105], dp[105][105], dir[105];

ull call(ull k, ull cnt){
    if(dp[k][cnt]!=-1)
        return dp[k][cnt];

    if(cnt==n)
        return 1;

    ull maxi=0;

    for(ull i=0;i<n;i++){
        if((a[i]*3==a[k]) || (a[k]*2==a[i]) ){

            int tmp= call(i,cnt+1);

            if(tmp>maxi){
                maxi=tmp;
                dir[k]= i;
            }

        }
    }



    return dp[k][cnt]= maxi;


}

void solution(ull start){
    if(dir[start]==-1)
        return;

    cout<<" "<<a[dir[start]];
    solution(dir[start]);

}

main(){
    ull fl, start;
    cin>>n;
    memset(dp, -1, sizeof dp);
    memset(dir, -1, sizeof dir);
    for(ull i=0;i<n;i++)
        cin>>a[i];

    for(ull i=0;i<n;i++){
        fl=call(i, 1);
        if(fl==1){
            start=i;
            break;
        }
    }

    cout<<a[start];
    solution(start);

    puts("");

}
