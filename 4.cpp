#include<iostream>
#include "Stack.h"
using namespace std;
class ass4{
	
private:struct root{
	char var;
	root*lch;
	root*rch;
};

public:
void intrav(root*r){
	if(r!=NULL)
	{
		intrav(r->lch);
		cout<<r->var;
		intrav(r->rch);
	}
}
 void p02tree(string st)
{ Stack<root*>r;
	for(int i=0;i<'\0';i++)
	{
	if(st[i]<='Z'&&st[i]>='A'||st[i]<='z'&&st[i]>='a')
	{ root*temp=new root;
	  temp->var=st[i];
	  temp->lch=NULL;
	  temp->rch=NULL;	
	  r.push(temp);
	  
					
		}
	else{
		 root*temp1=new root;
		 temp1->var=st[i];
		 temp1->rch=r.pop();
		 temp1->lch=r.pop();
		 r.push(temp1);
	}	
			}root*s=r.peep();
			
			intrav(s);
		}
	
		
};
int main(){string str;
	cout<<"enter the postfix expression="<<endl;
	cin>>str;;
	ass4 a;
	a.p02tree(str);
	
}
