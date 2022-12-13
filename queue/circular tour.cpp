#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> petrol={4,6,7,4};
	vector<int> distance={6,5,3,5};
	int i=0,n=petrol.size();
	
	while(i<n){
		if(distance[i]>petrol[i])i++;
		else break;}
	int index=i,ans=0;
		
	do{
		ans+=petrol[i%n]-distance[i%n];
		if(ans<0){
			index=(i+1)%n;
			ans=0;}
		++i;
	}while(i%n!=index);
	cout<<ans;
}