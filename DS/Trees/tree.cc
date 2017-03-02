#include <iostream>
#include <queue>
#include <stack>
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

int countLeafNodes(node *root){
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;
    else 
    return countLeafNodes(root->left)+countLeafNodes(root->right);
}

void printSpiralLevel(node *root,int level,bool flag){
    if(root==NULL)
    return;
    
    if(level==1)
        cout<<root->data<<' ';
    else if(level>1)
    {
        if(flag){
            printSpiralLevel(root->left,level-1,flag);
            printSpiralLevel(root->right,level-1,flag);
            
        }else{
            printSpiralLevel(root->right,level-1,flag);
             printSpiralLevel(root->left,level-1,flag);
            
        }
    }
}


void printSpiralRecursive(node *root){
    int h=heigtOfTree(root);
    
    bool flag=false;
    
    for(int i=1;i<=h;i++)
    {
        printSpiralLevel(root,i,flag);
        flag=!flag;
    }
}
void printSpiralIterative(node *root){
    stack<node *> s1;
    stack<node *> s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
        
        while(!s1.empty()){
            node *tmp=s1.top();
            s1.pop();
            cout<<tmp->data<<' ';
            //right is pushed first
            if(tmp->right)
            s2.push(tmp->right);
            if(tmp->left)
            s2.push(tmp->left);
        }
        
        while(!s2.empty()){
            node *tmp=s2.top();
            s2.pop();
            cout<<tmp->data<<' ';
            if(tmp->left)
            s1.push(tmp->left);
            if(tmp->right)
            s1.push(tmp->right);
        }
    }
    
}

bool areIdenticalIterative(node *root1,node *root2){
    
    if(!root1 && !root2)
    return true;
    
    if(!root1 || !root2)
    return false;
    
    queue<node *> q1,q2;
    
    q1.push(root1);
    q2.push(root2);
    
    while(!q1.empty() && !q2.empty()){
        node *n1=q1.front();
        node *n2=q2.front();
        
        if(n1->data!=n2->data)
        return false;
        
        q1.pop();q2.pop();
        
        if(n1->left && n2->left){
            q1.push(n1->left);
            q2.push(n2->left);
        }
        else if (n1->left || n2->left)
            return false;
            
        if (n1->right && n2->right)
        {
            q1.push(n1->right);
            q2.push(n2->right);
        }
        else if (n1->right || n2->right)
            return false;
        
    }
    return true;
    
}

int diameter(node *root){
    if(root==NULL)return 0;
    
    int lHeight = heigtOfTree(root->left);
    int rHeight = heigtOfTree(root->right);
    
    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);
    
    return max(lHeight +rHeight + 1,max(lDiameter,rDiameter));
}

int diameterOptUtil(node *root,int *height){
    int lh=0;
    int rh=0;
    
    int lDiameter=0;
    int rDiameter=0;
    
    if(root==NULL)
    {
    *height=0;
    return 0;
    }
    
    /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
    lDiameter = diameterOptUtil(root->left, &lh);
    rDiameter = diameterOptUtil(root->right, &rh);
  
    /* Height of current node is max of heights of left and
     right subtrees plus 1*/
     *height = max(lh, rh) + 1;
  
    return max(lh + rh + 1, max(lDiameter, rDiameter));
    
    
}
int diameterOpt(node *root){
    int height=0;
    return diameterOptUtil(root,&height);
}

