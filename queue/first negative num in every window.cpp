#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> nums={2,-1,3,-4,7,8,-7,9};
	int n=nums.size(),i=0,k=3;
	queue<int> q;
	for(i=0;i<k;++i) if(nums[i]<0) q.push(i);
	if(q.empty()) cout<<"0 "<<endl;
	else cout<<nums[q.front()]<<" ";
	i=k;	
	cout<<i<<endl;
	while(i<n){
		while(!q.empty() && i-k>q.front()) q.pop();
		if(nums[i]<0) q.push(i);
		if(q.empty()) cout<<"0 "<<endl;
		else cout<<nums[q.front()]<<" ";
		cout<<"i-- "<<i<<endl;
		++i;}

}