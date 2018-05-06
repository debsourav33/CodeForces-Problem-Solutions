#include<bits/stdc++.h>
using namespace std;


main(){
    int row, col,q,r1,c1,r2,c2;
    cin>>row>>col;

    string s[row+5];
    int vertical_dp[505][505], horizontal_dp[505][505];

    for(int i=0; i<row; i++)
        cin>>s[i];


   for(int i=0;i<row;i++){
        int cnt=0;
        for(int j=1;j<col;j++){
            if(s[i][j] == s[i][j-1] && s[i][j]=='.')
                cnt++;

            horizontal_dp[i][j]=cnt;
        }

   }

   for(int i=0;i<col;i++){
        int cnt=0;
        for(int j=1; j<row; j++){
            if(s[j][i]==s[j-1][i] && s[j][i]=='.')
                cnt++;

            vertical_dp[j][i]=cnt;
        }
   }


   cin>> q;

    while(q--){
        int ans=0;
        cin>>r1>>c1>>r2>>c2;

        int row1=r1-1, row2=r2-1, col1=c1-1, col2=c2-1;

        for(int i=row1;i<=row2;i++){
            ans+= horizontal_dp[i][col2]-horizontal_dp[i][col1];
        }

        for(int i=col1; i<=col2;i++)
            ans+= vertical_dp[row2][i]- vertical_dp[row1][i];


        cout<<ans<<endl;
    }


}
