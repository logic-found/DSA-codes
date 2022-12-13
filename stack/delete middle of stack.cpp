#include<bits/stdc++.h>
using namespace std;
void solve(stack<int> &st,int size,int count){
	if(count==size/2){
		st.pop();
		return;}
	int n=st.top();
	st.pop();
	solve(st,size,count+1);
	st.push(n);
}
int main(){
	stack<int> st;
		st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	solve(st,st.size(),0);
	
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}