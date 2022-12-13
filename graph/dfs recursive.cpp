#include<bits/stdc++.h>
using namespace std;
void dfs_traversal(int node,vector<int> &vis,vector<int> adj[],vector<int> &dfs){
	vis[node]=1;
	dfs.push_back(node);
	for(auto i:adj[node]){
		if(vis[i]==0) dfs_traversal(i,vis,adj,dfs);
	}
}
int main(){
	int v,e;
	cout<<"enter no of vertex and edges ";
	cin>>v>>e;
	vector<int> adj[v+1];
	for(int i=0;i<e;++i){
		int u,v;
		cout<<"edge "<<endl;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	
	vector<int> vis(v+1,0);
	vector<int> dfs;
	dfs_traversal(1,vis,adj,dfs);
	for(auto i:dfs) cout<<i<<" ";
	
}
