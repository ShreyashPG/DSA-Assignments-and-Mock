//INSERTION SORT:Implement airplane passengers database ,sort the database using passenger seat number and perform searching using linear search on any parameter.



#include<bits/stdc++.h>

using namespace std;

struct database{
	string name;
	int seat_number;
	int age;
	
};


class Airplane_passengers {
	
	struct database d[100];
	int size;
	
	public:
	Airplane_passengers(){
	cout<<"Enter number of passengers : ";
	cin>>size;
	if(size<=0)
	{
	cout<<"invalid input "<<endl;}
	
	
	
	
	}
	
	
	void getData();
	void display();
	void insertion_sort();
	void linear_search(string name); 

	
};
//to take input of passengers
     void Airplane_passengers::getData(){
     		d[0]={"Sai",2,34};
     		d[1]={"om",1,30};
     		d[2]={"yash",3,36};
     		d[3]={"gogy",0,35};
     		d[4]={"jayesh",8,39};
     		d[5]={"jeet",20,24};
     		d[6]={"sima",12,44};
     		d[7]={"riya",1,31};
     		d[8]={"priya",3,14};
     		d[9]={"Sejal",6,64};
     		
   //  		size=10;
     		
     		
     //		for(int i=0;i<size;i++){
     //		cout<<"Enter name  of passenger : ";
     //		cin>>d[i].name;
     		
     			cout<<endl;
     //		cout<<"Enter seat_number : ";
     //		cin>>d[i].seat_number;
     //		cout<<endl;
     		
    // 		cout<<"Enter age of passenger : ";
     //		cin>>d[i].age;
     		
     //		}
     		
     	//	cout<<"Database of "<<size<<" is stored "<<endl;
     		
     }
     
     //function to display datbase of passengers
     void Airplane_passengers::display(){
     
     if(size<=0)
	{
		cout<<"Invalid Database "<<endl;
	}
     else{
     cout<<"Displaying Database "<<endl;
     cout<<" ---------------- "<<endl;
     for(int i=0;i<size;i++)
     {
     cout<<d[i].name<<" "<<d[i].seat_number<<" "<<d[i].age<<endl;;
     
     }
      cout<<" ---------------- "<<endl;
     }
     } 
	
	//Function for sorting database according to seat_number
     void Airplane_passengers::insertion_sort(){
	if(size<=0)
	{
		cout<<"Invalid Database "<<endl;
	}
	else{
	for(int i=1;i<size;i++)
	{
		struct database  temp=d[i];
		int j;
		for( j=i-1;j>=0;j--)
		{
			if(d[j].seat_number>temp.seat_number)
			{
				d[j+1]=d[j];
			
			}
			else{break;}
		
		}
		
		d[j+1]=temp;
	
	
	}
	cout<<"Sorting is over "<<endl;
	
	
	}
	
	}
	
	//Function for linear search
	void Airplane_passengers::linear_search(string name){
	if(size<=0)
	{
		cout<<"Invalid Database "<<endl;
	}
	else{
		int count=0;		
		for(int i=0;i<size;i++)
		{
			if(d[i].name==name)
			{
				cout<<"Seat Number of passenger  name is  "<<d[i].seat_number<<endl;
				count++;
			}
		
		
		}
		
		if(count==0)
		{
		cout<<"Name not found in passengers database "<<endl;
	}
	
	
	}
	}





int main(){
			//creating object
			Airplane_passengers A1;
			
			A1.getData();
			A1.display();
			A1.linear_search("om");
			A1.insertion_sort();
			A1.display();






}
