#include<iostream>
#include<queue> 
using namespace std;
class stk{
	public:
		queue<int> q1;
		queue<int> q2;
		int size;
		
	stk(int size){
		this->size=size;}
	void copy(){
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();}}	
			
	void push(int val){
		if(q1.size()==size){
			cout<<"overflow";return;}
		else if(q1.empty()){
			q1.push(val);return;}
		q2.push(q1.front());
		q1.pop();
		push(val);
		copy();}		 
	void pop(){
		if(q1.empty()){
			cout<<"underflow";
			return;}
		q1.pop();}
		
	int topEle(){
		return q1.front();}
		
	void print(){
		queue<int> dummy(q1);
		
		while(!dummy.empty()){
			cout<<dummy.front()<<" ";
			dummy.pop();}
	}

	
};
int main(){
	stk obj(5);
	obj.push(1);
	obj.push(2);
	cout<<obj.topEle()<<endl;
	obj.pop();
	obj.push(4);
	obj.push(5);
	obj.pop();
	cout<<obj.topEle()<<endl;

	cout<<obj.topEle();
	
	
}