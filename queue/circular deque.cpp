#include<iostream>
using namespace std;
int c;
class queue{
	public:
		int* arr;
		int size;
		int rear;
		int front;
		
	queue(int size){
		this->size=size;
		arr=new int[size];
		front=-1;
		rear=-1;}
		
	void push(int val){
		if(c>=size) {
			cout<<"overflow-push_back"<<endl; return;}
			
		else if(front==-1) {
			front++;rear++;}
		else if(rear==size-1 && front!=0) rear=0;
		else rear++;
		arr[rear]=val;
		++c;
	}
			
	void pop(){
		if(c==0) {
			cout<<"underflow--pop_front"<<endl;
			return;}
		if(c==1) {
			front=rear=-1;}
		else if(front==size-1) front=0;
		else front++;
		c--;}
		
	int frontVal(){
		if(c==0){
			cout<<"underflow";
			return -1;}
		return arr[front%size];}
		
	int rearVal(){
		if(c==0){
			cout<<"underflow";
			return -1;}
	
		return arr[(rear)%size];}
		
	bool isEmpty() {
        if(c!=0) return false;
        return true;}
    
    bool isFull() {
        if(c>=size) return true;
        return false;}
        
    void push_front(int val){
    	if(c==size){
    		cout<<"overflow--push_front"<<endl;return;}
    	if(front==-1){
    		front=rear=0;}
    	else if(front==0 && rear!=size){
    		front=size-1;}
    	else{
    		front--;}
    	arr[front%size]=val;
    	++c;
	}
	void pop_back(){
		if(c==0) {
			cout<<"underflow-pop_back"<<endl;
			return;}
		else if(c==1){
			front=-1;rear=-1;}
		else if(rear==0){
			rear=size-1;}
		else rear--;
		--c;
	}	
	void print(){
		
		for(int i=front;i<=rear-1;++i) cout<<arr[i%size]<<" ";}
};
int main(){
	queue obj(4);
	obj.push_front(1);
	obj.push_front(2);
	obj.push_front(3);
	obj.push_front(4);
	obj.pop_back();
	
	

	cout<<"front- "<<obj.frontVal()<<"  rear- "<<obj.rearVal()<<endl;
	
	}