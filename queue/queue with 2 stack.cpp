#include<bits/stdc++.h>
using namespace std;
int size=0,top=-1;
int arr1[100],arr2[100];
class q{
	public:
	q(int max){
		size=max;}
	
	void push(int item){
		if((top+1)==size){
			cout<<"overflow"<<endl;
			return;}
		arr1[++top]=item;
		return;
	}
	void pop(){
		if(top==-1){
			cout<<"underflow"<<endl;
			return;}
		for(int i=0;i<=top;++i){
			arr2[top-i]=arr1[i];}
		top--;
		for(int i=0;i<=top;++i){
			arr1[i]=arr2[top-i];}
	}
	int topEle(){
		if(top==-1) cout<<"no element ";
		return top;}
		
	void display(){
		if(top==-1){
			cout<<"no element"<<endl;
			return;}
		for(int i=0;i<=top;++i) cout<<arr1[i]<<" ";
		cout<<endl;
	}		
			
};
int main(){
	q obj(5);
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.display();
	obj.pop();
	obj.display();
	obj.push(4);
	obj.push(5);
	obj.pop();
	obj.display();
	cout<<endl<<"top element "<<obj.topEle()<<endl;
	
	
}