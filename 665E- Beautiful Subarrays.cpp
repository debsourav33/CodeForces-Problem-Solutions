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
#define null NULL

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
//}

struct node{
    ll cur;
    node* child[2];

    node(){
        cur= 0;
        fr(2)
            child[i]= null;
    }
};

struct Trie{
    node* root= new node();

    ll resetbit(ll a, ll i){
        return a & ~(1LL<<i);
    }

    ll setbit(ll a, ll i){
        return a | (1LL<<i);
    }

    bool check(ll mask, ll i){
        return mask & (1LL<<i);
    }

    void insert(ll num, ll i, node* root){
        if(i==-1)  return;
        ll id= check(num,i);

        if(root->child[id]==null){
            node* t= new node();
            root->child[id]= t;
        }

        root->child[id]->cur++;
        insert(num,i-1,root->child[id]);
    }

    ll query(ll num, ll k, ll i, node* root, ll val){
        if(i==-1) return 0;
        if(root==null)  return 0;

        ll bit_n= check(num,i);
        ll bit_k= check(k,i);

        if(bit_k==1){
            if(bit_n==val){
                return 0;
            }
            if(i==0)
                return root->cur;
        }

        if(bit_k==0){
            if(bit_n!=val)
                return root->cur;
            if(i==0)
                return root->cur;
        }

        return query(num,k,i-1,root->child[0],0)+ query(num,k,i-1,root->child[1],1);

    }

    void init(){
        insert(0,63,root);
    }

};



main(){
    Trie T;
    ll n,q,d,num,k, pre= 0, ans= 0;
    cin>>n>>k;

    T.init();

    fr(n){
        cin>>num;

        pre= pre ^ num;

        ans+= T.query(pre,k,63,T.root->child[0],0) + T.query(pre,k,63,T.root->child[1],1);
        T.insert(pre,63,T.root);
    }

    cout<<ans<<endl;
}
