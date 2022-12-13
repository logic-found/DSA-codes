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
		print(head->next);
	}
}
void push_begin(Node* &head,int n){
	Node* new_node=new Node(n);
	new_node->next=head;
	head=new_node;
}
void push_last(Node* &head,int data){
	if(head->next==NULL){
	Node* new_node=new Node(data);
	head->next=new_node;
	return;}
	else{
		return push_last(head->next,data);
	}
}

void insert_after(Node* &head,int pos,int data){
	if(pos==2){
		Node* new_node=new Node(data);
		Node* res=head->next;
		head->next=new_node;
		new_node->next=res;
		return;}
	else{
		return insert_after(head->next,pos-1,data);
	}
}

int main(){
	Node* head=new Node(7);
	push_begin(head,6);
	push_begin(head,5);
	push_begin(head,4);
	print(head);cout<<endl;
	
	push_last(head,21);
	push_last(head,22);
	print(head);cout<<endl;
	
	insert_after(head,2,50);
	print(head);cout<<endl;
		
	
}
	
