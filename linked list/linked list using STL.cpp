#include<forward_list>
#include<iostream>
using namespace std;

int main(){
	forward_list<int> f1;
	
	f1.push_front(0);
	f1.push_front(1);
	f1.push_front(4);
	f1.insert_after(f1.begin(),3);
	f1.pop_front();
	
	for(auto i:f1) cout<<i<<" ";
}