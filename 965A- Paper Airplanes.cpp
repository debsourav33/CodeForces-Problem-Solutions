#include<bits/stdc++.h>
using namespace std;

main(){
    int k,n,s,p;

    cin>> k>> n>> s>> p;

    int sPerPerson= (n-1)/s+1;

    int totalS= sPerPerson * k;

    int totalP= (totalS-1)/p+1;

    cout<< totalP <<endl;




}
