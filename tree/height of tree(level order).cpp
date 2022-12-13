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
	return root;}
int level(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int c=1;
	Node* temp=root;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(!temp){
			if(!q.empty()){
				++c;
				q.push(NULL);}
			else break;
			}
		else{
			if(temp->left) q.push(temp->left);
			if(temp->right)q.push(temp->right);
			}
	}
	return c;
}
int main(){
	Node* root=build();
	int n=level(root);
	cout<<"result "<<n;
}