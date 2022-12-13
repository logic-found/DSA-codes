#include<iostream>
using namespace std;
class Node{
	public:
		int val;
		Node* next;
	Node(int n){
		this->val=n;
		this->next=NULL;}
};
class LinkedList{
	public:
		Node* head;
		Node* tail;
		
	LinkedList(int n){
		Node* newnode=new Node(n);
		head=tail=newnode;
		tail->next=head;}
	
	void print(){
		Node* temp=head->next;
		cout<<head->val<<" ";
		while(temp!=head){
			cout<<temp->val<<" ";
			temp=temp->next;}
		cout<<"  head--"<<temp->val<<" ";
	}
			
	void push_back(int n){
		Node* newnode=new Node(n);
		newnode->next=head;
		tail->next=newnode;
		tail=tail->next;}
		
	void push_begin(int n){
		Node* newnode=new Node(n);
		newnode->next=head;
		tail->next=newnode;
		head=newnode;}
		
	void delete_last(){
		Node* temp=head;
		while(temp->next!=tail){
			temp=temp->next;}
		Node* node=temp->next;
		tail=temp;
		tail->next=head;
		delete(node);}
		
	void delete_begin(){
		Node* node=head;
		head=head->next;
		tail->next=head;
		delete(node);
	}
	
};
int main(){
	LinkedList obj(0);
	obj.push_back(1);
	obj.push_back(2);
	obj.push_back(3);
	obj.print();cout<<endl;
	obj.push_begin(4);
	obj.push_back(10);
	obj.push_begin(5);
	obj.print();cout<<endl;
	obj.delete_last();
	obj.print();cout<<endl;
	obj.delete_last();
	obj.print();cout<<endl;
	obj.delete_begin();
	obj.print();cout<<endl;
	obj.delete_begin();
	obj.print();cout<<endl;
	
	
	
}
