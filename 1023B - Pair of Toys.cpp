#include<bits/stdc++.h>
using namespace std;

main(){
    long long a, b;
    cin>>a>>b;

    if(b<a){
        cout<<b/2<<endl;
        return 0;
    }

    if((b/2) > a){
        cout<<"0"<<endl;
        return 0;
    }

    long long c= (b-1)/2 +1;

    cout<< a-c+1 << endl;


}
