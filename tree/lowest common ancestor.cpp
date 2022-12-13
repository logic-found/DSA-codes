#include<iostream>
#include<stack>
#include<map>
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
map<int,int> mp;
int ans=0;
bool fun(stack<int> st){
	if(st.empty()) return false;
	
	int n=st.top();
	st.pop();
	cout<<n<<endl;
	if(mp.find(n)!=mp.end()){
		ans=n;return true;}
	else mp[n]=1;
	bool a=fun(st);
	cout<<"pus: "<<n<<endl;
	st.push(n);
	return a;
}
int x=0;

int LCA(Node* root,int p,int q,stack<int> st){
	if(!root) return false;;
	
	st.push(root->val);
	
	if(root->val==p || root->val==q){
		bool x=fun(st);
		cout<<"x: "<<x<<endl;
		return x;}
		
	bool a=LCA(root->left,p,q,st);
	if(a) return true;
	bool b=LCA(root->right,p,q,st);
	 if(b) return true;;
	
	
}
int main(){
	Node* root=build();
	stack<int> st;
	LCA(root,5,7,st);
	cout<<"ans"<<ans<<endl;
	cout<<"map"<<endl;
	for(auto [key,val]:mp) cout<<key<<endl;
	
}