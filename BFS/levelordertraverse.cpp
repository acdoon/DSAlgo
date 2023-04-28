#include<queue>
#include<iostream>
#include<vector>
using namespace std;



struct Treenode{
    int data;
    Treenode* left;
    Treenode* right;

    Treenode(int  data):data(data),
    left(nullptr),right(nullptr){}
};
Treenode* root = nullptr;

void insert(int x){
    if(root == nullptr){
        root = new Treenode(x);
        return;
    }

    Treenode* newNode =  new Treenode(x);

     Treenode *parent = nullptr;
     Treenode *tempNode = root;
            while (tempNode != nullptr){
            
                parent = tempNode;
                if (x <= tempNode->data)
                {
                    tempNode = tempNode->left;
                }
                else
                {
                    tempNode = tempNode->right;
                }
            }
            if (x <= parent->data)
            {
                parent->left = newNode;
            }
            else
            {
                parent->right = newNode;
            } 
}

void makeTree(vector<int>& arr)
{
    for(int x :  arr){
        insert(x) ;
    }
}


void printLevelOrder()
{
	queue<Treenode> cq, nq;

    if(root != nullptr)
    {
         cq.push(*root);
         while( !cq.empty() && nq.empty())
         {      cout<< "[ ";
                while(!cq.empty())
                {
                    Treenode node =  cq.front();
                    cout<< node.data << " ,";
                    if(node.left !=nullptr)
                        nq.push(*(node.left));
                    if(node.right != nullptr)
                        nq.push(*(node.right));
                    cq.pop();
                }
                cout<< "]" << endl;
                cout<< "[ ";
                while(!nq.empty())
                {
                    Treenode node =  nq.front();
                    cout<< node.data << " ,";
                    if(node.left !=nullptr)
                        cq.push(*(node.left));
                    if(node.right != nullptr)
                        cq.push(*(node.right));
                    nq.pop();
                }
                cout<< "]" <<endl;
         }
    }

}
int main()
{
     vector<int> tree =  { 8,6,12,2,9,14,1,76};
     makeTree(tree);
     printLevelOrder();
    return 0;
}