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

void push_last(Node* &head,int n){
	Node* new_node=new Node(n);
	Node* temp=head;
	
	while(temp->next!=NULL){
		temp=temp->next;}
		
	temp->next=new_node;
}

int main(){
	Node* head=new Node(0);
	print(head);cout<<endl;
	push_last(head,1);
	push_last(head,2);
	push_last(head,3);
	print(head);cout<<endl;
	
}