#include "linkedlist.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 	
 	
 	//Oguzhan ÖZER 140308002 COMPE226_DATA_STRUCTURE HOMEWORK1 
 	
 	int total_credit=0;
	bool moreTwo;
	bool finish;

	int no=0,number=0;
		
	int credit,section;
	double cgpa;
	long int student_id;
	string first_name,last_name,code;
		
	void reading_link();
 			
 	Deneme<string,int> obj;
		

	void operate(string choice)
	{
	    int credit,section,change;
		string code;
	
	    if(choice.compare("Add")==0){
	            cout << "Enter CourseCode, Credit and Section to be added: ";
	            cin >>code >>credit >> section;
	            
	            total_credit+=credit;
	            
		       if(obj.found_name(code) == false){
	            	
	           	if(moreTwo == true)
				{
					if(total_credit<34)
					{
		        		 
		            	obj.insertLast(code,credit,section);
		            	cout<<code<<" "<<credit<<" "<<section<<" "<<"has been added";
					  	
					}else {
						cout<<"     Error: Total Credit Limit is 34. \n";
						total_credit-=credit;
					}

			 		 }else{
			 	
		            if(total_credit<24){
		        		 	
		            	obj.insertLast(code,credit,section);
						cout<<code<<" "<<credit<<" "<<section<<" "<<"has been added\n";
		        	
				 	 	  	
					}else {
					cout<<"     Error: Total Credit Limit is 24.\n";
					total_credit-=credit;
					}
				}   	
	        
	            	
				}else{
					cout<<"     Error "<<code<<" is already registered"<<endl;
				}
	            
				cout<<endl;
	    }
	     else  if(choice.compare("List")==0)
	      	{
	      		reading_link(); 
		   	}	     	
	
	     else   if(choice.compare("Drop")==0)
	      	{
			 	 cout << "Enter the order of the node to delete: ";
	            cin >> code;
	            obj.deleteNode(code);
				total_credit=total_credit - obj.sumcredits;
				cout<<"Enter CourseCode to be deleted: "<<code<<"\n";
	     	
	      		cout<<endl;
		  }	
	    
	     else if(choice.compare("Change")==0)
		   {
		   
	            cout << "Enter CourseCode and new section: ";
	            cin>>code>>change;
	         	obj.changes(code,change);
				cout<<code<<" section has been changed to "<<change<<"."<<endl;
	        
	        	cout<<endl;
			}
			else if(choice.compare("Quit")==0)
	        {
	       		finish = true;
	       		cout<<endl;
	            cout<<"Thank you for using ATACS-2.0.";
	            	
			}
			
	}
	
	
	
	
 	void reading_link()
 	{
 		cout<<"Name : "<<first_name<<" "<<last_name<<" "<<"ID : "<<student_id<<" "<<"CGPA : "<<cgpa<<" Total Credits : "<<total_credit<<endl<<"Registered Courses :"<<endl; 	
		cout<<obj<<"\n";				
	} 
	
	
	
 	 	  
	 int main()
 		{
	
		finish = false;
	    string choice;
		
	
		ifstream reading_file("data.txt");
			while(!reading_file.eof())
			{
				
				if(no==0)
				{
					reading_file>>first_name>>last_name;
				}
				else if(no==1)
				{
					reading_file>>student_id>>cgpa;
					if(cgpa>2.00)
						moreTwo = true;
								
				}else{
				
					reading_file>>code>>credit>>section;
					
					obj.insertLast(code,credit,section);	
					total_credit+=credit;
					
				}
				
					no++;
			}	 	
	    
			
			node<string,T1> *p ;

	    while(!finish){
	      cout<<"Enter Add | Drop | Change | List | Quit: ";
	      
	        cin >> choice;
	        operate(choice);
	    }

		reading_file.close();
				 
		}
		
