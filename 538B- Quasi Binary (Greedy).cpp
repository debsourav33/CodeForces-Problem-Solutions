#include<bits/stdc++.h>
using namespace std;
#define MX 999999
vector <int> bins, v;

int dir[1000];
int call(int num, int i){
    if(num==0)
        return 0;

    int opt1=MX, opt2= MX;

    if(num>=bins[i])
        opt1= 1+ call(num-bins[i],i);

    if(i>0)
        opt2= call(num,i-1);



    return min(opt1,opt2);

}


int getBin(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}



}

main(){
    int num;
    cin>> num;

    int digits= log10(num)+1;

    int border= ceil(pow(2,digits))-1;


    for(int i=1; i<=border; i++)
        bins.push_back(getBin(i));

    cout<< call(num,bins.size()-1) <<endl;

    for(int i=0;i< v.size();i++){
        cout<< v[i]<<" ";
    }

}
