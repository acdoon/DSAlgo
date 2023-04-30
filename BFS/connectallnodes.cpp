/*
The task is to connect all nodes in a binary tree. Connect them from left to 
right so that the next pointer of each node points to the node on its immediate
right. The next pointer of the right-most node at each level should point to 
the first node of the next level in the tree.

Each node in the given binary tree for this problem includes a next pointer,
along with the left and right pointers. Your solution must set the next pointer 
to connect the same level nodes to each other and across levels.
*/

#include<iostream>
#include "binarytree.cpp"
#include <vector>
#include <queue>
using namespace std;
BinaryTree* tree = nullptr;

void connectAllNodes(){
 if( tree && tree->getRoot())
 {
    queue<TreeNode*> now,next;
    now.push(tree->getRoot());
    TreeNode* prev,*curr;
    prev =nullptr;
    while (!now.empty() || !next.empty())
    {
        while(!now.empty()){
            TreeNode* node =  now.front();
            if(prev != nullptr)
                prev->setNext(node);
            now.pop();
            /* if this is last node at last level then
            assign next node as null*/
            if( node->getLeft() == nullptr
                 && node->getRight() ==nullptr
                 && now.empty()
                 && next.empty())
               {
                 node->setNext(nullptr);
               }
            else
                prev = node;
            if( node->getLeft() != nullptr)
                next.push(node->getLeft());
            if( node->getRight() != nullptr)
                next.push(node->getRight()); 

        }

        while(!next.empty())
        {
            TreeNode* node =  next.front();
            if(prev != nullptr)
                prev->setNext(node);
            next.pop();
            /* if this is last node at last level then
            assign next node as null*/
            if( node->getLeft() == nullptr
                 && node->getRight() ==nullptr
                 && now.empty()
                 && next.empty())
               {
                 node->setNext(nullptr);
               }
            else
                prev = node;
            if( node->getLeft() != nullptr)
                now.push(node->getLeft());
            if( node->getRight() != nullptr)
                now.push(node->getRight()); 
        }
    }
 }
}

void printTree2list()
{
    if( tree == nullptr || tree->getRoot() == nullptr)
        return;

    TreeNode* node;
    node = tree->getRoot();
    cout<< "[ ";
    while( node)
    {
        cout << node->getData()<< ",";
        node =  node->getNext();
    }
    cout<< "]"<<endl;
}
int main()
{
    vector<int> list = {8,6,12,2,9,14,1,76};
    tree = new BinaryTree();
    tree->makeTree(list);
    connectAllNodes();
    printTree2list();
    return 0;
}

/*
              8
            6   12
          2  9    14
        1           76
*/