#include<iostream>
#include<stack>
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
	cout<<"enter val ";
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
void postorder(Node* root){
	stack<Node*> st1,st2;
	st1.push(root);
	Node* temp=NULL;
	while(!st1.empty()){
		temp=st1.top();
		st1.pop();
		st2.push(temp);
		if(temp->left) st1.push(temp->left);
		if(temp->right) st1.push(temp->right);
	}
	while(!st2.empty()){
		cout<<st2.top()->val;
		st2.pop();}
}

int main(){
	Node* root=build();
	postorder(root);
}