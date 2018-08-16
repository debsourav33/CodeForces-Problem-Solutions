#include<bits/stdc++.h>
using namespace std;

string text, pattern;

int kmp(){
    int match=0, now, pi[100105];

    pi[0]= now= -1;
    for(int i=1; i<text.length();i++){

        while(now!=-1 && text[i]!=text[now+1])
            now= pi[now];

        if(text[i]==text[now+1])    pi[i]= ++now;
        else    pi[i]= -1;

        if(now==pattern.length()-1){
            now= -1; //ababab for pattern abab can be deminished by aba#ab
            match++;
        }

    }

    return match;

}


main(){
    cin>>text>>pattern;
    text= pattern+"#"+text;

    cout<<kmp()<<endl;


}
