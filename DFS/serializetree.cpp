#include<iostream>
#include <string>
#include <vector>
#include "../BFS/binarytree.cpp"
#include<queue>
using namespace std;
/*
serialize a given binary tree to a file and deserialize 
it back to a tree. Make sure that the original and the 
deserialized trees are identical.

Serialize: Write the tree to a file.
Deserialize: Read from a file and reconstruct the tree in
memory.

Serialize the tree into a list of integers, and then, 
deserialize it back from the list to a tree. For simplicity’s
sake, there’s no need to write the list to the files
*/
/*           17
           /    \
          5      19  
        /   \      \
      2       6     23
    /   \     
  1      3   
*/
/*
    step1: 
*/

vector<string> serializeTree(TreeNode *  node)
{
    vector<string> retval;
    if(node !=nullptr)
    {
        queue<TreeNode*> now;
        now.push(node);
        while(!now.empty() )
        {
             TreeNode* node =  now.front();
             string tmp;
             tmp =  to_string(node->getData());
             retval.push_back(tmp);
             now.pop();
             if( node->getLeft())
               now.push(node->getLeft());
             if(node->getRight())
                now.push(node->getRight());

            if(now.front())
                retval.push_back(",");
        }
    }
    return retval;
}

int main()
{
    vector<int > list = {17,5,6,2,1,3,19,23};
    BinaryTree* tree = new BinaryTree();
    tree->makeTree(list);
    auto vec = serializeTree(tree->getRoot());
    for( auto x: vec)
        cout << x;
    cout<<endl;
    return 0;
}