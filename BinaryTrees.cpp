#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "BST_Class.h"
using namespace std;
class IsBSTReturn{
public:
    int maximum;
    int minimum;
    bool check_BST;
};
void print(BinaryTreeNode<int>* root){
if(root==nullptr){
    return;
}
cout<<root->data<<": ";
if(root->left!=nullptr){
    cout<<"L"<<root->left->data<<", ";
}
if(root->right!=nullptr){
    cout<<"R"<<root->right->data;
}
cout<<endl;
print(root->left);
print(root->right);
}
BinaryTreeNode<int>* takeInput(){
cout<<"Enter Data:"<<endl;
int data;
cin>>data;
if(data==-1){
    return nullptr;
}
BinaryTreeNode<int>* root=new BinaryTreeNode<int>(data);
root->left=takeInput();
root->right=takeInput();
return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
cout<<"Enter root data: "<<endl;
int rootData;
cin>>rootData;
if(rootData== -1){
    return nullptr;
}
BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
queue<BinaryTreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(!pendingNodes.empty()){
    BinaryTreeNode<int>* first=pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter left child of "<<first->data<<endl;
    int leftdata;
    cin>>leftdata;
    if(leftdata!=-1){
        BinaryTreeNode<int>* leftchild=new BinaryTreeNode<int>(leftdata);
        first->left=leftchild;
        pendingNodes.push(leftchild);
    }
    cout<<"Enter right child of "<<first->data<<endl;
    int rightdata;
    cin>>rightdata;
    if(rightdata!=-1){
        BinaryTreeNode<int>* rightchild=new BinaryTreeNode<int>(rightdata);
        first->right=rightchild;
        pendingNodes.push(rightchild);
    }
    }
    return root;
}
void printInputLevelWise(BinaryTreeNode<int>* root){
if(root==nullptr){
    return;
}
queue<BinaryTreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(!pendingNodes.empty()){
    BinaryTreeNode<int>* first=pendingNodes.front();
    pendingNodes.pop();
    cout<<first->data<<": ";
    if(first->left!= nullptr){
    cout<<"L"<<first->left->data<<", ";
    pendingNodes.push(first->left);
    }
    if(first->right!=nullptr){
    cout<<"R"<<first->right->data;
    pendingNodes.push(first->right);
    }
    cout<<endl;
}
}
int countNodes(BinaryTreeNode<int>* root){
if(root==nullptr){
    return 0;
}
/*int ans=1;
ans+=countNodes(root->left);
ans+=countNodes(root->right);
return ans;
The above 4 lines of code can be reduced to 1*/
return 1+countNodes(root->left)+ countNodes(root->right);
}
void inorder(BinaryTreeNode<int>* root){
if(root==nullptr){
    return;
}
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
void preorder(BinaryTreeNode<int>* root){
if(root==nullptr){
    return;
}
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
void postorder(BinaryTreeNode<int>* root){
if(root==nullptr){
    return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
BinaryTreeNode<int>* buildTreeHelper(int *in,int* pre,int inS,int inE,int preS,int preE){
if(inS>inE || preS>preE){
    return nullptr;
}
int rootData=pre[preS];
BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
int rootIndex=-1;
for(int i=inS;i<=inE;i++){
    if(in[i]==rootData){
        rootIndex=i;
        break;
    }
}
int lPreS=preS+1;
int lPreE=rootIndex+preS-inS;
int lInS=inS;
int lInE=rootIndex-1;
int rPreS=lPreE+1;
int rPreE=preE;
int rInS=rootIndex+1;
int rInE=inE;
root->left=buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
root->right=buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);
return root;
}
BinaryTreeNode<int>* buildTree(int* in,int* pre,int size_array){
    return buildTreeHelper(in,pre,0,size_array-1,0,size_array-1);
}
BinaryTreeNode<int>* postAndInBuildTreeHelper(int *inorder, int *postorder,int inS,int inE,int postS,int postE){
	if(inS>inE){
		return nullptr;
	}
	int rootData=postorder[postE];
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
	int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
		if(inorder[i]==rootData){
			rootIndex=i;
			break;
		}
	}
	int LInS=inS;
	int LInE=rootIndex-1;
	int LPostS=postS;
	int LPostE=LInE+LPostS-LInS;
	int RInS=rootIndex+1;
	int RInE=inE;
	int RPostS=LPostE+1;
	int RPostE=postE-1;
	root->left=postAndInBuildTreeHelper(inorder,postorder,LInS,LInE,LPostS,LPostE);
	root->right=postAndInBuildTreeHelper(inorder,postorder,RInS,RInE,RPostS,RPostE);
	return root;
}
BinaryTreeNode<int>* postAndInBuildTree(int *inorder, int *postorder, int size_array) {
    // Write your code here
	return postAndInBuildTreeHelper(inorder,postorder,0,size_array-1,0,size_array-1);
}
int height(BinaryTreeNode<int>* root){
if(root==nullptr){
    return 0;
}
 return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int>* root){
if(root==nullptr){
    return 0;
}
int option1=height(root->left)+height(root->right);
int option2=diameter(root->left);
int option3=diameter(root->right);
return max(option1,max(option2,option3));
}
pair<int,int> heightDiameter(BinaryTreeNode<int> *root){
if(root==nullptr){
    pair<int,int> N;
    N.first=0;
    N.second=0;
    return N;
}
pair<int,int> ansleft=heightDiameter(root->left);
pair<int,int> ansright=heightDiameter(root->right);
int lefth=ansleft.first;
int leftd=ansleft.second;
int righth=ansright.first;
int rightd=ansright.second;
int h=1+ max(lefth,righth);
int d=max(lefth+righth,max(rightd,leftd));
pair<int,int> ans;
ans.first=h;
ans.second=d;
return ans;
}
int minimum(BinaryTreeNode<int>* root){
if(root==nullptr){
    return INT_MAX;
}
return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int>* root){
if(root==nullptr){
    return INT_MIN;
}
return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
if (root==nullptr){
    return true;
}
int leftmax=maximum(root->left);
int rightmin=minimum(root->right);
bool output=((leftmax<root->data) && (root->data<=rightmin) && isBST(root->left) && isBST(root->right));
return output;
}
IsBSTReturn* isBST2(BinaryTreeNode<int>* root){
if(root==nullptr){
    IsBSTReturn* N=new IsBSTReturn;
    N->maximum=INT_MIN;
    N->minimum=INT_MAX;
    N->check_BST=true;
    return N;
}
IsBSTReturn* leftOutput=isBST2(root->left);
IsBSTReturn* rightOutput=isBST2(root->right);
IsBSTReturn* output=new IsBSTReturn;
output->maximum=max(root->data,max(leftOutput->maximum,rightOutput->maximum));
output->minimum=min(root->data,min(leftOutput->minimum,rightOutput->minimum));
output->check_BST=(root->data<=rightOutput->minimum) && (root->data>leftOutput->maximum) && leftOutput->check_BST && rightOutput->check_BST;
return output;
}
bool isBST3(BinaryTreeNode<int>* root,int minimum=INT_MIN, int maximum=INT_MAX){
if(root==nullptr){
    return true;
}
if(root->data>maximum || root->data<minimum){
    return false;
}
bool isLeftOk=isBST3(root->left,minimum,root->data-1);
bool isRightOk=isBST3(root->right,root->data,maximum);
return (isLeftOk && isRightOk);
}
vector<int>* getNodeToRootPath(BinaryTreeNode<int>* root,int data){
if(root==nullptr){
    return nullptr;
}
if(root->data==data){
    vector<int>* output=new vector<int>();
    output->push_back(root->data);
    return output;
}
vector<int>* left_Output=getNodeToRootPath(root->left,data);
if(left_Output!=nullptr){
    left_Output->push_back(root->data);
    return left_Output;
}
vector<int>* right_Output=getNodeToRootPath(root->right,data);
if(right_Output!=nullptr){
    right_Output->push_back(root->data);
    return right_Output;
}
return nullptr;
}
//4 2 6 1 10 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 10 -1 11 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    BST root;
    root.insertRoot(10);
    root.insertRoot(5);
    root.insertRoot(2);
    root.insertRoot(7);
    root.insertRoot(20);
    root.insertRoot(15);
    root.deleteRoot(15);
    root.deleteRoot(5);
    cout<<root.hasData(10)<<endl;
    root.print();

/*BinaryTreeNode<int>* root=new BinaryTreeNode<int>(1);
BinaryTreeNode<int>* node1=new BinaryTreeNode<int>(2);
BinaryTreeNode<int>* node2=new BinaryTreeNode<int>(3);
BinaryTreeNode<int>* node3=new BinaryTreeNode<int>(4);
BinaryTreeNode<int>* node4=new BinaryTreeNode<int>(5);
root->left=node1;
root->right=node2;
node1->right=node3;
node3->right=node4;*/
/*int in[9]={4,2,5,1,8,6,9,3,7};
int pre[9]={1,2,4,5,3,6,8,9,7};
int post[9]={4,5,2,8,9,6,7,3,1};
BinaryTreeNode<int>* root=buildTree(in,pre,9);
print(root);
BinaryTreeNode<int>* root1=postAndInBuildTree(in,post,9);
print(root1);*/
/*BinaryTreeNode<int>* root=takeInputLevelWise();
vector<int>* answer=getNodeToRootPath(root,10);
for(int i=0;i<answer->size();i++){
    cout<<answer->at(i)<<endl;
}*/
/*cout<<isBST2(root)->check_BST<<endl;
cout<<isBST3(root)<<endl;*/
/*cout<<diameter(root)<<endl;
BinaryTreeNode<int>* root1=takeInputLevelWise();
cout<<"height: "<<heightDiameter(root1).first<<endl;
cout<<"diameter: "<<heightDiameter(root1).second<<endl;
printInputLevelWise(root1);*/
/*cout<<"postorder: ";
postorder(root);
cout<<endl;
cout<<"preorder: ";
preorder(root);
cout<<endl;
cout<<"inorder: ";
inorder(root);
cout<<endl;*/
//cout<<countNodes(root)<<endl;
//printInputLevelWise(root);
}
