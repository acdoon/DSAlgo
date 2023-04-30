#include<iostream>
#include<vector>
#include"binarytree.cpp"
#include<map>
#include<queue>
#include<list>
using namespace std;

BinaryTree* tree = nullptr;
map<int,list<TreeNode*>> mp;
void traverseVertical()
{
    if(tree==nullptr || tree->getRoot() ==  nullptr)
        return;

 
  queue<TreeNode*> now,next;
  tree->getRoot()->setlevel(0);
  now.push(tree->getRoot());

  while(!now.empty() || !next.empty()){

    while( !now.empty())
    {
       TreeNode*  node =  now.front();
       list<TreeNode*>& lst = mp[node->getLevel()];
       lst.push_back(node);
       now.pop();
       if(node->getLeft() != nullptr)
       {
           node->getLeft()->setlevel(node->getLevel()-1);
           next.push(node->getLeft());
       }
       if(node->getRight() != nullptr)
       {
           node->getRight()->setlevel(node->getLevel()+1);
           next.push( node->getRight());
       }

    }

    while( !next.empty())
    {
       TreeNode*  node =  next.front();
       list<TreeNode*>& lst = mp[node->getLevel()];
       lst.push_back(node);
       next.pop();
       if(node->getLeft() != nullptr)
       {
           node->getLeft()->setlevel(node->getLevel()-1);
           now.push(node->getLeft());
       }
       if(node->getRight() != nullptr)
       {
           node->getRight()->setlevel(node->getLevel()+1);
           now.push( node->getRight());
       }

    }
  }

}


void printVerticalLevelOrder()
{
    if (mp.empty())
       return ;

 for(auto itr: mp)
     list<TreeNode*> lst = itr.second;
     cout<< " [  " ;
     for(auto x: lst)
     {
         cout<< x->getData() << ", ";
     }
     cout<< "]" << endl;
 
}
int main()
{  
    vector<int> list =  { 8,6,12,2,9,14,1,76};
    tree = new BinaryTree();
    tree->makeTree(list);
    traverseVertical();
    printVerticalLevelOrder();
    return 0;
}

/*
               8
            6       12
        2      9        14
    1                       76
*/