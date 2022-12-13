#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,3,4,2,7};
	int n=5;
	stack<int> st;
	vector<int> v;
	int i=n-1,t=-1;
	while(i>=0){
			if(i==n-1){
				v.push_back(-1);
				i--;continue;}
			else{
				st.push(arr[i+1]);}
				
			while(!st.empty()){
				if(st.top()<=arr[i]){
					st.pop();}
				else{
					v.push_back(st.top());
					break;}
			}
			if(st.empty()) v.push_back(-1);
			i--;}
	reverse(v.begin(),v.end());
	for(auto i:v) cout<<i<<" ";


}