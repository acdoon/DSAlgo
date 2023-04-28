#include<queue>
#include<iostream>
#include<vector>
#include "binarytree.cpp"
using namespace std;

BinaryTree*  tree;

void printLevelOrder()
{
	queue<TreeNode> cq, nq;

    if(!tree->isEmpty())
    {
         cq.push(*tree->getRoot());
         while( !cq.empty() && nq.empty())
         {      cout<< "[ ";
                while(!cq.empty())
                {
                    TreeNode node =  cq.front();
                    cout<< node.getData() << " ,";
                    if(node.getLeft() !=nullptr)
                        nq.push(*(node.getLeft()));
                    if(node.getRight() != nullptr)
                        nq.push(*(node.getRight()));
                    cq.pop();
                }
                cout<< "]" << endl;
                cout<< "[ ";
                while(!nq.empty())
                {
                    TreeNode node =  nq.front();
                    cout<< node.getData() << " ,";
                    if(node.getLeft() !=nullptr)
                        cq.push(*(node.getLeft()));
                    if(node.getRight() != nullptr)
                        cq.push(*(node.getRight()));
                    nq.pop();
                }
                cout<< "]" <<endl;
         }
    }

}
int main()
{
     vector<int> list =  { 8,6,12,2,9,14,1,76};
     tree = new BinaryTree();
     tree->makeTree(list);
     printLevelOrder();
    return 0;
}