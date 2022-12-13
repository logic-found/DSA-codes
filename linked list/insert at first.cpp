#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
	Node(int data){
		this->data=data;
		this->next=NULL;}
};
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;}
}
void push_begin(Node* &head,int n){
	Node* new_node=new Node(n);
	new_node->next=head;
	head=new_node;
}
void push_last(Node* &head,int n){
	Node* new_node=new Node(n);
	Node* temp=head;
	
	while(temp->next!=NULL){
		temp=temp->next;}
		
	temp->next=new_node;
}

void insertAfter(Node* &head,int position,int n){
	Node* new_node=new Node(n);
	int c=1;
	Node* temp=head;
	while(c<position-1){
		temp=temp->next;c++;}
	new_node->next=temp->next;
	temp->next=new_node;
}

int main(){
	Node* head=new Node(0);

	print(head);cout<<endl;
	
	push_begin(head,1);
	push_begin(head,2);
	push_begin(head,3);
	
	print(head);cout<<endl;
	
	insertAfter(head,2,15);
	
	
	print(head);cout<<endl;
	push_last(head,6);
	push_last(head,7);
	
	
	print(head);cout<<endl;
	
}