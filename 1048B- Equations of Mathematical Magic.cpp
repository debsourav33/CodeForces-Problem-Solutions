#include<bits/stdc++.h>
using namespace std;


/*
If current pos bit in a is 1, we can place 0 or 1 in bit position pos for x,
Since 1-0= 1 xor 0 and 1-1= 1 xor 1

but for bit 0, we can place only 0 for x, because 0-0= 0 xor 0
but placing 1 for x causes 0 xor 1= 1 and
in order to 0 - 1 to be 1,
we have to have a borrow from nearmost 1, which leaves a vacancy of (0) there..
hence at that 1, if xor is 1, sub is 0 (a had 1 (after borrow a has 0) and x has 0))

So we have 2 choices for the position where bit is 1 and 1 choice where bit is 0 (in a)
*/

int a;

int checkbit(int num, int i){
    return num & (1<<i);
}

int call(int pos){
    if(pos==31)  return 1;
    int opt;

    if(checkbit(a,pos))
        opt= 2*call(pos+1);
    else
        opt= call(pos+1);

    return opt;
}

int main(){
    int opt;
    cin>>opt;

    while(opt--) {
        cin >> a;
        cout << call(0) << endl;
    }
}
