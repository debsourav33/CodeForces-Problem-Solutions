#include<bits/stdc++.h>
using namespace std;

main(){
    string pat,text;
    int p, t, cnt, flag=0, crossed=0;

    cin>>p>>t;
    cin>>pat>>text;

    if(p>t+1){
        cout<<"NO"<<endl;
        return 0;
    }

    if(p<t || p==t+1){
        for(int i=0;i<p;i++){
            if(pat[i]=='*')
                flag=1;
        }

        if(flag==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    /*traverse from left of '*', search for unmatched*/
    for(int i=0;i<t;i++){
        if(pat[i]=='*')
            break;

        if(text[i]!=pat[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cnt= p-1;

    /*traverse from right of '*', search for unmatched*/
    for(int i=text.size()-1; i>=0; i--){
        if(pat[cnt]=='*'){
            flag=1;
            break;
        }

        if(text[i]!=pat[cnt]){
            cout<<"NO"<<endl;
            return 0;
        }

        cnt--;
    }

    /*left and right of '*' has matched*/
    cout<<"YES"<<endl;

}
