#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28
#define ll long long

struct seg{
        int l;
        int r;
        int pos;

        seg(){
        }

        seg(int _l, int _r,int _pos){
            l=_l;
            r=_r;
            pos=_pos;
        }



};

bool comp(seg a, seg b){
    if(a.l==b.l)
        return a.r>b.r;

    return a.l<b.l;
}


main(){
    vector <seg> v;
    int n,l,r;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>l>>r;
        v.push_back(seg(l,r,i+1));
    }

    sort(v.begin(),v.end(),comp);

    int mxR=v[0].r;
    int mxPos=1;

    for(int i=0;i<v.size()-1;i++){
        if(v[i+1].r<=v[i].r){
            cout<<v[i+1].pos<<" "<<v[i].pos<<endl;
            return 0;
        }

    }


    cout<<"-1 -1"<<endl;


}
