#ifndef DENEME2_H
#define DENEME2_H

#include<iostream>
#include<fstream>
#include<string>
using namespace std; 	


	template<class string,class T1>
 	struct node{
 		T1 credit;
 		T1 section;
 		string name;
 		node<string,T1> *link;
	 };
	 
	template<class string,class T1>
	 class Deneme{
	 	
		 protected:
	 		node<string,T1> *head,*last,*current;
	 		
	 		int count;
	 		double average;
			long int student_id;
			string first_name,last_name;
		
		public:
		Deneme();
		~Deneme(){}
	
		int sumcredits;
		int length();
		void insertLast(string,T1,T1);
		void deleteNode(string);
		void changes(string,T1);
		bool found_name(string);
		
		
		Node* LinkedList::search(int val)
		{
		    Node* pNode = _pHead;
		    
		    /* traverse the list */
		    while (pNode != NULL) {
		        /* Target! */
		        if(pNode->_value == val)
		        {
		            return pNode;
		        }
		        /* move to the next one */
		        pNode = pNode->_pNext;
		    }
		    return NULL;
		}
		
		friend ostream& operator<< (ostream & os,const Deneme<string,T1>& list)
		{
			node<string,T1> *p = list.head;
 		
 			while(p!=NULL)
 			{
 				os<<p->name<<" "<<p->credit<<" "<<p->section;
 				cout<<endl;
				 p=p->link;	
			}
		return os;
		}
	
	
		
	 };
	 
	
	 
	 template<class string,class T1>
	 Deneme<string,T1>::Deneme()
	 {
	 	head=last=current=NULL;
	 	count=0;
	 }
	 
	 
	template<class string,class T1>
	int Deneme<string,T1>::length()
	{
		return count;	
	}
	
	
	template<class string,class T1>
	bool Deneme<string,T1>::found_name(string names)
	{	
	    node<string,T1> *current = new node<string,T1>;
	    current = head;
	    while(current != 0 && current->name != names){
	        current = current->link;
	    }
	
	    if(current == 0){
	        return false;
	   		 }
	    else{
	        return true;
	    }
	    
	    
	}
	
	
	template<class string,class T1>
	void Deneme<string,T1>::changes(string names,T1 sectiondeg)
	{	
	
	    int counter = 1;
	    node<string,T1> *current = new node<string,T1>;
	    current = head;
	    while(current != 0 && current->name != names){
	        current = current->link;
	        counter++;
	    }
	
	    if(current == 0){
	     current->section = sectiondeg;
	    }
	
	}
	
	
	
	
	template<class string,class T1>
	void Deneme<string,T1>::insertLast(string names,T1 credits,T1 sections)
	{
		node<string,T1> *p = new node<string,T1>;
		p->credit = credits;
		p->name = names;
		p->section = sections;
		p->link = NULL;
		
		if(head!=NULL)
		{
			last->link =p;
			last = p;
		}
		else 
			head = last = p;
			
		count++;
		
	}
	
	
	
	template<class string,class T1>
	
	void Deneme<string,T1>::deleteNode(string names)
	{
		
		node<string,T1> *p,*q;
		bool found =false;
		
		if(head == NULL)
			cout<<"list is empty"<<endl;
		else
		{
			if(head->name == names)
			{
				p=head;
				head=head->link;
				delete p;
				
				count--;
					
				if(head==NULL)
					last = NULL;
						
			}
			else
			{
				p=head;
				q=head->link;
					while(q!=NULL && !found)
					{
						if(q->name == names)
							found = true;
						else
						{
							p=q;
							q=q->link;	
						}
					}
	
			if(found)
			{
				p->link = q->link;
				count--;
				if(last==q)
					last = p;
			
			delete q;
			
			}
		

			}
			
	
		}
		
			sumcredits = p->credit;
	
		}
			

	
#endif 
	
	
