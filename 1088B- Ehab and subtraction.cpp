#include<bits/stdc++.h>
using namespace std;

#define sii(a,b) scanf("%d %d",&a,&b);
#define fr(n) for(int i=0;i<n;i++)

int n, k, a[100005],x;
priority_queue<int, std::vector<int>, std::greater<int> > q;

int main(){
    sii(n,k);

    fr(n) {
        si(x);
        q.push(x);
    }

    int d= 0, cnt=k;
    while(!q.empty()) {
        if(q.top()-d!=0) {
            outi(q.top() - d);
            if(--cnt==0)
                break;
        }

        d+= q.top()-d;
        q.pop();

    }

    while(cnt--) {
        puts("0");
    }
}
