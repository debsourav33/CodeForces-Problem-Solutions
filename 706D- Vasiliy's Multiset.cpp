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
    //cout<<"inserting "<<id<<endl;
    if(root->child[id]==null){
        node* t= new node();
        root->child[id]= t;
    }

    root->child[id]->cur++;
    insert(num,i-1,root->child[id]);
}

void delet(ll num, ll i, node* root){
    if(i==-1)  return;

    ll id= check(num,i);

    root->child[id]->cur--;
    delet(num,i-1,root->child[id]);
}

ll query(ll num, ll i, node* root){
    if(i==-1)  return num;

    ll id= 1-check(num,i);

    if(root->child[id]==null || root->child[id]->cur==0){
        id= 1-id;
        num= resetbit(num,i);
    }
    else
        num= setbit(num,i);

    query(num,i-1,root->child[id]);
}

void init(ll num, ll i, node* root){
    if(i==-1)  return;
    ll id= check(num,i);
    //cout<<"inserting "<<id<<endl;
    if(root->child[id]==null){
        node* t= new node();
        root->child[id]= t;
    }

    root->child[id]->cur= 300005;
    insert(num,i-1,root->child[id]);
}

main(){
    ll n,q,d,num;
    char choice;
    cin>>n;

    init(0,63,root);

    fr(n){
        cin>>choice>>num;

        if(choice=='+')
            insert(num,63,root);
        else if(choice=='-')
            delet(num,63,root);
        else
            cout<<query(num,63,root)<<endl;
    }

}

/*
11
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
- 9
? 3
? 8
? 11
*/
