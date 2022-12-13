#include<bits/stdc++.h>
using namespace std;
stack<int> temp;
void position(int ele){
	if(temp.empty()){
		temp.push(ele);return;}
		
	else{
		if(temp.top()>ele){
			int x=temp.top();
			temp.pop();
			position(ele);
			temp.push(x);}
		else{
			temp.push(ele);
			return;}
	}
}

void sort(stack<int> &st){
	if(st.empty()) return;
	else{
		int n=st.top();
		position(n);
		st.pop();
		sort(st);
		st.push(n);}
}

void print(){
	while(!temp.empty()){
		cout<<temp.top()<<" ";
		temp.pop();}
}

int main(){
	stack<int> st;
	st.push(3);
	st.push(4);
	st.push(0);
	st.push(8);
	st.push(1);
	sort(st);
	print();
}