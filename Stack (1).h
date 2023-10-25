#include <iostream>
using namespace std;

//template <class T>
class Stack
{
    private : struct Node 
    {
        int ele;
        Node * next;
    };

    private : Node * tos;

    //constructor to initialize the top of the stack
    public : Stack()
    {  
        tos = NULL;
    }

    //function to add element on the top of the
    public : bool push(int ele)
    {
    	
        Node * temp = new Node;
        //if memory is exhausted and new node is not created
        if(temp == NULL)
        {
            return 0;
        }
        temp->ele = ele;
        temp->next = tos;
        tos = temp;
        //1 shows that new node is created
        return 1;
    }

    //function to pop element from the top of the stack
    public : int pop()
    {
        Node * temp = tos;
        tos = tos->next;
        int x = temp->ele;
        delete temp;
        return x;
    }

    //function to check if the stack is empty
    public : bool IsEmpty()
    {
        if(tos == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //function to get the element on the top of the stack
    public : int peep()
    {
        if(tos != NULL)
        {
            return tos->ele;
        }
        else
        {
            return 0;
        }
    }
};
int main(){
	Stack s;
	s.push(1);
	
	s.pop();
	s.peep();
}    


    

