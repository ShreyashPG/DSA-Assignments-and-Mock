#include <iostream>
#include <math.h>
#include "Stacks.h"

using namespace std;

//instance of Stack class
 
bool isOperator(char c)//to check whether input char c is an operator and returns true or false.
{

	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isOperand(char c)//it checks whether char c is alphanumeric character & if it is then returns true.
{
	if(isalnum(c))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int prescedence(char op)//to 
{
	if(op=='+'||op=='-')
	{
		return 1;//lower precedence compared to others.
	}
	else if(op=='*'||op=='/')
	{   
		return 2;//higher precedence.
	}
    else if(op=='^')
    {
        return 3;
    }
	else
	{
		return 0;//for '('..lowest precedence
	}
}

string infixToPostfix(string infix)
{
	Stack<char> s;
	string postfix;
	for(int i=0; i<infix.length();i++)
	{
		if(isalnum(infix[i]))
		{
			postfix+=infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(!s.isEmpty() && s.peek()!='(')
			{
				postfix+=s.peek();
                s.pop();	
			}
			s.pop(); //'('
		}

		else if(isOperator(infix[i]))
		{	
			while(!s.isEmpty() && prescedence(infix[i])<=prescedence(s.peek()))
			{
				postfix+=s.peek();
                s.pop();
			}
			s.push(infix[i]);
		}	
	}		
	while(!s.isEmpty())
	{
		postfix+=s.peek();
        s.pop();
	}
	return postfix;
}

int evalpost(string postfix)
{	
	Stack<int> s;
	for(int i=0; i<postfix.length() ;i++)
	{	
		if (isalnum(postfix[i]))
		{
			s.push(postfix[i]-'0');//to convert char to int
		}
		else if(isOperator(postfix[i]))
		{	
			int op2=s.peek();
			s.pop();
			int op1= s.peek();
			s.pop();

			int result;
			if(postfix[i]=='+')
			{
				result=op1+op2;
			}
			else if(postfix[i]=='-')
			{
				result=op1-op2;
			}
			else if(postfix[i]=='*')
			{
				result=op1*op2;
			}
			else if(postfix[i]=='/')
			{
				result=op1/op2;
			}
			else
			{
				result=pow(op1,op2);
			}
			
			s.push(result);
		}
	}
	return s.peek();
}
string reverseString(string st)//reversing string
{
	string reversed;
	//reverse string
	for(int i=st.length()-1;i>=0;i--)
	{
		reversed+=st[i];
	}
	return reversed;
}
string infixToPrefix(string infix)
{	
    Stack<char> s;
	string reversedinf=reverseString(infix);
	string prefix;
	for(int i=0;i<reversedinf.length();i++)
	{
		if(isalnum(reversedinf[i]))
		{
			prefix +=reversedinf[i];
		}
		else if(reversedinf[i]==')')
		{
			s.push(reversedinf[i]);
		}
		else if(reversedinf[i]=='(')
		{
			while(!s.isEmpty()&&s.peek()!=')')
			{
				prefix+=s.peek();
				s.pop();
			}
			s.pop(); //')'
		}
		else if(isOperator(reversedinf[i]))
		{
			while(!s.isEmpty() && prescedence(reversedinf[i])<prescedence(s.peek()))
			{
				prefix+=s.peek();
				s.pop();
			}
			s.push(reversedinf[i]);//pushing operator whose icp>isp
		}
	}
	while(!s.isEmpty())
	{
		prefix+=s.peek();
		s.pop();
	}
	return reverseString(prefix);
}
int evalprefix(string prefix)
{
	Stack<int> s;
	for(int i=prefix.length()-1;i>=0;i--)
	{
		if(isalnum(prefix[i]))
		{
			s.push(prefix[i]-'0');
		}
		else if(isOperator(prefix[i]))
		{
			int op1 =s.peek();
			s.pop();
			int op2 =s.peek();
			s.pop();
			
			int result;
			
			if(prefix[i]=='+')
			{
				result=op1+op2;
			}
			else if(prefix[i]=='-')
			{
				result=op1-op2;
			}
			else if(prefix[i]=='*')
			{
				result=op1*op2;
			}
			else if(prefix[i]=='/')
			{
				result=op1+op2;
			}
			else if(prefix[i]=='^')
			{
				result=pow(op1,op2);

			}
			s.push(result);
		}
	}
	
	return s.peek();
	
}
int main()
{
	int ch;
	string infix;
	string post,prefix;
	int res=0;
	do{
	cout<<"====Menu====="<<endl;
	cout<<"1. Infix to Postfix"<<endl;
	cout<<"2. Infix to Prefix"<<endl;
	cout<<"3. Postfix Evaluation"<<endl;
	cout<<"4. Infix Evaluation"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>ch;
	int i=0;
	switch(ch)
	{
		case 1:
		
		    cout<<"Enter Infix Expresssion:"<<endl;				
			cin>>infix;
			post=infixToPostfix(infix);
			cout<<"Postfix expression :"<<post<<endl;
			
		break;
		
		case 2: cout<<"Enter Infix Expresssion:"<<endl;				
			cin>>infix;
			prefix=infixToPrefix(infix);
			cout<<"Prefix expression :"<<prefix<<endl;
			
		break;
		
		case 3:cout<<"Enter Postfix Expresssion:"<<endl;				
			cin>>post;
			res=evalpost(post);
			cout<<"Postfix expression evaluation  :"<<res<<endl;
		break;
		
		case 4:cout<<"Enter Prefix Expresssion:"<<endl;				
			cin>>prefix;
			res=evalprefix(prefix);
			cout<<"prefix expression evaluation  :"<<res<<endl;
		break;
		
		case 5:cout<<"exit";
		break;
	}
	}while(ch!=5);
}
