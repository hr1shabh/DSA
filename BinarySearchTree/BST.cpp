#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
 
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
//===========================================================================//
node* build(node* root, int d){
if(root == NULL){
root = new node(d);
return root;
}
if(root->data > d){
    root->left = build(root->left,d);
}
else 
root->right = build(root->right,d);
return root;
}
//===========================================================================//
void inorder(node* root){
if(root == NULL) return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
//===========================================================================//
bool search(node* root, int d){
if(root == NULL) return 0;
if(root->data == d) return 1;
if(root->data > d){
    return search(root->left,d);
}
else
return search(root->right,d);
}
//===========================================================================//
node* deleteInBST(node* root,int d){
if(root == NULL) return NULL;
if(root->data > d){
    root->left = deleteInBST(root->left,d);
}
else if(root->data < d){
 root->right = deleteInBST(root->right,d);
}
else{
    // 0 child case
if(root->left == NULL and root->right == NULL){
    delete root;
    return NULL;
}
// 1 child case
else if(root->right == NULL and root->left != NULL){
    node* t = root->left;
    delete root;
    return t;
}
else if(root->right != NULL and root->left == NULL){
    node* t = root->right;
    delete root;
    return t;
}
// 2 child case
else{
node* t = root->right;
while(t->left != NULL){
    t = t->left;
}
root->data = t->data;
delete t;
}
}
return root;
}

//===========================================================================//

int main(){
int d; 
cin>>d;
node* root = NULL;
while(d!=-1){
root = build(root,d);
cin>>d;
}
inorder(root);
cin>>d;
//cout<<search(root,d)<<endl;
root = deleteInBST(root,d);
inorder(root);
}
