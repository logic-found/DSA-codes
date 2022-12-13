#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
	node* buildTree(node* root) {
	    cout << "Enter the data: " << endl;
	    int data;
	    cin >> data;
	    root = new node(data);    
	
	    if(data == -1) {
	        return NULL;
	    }
	
	    cout << "Enter data for inserting in left of " << data << endl;
	    root->left = buildTree(root->left);
	    cout << "Enter data for inserting in right of " << data << endl;
	    root->right = buildTree(root->right);
	    return root;
	
	}
	void morrisTraversal(node* root){
		node* current=root;
		while(current){
			if(!current->left){
				cout<<current->data<<" ";
				current=current->right;
			}
			else{
				node* pre=current->left;
				while(pre->right!=NULL && pre->right!=current){
					pre=pre->right;}
				if(!pre->right){
					pre->right=current;
					current=current->left;
				}
				else{
					pre->right=NULL;
					cout<<current->data;
					current=current->right;
				}
			}
		}
	}
int main() {
    node* root=NULL;
    buildTree(root);
    morrisTraversal(root);
}