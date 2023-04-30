/*connect all nodes of the same hierarchical level. 
We need to connect them from left to right, 
so that the next pointer of each node points to the node on
its immediate right. The next pointer of the right-most node
at each level will be NULL.*/
#include "binarytree.cpp"
#include <queue>
BinaryTree * tree =nullptr;

void assignNext()
{
    TreeNode* prev;
    TreeNode* cur;
    queue<TreeNode*> now,next;
    if( tree !=nullptr && tree->getRoot() != nullptr)
    {
        cur =  tree->getRoot();
        now.push(cur);
        while(!now.empty() || !next.empty())
        {   
            prev = nullptr;
            while(!now.empty())
            {
                 cur =  now.front();
                 if(prev!=nullptr)
                 {
                    prev->setNext(cur);
                 }
                 now.pop();
                 if(now.front()!=nullptr)
                    prev = cur; 
                 else
                    cur->setNext(nullptr);
                
                if(cur->getLeft()!=nullptr)
                    next.push(cur->getLeft());
                if(cur->getRight()!=nullptr)
                    next.push(cur->getRight());
            }
            prev = nullptr;
            while(!next.empty())
            {
                 cur =  next.front();
                 if(prev!=nullptr)
                 {
                    prev->setNext(cur);
                 }
                 next.pop();
                 //make cur node as previous if queue has next
                 if(next.front()!=nullptr)
                    prev = cur; 
                 else
                    cur->setNext(nullptr);
                
                if(cur->getLeft()!=nullptr)
                    now.push(cur->getLeft());
                if(cur->getRight()!=nullptr)
                    now.push(cur->getRight());
            }
        }
    }
}

void printTreeNextNodes()
{
    if(tree->getRoot() ==  nullptr || tree == nullptr)
        return;
    TreeNode* left = tree->getRoot();
    TreeNode* cur = left;
    while( left != nullptr) 
    {
        while(cur !=nullptr)
        {
            cout << cur->getData() << ", ";
            cur = cur->getNext();
        }
        cout<<endl;
        left =  left->getLeft();
        cur = left;
    }
    
    
}
int main()
{  
    vector<int> list =  { 8,6,12,2,9,14,1,76};
    tree = new BinaryTree();
    tree->makeTree(list);
    assignNext();
    printTreeNextNodes();
    return 0;
}

/*
              8
             6  12
            2  9  14
           1        76
*/