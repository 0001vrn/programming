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

node* search(node *root,int el){
    
    if(root==NULL || root->key==el)
        return root;
    
    if(el < root->key)
        return search(root->left,el);
    else if(el > root->key)
        return search(root->right,el);
    
}

void preOrder(node *root){
    if(root==NULL)
        return;
    cout<<root->key<<' ';
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<' ';
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<' ';
    
}
node *minimum(node *root){
    
    while(root->left!=NULL)
        root=root->left;
    
    return root;
}

node *maximum(node *root){
    
    while(root->right!=NULL)
        root=root->right;
    
    return root;
}
bool isBST(node* root)
{
    static node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->key <= prev->key)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}
node *inorderSuccessor(node *root,node *n){
    if(n->right!=NULL)
        return minimum(n->right);
    
    node *succ = NULL;
    
    while(root){
        if(root->key > n->key){
            succ=root;
            root=root->left;
        }    
        else if(n->key > root->key)
            root=root->right;
        else break;
    }
    return succ;
}

int main(){
    
    node *root=NULL;
    root=insert(root,10);
    insert(root,2);
    insert(root,1);
    insert(root,13);
    insert(root,4);
    insert(root,15);
    
    cout<<"\nPreorder : ";
    preOrder(root);
    cout<<"\nInorder : ";
    inorder(root);
    cout<<"\nPostorder : ";
    postorder(root);
    
    cout<<"\nSearch : "<<search(root,4)->key;
    
    cout<<"\nMinimum : "<<minimum(root)->key;
    cout<<"\nMaximum : "<<maximum(root)->key;
    cout<<"\nisBST : ";
    isBST(root)?cout<<"Yes":cout<<"No";
    node *tmp=root->right;
    cout<<"\nInorder Successor of "<<tmp->key<<" : "<<inorderSuccessor(root,tmp)->key;
    
    
    
    return 0;
}