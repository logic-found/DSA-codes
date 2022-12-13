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
void deleteTail(Node* &head){
	Node* temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;}
	temp->next=NULL;	
}
void deleteHead(Node* &head){
	head=head->next;
}
	
void deleteAfter(Node* &head,int position){
	int c=1;
	Node* temp=head;
	while(c<position-1){
		temp=temp->next;c++;}
	temp->next=temp->next->next;
}
int main(){
	Node* head=new Node(7);
	push_begin(head,6);
	push_begin(head,5);
	push_begin(head,4);
	push_begin(head,3);
	push_begin(head,2);
	push_begin(head,1);
	push_begin(head,0);
	print(head);cout<<endl;
	
	deleteTail(head);
	deleteTail(head);
	print(head);cout<<endl;
	
	deleteHead(head);
	deleteHead(head);
	print(head);cout<<endl;
	
	deleteAfter(head,2);
	print(head);cout<<endl;
	deleteAfter(head,2);
	print(head);cout<<endl;
}
	