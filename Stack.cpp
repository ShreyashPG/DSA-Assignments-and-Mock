#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//template<class T>

struct Stack{

char data;
struct Stack* next;

Stack(){

	this->data=NULL;
	this->next=NULL;
	
}

Stack(char a){

	this->data=a;
	this->next=NULL;
	
}


};


void push(Stack* &head, int data)
{
struct	Stack* newnode=new Stack(data);	
		if(head==NULL){
		head=newnode;
		}
	else{
	
	newnode->next=head;
	head=newnode;
	
	}


}

Stack* pop(Stack* &head){
	struct Stack* newnode =head;
	struct Stack* newnode1=head;
	if(head==NULL)
	{
	return newnode;
	
	}
	else {
	
	newnode=newnode->next;
	head=newnode;
	return newnode1;
	
	}
	

}

char peep(Stack* &head){
	
	struct Stack* newnode=head;	




return newnode->data;





}


bool isEmpty(Stack* &head){

if(head==NULL)
{
return true;

}

else {

return false;
}


}

void display(Stack* &head){

struct Stack* newnode=head;
while(newnode!=NULL)

{
cout<<newnode->next;
newnode=newnode->next;

}



}

int main(){


struct  Stack* n1=new Stack(10);






}