bool isBalanced(node *root){
    int lh,rh;
    if(root==NULL)
    return true;
    
    lh=heigtOfTree(root->left);
    rh=heigtOfTree(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
    return true;
    
    return false;
}

bool isBalancedOptUtil(node *root,int *height){
    int lh=0;int rh=0;
    int l=0;int r=0;
    if(root==NULL){
        *height=0;
        return 1;
    }
    
    l=isBalancedOptUtil(root->left,&lh);
    r=isBalancedOptUtil(root->right,&rh);
    
    *height=max(lh,rh)+1;
    
    if(abs(lh-rh)>=2)
    return 0;
    else return l&&r;
    
    
}
bool isBalancedOpt(node *root){
    int height=0;
    return isBalancedOptUtil(root,&height);
    
}

bool hasPathSum(node *root,int sum){
    if(root==NULL){
        return sum==0;
    }
    else{
        bool ans=0;
        int subSum=sum-root->data;
        /* If we reach a leaf node and sum becomes 0 then return true*/
        if ( subSum == 0 && root->left == NULL && root->right == NULL )
            return 1;
  
        if(root->left)
            ans = ans || hasPathSum(root->left, subSum);
        if(root->right)
            ans = ans || hasPathSum(root->right, subSum);
  
        return ans;
    }
}

bool printAncestorsOfNode(node *root,int key){
    if(root==NULL)
    return false;
    
    if(root->data==key)
    return true;
    
    if(printAncestorsOfNode(root->left,key)||printAncestorsOfNode(root->right,key))
    {
        cout<<root->data<<' ';
        return true;
    }
    
    return false;
}
int sum(node *root){
    
    if(root==NULL)
    return 0;
    else
    return sum(root->left)+ root->data +sum(root->right);
}

bool isSumTree(node *root){
    int ls,rs;
    
    if(root==NULL || root->left==NULL && root->right==NULL)
    return 1;
    
    ls=sum(root->left);
    rs=sum(root->right);
    
    if(root->data==ls+rs && isSumTree(root->left) && isSumTree(root->right))
    return 1;
    
    return 0;
}
bool isLeaf(node *root){
    if(root==NULL)
    return 0;
    
    if(root->left==NULL && root->right==NULL)
    return 1;
    
    return 0;
}
bool isSumTreeOpt(node *root){
    
    int ls,rs;
    
    if(root==NULL || isLeaf(root))
    return 1;
    
    if(isSumTreeOpt(root->left) && isSumTree(root->right)){
        
        if(root->left==NULL)
            ls=0;
        else if(isLeaf(root->left))
            ls=root->left->data;
        else
            ls=2*root->left->data;
            
        if(root->right==NULL)
            rs=0;
        else if(isLeaf(root->right))
            rs=root->right->data;
        else 
            rs=2*root->right->data;
            
        return (root->data==ls+rs);
    }
    return 0;
}

int main(){

    node *root          =new node(26);
    root->left          =new node(10);
    root->right         =new node(3);
    root->left->left    =new node(4);
    root->left->right   =new node(6);
    root->right->right  =new node(3);
    root->right->left   =new node(0);
    
    cout<<"\nPreorder : ";
    preOrder(root);
    //Time Complexity - O(n)
    cout<<"\nPostorder : ";
    postOrder(root);
    //Time Complexity - O(n)
    cout<<"\nInorder : ";
    inOrder(root);
    //Time Complexity - O(n)
    cout<<"\nSize of Tree : "<<sizeOfTree(root)<<endl;
    //Time Complexity - O(n)
    
    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    
    areIdentical(root,root2)?cout<<"Yes\n":cout<<"No\n";
    //Time Complexity - O(m) if m < n 
    // m is # of nodes is tree1 and n is # of nodes in tree2
    
    areIdenticalIterative(root,root2)?cout<<"Yes\n":cout<<"No\n";
    //Time Complexity - O(m + n)  
    
    
    cout<<"Height : "<<heigtOfTree(root)<<endl;
    //Time Complexity - O(n)
    
    //Delete Tree always use Post order as you need to delete child node before parent
    //deleteTree(root);
    //mirror(root);
    
    //cout<<"Inorder : ";
    //inOrder(root);
    cout<<"\nRoot to Leaf Paths : \n";
    printRootToLeafPaths(root);
    //Time Complexity - O(n)
    
    cout << "\nLCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    //Time Complexity - O(n)
    
    //node *head = bTreeToCList(root);
    //display(head);
    
    cout<<"\nLevel order : ";
    printLevelOrder(root);
    //Time Complexity - O(n^2) in case of skewed trees
    
    cout<<"\nLevel order using queue : ";
    printLevelOrderUsingQueue(root);
    //Time Complexity - O(n)
    
    cout<<"\n# of Leaf nodes : "<<countLeafNodes(root);
    //Time Complexity - O(n)
    
    cout<<"\nSpiral Order Recursive : ";
    printSpiralRecursive(root);
    //Time Complexity - O(n^2) in case of skewed trees
    
    cout<<"\nSpiral Order Iterative : ";
    printSpiralIterative(root);
    //Time Complexity - O(n)
    
    cout<<"\nDiameter : "<<diameter(root);
    //Time Complexity - O(n^2)
    
    cout<<"\nDiameter : "<<diameterOpt(root);
    //Time Complexity - O(n)
    
    isBalanced(root)?cout<<"\nYes":cout<<"\nNo";
    //Time Complexity: O(n^2) Worst case occurs in case of skewed tree.
    
    isBalancedOpt(root)?cout<<"\nYes":cout<<"\nNo";
    //Time Complexity: O(n)
    
    hasPathSum(root,17)?cout<<"\nYes":cout<<"\nNo";
    //Time Complexity - O(n)
    
    cout<<"\nAncestors of 4 are : ";
    printAncestorsOfNode(root,7);
    //Time Complexity - O(n)
    
    isSumTree(root)?cout<<"\nYes":cout<<"\nNo";
    //Time Complexity: O(n^2) in worst case. Worst case occurs for a skewed tree.
    
    isSumTreeOpt(root)?cout<<"\nYes":cout<<"\nNo";
    //Time Complexity: O(n)
    
    
    return 0;
}