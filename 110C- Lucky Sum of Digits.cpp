#include<bits/stdc++.h>
using namespace std;

//{
#define cel(n,k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define max(a,b) ((a)>(b)? (a):(b))
#define min(a,b) ((a)<(b)? (a):(b))
#define fr(n) for(int i=0;i<n;i++)
#define fr1(n) for(int i=1;i<=n;i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define INF 10000007

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

int visited[1000006], parent[1000006];

void reset(){
    clr(visited);
    sets(parent);
}

int dr[]= {4,7};

void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]= 1;

    while(!q.empty()){
        int val= q.front();
        q.pop();

        for(int i=0;i<2;i++){
            if(val<dr[i])  continue;
            int nd= val-dr[i];

            if(!visited[nd]){
                visited[nd]= 1;
                parent[nd]= val;
                q.push(nd);
            }

        }


    }
}

void print_path(int u){
    stack<int> st;
    while(parent[u]!=-1){
        st.push(parent[u]-u);
        u= parent[u];
    }

    while(!st.empty()){
        printf("%d",st.top());
        st.pop();
    }
    puts("");
}

main(){
    reset();
    int val;
    cin>>val;

    bfs(val);

    if(parent[0]==-1)  cout<<"-1"<<endl;
    else  print_path(0);
}
