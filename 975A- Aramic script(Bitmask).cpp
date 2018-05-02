#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28
#define ll long long
#define ull unsigned long long

int sets(int N, int pos){
    return N= N | (1<<pos);
}

main(){
    int n;
    cin>> n;
    set<int> st;
    string s;

    for(int opt=0;opt<n;opt++){
        int mask=0;
        cin>> s;

        for(int i=0;i<s.size();i++){
            int value= (int) (s[i]-'a');
            mask= sets(mask,value);

        }

        st.insert(mask);
    }

    cout<<st.size()<<endl;


}
