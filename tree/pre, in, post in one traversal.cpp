#include<iostream>
#include<stack>
#include<vector> 
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
void traversal(Node* root){
	Node* temp=root;
	vector<int> preorder,inorder,postorder;
	
	stack<pair<Node*,int>> st;
	st.push({root,1});
	while(!st.empty()){
		Node* node5=st.top().first;
		if(st.top().second==1){
			preorder.push_back(node->val);
			st.top().second++;
			temp=node->left;}
			
		else if(st.top().second==2){
			inorder.push_back(node->val);
			st.top().second++;
			temp=node->right;}
			
		else{
			postorder.push_back(node->val);
			st.pop();}
		if(temp) st.push({temp,1});
	}
	
	cout<<"preorder: ";
	for(auto i:preorder) cout<<i<<" ";
	cout<<endl;
	
	cout<<"inorder: ";
	for(auto i:inorder) cout<<i<<" ";
	cout<<endl;
	
	cout<<"postorder: ";
	for(auto i:postorder) cout<<i<<" ";
	cout<<endl;
}
int main(){
	Node* root=build();
	traversal(root);
}