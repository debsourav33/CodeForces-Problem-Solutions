#include<bits/stdc++.h>
using namespace std;

int n, dp[200005];
int call(int a[], int i){
    if(dp[i]!=-1)
        return dp[i];

    int maxi=0;

    if(i==n-1)
        return 1;

    if(a[i+1]>=a[i]){
        int tmp= call(a,i+1);

        if(tmp >maxi)
            maxi= tmp;
    }

    return dp[i]=maxi+1;


}

main(){
    int *a, maxi=0;
    cin>>n;
    a= (int*) malloc(sizeof (int)* n);

    for(int i=0;i<200005; i++)
        dp[i]=-1;

    for(int i=0;i<n;i++){
        cin >> a[i];

    }



    for(int i=0;i<n;i++)
        maxi= max(call(a,i),maxi);

    cout<< maxi <<endl;



}
