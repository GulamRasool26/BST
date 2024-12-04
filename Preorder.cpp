#include<iostream>
using namespace std;
class TreeNode
{
    private:
        int data;
        TreeNode* Left;
        TreeNode* Right;
    public:
        TreeNode()
        {
            data = 0;
            Left = nullptr;
            Right = nullptr;
        }
        TreeNode(int data)
        {
            this->data = data;
            Left = nullptr;
            Right = nullptr;
        }
        void SetData(int data)
        {
            this->data = data;
        }
        int GetData()
        {
            return data;
        }
        void SetLeft(TreeNode* left)
        {
            this->Left = left;

        }
        TreeNode* GetLeft()
        {
            return Left;
        }
        void SetRight(TreeNode* right)
        {
            this->Right = right;
        }
        TreeNode* GetRight()
        {
            return Right;
        }
        

        TreeNode* InsertNode(TreeNode* root,int data)
        {
            if(root ==  nullptr)
            {
               return  new TreeNode(data);   
            }
            if(data < root->GetData())
            {   
                root->SetLeft(InsertNode(root->GetLeft(),data));        
            }
            else if(data > root->GetData())
            {    
                root->SetRight(InsertNode(root->GetRight(),data));
            }
             return root;
            
        }
        void PreOrder(TreeNode* root)
        {
            if(root == nullptr)
            {
                return;
            }
            cout<<root->GetData()<<" ";
            PreOrder(root->GetLeft());
            PreOrder(root->GetRight());
        }
};
int main ()
{
    TreeNode *root = nullptr;
    int array[] = {100,500,30,10,20,40};
    for(int i = 0; i < 6; i++)
    {
        root = root->InsertNode(root,array[i]);
    }
     cout<<"preorder: ";
    root->PreOrder(root);
}