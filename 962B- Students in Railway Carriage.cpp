#include<bits/stdc++.h>
using namespace std;

main(){

    int total, a,b, mx, tmp=0,seats=0;
    char str[200005];

    cin>> total >> a >>b;

    for(int i=0;i<total;i++){
        cin>> str[i];
        if(str[i]=='.')
            seats++;
    }

    if(b>a){
        swap(a,b);
    }

    for(int i=0;i<total;i++){
        if(a==0)
            break;

        if(str[i]=='.' ){
            str[i]='a';
            i++;
            tmp++;
            a--;
        }

    }

    seats=seats-tmp;

    tmp+= min(seats, b);

    cout<< tmp<< endl;






}
