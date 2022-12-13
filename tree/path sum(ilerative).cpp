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
bool path(Node* root,int target){
	stack<pair<int,Node*>> st;
	int sum=0;
	
	while(!st.empty() || root){
		while(root){
			sum+=root->val;
			if(root->right) st.push({sum,root->right});
			if(root->left) root=root->left;
			else break;}
		if(!root->left && !root->right && sum==target) return true;
		else if(st.empty() && !root->left && !root->right) return false;
		else{
			sum=st.top().first;
			root=st.top().second;
			st.pop();}
	}
	return false;

}
int main(){
	Node* root=build();
	cout<<path(root,1);
	
}