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
		if(st1.empty()) { st1.push(val); return;}
	
		int n=st1.top();
		st1.pop();
		push(val);
		st1.push(n);
		if(!st2.empty()) st2.top()=val;
		else st2.push(val);
	}
		
	void pop(){
		int n=st1.size();
		if(n==0){ cout<<"underflow";return;}
		if(n==1) st2.pop();
		st1.pop();}
		
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