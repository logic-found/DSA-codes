#include<bits/stdc++.h>
using namespace std;
int i=0;
int c=2;map<int,int> mp;

class Node{
	public:
	int val;
	Node* next;
	Node* prev;
	
	Node(int data){
		this->val=data;
		this->next=NULL;
		this->prev=NULL;}
};
class linkedlist{
	public:
	Node* head;
	Node* tail;
	
	linkedlist(int val){
		head=tail=new Node(val);
	}
	void print(){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp=temp->next;}
	}
			
	void capacity(int cap){
	c=cap;
	return;}
	
	int get(int key){
	if(mp.find(key)==mp.end()) return -1;
	Node *temp=head;
	while(temp && temp->val!=key){
		temp=temp->next;}
	if(temp){
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		temp->prev=NULL;
		temp->next=head;
		head->prev=temp;
		head=temp;
		return mp[key];}
	return -1;}
	
	void put(int key,int value){
	if(mp.find(key)!=mp.end()){
		mp.erase(key);
		Node* temp=head;
		i--;
		while(temp && temp->val!=key){
			temp=temp->next;}
		if(temp!=tail){
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			temp->prev=temp->next=NULL;
			delete(temp);}
		else{
			tail=tail->prev;
			tail->next=NULL;
			delete(temp);}
	}
	
	if(i>=c){
		Node* node=tail;
		mp.erase(tail->val);
		tail=tail->prev;
		tail->next=NULL;
		cout<<"increase "<<i<<endl;
		print();cout<<endl;
		node->next=node->prev=NULL;
		delete(node);i--;}
	cout<<"i= "<<i<<endl;
	
	if(i<c){
		if(head==NULL && tail==NULL){
			mp[key]=value;
			Node* node=new Node(key);
			head=tail=node;
			i++;
			return;}
		else{
			mp[key]=value;
			Node* temp=new Node(key);
			temp->next=head;
			head->prev=temp;
			head=temp;
			tail=head;
			i++;
			cout<<"a= "<<i<<endl;
			print();cout<<endl;
			return;}}
	}	
};

int main(){
	linkedlist obj(0);
	obj.put(1,1);
	obj.put(2,2);
	obj.print();cout<<endl;
	cout<<obj.get(1)<<endl;
	cout<<obj.get(3)<<endl<<endl;
	obj.put(4,4);
	obj.put(6,6);
	cout<<obj.get(3);

	}