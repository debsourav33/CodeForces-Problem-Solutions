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

    const int N= 2e6+5, NN= 2e6+5, m= 1e9+9, p[]= {31,53};

    char s[N], t[N] ;
    i64 pre_hash[N][2], pow_p[N][2], mod_inv_p[N][2];
    int n, no, k, gn;
    map<pll,int> pos;

    i64 compute_hash(char s[], int cnt, int k) {
        i64 hash_value = 0;
        i64 p_pow = 1;
        int n= strlen(s);
        fr(n) {
            char c= s[i];
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p[k]) % m;

            if(cnt==0)  pre_hash[i][k]= hash_value;
        }
        return hash_value;
    }

    i64 exp(i64 b, i64 e, i64 M){
        i64 ans=1;

        while(e){
            if(e&1)  ans= (ans*b) % M;
            b= (b*b) % M;
            e/= 2;
        }

        return ans;
    }

    void pre_calc(int k){
        int n= strlen(s);
        i64 curr_pow = 1;
        pow_p[0][k]= 1;

        fr1(n){
            curr_pow= (curr_pow*p[k])%m;
            pow_p[i][k]=  curr_pow;
        }

        fr(n+1){
            mod_inv_p[i][k]= exp(pow_p[i][k],m-2,m);
        }
    }

    i64 sub_hash(char s[], int i, int j, int k){
        i64 a= 0, b= pre_hash[j][k];
        if(i!=0)  a= pre_hash[i-1][k];

        i64 diff= (b-a+m) % m;
        i64 sub_hashvalue= diff * mod_inv_p[i][k];

        return sub_hashvalue % m;
    }

    set<pll> cnt[N];
    vector<int> v[N];

    void solve(){
        fr(n){
            int par= i%k;

            i64 sh1= sub_hash(s,i,i+k-1,0), sh2= sub_hash(s,i,i+k-1,1);
            if(sh1>sh2)  swap(sh1,sh2);

            //outii(i,pos.count(mp(sh1,sh2)));

            if(pos.count(mp(sh1,sh2))){

                int sz1= cnt[par].size();
                cnt[par].insert(mp(sh1,sh2));
                int sz2= cnt[par].size();

                if(sz2>sz1) v[par].pb(pos[mp(sh1,sh2)]);  //size differs so unique hash has been added
            }

            if(cnt[par].size()==no){
                puts("YES");
                fr(v[par].size())  outis(v[par][i]);
                puts("");

                return;
            }
        }

        puts("NO");
    }

    main(){
        sii(no,k);

        scanf("%s",t);
        int tlen= strlen(t);

        fr(tlen)  s[i]= t[i];
        fr(k)  s[tlen+i]= t[i];

        //fr(no*k+k)  printf("%c",s[i]);  puts("");

        n= tlen+k;

        i64 hash1= compute_hash(s,0,0), hash11= compute_hash(s,0,1);
        pre_calc(0);  pre_calc(1);

        si(gn);
        fr1(gn){
            char g[NN];

            scanf("%s",g);
            i64 hash2= compute_hash(g,1,0), hash22= compute_hash(g,1,1);

            if(hash2>hash22) pos[mp(hash22,hash2)]= i;
            else pos[mp(hash2,hash22)]= i;
        }

        solve();
    }
