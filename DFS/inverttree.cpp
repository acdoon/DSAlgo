#include<iostream>
#include"../BFS/binarytree.cpp"

using namespace std;

/*Given the root node of a binary tree, 
convert the binary tree into its mirror image.*/
/*           17
           /    \
          5      19  
        /   \      \
      2       6     23
    /   \     
  1      3   
*/
/*
    step1: PostOrder Traversal to left node
    step2: PostOrder Traversal to right Node
    Step3. Swap leftchild with right child
*/
void  invertTree(TreeNode*  node)
{
       if(!node || (!node->getLeft() && !node->getRight()) )
           return;
       invertTree(node->getLeft());
       invertTree(node->getRight());

       TreeNode* temp =  node->getLeft();
       node->setLeft(node->getRight());
       node->setRight(temp); 
}
int main()
{   vector<int > list = {17,5,6,2,1,3,19,23};
    BinaryTree* tree = new BinaryTree();
    tree->makeTree(list);
    invertTree(tree->getRoot());
    return 0;
}