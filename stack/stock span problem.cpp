#include<bits/stdc++.h>
using namespace std;
vector<int> v;
stack<int> st;
void stock(vector<int> &arr,int n){
	for(int i=0;i<n;i++){
		if(i==0){
			st.push(i);
			v.push_back(1);
			continue;}
	while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
	if(st.empty()) v.push_back(i+1);
	else v.push_back(i-st.top());
	st.push(i);}
}
int main(){
	vector<int> arr={4,5,3,4,5,3};
	stock(arr,arr.size());
	for(auto i:v) cout<<i<<" ";
}