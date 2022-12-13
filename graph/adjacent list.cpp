#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e;
	cin>>v>>e;
	vector<int> adj(e+1);
	for(int i=0;i<v;++i){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}