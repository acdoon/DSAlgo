#include "../BFS/binarytree.cpp"
#include<iostream>
#include<vector>
#include<stack>
/*flatten the tree into a linked list using the 
same Tree class. */
/*
    4
   / \
  2   17
 / \  / \
1  3 5  19

*/
/*
    step1: if left child exist
    step2: make right child as temp
    step3: make left child as right 
    step4: make left child as null
    step5:  find the rightmost child of the right child.
    step6: make temp as rightchild of the rightmost child.
    step7: move to right child and repeat step 1. 
*/

void flatenBinaryTree(TreeNode* node)
{
      if(node== nullptr || (node->getLeft()==nullptr && 
        node->getRight() == nullptr))
            return;

     if(node->getLeft() != nullptr)
     {
        TreeNode*  tmp =  node->getRight();
        node->setRight(node->getLeft());
        node->setLeft(nullptr);
        TreeNode* rightmost =  node;
        while(rightmost->getRight())
        {
            rightmost =  rightmost->getRight();
        }
       rightmost->setRight(tmp);
     }
     flatenBinaryTree(node->getRight());

}

void printTree2list(TreeNode* node)
{
    if(node == nullptr)
        return;
    
    while(node!=nullptr)
    {
        cout << node->getData()<< " ,";
       node= node->getRight();
    }
    cout<<endl;
}

BinaryTree* tree =nullptr;
int main()
{
    tree =  new BinaryTree();
    vector<int> list = { 4,2};
    tree->makeTree(list);
    flatenBinaryTree(tree->getRoot());
    printTree2list(tree->getRoot());
    return 0;
}
