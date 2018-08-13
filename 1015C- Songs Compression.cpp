#include<bits/stdc++.h>
using namespace std;

/*bool compare(long long a, long long b){
    return a>b;
}*/

main(){
    long long current=0, cnt=-1, init, reduced,m, n;
    cin>>n>>m;
    vector <long long> v;

    for(long long i=0;i<n;i++){
        cin>>init>>reduced;
        current+=init;
        v.push_back(init-reduced);
        cnt++;
    }

    sort(v.begin(),v.end());
    long long moves=0;

    while(true){
        if(current<=m)
            break;

        if(cnt<0){
            cout<<"-1"<<endl;
            return 0;
        }

        current-=v[cnt];
        cnt--;
        moves++;

    }

    cout<<moves<<endl;

}
