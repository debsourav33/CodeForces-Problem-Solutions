#include<bits/stdc++.h>
using namespace std;

vector <int> v;

string t,p;
int m,n;

void rearrange(){
    if(n>m){
        string temp= t;
        t= p;
        p= temp;

        int tmp= m;
        m= n;
        n= tmp;
    }
}

void push_div(){
    for(int i=1;2*i<=n;i++){
        if(n%i==0 && m%i==0)
            v.push_back(i);

    }

    if(m%n==0)
        v.push_back(n);

}

int is_div2(string s, int i,int l){
    if(i==m){
        return 1;
    }

    return p.substr(i,l)==s ? is_div2(s,i+l,l) : 0;
}

int is_div(string s, int i,int l){
    if(i==n)
        return is_div2(s,0,l);

    return t.substr(i,l)==s ? is_div(s,i+l,l) : 0;
}


main(){
    int common=0;
    cin>>t>>p;
    n= t.length();
    m= p.length();

    rearrange();
    push_div();

    for(int i=0;i<v.size();i++){
        int d= v[i];
        string s= t.substr(0,d);

        if(is_div(s,d,d))
            common++;
    }

    cout<<common<<endl;



}
