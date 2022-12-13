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

int main(){
	Node* root=build();
	queue<pair<Node*,pair<int,int>>> q;
	map<int,pair<int,int>> mp;
	q.push({root,{0,0}});
	while(!q.empty()){
		auto[node,x]=q.front();
		q.pop();
		int lev=x.first,ver=x.second;
		
		if(mp.find(lev)==mp.end()){ mp[lev]={ver,node->val};}
		else {
			auto key=mp.find(lev);
			auto x=key->second;
			if(x.first<ver){
			cout<<x.first<<" "<<ver<<endl;
			mp.erase(lev);
			mp[lev]={ver,node->val};}
		}
		if(node->left) q.push({node->left,{lev+1,ver-1+ver}});
		if(node->right) q.push({node->right,{lev+1,ver+1+ver}});
	}
		
	vector<int> v;
	for(auto [key,val]:mp){
		v.push_back(val.second);}
	cout<<endl;
	for(auto i:v) cout<<i<<" ";
	return 0;
}
