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
	return root;
}
void invert(Node* p,Node* q){
	if(!p && !q) return;
	if(p && !q){
		Node* node=p;
		q=new Node(p->val);
		p=NULL;
		invert(node->left,q->right);
		invert(node->right,q->left);}
	else if(!p && q){
		Node* node=q;
		p=new Node(q->val);
		q=NULL;
		invert(p->left,node->right);
		invert(p->right,node->left);}
	else{
		swap(p->val,q->val);
		invert(p->left,q->right);
		invert(p->right,q->left);}
	return;	
}
void levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	Node* temp=root;
	
	while(!q.empty()){
		temp=q.front();
		q.pop();
		
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()) q.push(NULL);}
		else{
			cout<<temp->val<<" ";
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);}
	}
}

int main(){
	Node* root=build();
	invert(root->left,root->right);
	levelOrder(root);
	
}

