using namespace std;
class BST{
BinaryTreeNode<int>* root;
bool hasData(BinaryTreeNode<int>* root,int data){
    if(root==nullptr){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(root->data>data){
        return hasData(root->left,data);
    }else{
        return hasData(root->right,data);
    }
    }
BinaryTreeNode<int>* insertRoot(BinaryTreeNode<int>* root,int data){
        if(root==nullptr){
            BinaryTreeNode<int>* ans=new BinaryTreeNode<int>(data);
            return ans;
        }
        if(root->data>=data){
            root->left=insertRoot(root->left,data);
        }else{
        root->right=insertRoot(root->right,data);
        }
        return root;
    }
    BinaryTreeNode<int>* deleteRoot(BinaryTreeNode<int>* root,int data){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==data){
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left!=nullptr && root->right==nullptr){
            BinaryTreeNode<int>* newNode=root->left;
            root->left=nullptr;
            delete root;
            return newNode;
        }
        else if(root->left==nullptr && root->right!=nullptr){
            BinaryTreeNode<int>* newNode=root->right;
            root->right=nullptr;
            delete root;
            return newNode;
        }
        else{
            BinaryTreeNode<int>* minNode=root->right;
            while(minNode->left!=nullptr){
                minNode=minNode->left;
            }
            root->data = minNode->data;
            root->right = deleteRoot(root->right, minNode->data);
            return root;
        }
    }else if(root->data>data){
        root->left=deleteRoot(root->left,data);
    }else{
        root->right=deleteRoot(root->right,data);
    }
    return root;
    }
    void print2(BinaryTreeNode<int>* root){
        if(root==nullptr){
        return;
    }
     cout<<root->data<<":";
     if(root->left!=nullptr){
         cout<<"L:"<<root->left->data<<",";
     }
     if(root->right!=nullptr){
        cout<<"R:"<<root->right->data;
     }
     cout<<endl;
     print2(root->left);
     print2(root->right);
    }
public:
    BST(){
    root=nullptr;
    }
    ~BST(){
    delete root;
    }
    void insertRoot(int data){
        this->root=insertRoot(this->root,data);
    }
    void deleteRoot(int data){
        this->root=deleteRoot(this->root,data);
    }
    bool hasData(int data){
    return hasData(this->root,data);
    }
    void print(){
        print2(this->root);
    }
};
