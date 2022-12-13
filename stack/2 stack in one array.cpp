#include<iostream>
using namespace std;
class Stack{
	public:
	int size;
	int top1,top2;
	int* arr;
	
	Stack(int n){
		this->size=n;
		this->top1=-1;
		this->top2=size;
		arr=new int[n];}
		
	void push1(int n){
		if(top2-top1>1){
			top1++;
			arr[top1]=n;}
		else cout<<"stack overflow"<<endl;}
	
	void push2(int n){
		if(top2-top1>1){
			top2--;
			arr[top2]=n;}
		else cout<<"stack overflow"<<endl;}
		
	int pop1(){
		if(top1>-1){
			int x=arr[top1];
			top1--;
			return x;}
		else cout<<"stack underflow"<<endl;}
	
	int pop2(){
		if(top2<size){
			int x=arr[top2];
			top2--;
			return x;}
		else cout<<"stack underflow"<<endl;}
	
	int topEle1(){
		if(top1>-1) return arr[top1];
		else return -1;}
		
	int topEle2(){
		if(top2<size) return arr[top2];
		else return -1;
	}
	void printStack1(){
		for(int i=0;i<=top1;i++){
			cout<<arr[i]<<" ";}
	}
	void printStack2(){
		for(int i=size-1;i>=top2;i--){
			cout<<arr[i]<<" ";}
	}
	
};
int main(){
	Stack obj(5);
	obj.push1(1);
	obj.push1(2);
	obj.push1(3);
	obj.push2(6);
	obj.push2(5);
	obj.push2(4);
	cout<<obj.topEle1()<<endl;
	cout<<obj.topEle2()<<endl;
	
	obj.printStack1();cout<<endl;
	obj.printStack2();cout<<endl;
	
}