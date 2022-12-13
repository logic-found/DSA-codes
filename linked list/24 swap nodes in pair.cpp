#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int val;
	Node* next;
	
	Node(int data){
		this->val=data;
		this->next=NULL;}
};
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp=temp->next;}
}
void push_last(Node* &head,int n){
	Node* new_node=new Node(n);
	Node* temp=head;
	
	while(temp->next!=NULL){
		temp=temp->next;}
	temp->next=new_node;}

void swapPair(Node* head) {
        if(!head) return;
       Node* temp=head;
       Node* prev=head;
        while(temp && temp->next){
            Node* node=temp->next;
            
            Node* nextNode=temp->next;
			node->next=temp;
			temp=node;}
			 print(head);
			
       
}

int main(){
	Node* head=new Node(1);
	push_last(head,2);
	push_last(head,3);
	push_last(head,4);
	
	
	print(head);cout<<endl;
	swapPair(head);
}