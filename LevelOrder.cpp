#include<iostream>
using namespace std;

class TreeNode;
class Node
{
    private:
        TreeNode* Data;
        Node* next;
    public:
        Node(TreeNode* node)
        {
            Data = node;
            next = nullptr;
        }
    void SetNext(Node* node)
    {
        next = node;
    }
    Node* GetNext()
    {
        return next;
    }
    TreeNode* GetData()
    {
        return Data;
    }
};
class Queue {

private:
    Node* front;  
    Node* rear;       
public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    ~Queue()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }
    Node* Getfront()
    {
        return front;
    }
 
    void enqueue(TreeNode* treeNode) {
        Node* newNode = new Node(treeNode);

        if (isEmpty()) {
            front = rear = newNode; 
        } else {
            rear->SetNext(newNode);  
            rear = newNode;        
        }
    }
     void dequeue() 
     {
        if (isEmpty()) 
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;      
        front = front->GetNext();        

        delete temp;    

        if (front == nullptr) 
        {    
            rear = nullptr;
        }

    }
    bool isEmpty()
    {
        return front == nullptr;
    }
};
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
          void levelorderTraversal(TreeNode* root)
        { if(root == nullptr)
                {
                    return;
                } 
            Queue q ;
            q.enqueue(root);
            while(!q.isEmpty())
            {
                Node* node = q.Getfront();
                TreeNode* treeNode = node->GetData();
                cout<<(treeNode->GetData())<<" ";
                q.dequeue();
                if(treeNode->GetLeft() != nullptr)
                {
                    q.enqueue(treeNode->GetLeft());
                }
                if(treeNode->GetRight() != nullptr)
                {
                    q.enqueue(treeNode->GetRight());
                }
            }
            
            
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
     cout<<endl<<"levelorder: ";
    root->levelorderTraversal(root);
}