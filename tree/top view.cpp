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

int main(){
	Node* root=build();
	queue<pair<Node*,pair<int,int>>> q;
	map<int,pair<int,int>> mp;
	q.push({root,{0,0}});
	while(!st.empty()){
		auto[node,x]=q.front();
		q.pop();
		int ver=x.first,lev=x.second;
		
		if(mp.find(ver)==mp.end()){ mp[ver]={lev,node->val};}
		else {
			auto key=mp.find(ver);
			auto x=key->second;
			if(x.first>lev){
			mp.erase(ver);
			mp[ver]={lev,node->val};}
		}
		if(node->left) q.push({node->left,{ver-1,lev+1}});
		if(node->right) q.push({node->right,{ver+1,lev+1}});
		
	}
		
	vector<int> v;
	for(auto [key,val]:mp){
		v.push_back(val.second);	}
	
	for(auto i:v) cout<<i<<" ";
	return 0;
}
