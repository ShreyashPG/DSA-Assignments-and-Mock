#include <iostream>
#include "Stack.h"
using namespace std;


struct function
{
	char var;
	float val;
};

//function to check instack priority
int isp(Stack<char> s)//Stack<char>this will helps to use char present in stack
{
	char ch = s.peep();
		 if(ch== '+' || ch == '-')
        {
		return 1;
	}
	else if(ch == '*' || ch== '/')
        {
		return 2;
	}

	else if (ch=='^')
        {
		return 3;
	}
	else if(ch=='(')
	{
		return 4;
	}
	else {
		return 0;
	}
}


int icp(char x)//function to check incoming priority
{
	
		 if(x== '+' || x == '-')
        {
		return 1;
	}
	else if(x == '*' || x== '/')
        {
		return 2;
	}

	else if (x=='^')
        {
		return 3;
	}
	else if(x=='(')
	{
		return 4;
	}
	else {
		return 0;
	}
}

//fucnvtion to convert infix to postfix 
string infix2Postfix(string infix){
	string postfix;
	int n=infix.length();
	Stack<char> s;//Stack<char>this will helps to use char present in stack    
	for(int i=0; i<infix.length(); i++)//infix.;ength will give length of string and this loop is for iterating over length of string
        {
		char fs = infix[i];//fs(full string)stores the character of infix by itertion
	
		if((fs >= 'a' && fs <= 'z') || (fs >= 'A' && fs <= 'Z'))	//if the character is operand, append it to the postfix string
		{
			postfix += fs;//appending it to the postfix
		}
	
		else	//if the character is an operator
		{  if(isp(s) < icp(fs))//if incoming priority is greater than instack priority then push it on stack
			{
				if(fs!= ')')
				{
					s.push(fs);
				}
			}
			
			else if(s.peep() == '(')//if opening bracket is present in stack then push operator directly
			{
				s.push(fs);
			}
			
			
			else if(fs == ')')		//if closing bracket there is closing bracket pop until opening bracket
			{
				while(s.peep() != '(')
				{ char c=s.pop();
					postfix += c;
						
				}
				s.pop();
				
			}
			else
			{
				while(isp(s) >= icp(fs))
				{
					postfix += s.pop();
				}
				s.push(fs);
			}
		}
	}
	
	while(!s.IsEmpty())//append all the remaining operatrs from the stack to the postfix expression
	{
		postfix += s.pop();
	}
	return postfix;
}

//function for calculating the values of operations
float calculate(float Rop, float Lop, char opra)
{

	//left operand (lop)is on tos hence it should be left side
	float ans;
	if(opra == '+')
	{
		
		ans = Lop+Rop;
	}
	else if(opra== '-')
	{
		ans =  Lop-Rop;
	}
	else if(opra == '*')
	{
		ans =  Lop*Rop;
	}
	else if(opra == '/')
	{
		ans = Lop/Rop;
	}
	return ans;
}


float evaluate(string postfix, int n, struct function arr[])
{
	Stack<float> f;
	char opra, m;
	float Lop, Rop;
	int i = 0;
	while(postfix[i] != '\0')
	{
		m = postfix[i];
		if((m <= 'z' && m >= 'a') || (m <= 'Z' && m >= 'A'))
		{
			for(int j=0; j<n; j++)
			{
				if(arr[j].var == m)
				{
					f.push(arr[j].val);
					break;
				}
			}
		}
		else
		{
			if(!f.IsEmpty())
			{
				opra = postfix[i];
				Rop = f.pop();
				Lop = f.pop();
				f.push(calculate(Rop, Lop, opra));
			}
		}
		i++;
	}
	return f.peep();
}

int main()
{
	
	int k;
	cout<<"Enter the number of operands prestent in the infix expression : ";
	cin>>k;
	struct function arr[k];
	for(int i=0; i<k; i++)
	{
		cout<<" Enter the variable: ";
		cin>>arr[i].var;
		cout<<"Enter value of variable: ";
		cin>>arr[i].val;
	}
	

	string infix;
	cout<<"Enter Infix Expression : ";
	cin>>infix;

	
	string pstfix = infix2Postfix(infix);
	cout<<"Postfix Expression is : "<<pstfix<<endl;

	//evaluate the postfix expression
	cout<<evaluate(pstfix,k, arr);

	return 0;
}
