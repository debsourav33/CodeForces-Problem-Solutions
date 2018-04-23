#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, *a, x;
    cin >> n;

    a= (int *) malloc(n* sizeof (int));

    int maxi=0, maxSoFar=0;
    int start=0, endi=0, tmpStart=0;

    for(int i=0;i<n;i++){
        cin>> x;

        if(x==0)
           a[i]=1;
        if(x==1)
            a[i]=-1;
    }

    for(int i=0;i<n;i++){
         if(maxSoFar+a[i]>=0)
            maxSoFar+=a[i];
         else{
            tmpStart=i+1;
            maxSoFar=0;
         }

         if(maxSoFar>=maxi){
            start=tmpStart;
            endi=i;
         }
         maxi= max(maxSoFar,maxi);
    }

    int cnt=0;

    for(int i=0; i<n; i++){
        if(i>=start && i<=endi){
            if(a[i]==1)
                cnt++;
        }
        else if(a[i]==-1)
                cnt++;


    }

    if(start>endi)
        cnt--;

    cout<< cnt <<endl;

}
