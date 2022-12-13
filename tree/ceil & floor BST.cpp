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
int ceil=-1;
void ceilFun(Node* root,int target){
	while(root){
		if(root->val==target){
			ceil=target;
			return;}
		else if(root->val>target){
			ceil=root->val;
			root=root->left;}
		else root=root->right;}
}
int floor=-1;
void floorFun(Node* root,int target){
	while(root){
		if(root->val==target){
			floor=target;
			return;}
		else if(root->val<target){
			floor=root->val;
			root=root->right;}
		else root=root->left;
		}
}
int main(){
	Node* root=build();
	
	ceilFun(root,5);
	cout<<ceil<<" ";
	
	floorFun(root,5);
	cout<<floor;
}