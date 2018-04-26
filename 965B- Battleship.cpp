#include<bits/stdc++.h>
using namespace std;

int a[105][105], val[105][105], vis[105][105], n, k;
int maxi=0,max_i=0,max_j=0;
void call(int i, int j){
    if(vis[i][j]==1)
        return;

    vis[i][j]=1;

    if(i>=n || j>=n)
        return;

    int flag=1;

    if((i+k)<=n){
        for(int x=i; x<i+k; x++){
            if(a[x][j]!=1){
                flag=0;
                break;
            }
        }

        if(flag){


              for(int x=i; x<i+k; x++){
                    val[x][j]++;
                    if(val[x][j]>=maxi){
                        maxi=val[x][j];
                        max_i=x;
                        max_j=j;
                    }
              }
        }
    }

    int flag2= 1;

    if((j+k)<=n){
        for(int x=j; x<j+k; x++){
            if(a[i][x]!=1){
                flag2=0;
                break;
            }
        }

        if(flag2){

              for(int x=j; x<j+k; x++){
                    val[i][x]++;

                    if(val[i][x]>=maxi){
                        maxi=val[i][x];
                        max_i=i;
                        max_j=x;
                    }

              }
        }
    }
    call(i+1,j);
    call(i,j+1);

    return;



}

main(){
    cin >> n>> k;
    string c;
    char cas[105], ch;

    memset(val, 0, sizeof val);
    memset(vis, -1, sizeof vis);

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cin>> ch;
            if(ch=='#')
                a[i][j]=0;
            else if(ch=='.')
                a[i][j]=1;

        }

    }

    call(0,0);

    cout<<max_i+1<<" "<<max_j+1<<endl;



}
