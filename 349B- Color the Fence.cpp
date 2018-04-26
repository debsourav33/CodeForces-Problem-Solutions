#include<bits/stdc++.h>
using namespace std;

int a[9];
string str;
int getValue(vector <int> v){

    int s=0;
    for(int j=0;j<v.size();j++){
        s=s*10+v[j];
    }

    return s;


}

string call(int i, int paint, string v){
    if(paint==0)
        return v;

    string opt1=v, opt2=v;

    if(i>0)
        opt2= call(i-1, paint, v);

    if(paint>=a[i]){
        char c= '0' + (i+1);
        v.push_back(c);
        opt1= call(i, paint-a[i], v);
    }


    if(opt1.length()==opt2.length()){
        int flag=0;
        for(int i=0;i<opt1.length();i++){

            int op1= opt1[i]-'0';
            int op2= opt2[i]-'0';

            if(op1>op2){
                flag=1;
                break;
            }
            else if(op2>op1){
                flag=2;
                break;
            }

        }

        if(flag==1)
            return opt1;
        else
            return opt2;


    }
    if(opt1.length()<opt2.length())
        return opt2;
    else
        return opt1;

    //return opt1.length()>opt2.length() ? opt1: opt2;

}

main(){
    int paint;
    cin>>paint;

    for(int i=0;i<9;i++){
        cin>> a[i];
        char c= (char) a[i];
        str.push_back(c);
    }

    string s;

    cout<< call(8,paint,s)<< endl;


}
