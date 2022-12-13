#include<iostream>
using namespace std;

class Stack{
	public:
	int size;
	int top;
	int *arr;
	
	Stack(int n){
		this->size=n;
		top=-1;
		arr=new int[n];}
				
	void push(int val){
		if(size-top>1){
			top++;
			arr[top]=val;}
		else cout<<"Stack overflow"<<endl;
	}
	int topEle(){
		if(top!=-1)
			return arr[top];
		else{
			cout<<"stack is empty--";
			return -1;}
	}
	void pop(){
		if(top>=0) top--;
		else cout<<"Stack underflow"<<endl;}
	
	void isEmpty(){
		if(top==-1) cout<<"stack empty"<<endl;
		else cout<<"Not empty"<<endl;}		
		
};

int main(){
	Stack st(3);
	st.pop();
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.isEmpty();
	cout<<st.topEle()<<endl;
	st.pop();
	st.pop();
	st.pop();
	cout<<st.topEle()<<endl;
	
}