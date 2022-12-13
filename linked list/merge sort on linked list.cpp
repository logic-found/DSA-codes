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
	
Node* findMid(Node* &head){
	Node* slow=head,*fast=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;}
	return slow;
}
Node* merge(Node* &left,Node* &right){
	if(left==NULL) return right;
	else if(right==NULL) return left;
	Node* head1=new Node(0);
	Node* node=head1;
	
	while(left && right){
		if(left->val<right->val){
			Node* node2=new Node(left->val);
			node->next=node2;
			node=node->next;
			left=left->next;}
		else{
			Node* node2=new Node(right->val);
			node->next=node2;
			node=node->next;
			right=right->next;}}
	while(left){
		Node* node2=new Node(left->val);
		node->next=node2;
		node=node->next;
		left=left->next;}
	while(right){
		Node* node2=new Node(right->val);
		node->next=node2;
		node=node->next;
		right=right->next;}
		
	return head1;
}
Node* mergeSort(Node* &head){
	if(head==NULL || head->next==NULL) return head;
	Node* mid=findMid(head);
	Node* left=head;
	Node* right=mid->next;
	mid->next=NULL;
	
	left=mergeSort(left);
	right=mergeSort(right);
	Node* result=merge(left,right);
	print(result);
	return result;
	
}	
int main(){
	Node* head=new Node(5);
	push_last(head,3);
	push_last(head,1);
	push_last(head,8);
	push_last(head,4);
	push_last(head,0);
	print(head);cout<<endl;
	cout<<"a";
	Node* result=mergeSort(head);
	cout<<"b";
	print(result);
	
	print(head);
	
}
	
	
	
