#include<bits/stdc++.h>
using namespace std;
bool bipatite(int node,vector<int>& vis,vector<int> adj[]){
	queue<pair<int,int>> q;
	q.push({node,-1});
	vis[node]=1;
	while(!q.empty()){
		auto[node,parent]=q.front();
		q.pop();
		 
		for(auto i:adj[node]){
			if(vis[i]==-1){
				
				q.push({i,node});
			else if(i!=parent && vis[parent]==vis[i]) return true;
		}
	}
	return false;

}
int main(){
	int v,e;
	cin>>v>>e;
	vector<int> adj[v+1];
	for(int i=0;i<e;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(v+1,-1);
	q.push({0,-1});
	for(int i=0;i<v;++i){
		if(vis[i]==-1)
			if(bipatite(i,vis,adj)){
				cout<<true;
				break;}
		}
	
}