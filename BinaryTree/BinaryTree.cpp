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
/*===============================================================================================*/
//Preorder Built
node* buildtree(){
int d;
cin>>d;     
if(d == -1) return NULL;
node*n = new node(d);
n->left = buildtree(); //calling recursion for left part
n->right = buildtree(); // for right part
return n; //at the end return root
}

/*===============================================================================================*/
//Level order traversal
void Levelorder(node* root){
if(root == NULL) return;
queue<node*> q;
q.push(root);
q.push(NULL); // NULL for printing endline
while(!q.empty()){
node* t = q.front();
if(t == NULL){ //we will push NULL if !q.empty() beacuse we reached the end of that level
    cout<<endl;
    q.pop();
    if(!q.empty()){
        q.push(NULL);
    }
}
else{
q.pop();
cout<<t->data<<" ";
if(t->left) q.push(t->left);
if(t->right) q.push(t->right);
}
}
}
/*===============================================================================================*/
//level order Build
node* BuildBFS(){
int d;
cin>>d;
node* root = new node(d);
queue<node*> q;
q.push(root);
while(!q.empty()){
node* t = q.front();
q.pop();
int a,b;
cin>>a>>b;
if(a!=-1){
t->left = new node(a);
q.push(t->left);
}
if(b!=-1){
t->right = new node(b);
q.push(t->right);
}
}
return root;
}
/*===============================================================================================*/
//Diameter of Tree -> max distance b/w any two nodes
// Time Complexity -> O(n*h) where h is height of tree.

//it's not actuall height function i.e. (max edges from root to leaf)
int height(node* root){ 
if(root == NULL) return 0;  //for actuall height it must return -1
return max(height(root->left),height(root->right))+1;
}

int diameter(node* root){
if(root == NULL) return 0;
int h = height(root->left) + height(root->right);
int d1 = diameter(root->left);
int d2 = diameter(root->right);
return max(h,max(d1,d2));
}
/*===============================================================================================*/
// Better Approach for Diameter O(n)
pair<int,int> DiaHeight(node* root){
if(root == NULL){
int a = 0, b= 0;
return {0,0};
}
pair<int,int> Left = DiaHeight(root->left);
pair<int,int> Right = DiaHeight(root->right);
int h = max(Left.first,Right.first) + 1; //max(h1,h2)+1
int d = max(Left.second,max(Right.second,Left.first+Right.first));
return {h,d}; //first will represent height while second will be diameter
}

/*===============================================================================================*/
    node* lowestCommonAncestor(node* root, node* p, node* q) {
        if(root == NULL) return NULL;
        if(root == p or root == q) return root;
        node* l = lowestCommonAncestor(root->left,p,q);
        node* r = lowestCommonAncestor(root->right,p,q);
        if(l != NULL and r!= NULL) return root; //That's the actall LCS(unless one of them is LCS)
        if(l == NULL and r == NULL) return NULL;
        return l!=NULL?l:r;
    }

/*===============================================================================================*/

int main(){
node* root = buildtree();
//node* root = BuildBFS();
Levelorder(root);
cout<<diameter(root)<<endl;
cout<<DiaHeight(root).second<<endl; //optimised
cout<<lowestCommonAncestor(root,root->left,root->right)->data<<endl;
return 0;
}