#include<iostream>
#include<stack>
using namespace std;

class queue{
	public:
		stack<int> st1;
		stack<int> st2;
		int size;
		
	queue(int size){
		this->size=size;}
			
	void push(int val){
		st1.push(val);}
		
	void pop(){
		if(st2.empty()){
			while(!st1.empty()){
				st2.push(st.top());
				st1.pop();
			}
		}}
		
	int front(){
		if(st1.empty()){ cout<<"underflow"; return -1;}
		return st1.top();}
		
	int rear(){
		if(st2.empty()) return -1;
		return st2.top();}
	
};
int main(){
	queue obj(5);
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	cout<<obj.front()<<endl;
	obj.pop();
	
	cout<<obj.rear()<<endl;
	
	cout<<obj.front()<<endl;
	obj.pop();
	
	
	
}