#include<iostream>
using namespace std;
class Node{
	public:
	int val;
	Node* left;
	Node* right;
	
	Node(int val){
		this->val=val;
		this->left=NULL;
		this->right=NULL;}
		
};
Node* build(){
	Node* root=NULL;
	cout<<"enter val "<<endl;
	int val;
	cin>>val;
	if(val==-1) return NULL;
	
	root=new Node(val);
	
	cout<<"insert left of "<<val;
	root->left=build();
	
	cout<<"insert right of "<<val;
	root->right=build();
	return root;
}
void print(Node* root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
}
void inorder(Node* root){
	if(root==NULL) return;
		
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
void preorder(Node* root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}


int main(){
	Node* root=build();
	print(root);cout<<endl;
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	postorder(root);cout<<endl;
	
}