#include<iostream>
#include<queue>
using namespace std;
void  reverse(queue<int> &q){
	if(q.empty()) return;
	
	 int n=q.front();
	 q.pop();
	 reverse(q);
	 q.push(n);
	 
	 
}
		
void print(queue<int> q){
	while(q.size()){
		cout<<q.front()<<" ";
		q.pop();}
}
int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	print(q);cout<<endl;
	reverse(q);
	cout<<q.front()<<" "<<q.back()<<endl;
	
	print(q);cout<<endl;

}