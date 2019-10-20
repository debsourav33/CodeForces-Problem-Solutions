    #include<bits/stdc++.h>
    using namespace std;

    //{
    #define si(a) scanf("%d",&a)
    #define sii(a,b) scanf("%d %d",&a,&b);
    #define siii(a,b,c) scanf("%d %d %d",&a,&b,&c);

    #define sl(a) scanf("%lld",&a)
    #define sll(a,b) scanf("%lld %lld",&a,&b);
    #define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c);

    #define outi(a) printf("%d\n",a)
    #define outii(a,b) printf("%d %d\n",a,b)
    #define outis(a) printf(" %d",a)

    #define outl(a) printf("%lld\n",a)
    #define outll(a,b) printf("%lld %lld\n",a,b)
    #define outls(a) printf(" %lld",a)

    #define cel(n,k) ((n-1)/k+1)
    #define sets(a) memset(a, -1, sizeof(a))
    #define clr(a) memset(a, 0, sizeof(a))
    #define fr(n) for(i64 i=0;i<n;i++)
    #define fr1(n) for(i64 i=1;i<=n;i++)
    #define frj(n) for(i64 j=0;j<n;j++)
    #define frj1(n) for(i64 j=1;j<=n;j++)
    #define pb push_back
    #define all(v) v.begin(),v.end()
    #define mp make_pair
    #define ff first
    #define ss second
    #define INF 10000007
    #define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL);

    typedef long long i64;
    typedef unsigned long long ull;
    typedef pair<int,int> pii;
    typedef pair<long long,long long> pll;
    //}

    const int N= 3e5+5;

    struct node{
        i64 ver, cost, used;
        node(i64 v, i64 w, i64 u){
            ver= v;
            cost= w;
            used= u;
        }
    };

    vector<node> v[N];
    vector<i64> train_dist[N];
    i64 n, dist[N][2], edges, k, d;

    bool operator <(node a, node b){
        return a.cost>b.cost;
    }

    void reset(){
        fr(n)  v[i].clear();
    }

    void dijakstra(i64 source){
        priority_queue <node> q;
        q.push(node(source,0,0));

        fr1(n)
            frj(2)
                dist[i][j]= (i64) 1e17;

        dist[source][0]= 0;

        while(!q.empty())
        {
            i64 u= q.top().ver, u_used= q.top().used, cost= q.top().cost;

            q.pop();

            if(cost!=dist[u][0] && cost!=dist[u][1]) continue;

            fr(v[u].size())
            {
                i64 nd= v[u][i].ver, weight= v[u][i].cost;

                if(!train_dist[nd].empty() && dist[nd][1]>train_dist[nd][0]){
                    q.push(node(nd,train_dist[nd][0],1));
                    dist[nd][1]= train_dist[nd][0];
                }

                if(dist[u][u_used]+ weight < dist[nd][0]){
                    dist[nd][0]= dist[u][u_used]+ weight;
                    q.push(node(nd,dist[nd][0],0));
                }
            }
        }
    }

    main(){
        i64 a, b, w;

        slll(n, edges,k);

        fr1(edges) {
            slll(a, b, w);

            v[a].pb(node(b, w, 0));
            v[b].pb(node(a, w, 0));
        }

        fr1(k) {
            sll(a, w);
            train_dist[a].pb(w);
        }

        fr1(n)  sort(all(train_dist[i]));

        dijakstra(1);
        //puts("done");

        int cnt= 0;

        fr1(n){
            //outi(t);
            //outl(dist[t][0]);

            for(i64 d: train_dist[i]) {
                if (dist[i][0] <= d) cnt += train_dist[i].size();
                else cnt += train_dist[i].size() - 1;

                break;
            }
        }

        outi(cnt);
    }

    /*
     2 2 3
    1 2 2
    2 1 3
    2 5
    2 2
    2 3
     */
