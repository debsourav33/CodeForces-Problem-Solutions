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
    #define fr(n) for(int i=0;i<n;i++)
    #define fr1(n) for(int i=1;i<=n;i++)
    #define frj(n) for(int j=0;j<n;j++)
    #define frj1(n) for(int j=1;j<=n;j++)
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

    const int maxn= 1e5+5;

    int n, m, T[maxn], P[maxn][22], Maxi[maxn][22], Mini[maxn][22], L[maxn], par[maxn];
    vector<int> v[maxn];
    map<pii,int> weight;

    struct edge {
        int u, v, w;
        bool operator<(const edge& p) const
        {
            return w < p.w;
        }
    };


    void dfs(int u, int p){
        T[u]= p;
        L[u]= (p>-1) ? L[p]+1 : 1;

        for(int s: v[u]){
            if(s==T[u]) continue;

            dfs(s,u);
        }
    }

    void init_LCA(int n){
        sets(P);

        fr1(n){
            P[i][0]= T[i];

            if(P[i][0]!=-1) {
                Maxi[i][0] = weight[mp(i,T[i])];
                Mini[i][0] = weight[mp(i,T[i])];

                //outii(i,Maxi[i][0]);
                //outii(i,Mini[i][0]);
                //puts("");

            }
        }

        for(int j=1; (1<<j)<n;j++){
            fr1(n)
                if(P[i][j-1]!=-1) {
                    P[i][j] = P[P[i][j - 1]][j - 1];
                    Maxi[i][j]= max(Maxi[i][j-1], Maxi[P[i][j-1]][j-1]);
                    Mini[i][j]= min(Mini[i][j-1], Mini[P[i][j-1]][j-1]);
                }
        }
    }

    pii max_min(int p, int q){
        int tmp, log, i, maxi= 0, mini= 1;

        int fl=0;
        if (L[p] < L[q])
            tmp = p, p = q, q = tmp, fl=1;

        log = 1;
        while (1) {
            int next = log + 1;
            if ((1 << next) > L[p])break;
            log++;

        }

        for (i = log; i >= 0; i--)
            if (L[p] - (1 << i) >= L[q]) {
                if(fl==1)
                    maxi= max(maxi,Maxi[p][i]);
                else
                    mini= min(mini,Mini[p][i]);

                p = P[p][i];
            }

        if (p == q)  return mp(maxi,mini);

        /*
        if(fl)
            return mp(mini,maxi);
        else
            return mp(maxi,mini);
        */


        for (i = log; i >= 0; i--)
            if (P[p][i] != -1 && P[p][i] != P[q][i]) {
                if(fl==1) {
                    maxi = max(maxi, Maxi[p][i]);
                    mini = min(mini, Mini[q][i]);
                }
                else {
                    maxi = max(maxi, Maxi[q][i]);
                    mini = min(mini, Mini[p][i]);
                }

                p = P[p][i], q = P[q][i];
            }

        if(fl==1) {
            maxi = max(maxi, Maxi[p][0]);
            mini = min(mini, Mini[q][0]);
        }
        else{
            maxi = max(maxi, Maxi[q][0]);
            mini = min(mini, Mini[p][0]);
        }



        return mp(maxi,mini);

        if(fl)
            return mp(mini,maxi);
        else
            return mp(maxi,mini);

    }

    main(){
        si(n);
        fr(n-1) {
            int x, y, w;
            sii(x, y);
            v[x].pb(y);
            v[y].pb(x);

            weight[mp(x,y)]= 1;
            weight[mp(y,x)]= 0;
        }

        L[1] = 0;
        dfs(1, -1);

        init_LCA(n);

        int q, x, y;
        si(q);

        while (q--) {
            sii(x, y);
            pii p= max_min(x,y);

            if(p.ff>0 || p.ss<1)  puts("No");
            else  puts("Yes");
        }
    }

    /*
    8
     1 3
     3 2 3 4 3 5
     4 6 7 4
     8 5


     */
