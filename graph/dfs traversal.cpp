#include<bits/stdc++.h>
using namespace std;

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
	stack<int> st;
	
	for(int i=1;i<=v;++i){
		if(vis[i]==0){
			st.push(i);
			vis[i]=1;
		while(!st.empty()){
			int node=st.top();
			st.pop();
			dfs.push_back(node);
			for(auto x:adj[node]){
				if(vis[x]==0){
					st.push(x);
					vis[x]=1;}
			}
		}
		}
	}
	for(auto i:dfs){
		cout<<i<<" ";}
}