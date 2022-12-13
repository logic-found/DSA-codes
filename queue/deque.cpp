#include<iostream>
using namespace std;
int arr[100],size=0,front=-1,rear=-1;
class q{
	q(int max){
		size=max;}
		
	void pushBack(int item){
		if(rear==size){
			cout<<"overflow"<<end;
			return;}
		arr[++rear]=item;}
		
	void pushFront(int item){
		if(rear==size){
			cout<<"overflow"<<endl;
			return;}
		for(int i=rear;i>=0;i--){
			arr[i+1]=arr[i];}
		arr[0]=item;
		return;}
	void popFront(){
		if(front==-1){
			cout<<"underflow"<<endl;
			return;}
		front++;
		return;}
	void popBack(){
		if(front==-1){
			cout<<"underflow"<<endl;
			return;}
		rear--;
		return;
	}
};
int main(){
	
}