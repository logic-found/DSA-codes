#include<bits/stdc++.h>
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

void parentFun(Node* root,unordered_map<Node*,Node*> &parent){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* curr=q.front();
		q.pop();
		if(curr->left){
			parent[curr->left]=curr;
			q.push(curr->left);}
		if(curr->right){
			parent[curr->right]=curr;
			q.push(curr->right);}
	}
}

int main(){
	Node* root=build();
	unordered_map<Node*,Node*> parent;
	parentFun(root,parent);
	unordered_map<Node*,bool> visited;
	
	Node* target=root->left;	
	queue<Node*> q;
	q.push(target);
	visited[target]=true;
	
	int c=0,k=2;
	while(!q.empty()){
		int n=q.size();
		if(c==k) break;
		++c;
		for(int i=0;i<n;++i){
			Node* curr=q.front();
			q.pop();
			
			if(curr->left && !visited[curr->left]){
				q.push(curr->left);
				visited[curr->left]=true;}
			if(curr->right && !visited[curr->right]){
				q.push(curr->right);
				visited[curr->right]=true;}
			if(parent[curr] && !visited[parent[curr]]){
				q.push(parent[curr]);
				visited[parent[curr]]=true;}
		}}
	vector<int> ans;
	while(!q.empty()){
		ans.push_back(q.front()->val);
		q.pop();}
	
}
