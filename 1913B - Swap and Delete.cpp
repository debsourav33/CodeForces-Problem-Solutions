#include<bits/stdc++.h>
using namespace std;

#define fr(n) for(int i=0;i<n;i++)
#define sc(n) scanf("%d",&n)

int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        string s;
        
        cin>>s;
        
        n = s.length();
        
        int ones = 0, zeros = 0, res = 0;
        for(char c: s)  c == '0' ? zeros++ : ones++;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(ones==0){
                    res = n-i;
                    break;
                }
                ones--;
            }
            if(s[i]=='1'){
                if(zeros==0){
                    res = n-i;
                    break;
                }
                zeros--;
            }    
        }
        
        printf("%d\n",res);
        
    }
    
    return 0;
    
}
