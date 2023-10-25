#include <iostream>
using namespace std;

template <class T>
class Stack{
    private: struct Node {
    T elem;
    Node *next;
    
    
};
    private : Node *tos;
    public: Stack(){
    	tos = NULL;
    }
public:
    bool push(T elem){
       
        Node *temp = new Node;
        if(temp == NULL)
            return 0;
        temp->elem = elem;
        temp->next = tos;
        tos = temp;
        return 1;

    }
public:
    T pop(){
        Node *temp = new Node;
        temp = tos;
        tos = temp->next;
        return temp->elem;



    }
public:
    bool IsEmpty(){
        if(tos == NULL){
            return 1;

        }


    }
public:
    T peep(){
        if(tos != NULL){
            return tos->elem;
        }
            
        else{
            return 0;
        }


    }



};
/*int main(){
	Stack s;
	cout << s.peep()<<endl;











return 0;
}
*/


/*
#include<iostream>

using namespace std;


template <class T>
class Stack{
     private: 
          struct Node{
      T element;
      Node *next;
	};
     Node *tos=NULL;

     public :
     bool push(T x){
      Node *temp=new Node;
      if(temp==NULL){
      	return 0;
      }
      
	temp->element = element;
      temp->next=tos;
      tos=temp;

     
      return 1;
     }
     T pop(){
	    if(isEmpty()){

	     return 0;

	     }else{

	     Node *temp=tos;
	     tos=tos->next;
	     return temp->element;


	     }
     }
     bool isEmpty(){
	  if(tos==NULL){
	   return true;

	  }else{

	  return false;
	  }
     }
     T peep(){
         if(isEmpty()){

	    return 0;


	    }else{

	    return tos->element;

	    }
     
     }

};
*/
