// Java program to demonstrate insert operation in binary search tree
class BinarySearchTree {
 
    /* Class containing left and right child of current node and key value*/
    class Node {
        int key;
        Node left, right;
 
        public Node(int item) {
            key = item;
            left = right = null;
        }
    }
 
    // Root of BST
    Node root;
 
    // Constructor
    BinarySearchTree() { 
        root = null; 
    }
 
    // This method mainly calls insertRec()
    void insert(int key) {
       root = insertRec(root, key);
    }
     
    /* A recursive function to insert a new key in BST */
    Node insertRec(Node root, int key) {
 
        /* If the tree is empty, return a new node */
        if (root == null) {
            root = new Node(key);
            return root;
        }
 
        /* Otherwise, recur down the tree */
        if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);
 
        /* return the (unchanged) node pointer */
        return root;
    }
 
    // This method mainly calls InorderRec()
    void inorder()  {
       inorderRec(root);
    }
 
    // A utility function to do inorder traversal of BST
    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.println(root.key);
            inorderRec(root.right);
        }
    }
    
    public int getMaxDepth(){
        return maxDepth(root);
    }
 
    public int maxDepth(Node root){
         if(root == null){
             return 0;
         }
         return 1+Math.max(maxDepth(root.left),maxDepth(root.right));
    }
    
    public int getMinDepth(){
        return minDepth(root);
    }
    public int minDepth(Node root){
         if(root == null){
             return 0;
         }
         return 1+Math.min(maxDepth(root.left),maxDepth(root.right));
    }
    
     
    public boolean isBalanced(){
         return  (maxDepth(root) - minDepth(root) <= 1);
    }
 
}