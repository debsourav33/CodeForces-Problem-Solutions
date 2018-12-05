#include<bits/stdc++.h>
using namespace std;

#define si(a) scanf("%d",&a)
#define fr(n) for(int i=0;i<n;i++)

int n, a[100005];

int main(){
    si(n);

    fr(n) {
        si(a[i]);
        a[i]= a[i]%2;
    }

    int s= 5000;

    printf("%d\n",n+1);
    printf("2 %d 1\n",n);
    printf("1 %d %d\n",n,s);

    fr1(n-1){
        printf("2 %d %d\n",i,s--);
    }

}
