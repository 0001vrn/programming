#include<iostream>
using namespace std;

class node{
  
  public:
  int key;
  node *left;
  node *right;
  node(int k){
      key=k;
      left=right=NULL;
  }
  
};

node* insert(node *root,int el){
    
    if(root==NULL)
        return new node(el);
    if(el < root->key)
        root->left = insert(root->left,el);
    else if(el > root->key)
        root->right = insert(root->right,el);
    
    return root;
}

void preOrder(node *root){
    if(root==NULL)
        return;
    cout<<root->key<<' ';
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    
    node *root=NULL;
    root=insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    
    preOrder(root);
    
    return 0;
}