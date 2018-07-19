#include<bits/stdc++.h>
using namespace std;

int pi[1000005];
string p;

int KMP(){
    int now;

    pi[0]= now= -1;

    for(int i=1;i<p.length();i++){

        while(now!=-1 && p[i]!=p[now+1])
            now= pi[now];

        if(p[i]==p[now+1])
            pi[i]= ++now;
        else
            pi[i]= -1;


    }

}

main(){
    cin>> p;
    KMP();
    int len= p.length();

    int maxi= pi[len-1];
    int found= pi[maxi];
    if(maxi==-1)
        found=-1;

    for(int i=1;i<(len-1);i++){
        if(pi[i]==maxi)
            found=maxi;
    }

    if(found==-1)
        cout<<"Just a legend"<<endl;
    else{
        cout<< p.substr(0,found+1) <<endl;
    }


}
