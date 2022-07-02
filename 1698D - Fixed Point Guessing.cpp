#include<bits/stdc++.h>
using namespace std;

int n;

int bolod_count(int l, int r){
    int bolods = 0, x;

    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();

    for(int i=l;i<=r;i++){
        cin>>x;

        if(x>=l && x<=r)  bolods++;
    }

    return bolods;
}

int main(){
    int opt;
    cin>>opt;

    while(opt--){
        cin>>n;

        int lo = 1, hi = n;

        while(lo<hi){
            int mid = (lo+hi)/2;

            //bolods = no. of elements that lies in their own region (1 4 2 3) -> for (1 4 2), bolods = 2 (1 and 2 are valids)
            //The Observation: Bolods must be in pairs -> Except the original unchanged bolod
            //if that sub-array contains the unchanged element, then bolods must be odd (the original unchanged element + other bolods in PAIRS)
            if(bolod_count(lo,mid)%2==1)  hi = mid;
            else  lo = mid + 1;

        }

        cout<<"! "<<lo<<endl;
        cout.flush();
    }
}
