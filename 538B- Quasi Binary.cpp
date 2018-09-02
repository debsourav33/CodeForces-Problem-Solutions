#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define sets(a) memset(a,-1,sizeof(a))
#define pb push_back

int visited[1000006], level[1000006], parent[1000006];
int bins[]= {1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,11000,11001,11010,11011,11100,11101,11110,11111,100000,100001,100010,100011,100100,100101,100110,100111,101000,101001,101010,101011,101100,101101,101110,101111,110000,110001,110010,110011,110100,110101,110110,110111,111000,111001,111010,111011,111100,111101,111110,111111,1000000,1000001};

void reset(){
    clr(visited);
    clr(level);
    sets(parent);
}

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]= 1;
    level[source]= 0;

    while(!q.empty()){
        int val= q.front();
        q.pop();

        for(int i=0;i<65;i++){
            if(val>=bins[i]){
                int nd= val-bins[i];

                if(!visited[nd]){
                    visited[nd]= 1;
                    level[nd]= level[val]+1;
                    parent[nd]= val;
                    q.push(nd);
                }
            }
        }


    }
}

void print_path(int u){
    if(parent[u]==-1){
        puts("");
        return;
    }

    cout<<" "<<(parent[u]-u);
    print_path(parent[u]);
}


main(){
    reset();
    int val;
    cin>>val;

    bfs(val);
    cout<<level[0]<<endl;
    cout<<parent[0]-0;
    print_path(parent[0]);

}

