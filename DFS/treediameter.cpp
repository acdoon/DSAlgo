#include<iostream>
#include "../BFS/binarytree.cpp"
#include<vector>
/*
            17
           /   \
          5     19  
        /   \     \
      2       6    23
    /   \     
  1      3     

*/
/*
    STEP1:  find height of left subtree
    Step2: find height of right subtree
    step 3: 1+ max( lefth, righth)
    
*/

int  height(TreeNode* node)
{
    if(node == nullptr)
        return 0;
    
    int left=  height(node->getLeft());
    int right = height(node->getRight());

    return 1+ max(left,right);
}

int diamter(TreeNode* root)
{
    if(root == nullptr)
      return 0;
    int left =  height(root->getLeft());
    int right =  height(root->getRight());
    return left+right;
}


int main()
{
    vector<int > list = {17,5,6,2,1,3,19,23};
    BinaryTree* tree = new BinaryTree();
    tree->makeTree(list);
    cout<< "Diameter of the tree is : " << diamter(tree->getRoot());
    return 0;
}