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
		this->left=NULL;
		this->right=NULL;}
		
};
Node* build(Node* root){
	int val;
	cout<<"enter val "<<endl;
	cin>>val;
	root=new Node(val);
	if(val==-1) return NULL;
	
	cout<<"insert left of "<<val;
	root->left=build(root->left);
	
	cout<<"insert right of "<<val;
	root->right=build(root->right);
	return root;
}
void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	Node* temp=root;
	while(!q.empty()){
		temp=q.front();
		if(q.front()) cout<<q.front()->val<<" ";
		else{
			cout<<"no node";
			return;}
		q.pop();
		
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
}
int main(){
	Node* root=NULL;
	build(root);
	levelOrder(root);
}