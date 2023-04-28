#include<iostream>
#include <vector>
#include "binarytree.cpp"
#include <queue>
#include <stack>
using namespace std;
BinaryTree* tree = nullptr;


void printZigZag()
{
    if(tree != nullptr &&  !tree->isEmpty())
    {
        queue<TreeNode*> cur;
        stack<TreeNode*> next;

        cur.push(tree->getRoot());

        while( !cur.empty() || !next.empty())
        {
           cout<<"[ ";
           while(!cur.empty())
           {
              TreeNode * node =  cur.front();
              cout<<node->getData()<<", ";

              if(node->getLeft() != nullptr)
              {
                next.push(node->getLeft());
              }
              if(node->getRight() != nullptr){
                next.push(node->getRight());
              }
              cur.pop();
           }
           cout<< "]";
           cout<<"[ ";
           while(!next.empty())
           {
              TreeNode * node =  next.top();
              cout<<node->getData()<<", ";

              if(node->getLeft() != nullptr)
              {
                cur.push(node->getLeft());
              }
              if(node->getRight() != nullptr){
                cur.push(node->getRight());
              }
              next.pop();
           }
           cout<< "]";
        }

    }
}

int main()
{
     vector<int> list =  { 8,6,12,2,9,14,1,76};
     tree = new BinaryTree();
     tree->makeTree(list);
     printZigZag();
    return 0;
}