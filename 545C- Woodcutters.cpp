#include<bits/stdc++.h>
using namespace std;

#define ll long long

main(){
    ll n,x, h, t_x, a[100005], cmp=-1000000030, tree=0;
    cin>>n;

    while(n--){
        cin>>x>>h;

        /*first try to cut tree down at left, at [x-h,x]*/
        if(x-h > cmp){
            cmp=x;
            tree++;
        }

        /*if not possible, try cutting it down at right, at [x,x+h]*/
        else if(x>cmp){
            cmp= x+h;
            tree++;
        }

        /*this tree false in a cut-segment, discard previous cut and try cutting it down at left, at [x-h,x], but don't count again (due to overlapping previous count)*/
        else if(x-h >t_x){
            cmp= x;
        }

        /*else you have to cut it down at right*/
        else{
            cmp= x+h;
        }

        t_x=x;

    }

    cout<<tree<<endl;


}
