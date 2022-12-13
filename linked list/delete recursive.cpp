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
	if(head==NULL) return;
	else{
		cout<<head->data<<" ";
		print(head->next);}
}

void push_begin(Node* &head,int n){
	Node* new_node=new Node(n);
	new_node->next=head;
	head=new_node;
}
void deleteLast(Node* &head){
	if(head->next->next==NULL){
		head->next=NULL;return;
	}
	else{
		return deleteLast(head->next);
	}
}
void deleteBegin(Node* &head){
	head=head->next;
}
void deleteAfter(Node* &head,int pos){
	if(pos==1){
		deleteBegin(head);return;}
	if(pos==2){
		head->next=head->next->next;
		return;}
	else{
		deleteAfter(head->next,pos-1);
	}
}
Node* deleteNode(Node* &head,int pos){
	
	if(pos==1){
		Node* node=head->next;
		delete(head);
		return node;}
		
	head->next=deleteNode(head->next,pos-1);
	return head;
}
int main(){
	Node* head=new Node(7);
	push_begin(head,6);
	push_begin(head,5);
	push_begin(head,4);
	push_begin(head,3);
	push_begin(head,2);
	push_begin(head,1);
	print(head);cout<<endl;
	
	deleteLast(head);
	print(head);cout<<endl;
	
	deleteAfter(head,2);
	print(head);cout<<endl;
	
	deleteAfter(head,3);
	print(head);cout<<endl;
	
	deleteNode(head,2);
	print(head);cout<<endl;
	
	deleteNode(head,2);
	print(head);cout<<endl;
	
	
	
	
	
}
	
