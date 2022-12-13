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
void postorder(Node* root){
	stack<Node*> st;
	Node* temp=root;
	while(temp || !st.empty()){
		if(temp){
			st.push(temp);
			temp=temp->left;}
		else{
			Node* curr=st.top()->right;
			if(curr==NULL){
				curr=st.top();
				cout<<curr->val<<" ";
				st.pop();
				while(!st.empty() && curr==st.top()->right){
					curr=st.top();
					cout<<curr->val<<" ";
					st.pop();}
			}
			else temp=curr;}
	}
}

int main(){
	Node* root=build();
	postorder(root);
}