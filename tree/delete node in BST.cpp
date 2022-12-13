#include<iostream>
using namespace std;
class TreeNode{
	public:
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val){
		this->val=val;
		this->left=NULL;
		this->right=NULL;}
		
};
TreeNode* build(){
	TreeNode* root=NULL;
	cout<<"enter val "<<endl;
	int val;
	cin>>val;
	if(val==-1) return NULL;
	
	root=new TreeNode(val);
	cout<<"insert left of "<<val;
	root->left=build();
	
	cout<<"insert right of "<<val;
	root->right=build();
	return root;
}
void print(TreeNode* root){
	if(root==NULL) return;
	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
}
TreeNode* parent(TreeNode* root){
	if(!root) return NULL;

	if(root->left==target || root->right==target) return root;
	
	TreeNode* a=parent(root->left);
	TreeNode* b=parent(root->right);
	
	if(a) return a;
	else if(b) return b;
	return NULL;}
	
void deleteNode(TreeNode* target){
	if(!target->left && !target->right){
		if(parent->left==target) parent->left=NULL;
		else parent->right=NULL;}
		
	else if(!target->left){
		if(parent->left==target) parent->left=target->right;
		else parent->right=target->right;}
	else if(!target->right){
		if(parent->left==target) parent->left=target->left;
		else parent->right=target->left;
	}
	else{
		TreeNode* node=target->right;
		TreeNode* curr=node;
		while(curr && curr->left){
			if(!curr->left->left) break
			curr=curr->left;}
		TreeNode* change=curr->left;
		if(change){
			node->left=change->right;
			target->val=change->val;
			delete(change);
		}
		else{
			target->val=node->val;
			delete(node);
		}
	
}
}

int main(){
	TreeNode* root=build();
	print(root);
	TreeNode* target=root->left;
	TreeNode* temp=target->right;
	while(temp && temp->left){
		temp=temp->left;
		if(!temp->left->left && !temp->left->right) break;}
		
	TreeNode* curr=temp->left;
	temp->left=NULL;
	
	curr->left=target->left;
	curr->right=target->right;
	target->val=curr->val;
	cout<<endl;
	print(root);
	return 0;
}
