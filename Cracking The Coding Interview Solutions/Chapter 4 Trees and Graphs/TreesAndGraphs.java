/*
4.1 Implement a function to check if a tree is balanced. For the purposes of this question,
    a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
    from the root by more than one.

*/
class TreesAndGraphs{
    public static void main(String[] args){
        BinarySearchTree tree = new BinarySearchTree();
 
        /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);
 
        // print inorder traversal of the BST
        tree.inorder();
        System.out.println(tree.getMaxDepth());
        System.out.println(tree.getMinDepth());

        System.out.println(tree.isBalanced());
    }
}