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
void inorder(Node* root){
	stack<Node*> st;
	Node* temp=root;
	while(temp || !st.empty()){
		while(temp){
			st.push(temp);
			temp=temp->left;}
		if(temp==NULL){
			temp=st.top();
			cout<<temp->val<<" ";
			st.pop();
			temp=temp->right;}
	}
		
}

int main(){
	Node* root=build();
	inorder(root);
}