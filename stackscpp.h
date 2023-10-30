#include<iostream>
using namespace std;
template<class T>
class Node
{
    public:
        T data;
        Node<T>*next;

};

template<class T>
class Stack
{
    private: 
        Node<T>*TOS;
    public:
        Stack();
        void push(T);
        T pop();
        T peek();
        void display();
        bool isEmpty();
};

template<class T>
Stack<T>::Stack()
{
    TOS=NULL;    
}

template <class T>
void Stack<T>::push(T element)
{
    Node<T>*temp;
    temp=new Node<T>;
    temp->data=element;
    temp->next=NULL;
    
    if(TOS==NULL){
        TOS=temp;
    }
    else
    {
        temp->next=TOS;
        TOS=temp;
    }
}

template <class T>    
T Stack<T>::pop()
{   
    if(TOS==NULL)
    {
        cout<<"Stack is empty.";
        return '\0';
    }

    else{
    Node<T>*temp;
    temp=TOS;
    TOS=TOS->next;
    T element=temp->data;
    delete temp;
    return element;
}
    }

template <class T>
T Stack<T>::peek()
{
    if (TOS==NULL)
    {
        return 0;
       
    }
    else
    {
        return TOS->data;
    }
    

}
    
template <class T>    
bool Stack<T>::isEmpty()
{
    if(TOS==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void Stack<T>::display()
{
    Node<T>*temp;
    temp=TOS;
    while(temp!=NULL)
    {
        cout<<endl<<temp->data<<endl;
        temp=temp->next;
    }
}