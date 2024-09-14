#include <iostream>
using namespace std;

#include "TreeNode.h"
#include <queue>
TreeNode<int>* TakeInputLevelWise(){
cout<<"Enter the root node"<<endl;
int root;
cin>>root;
TreeNode<int>* rootNode=new TreeNode<int>(root);
queue<TreeNode<int>*> pendingNodes;
pendingNodes.push(rootNode);
while(!pendingNodes.empty()){
    TreeNode<int>* first=pendingNodes.front();
    pendingNodes.pop();
    cout<<"Enter the number of children of "<<first->data<<":"<<endl;
    int children;
    cin>>children;
    for(int i=0;i<children;i++){
        cout<<"Enter the data of "<<i<<" child of"<<first->data<<":"<<endl;
        int childData;
        cin>>childData;
        TreeNode<int>* child=new TreeNode<int>(childData);
        first->children.push_back(child);
        pendingNodes.push(child);
    }
}
return rootNode;
}
TreeNode<int>* TakeInput(){
int data;
cout<<"Enter the data: "<<endl;
cin>>data;
TreeNode<int>* root=new TreeNode<int>(data);
cout<<"Enter the number of children"<<endl;
int n;
cin>>n;
for(int i=0;i<n;i++){
    TreeNode<int>* child=TakeInput();
    root->children.push_back(child);
}
return root;
}
void print(TreeNode<int>* root){
if(root==nullptr){
    return;
}
cout<<root->data<<' ';
for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<',';
}
cout<<endl;
for(int i=0;i<root->children.size();i++){
    print(root->children[i]);
}
}
void printLevelWise(TreeNode<int>* root) {
    if(root==nullptr){
        return;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* first=pendingNodes.front();
        pendingNodes.pop();
        cout<<first->data<<":";
        int n=first->children.size();
        for(int i=0;i<n;i++){
            TreeNode<int>* child=first->children[i];
            if(i==n-1){
            cout<<child->data;
            }else{
            cout<<child->data<<",";
            }
            pendingNodes.push(child);
        }
        cout<<endl;
    }
}
void printNodesAtDepthD(TreeNode<int>* root,int k){
if(root == nullptr){
    return;
}
if(k == 0){
    cout<<root->data<<endl;
    return;
}
for(int i=0;i<root->children.size();i++){
    printNodesAtDepthD(root->children[i],k-1);
}
return;
}
void preorder(TreeNode<int>* root){
if(root==nullptr){
    return;
}
cout<<root->data<<" ";
for(int i=0;i<root->children.size();i++){
    preorder(root->children[i]);
}
}
void postorder(TreeNode<int>* root){
if(root==nullptr){
    return;
}
for(int i=0;i<root->children.size();i++){
    postorder(root->children[i]);
}
cout<<root->data<<" ";
}
void deleteTree(TreeNode<int>* root){
if(root==nullptr){
    return;
}
for(int i=0;i<root->children.size();i++){
    deleteTree(root->children[i]);
}
delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    TreeNode<int>* root=TakeInputLevelWise();
    /*TreeNode<int>* node1=new TreeNode<int>(2);
    TreeNode<int>* node2=new TreeNode<int>(3);
    TreeNode<int>* node3=new TreeNode<int>(4);
    root->children.push_back(node1);
    root->children.push_back(node2);
    node2->children.push_back(node3);*/
    //preorder(root);
    //cout<<endl;
    //postorder(root);
    //To-Do delete tree
    //deleteTree(root);
    delete root;

}
