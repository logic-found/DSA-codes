#include<bits/stdc++.h>
using namespace std;

void insertBottom(stack <int>&st,int element){
	if(st.empty()){
		st.push(element);
		return;}
		
	int num=st.top();
	st.pop();
	insertBottom(st,element);
	st.push(num);
}
void solve(stack<int> &st,int size,int count){
	if(count==size){
		return;}
	int n=st.top();
	st.pop();
	solve(st,size,count+1);
	insertBottom(st,n);
	
}
int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	solve(st,st.size(),0);
	
		while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}