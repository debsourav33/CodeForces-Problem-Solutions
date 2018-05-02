#include<bits/stdc++.h>
using namespace std;

#define MX 1<<28
#define ll long long
#define ull unsigned long long

string rmvDup(string s){
    for ( std::string::size_type i = 0; i < s.size(); i++ )
    {
        std::string::size_type j = i + 1;
        while ( j < s.size() )
        {
            if ( s[i] == s[j] )
            {
                s.erase( j, 1 );
            }
            else
            {
                ++j;
            }
        }
    }

    return s;
}

main(){
    int n;
    cin>>n;
    string s[n+2];

    vector <string> v;

    for(int i=0;i<n;i++){
        cin>> s[i];
        sort(s[i].begin(),s[i].end());
        s[i]= rmvDup(s[i]);
        v.push_back(s[i]);
    }

    if(v.size()!=0)
        sort(v.begin(),v.end());

    int cnt=1;

     for(int i=1;i<v.size();i++){
        if(v[i]!=v[i-1])
            cnt++;

    }

    cout<<cnt<<endl;


}
