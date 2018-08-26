#include<bits/stdc++.h>
using namespace std;

string text, pattern;
int pi[1000105];


void kmp(){
    int now;

    pi[0]= now= -1;
    for(int i=1; i<text.length();i++){

        while(now!=-1 && text[i]!=text[now+1])
            now= pi[now];

        if(text[i]==text[now+1])    pi[i]= ++now;
        else    pi[i]= -1;
    }

}


main(){
    int n,k;
    cin>>n>>k;
    cin>>text;
    kmp();

    int len= text.length();
    int st= pi[len-1];

    cout<<text;

    k--;

    while(k--){
        for(int i=st+1;i<len;i++){
            printf("%c",text[i]);
        }
    }

    puts("");


}
