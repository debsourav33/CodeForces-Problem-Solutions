#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28

main(){

    unsigned long long n,row,col,s,t;
    cin>>row>>col;
    cin>>n;

    if(n<= (row+col-2)){
        if(n<row){
            s= 1+n;
            t=1;
            cout<<s<<" "<<t<<endl;
            return 0;
        }
        else{
            s=row;
            t=2+n-row;
            cout<<s<<" "<<t<<endl;
            return 0;
        }

    }

    n=n-(row+col-2);
    unsigned long long chck= (n-1)/(col-1);

    s= row-1-((n-1)/(col-1));

    if(chck%2==0)
        t= col-((n-1)%(col-1));
    else
        t= 2+((n-1)%(col-1));

    cout<<s<<" "<<t<<endl;



}
