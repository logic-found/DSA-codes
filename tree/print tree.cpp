#include<iostream>
#include<queue> 
using namespace std;
class Node{
	public:
	int val;
	Node* left;
	Node* right;
	
	Node(int val){
		this->val=val;
		this->left=this->right=NULL;}
		
};
Node* build(){
	Node* root=NULL;
	int val;
	cin>>val;
	if(val==-1) return NULL;
	root=new Node(val);
	
	cout<<"insert val at left of "<<val;
	root->left=build();
	cout<<"insert val at right of "<<val;
	root->right=build();
	return root;
}
int main(){
	Node* root=new Node(1);
	Node* second=new Node(2);
	Node* third=new Node(3);
	root->left=second;
	root->right=third;
	
	Node* four=new Node(4);
	Node* five=new Node(5);
	second->left=four;
	second->right=five;
	
	Node* six=new Node(6);
	Node* seven=new Node(7);
	third->left=six;
	third->right=seven;
	levelOrder(root);
}