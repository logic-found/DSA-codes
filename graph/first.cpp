#include<bits/stdc++.h>
using namespace std;

int dfs(int node,vector<int>& vis,vector<int>& nums,vector<int> adj[]){
    vis[node]=1;
    long long x=nums[node-1];
    for(auto i:adj[node]){
        if(!vis[i]){
            x*=dfs(i,vis,nums,adj);
        }
    }
    return x;
}

int main(){
	vector<int> nums={3,25,6,14,12,5};
	vector<vector<int>> edge={{1,2},{6,1},{2,5},{4,2},{3,4}};
	vector<vector<int>> quer={{2,2,-1},{1,2,10},{2,2,-1},{2,6,-1},{1,6,10}};

	int n=edge.size();
    vector<int> adj[n+2];
    
    for(auto i:edge){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(n+2,0);
    dfs(1,vis,nums,adj);
    vector<int> ans;
    //	cout<<endl;
    for(auto i:quer){
        if(i[0]==1){
            nums[i[1]-1]=i[2];
            ans.push_back(-1);
        }
        else{
        	vector<int> vis(n+2,0);
        	int num=dfs(i[1],vis,nums,adj),x=0;
        	string s=to_string(num);
        	int i=s.size();--i;
        	while(s[i--]=='0'){
        		++x;
			}
            ans.push_back(x);
        }
    }
    for(auto i:ans) cout<<i<<" ";
    
}