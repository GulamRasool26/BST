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
           TreeNode* FindMinimum(TreeNode* root)
        {
            TreeNode* current = root;
            while(current->GetLeft() != nullptr)
            {
                current = current->GetLeft();
            }
            return current;
        }
         TreeNode* FindMaximum(TreeNode* root)
        {
            TreeNode* current = root;
            while(current->GetRight() != nullptr)
            {
                current = current->GetRight();
            }
            return current;
        }
          TreeNode* DeleteNode(TreeNode* root, int node) {
        if (root == nullptr) {
            return root;
        }

       
        if (node < root->GetData())
        {
            root->SetLeft(DeleteNode(root->GetLeft(), node));
        } else if (node > root->GetData())
        {
            root->SetRight(DeleteNode(root->GetRight(), node));
        } else 
        {
           
            if (root->GetLeft() == nullptr) {
                TreeNode* temp = root->GetRight();
                delete root;
                return temp;
            } else if (root->GetRight() == nullptr) {
                TreeNode* temp = root->GetLeft();
                delete root;
                return temp;
            }

            // Case 2: Node with two children
            TreeNode* temp = FindMinimum(root->GetRight());
            root->SetData(temp->GetData());
            root->SetRight(DeleteNode(root->GetRight(), temp->GetData()));
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
    cout<<endl<<" Deleting  30....";
    root->DeleteNode(root,30);
    cout<<endl<<"preorder: ";
    root->PreOrder(root);
}