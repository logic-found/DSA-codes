#include<bits/stdc++.h>
using namespace std;
int x=INT_MAX;
void getMin(stack<int>&st){
	if(st.empty()) return;
	
	int n=st.top();
	if(x>n) x=n;
	st.pop();
	getMin(st);
	st.push(n);
}
int main(){
stack<int> st;
	st.push(-2);	
	st.push(0);
	st.push(-3);
	getMin(st);
	cout<<x;	
}