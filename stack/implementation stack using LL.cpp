#include<iostream>
using namespace std;
int top=-1,size=-1;
class Node{
	public:
	int val;
	Node* next;
	Node(int n){
		this->val=n;
		this->next=NULL;}
};

class Stack{
	public:
	int size,top;
	Node* head;
	
	Stack(int n){
		this->size=n;
		this->top=-1;
		this->head=NULL;}
		
	void print(){
		if(top>-1){
			Node* temp=head;
			while(temp){
				cout<<temp->val<<" ";
				temp=temp->next;}}
		else cout<<"No element in stack"<<endl;
	}			
	void push(int value){
		if(size-top<1){
			cout<<"Stack full"<<endl;
			return;}
				
		top++;
		Node* newnode=new Node(value);
		if(top==0) head=newnode;
		else {
			newnode->next=head;
			head=newnode;}
	}
	void pop(){
		
		if(top>-1){	
			top--;
			head=head->next;}
		else if(top==-1)
			cout<<"No element in stack"<<endl;
		}
			
	int topEle(){
		if(top==-1){
			cout<<"no element in stack"<<endl;
			return -1;}
			
		return head->val;}
		
	bool isEmpty(){
		return top!=0;}	
};
int main(){
	Stack obj(5);
	obj.push(3);
	obj.push(2);
	obj.push(1);
	cout<<"top ele-"<<obj.topEle()<<endl;
	obj.print();cout<<endl;
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.print();cout<<endl;
	obj.push(12);
	obj.push(15);
obj.print();cout<<endl;
	
	
}