#include<bits/stdc++.h>
using namespace std;

int flag=0;
int moves[10005],cnt=0;

string reshape(string text, int i, int pos){
    for(i=i;i>pos;i--){
        moves[cnt++]=i;

        char tmp=text[i];
        text[i]=text[i-1];
        text[i-1]=tmp;
    }
    return text;
}

int solve(string text, string pattern){
    int offset=0;
    for(int pos=0;pos<pattern.length();pos++){

        for(int i=pos;i<text.length();i++){
            if(pattern[pos]==text[i]){
                offset+=i-pos;
                text= reshape(text,i,pos);
                break;
            }
        }
    }

    return offset;
}

main(){
    int len;
    string text, pattern;
    cin>>len>>text>>pattern;
    string t_text=text, t_pattern=pattern;
    sort(t_text.begin(),t_text.end());
    sort(t_pattern.begin(),t_pattern.end());

    if(t_text!=t_pattern){
        cout<<"-1"<<endl;
        return 0;
    }

    int offset= solve(text,pattern);

    if(offset==0){
        cout<<"0"<<endl;
        return 0;
    }

    if(cnt>10000){
        cout<<"-1"<<endl;
        return 0;

    }

    cout<<offset<<endl;

    cout<<moves[0];
    for(int i=1;i<cnt;i++)
        cout<<" "<<moves[i];
    puts("");


}
