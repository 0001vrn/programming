#include <iostream>
#include <queue>
using namespace std;

struct node{
    
    
    int data;
    node *left;
    node *right;
    
    node(int d){
        data=d;
        left=right=NULL;
    }
    
};




void preOrder(node *root){
    if(root==NULL)
    return;
    
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(node *root){
    if(root==NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<' ';
    
    
}

void inOrder(node *root){
    
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<' ';
    inOrder(root->right);

    
}

int sizeOfTree(node *root){
    if(root==NULL)
    return 0;
    else
    return (sizeOfTree(root->left) + 1 + sizeOfTree(root->right));
}

int areIdentical(node *a,node *b){
    /*1. both empty */
    if (a==NULL && b==NULL)
        return 1;
 
    /* 2. both non-empty -> compare them */
    if (a!=NULL && b!=NULL)
    {
        return
        (
            a->data == b->data &&
            areIdentical(a->left, b->left) &&
            areIdentical(a->right, b->right)
        );
    }
     
    /* 3. one empty, one not -> false */
    return 0;
}

int heigtOfTree(node *root){
    if(root==NULL)
    return 0;
    else
    {
        int lDpeth = heigtOfTree(root->left);
        int rDepth = heigtOfTree(root->right);
        return max(lDpeth,rDepth)+1;
    }
}

void deleteTree(node *root){
    if(root==NULL)
    return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    
    cout<<root->data<<' ';
    
    delete root;
    
}

void mirror(node *root){
    if(root==NULL)
    return;
    else{
        node *tmp;
        
        mirror(root->left);
        mirror(root->right);
        
        tmp=root->left;
        root->left=root->right;
        root->right=tmp;
    }
    
}
int path[1000];
int pathlen=0;

void print(int path[],int pathlen){
    for(int i=0;i<pathlen;i++)
        cout<<path[i]<<' ';
    cout<<endl;    
}
void printPaths(node *root,int path[],int pathlen){
    if(root!=NULL){
        path[pathlen]=root->data;
        pathlen++;
    }
    if(root->left==NULL && root->right==NULL)
        print(path,pathlen);
    else {
        printPaths(root->left,path,pathlen);
        printPaths(root->right,path,pathlen);
    }
}

void printRootToLeafPaths(node *root){
    printPaths(root,path,pathlen);
}

node *findLCA(node *root,int n1,int n2){
    
    if(root==NULL)
    return NULL;
    
    if( root->data == n1 || root->data == n2 )
    return root;
    
     // Look for keys in left and right subtrees
    node *left_lca  = findLCA(root->left, n1, n2);
    node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
    
    
}
node *concatenate(node *a, node *b)
{
    // If either of the list is empty
    // then return the other list
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
 
    // Store the last Node of left List
    node *aEnd = a->left;
 
    // Store the last Node of right List
    node *bEnd = b->left;
 
    //join heads
    a->left=bEnd;
    bEnd->right=a;
    
    //join tails
    aEnd->right=b;
    b->left=aEnd;
    
    return a;
}


node *bTreeToCList(node *root){
    if(root==NULL)
    return NULL;
    
    node *left=bTreeToCList(root->left);
    node *right=bTreeToCList(root->right);
    
    root->left=root->right=root;
    
    return concatenate(concatenate(left,root),right);
}
void display(node *head)
{
    cout << "\nCircular Linked List is :\n";
    node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}
void bTreeToDLL(node *root){
    
    queue<node *> q;
    q.push(root);
    node *last=NULL;
    node *pres=NULL;
    while(!q.empty()){
        
        root = q.front();q.pop();
        
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        
        root->left=last;
        root->right=q.front();
        last = root;
    }
    
    
}
void traverse(node *head){
    node *itr=head;
    while(itr){
        cout<<itr->data<<"->";
        itr=itr->right;
    }
}
void printGivenLevel(node *root,int level){
    if(root==NULL)return;
    
    if(level==1)
        cout<<root->data<<' ';
    else if(level>1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
    
}
void printLevelOrder(node *root){
    int h = heigtOfTree(root);
    for(int d=1;d<=h;d++)
        printGivenLevel(root,d);
}

void printLevelOrderUsingQueue(node *root){
    queue<node *> q;
    
    q.push(root);
    
    while(!q.empty()){
        
        cout<<q.front()->data<<' ';
        
        root = q.front();
        q.pop();
        
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
    }
    
}

int main(){

    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    
    cout<<"\nPreorder : ";
    preOrder(root);
    cout<<"\nPostorder : ";
    postOrder(root);
    cout<<"\nInorder : ";
    inOrder(root);
    cout<<"\nSize of Tree : "<<sizeOfTree(root)<<endl;
    
    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    
    cout<<"Identical : "<<areIdentical(root,root2)<<endl;
    
    cout<<"Height : "<<heigtOfTree(root)<<endl;
    
    //Delete Tree always use Post order as you need to delete child node before parent
    //deleteTree(root);
    //mirror(root);
    
    //cout<<"Inorder : ";
    //inOrder(root);
    cout<<"\nRoot to Leaf Paths : \n";
    printRootToLeafPaths(root);
    
    cout << "\nLCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    
    //node *head = bTreeToCList(root);
    //display(head);
    
    cout<<"\nLevel order : ";
    printLevelOrder(root);

    
    cout<<"\nLevel order using queue : ";
    printLevelOrderUsingQueue(root);
    
    
    
    return 0;
}