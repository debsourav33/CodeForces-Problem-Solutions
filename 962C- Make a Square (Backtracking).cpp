#include<bits/stdc++.h>
#include<math.h>

#define MX 999999
using namespace std;

int n;
vector <int> v;

/* Can't Use Memorizing if you use backtracking */

int isSqr(){

    int s=0;
    for(int j=0;j<v.size();j++){
        s=s*10+v[j];
    }
    int root= sqrt(s);
    int sqr= root*root;

    if(s==sqr)
        return 1;

    return 0;

}

int call(int i){

    if(v.size()==0)
        return MX;

    if(isSqr() && v[0]!=0)
        return 0;

    if(i>=v.size())
        return MX;

    int opt1=MX, opt2=MX;


    opt1= call(i+1);

    int tmp=v[i];
    v.erase(v.begin()+i);
    opt2= 1+call(i);
    v.insert(v.begin()+i,tmp); //backtracking


    return min(opt1,opt2);

}


main(){

    int a,b,c,x;
    cin>> n;

   while(true){
        v.insert(v.begin(),n%10);
        n=n/10;
        if(n==0)
            break;
   }

    if(call(0)==MX)
        cout<< "-1" <<endl;
    else
        cout<< call(0) <<endl;



}
