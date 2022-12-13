#include<iostream>
#include<queue>
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
int x=0;
void find(Node* root,Node* target,int d){
    if(!root) return ;
    if(root==target){
        x=d;return;}
    find(root->left,target,d+1);
    find(root->right,target,d+1);
    return;}
vector<int> ans;
void dis(Node* root,Node* target,int depth,int k){
    if(!root) return;
    if(depth==k && root!=target){
        ans.push_back(root->val);return;}
    else if(depth>k) return;
    cout<<root->val<<" ";
    dis(root->left,target,depth+1,k);
    dis(root->right,target,depth+1,k);
    return;}
    
int main(){
	Node* root=build();
	Node* target=root->left;
	int k=2;
    find(root,target,0);
    cout<<x<<endl;
    dis(target,target,0,k);
    cout<<endl;
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
    dis(root,target,0,abs(k-x));
    
    for(auto i:ans) cout<<i<<" ";
 }
    
	

