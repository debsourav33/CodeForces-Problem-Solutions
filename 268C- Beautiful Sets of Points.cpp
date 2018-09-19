/*
I used 2 theorem to derive my algorithm for this problem
    1. if we increment x and decrement y, then for any stage
    a= |pj.x-pi.x| = |pj.y-pi.y|
    distance(pi,pj)= sqrt(|pj.x-pi.x|^2 + |pj.y-pi.y|^2)
                   = sqrt(a^2+a^2)
                   = sqrt(2*a^2)
                   = sqrt(2)* a
    Since, sqrt(2) is always non-integer, the distance is non-integer

    2. Pigeon Hole Theorem
    If we can get number of such pairs more than min(m+1, n+1), then
    at least 1 number will appear more than once which will result in integer distance
                    = sqrt((x-x)^2+(y1-y2)^2)
                    = (y1-y2)
    So, Maximum possible pairs= min(m+1, n+1)
*/

#include<bits/stdc++.h>
using namespace std;

main(){
    int m, n, x, y;
    cin>>m>>n;

    cout<<min(m+1,n+1)<<endl;

    x=0, y=max(m,n);

    while(x<=min(m,n)){
        if(m<=n)
            cout<<x++<<" "<<y--<<endl;
        else
            cout<<y--<<" "<<x++<<endl;
    }
}
