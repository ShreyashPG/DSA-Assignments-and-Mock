#include<bits/stdc++.h>
//#include"Stack1.h"
using namespace std;
//to prepare expresion tree using postorder

class Node{
public:
char element;
Node* left;
Node* right;


	Node(char element){
		this->element=element;
		this->left=NULL;
		this->right=NULL;


		}
 	


};
Node* buildTree(string postOrder){
				int size=postOrder.length();
				int i=0;	
			stack<Node* > st;		
		Node* root1=new Node(postOrder[i]);
					
		while(i<size){
		
		if(!isalpha(postOrder[i])){
		Node* root=new Node(postOrder[i]);
		
		root->right=st.top();
		st.pop();
		
		root->left=st.top();
		st.pop();
		
		st.push(root);
		
		root1=st.top();
		
		}
		else{
		
		
		Node* root=new Node(postOrder[i]);
		st.push(root);
		}
		
		
		i++;
		
		}
	
	return root1;

	}	
	
		
	 	void inorderTraversal(Node* root){
		if(root==NULL)
		{return;}
		
		inorderTraversal(root->left);
		cout<<root->element<<" ";
		inorderTraversal(root->right);
		
		
		}
		
		void postTraversal(Node* root){
		if(root==NULL)
		{return;}
		
		postTraversal(root->left);
		
		postTraversal(root->right);
		cout<<root->element<<" ";
		
		
		}
		
		void preTraversal(Node* root){
		if(root==NULL)
		{return;}
		
		cout<<root->element<<" ";
		preTraversal(root->left);
		preTraversal(root->right);
		
		
		
		}
		
void levelOrderTraversal(Node* root){
queue<Node* > q;

if(root==NULL){return;}

}

int main(){
stack<Node* > st;

string postOrder="abc/+d-";
string postOrder1="abc*+";

//int size=postOrder.length();

Node* root=NULL;

root=buildTree(postOrder);

inorderTraversal(root);
cout<<endl;
preTraversal(root);
cout<<endl;
postTraversal(root);
cout<<endl;



}
