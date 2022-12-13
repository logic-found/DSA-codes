#include<bits/stdc++.h>
using namespace std;
int arr[10],size=-1,top1=-1,top2=size;
class s{
	public:
	s(int max){
		size=max;}
		
	void push1(int data){
		if(top1+1==top2){
			cout<<"overflow"<<endl;
			return;}
		arr[++top1]=data;
		return;
	}
	void push2(int data){
		if(top2-1==top1){
			cout<<"overflow"<<endl;
			return;}
		arr[--top2]=data;
		return;
	}
	void display1(){
		for(int i=0;i<=top1;++i) cout<<arr[i]<<" ";
		cout<<endl;
	}
	void pop1(){
		if(top1==-1){
			cout<<"underflow"<<endl;
			return;}
		top1--;
		return;
	}
	void pop2(){
		if(top2==size){
			cout<<"underflow"<<endl;
			return;}
		top2++;
		return;
	}
	void display2(){a
		for(int i=size-1;i>=top2;--i) cout<<arr[i]<<" ";
		cout<<endl;
	}
};
int main(){
	s obj(5);
	obj.push1(1);
	obj.push1(2);
	obj.display1();
	
	obj.push2(5);
	obj.push2(4);
	obj.display2();
}