#include<bits/stdc++.h>
//#include"Stack1.h"
using namespace std;
//to prepare expresion tree using postorder

struct Node{

char data;
Node* left;
Node* right;
};


// class Node{

//     struct Node*  root;

// 	// Node(char element){
// 	// 	this->element=element;
// 	// 	this->left=NULL;
// 	// 	this->right=NULL;


// 	// 	}

// };


class Expression{
    struct Node* root;
    public:
    Expression(){
        root=NULL;
    }

Node* buildTree(string postOrder){
				int size=postOrder.length();
				int i=0;	
			stack<Node* > st;		
		Node* root1=new Node();
					root1->data=postOrder[i];
                    root1->left=NULL;
                    root1->right=NULL;
		while(i<size){
		
		if(!isalpha(postOrder[i])){
		Node* root=new Node();
        root->data=postOrder[i];
        root->left=NULL;
        root->right=NULL;
		
		root->right=st.top();
		st.pop();
		
		root->left=st.top();
		st.pop();
		
		st.push(root);
		
		root1=st.top();
		
		}
		else{
		
		
		Node* root=new Node();
        root->data=postOrder[i];
        root->left=NULL;
        root->right=NULL;
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
		cout<<root->data<<" ";
		inorderTraversal(root->right);
		
		
		}
		
		void postTraversal(Node* root){
		if(root==NULL)
		{return;}
		
		postTraversal(root->left);
		
		postTraversal(root->right);
		cout<<root->data<<" ";
		
		
		}
		
		void preTraversal(Node* root){
		if(root==NULL)
		{return;}
		
		cout<<root->data<<" ";
		preTraversal(root->left);
		preTraversal(root->right);
		
		
		
		}
		
void levelOrderTraversal(Node* root){
	if(root==NULL){return;}
queue<Node* > q;
q.push(root);
//q.push(NULL);

while(!q.empty())
{
	Node* temp=q.front();
	// if(temp->data==NULL){
	// 	cout<<endl;
	// }
	// else{
	cout<<temp->data<<" ";
    // }
	q.pop();

	

	if(temp->left){q.push(temp->left);}
	if(temp->right){
		q.push(temp->right);
	}

// if(!q.empty())
// {
// 	q.push(NULL);
// }
}

}

Node* getRoot()
{
    return root;
}
void setRoot(Node* temp)
{
root=temp;


}


};
int main(){
stack<Node* > st;

string postOrder="abc/+d-";
string postOrder1="abc*+";

//int size=postOrder.length();
Expression M;

//M.root=NULL;

M.setRoot(M.buildTree(postOrder));

M.inorderTraversal(M.getRoot());
cout<<endl;
M.preTraversal(M.getRoot());
cout<<endl;
M.postTraversal(M.getRoot());
cout<<endl;

M.levelOrderTraversal(M.getRoot());
cout<<endl;


}
