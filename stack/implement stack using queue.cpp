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
		
	void push(int val){
		if(q1.size()==size){
			cout<<"overflow";
			return;}
		q1.push(val);}
		
	void copyToQ1(){
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();}}	
				 
	void pop(){
		if(q1.size()==1) { q1.pop();return;}
		q2.push(q1.front());
		q1.pop();
		pop();
		copyToQ1();}
		
	int topEle(){
		return q1.back();}
		
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
	
	obj.print(); cout<<endl;
	cout<<obj.topEle()<<endl;
	obj.pop();
	obj.push(4);
	obj.push(5);
	obj.pop();
	cout<<endl; obj.print(); cout<<endl;
	cout<<obj.topEle()<<endl;

	cout<<obj.topEle();
	
	
}