#include<bits/stdc++.h>
using namespace std;

#define null NULL

struct node{
    int leaf;
    node* child[3];

    node(){
        leaf=0;
        for(int i=0;i<3;i++){
            child[i]= null;
        }
    }
};

node* root= new node();
int current_length=0;

void insert(char str[], int pos, node* root){
    if(pos==current_length){
        root->leaf=1;
        return;
    }

    int id= str[pos]- 'a';

    if(root->child[id]== null){
        node* t= new node();
        root->child[id]= t;
    }

    insert(str,pos+1,root->child[id]);
}

int query(char str[], int pos, node* root, bool mismatch){

    if(root==null) return 0;

    if(pos==current_length){
        if(root->leaf==1)
            return mismatch;
        return 0;
    }

    int id= str[pos]- 'a';

    if(!mismatch){
        for(int i=0;i<3;i++){
            if(query(str,pos+1,root->child[i],1-(i==id)))
                return 1;
        }
    }

    else
        return query(str,pos+1,root->child[id],1);

    return 0;
}


main(){
    int n,q;
    cin>>n>>q;

    char str[1000000];

    while(n--){
        cin>>str;
        current_length= strlen(str);
        insert(str,0,root);
    }

    while(q--){
        cin>>str;
        current_length= strlen(str);
        int res= query(str,0,root,0);

        if(res)
            cout<<"YES";
        else
            cout<<"NO";
        puts("");
    }
}
