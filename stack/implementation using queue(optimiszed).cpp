#include<iostream>
#include<queue> 
using namespace std;
class stk{
	public:
		queue<int> q;
		int size;
		
	stk(int size){
		this->size=size;}
		
	void push(int val){
		int n=q.size();
		q.push(val);
		while(n){
			q.push(q.front());
			q.pop();
			--n;}
	}
	void pop(){
		if(q.empty()){
			cout<<"underflow";
			return;}
		q.pop();}
		
	int topEle(){
		return q.front();}
		
	void print(){
		queue<int> dummy(q);
		
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