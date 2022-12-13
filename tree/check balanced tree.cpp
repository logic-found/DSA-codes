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
int balanced(Node* root,int l,int r){
	if(!root) return 0;
	l=balanced(root->left,l,r);
	r=balanced(root->right,l,r);
	if(l==-1 || r==-1) return -1;
	if(abs(l-r)>1) return -1;
	return max(l,r)+1;
}
int main(){
	Node* root=build();
	cout<<endl<<balanced(root,0,0);
}