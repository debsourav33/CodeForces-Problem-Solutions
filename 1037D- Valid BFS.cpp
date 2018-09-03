#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define sets(a) memset(a,-1,sizeof(a))
#define pb push_back

vector<int> v[200005];
int visited[200005], relorder[200005], cycle=0;

void reset(){
    clr(visited);
}

int arr[200005], n;

int bfs(int source){
    if(arr[0]!=source)
        return -1;

    queue<int> q;
    q.push(source);
    visited[source]= 1;
    int cnt=1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int nd= v[u][i];

            if(!visited[nd]){
                if(nd!=arr[cnt])
                    return -1;

                visited[nd]=1;
                q.push(nd);
                cnt++;
            }
        }
    }

    return cnt==n;
}

bool cmp(int a, int b){
    return relorder[a] < relorder[b];
}

main(){
    reset();
    int a, b, edges;
    cin>>n;

    for(int i=0;i<n-1;i++){
        cin>>a>>b;

        v[a].pb(b);
        v[b].pb(a);
    }

    for(int i=0;i<n;i++){
        cin>>arr[i];
        relorder[arr[i]]= i;
    }

    for(int i=1; i<=n;i++){
        sort(v[i].begin(), v[i].end(), cmp);
    }

    if(bfs(1)==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
