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
bool DFS(Node* root,int target){
	stack<pair<int,Node*>> st;
	st.push(target,root);
	while(!st.empty()){
		auto[target,node]=st.top();
		st.pop();
		target-=node->val;
		if(!node->left && !node->right && target==0) return true;
		
		if(node->right) st.push(target,node->right);
		if(node->left) st.push(target,node->left);}
	return false;

}
bool BFS(Node* root,int target){
	queue<pair<int,Node*>> q;
	q.push(target,root);
	while(!st.empty()){
		auto[target,node]=q.front();
		q.pop();
		target-=node->val;
		if(!node->left && !node->right && target==0) return true;
		
		if(node->left) q.push(target,node->left);
		if(node->right) q.push(target,node->right);}
	
	return false;
}

int main(){
	Node* root=build();
	cout<<path(root,1);
	
}