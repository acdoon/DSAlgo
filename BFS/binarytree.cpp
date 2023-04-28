#include<iostream>
#include<vector>

using namespace std;

class TreeNode{

        int data;
        TreeNode* left;
        TreeNode* right;
        public: TreeNode(int data):data(data),
                                    left(nullptr),
                                    right(nullptr){}
        int getData(){return data;}
        TreeNode* getLeft(){return left;}
        TreeNode* getRight(){return right;}
        void setLeft(TreeNode* node){ left = node;}
        void setRight(TreeNode* node){ right = node;}
    };

class BinaryTree{


    TreeNode * root;
    public:
    BinaryTree();
    void makeTree(vector<int>& );
    void insert(int);
    bool isEmpty();
    TreeNode* getRoot(){return root;}
};

BinaryTree::BinaryTree():root(nullptr){}
bool BinaryTree::isEmpty(){  return root == nullptr;}
void BinaryTree::makeTree(vector<int>& arr)
    {
        for(int x :  arr){
        insert(x) ;
        }
    }

void BinaryTree::insert(int x){
    if(root == nullptr){
        root = new TreeNode(x);
        return;
    }

    TreeNode* newNode =  new TreeNode(x);

     TreeNode *parent = nullptr;
     TreeNode *tempNode = root;
            while (tempNode != nullptr){
            
                parent = tempNode;
                if (x <= tempNode->getData())
                {
                    tempNode = tempNode->getLeft();
                }
                else
                {
                    tempNode = tempNode->getRight();
                }
            }
            if (x <= parent->getData())
            {
                parent->setLeft(newNode);
            
            }
            else
            {
                parent->setRight( newNode);
            } 
}