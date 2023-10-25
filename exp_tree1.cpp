#include<iostream>
#include "Stack.h"

using namespace std;

struct root{
	
	char data;
	root *lc;
	root *rc;

};

Stack <root *> s;

void inorder(root *p){
			
	if(p!=NULL){
			
		inorder(p->lc);
		cout<<p->data;
		inorder(p->rc);
			
	}

}

void preorder(root *p){
			
	if(p!=NULL){
			
		preorder(p->lc);
		preorder(p->rc);
		cout<<p->data;
			
	}
}

void postorder(root *p){
			
	if(p!=NULL){
		
		cout<<p->data;
		postorder(p->lc);
		postorder(p->rc);
			
	}
}



void exp_treee(){
	string pf = "abc*+$";
	int i = 0;
	while(pf[i]!='$'){
		if(isalpha(pf[i])){
			root *temp = new root;
			temp->data = pf[i];
			temp->lc = NULL;
			temp->rc = NULL;
			s.push(temp);
		}
		else{		
			root *temp = new root;
			temp->data = pf[i];
			temp->rc = s.pop();
			temp->lc = s.pop();
			s.push(temp);
		
		}
		i++; 
	}
	root *p = s.peep();
	
	inorder(p);
	cout<<endl;
	preorder(p);
	cout<<endl;
	postorder(p);

}
int main(){
	exp_treee();
	
	return 0;
	
}







