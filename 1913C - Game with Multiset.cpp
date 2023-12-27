#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, q, num;
    int two_29 = 1<<29;
    vector<int> cnt(32,0);
    
    scanf("%d",&m);
    
    while(m--){
        
        scanf("%d %d",&q,&num);
        
        if(q==1){
            cnt[num]++;
            while(num<30 && cnt[num]==3){
                cnt[num+1]++;
                cnt[num]=1;
                num++;
            }
        }
        else{
            for(int i=29;i>=0;i--){
                //cout<<i<<" "<<(1<<i)<<" :"<< cnt[i]<<endl;
                int sub = 1<<i;
                int sub_twice = sub * 2;
                
                if (num >= sub_twice && cnt[i] >=2)    num -= sub_twice;
                else if(num >= sub && cnt[i] >=1)    num -= sub;
            }
            
            if(num==0) printf("YES\n"); else printf("NO\n");
        }
    }
    

    return 0;
}
