#include <iostream>
using namespace std;

template <class t>
class node{
	public:
		t data;
		node<t>*next;
		
	node(t data):data(data){next=NULL;}	
	node()
	{
		next=NULL;
	}
		
};

template <class t>
class linkedlist{
	
	int size=0;
	public:
		node<t>*head=NULL;
		bool isEmpty(){
			if (head==NULL) 
			 return true;
			return false;	
		}
		int length()
		{
			if(!isEmpty())
			{
				node<t>*temp=head;int l=0;
				while(temp->next!=NULL) //we are directly using temp as we want to reach last element
				{
					temp=temp->next;
					l++;
				}
				return l;	
			}
			return -1;	
		}
		
		void insertionfront(t data)
		{
			node<t>*nn=new node<t>(data);
			if (isEmpty())
			{
				head=nn;
				nn->next=NULL;	
			}
			else
			{
				node<t>*temp=head;
				head=nn;
				nn->next=temp;
			}
			size++;
			cout<<"Node added at start"<<endl;
				
		}
		void insertionback(t data)
		{
			node<t>*nn=new node<t>(data);
			if (isEmpty())
				head=nn;
			else
			{
				node<t>*temp=head;
				while (temp->next!=NULL)
				{
					temp=temp->next;	
				}
				temp->next=nn;	//old empty now point to the address of new
			}
			nn->next=NULL;
			size++;
			
				
		}
		void insertionatindex(t data,int idx)
		{
			if (isEmpty()||idx==0)
			 insertionfront(data);
			 
			else if(idx==length()+1)
			 insertionback(data);
			 
			else if(idx>0 && idx<=length()) //eg if length is 3 and user enters 3 now 3rd node moved to 4th and new node
			{                                 // added at 3 index
			    node<t>*nn=new node<t>(data);
			    node<t>*temp=head;
			    int i=0;
				while(i<idx-1)
				{
					temp=temp->next; //in secondlast we will have address of required will return -1 ith of required
					i++; //if idx=1 l=2 and i=1 then will not work 0th node returned 
						
				}
				nn->next=(temp->next);//important
				temp->next=nn;
				size++;
				cout<<"Node added in middle"<<endl;
			}
			else
			 cout<<"Entered index is out of bounds"<<endl;
			 	
		}
		void deletionfront()
		{
			if(!isEmpty())
			{
				node<t>*temp=head;
			    temp=temp->next;
			    delete head;
			    head=temp;	
			    
			    size--;
			}
			else  
			 cout<<"Linked List is Empty"<<endl;	
		}
		void deletionback()
		{
			if(!isEmpty())
			{
				int l=0;
				node<t>*temp=head;
			    while(temp->next->next!=nullptr)
			    {
			    	temp=temp->next;
			    	l++;
				}
				delete temp->next;
				temp->next=NULL;
				size--;
				
			}
			else  
			 cout<<"Linked List is Empty"<<endl;
			
		}
		void deletionbyindex(int idx)
		{
			if(!isEmpty())
			{
				if(idx==0)//deletion start
			     deletionfront();
	            else if(idx==length())
			     deletionback();
				else if(idx>0 && idx<length())
				{
					node<t>*temp1=head;int i=0;
					while (i<idx-1)//works for 1 less than required
					{
						temp1=temp1->next;
						i++;
					}
					node<t>*temp2=temp1->next->next;
					delete temp1->next;
					temp1->next=temp2;
					size--;
					cout<<"Node deleted in the middle"<<endl;	
				}		
			}
			else
			 cout<<"Linked List is Empty"<<endl;	
		}
		void deletionbyvalue(t val)
		{
			if(!isEmpty())
			{
				node<t>*temp=head;int i=0;bool found=false;//i there so maybe deletion at front or back needed
				while(!found && temp!=NULL)
				{
					if(temp->data==val)
					 found=true;
					else
					{
						temp=temp->next;
					    i++;	
					}
				}
				if(found)
				{
					 deletionbyindex(i);//will handle all	
				}
				else 
				 cout<<"Value of linked List not found"<<endl;
			}
			else
			 cout<<"Linked List is Empty"<<endl;
			
		}
		
		~linkedlist()
		{
			node<t>*temp=head;int n=1;
			while(temp!=NULL) //or loop deletion front
			{
				temp=temp->next;
				delete head;
				head=temp;
				cout<<"Node "<<n<<" deleted"<<endl;
				n++;
			}
		}
		
};
	class block{
		public:
			int startbyteid;
			int totalbytes;
			
		block(int startbyteid, int totalbytes)
		{
			this->startbyteid=startbyteid;
			this->totalbytes=totalbytes;
		}
		
		void displayblock()
		{
			cout<<"[ "<<startbyteid<<" | "<<totalbytes<<" ]-> ";
		}
	
	};

	class program{
		
		public:
		int id;
		int sizereq;
		
		
	
	   
	program(int i,int si)
	{	
		id=i;
		sizereq=si;
		
	}
	
	void displayprogram()
	{
		cout<<"[ "<<id<<" | "<<sizereq<<" ]-> ";
	}
		
};
	class MemoryManagementSystem{
		
		linkedlist <block>pool; 
	    linkedlist <program>programs;
	    int sizemem;
	    bool strategy;//strategy 0=first,1=best
	    public:
	    	
	    MemoryManagementSystem(int size,bool s)
	    {
	    	
	    	sizemem=size;
	    	strategy=s;
	    	addblocktopool(size);
	    	
	    	
		}
		
		void addblocktopool(int total)
		{ 
		  block b(0,total);
		  pool.insertionback(b);
		  
		}
		
		
		
		
		bool getmem(int si)
		{
			
			bool add=false;
			node<block>*temp=pool.head;
			while(temp!=NULL)
			{
				if(temp->data.totalbytes>=si)
				{
					add=true;
				}
				temp=temp->next;
			}
			
			return add;
			

		}
		
		void addprogramtoprograms(int si)
		{
			
			if(getmem(si))
			{
				
				int start;
				int size;
				

				if(!strategy)//first fit
				{
					
					int i=0;
					bool run=true;
					node<block>*temp=pool.head;
					
					while(temp!=NULL && run)
					{
						if(temp->data.totalbytes>=si)
						{
							run=false;
							start=temp->data.startbyteid;
							size=temp->data.totalbytes;
							pool.deletionbyindex(i);
							block b(si+start,size-si);
							pool.insertionback(b);
							poolsorting();
							poolmerging();
							program p(start,si);
							programs.insertionback(p);
							
							
						}
						temp=temp->next;
						i++;
					}
					
				}
				else
				{
					int i=0,minsize=sizemem+1,minindex;
					node<block>*temp=pool.head;
					while(temp!=NULL)
					{
						if(temp->data.totalbytes>=si)
						{
							if(temp->data.totalbytes<minsize)
							{
								minsize=temp->data.totalbytes;
								minindex=i;
							}	
						}
						temp=temp->next;
						i++;
					}
					temp=pool.head;
					i=0;
					while(i<=minindex && temp!=NULL)
					{
						if(i==minindex)
						{
							start=temp->data.startbyteid;
							size=temp->data.totalbytes;
							pool.deletionbyindex(i);
							block b(si+start,size-si);
							pool.insertionback(b);
							poolsorting();
							poolmerging();
							program p(start,si);
							programs.insertionback(p);	
						}
						temp=temp->next;
						i++;
					}
					
				}
				
			}
			else
			 cout<<"INSUFFICIENT SPACE FOR PROGRAM"<<endl;
		}
		
		void poolsorting()
		{
			if(!pool.isEmpty())
			{
				node<block>*temp;int start,total;bool swap=true;
				while(swap==true)
				{
					temp=pool.head;//important as after every pass have to start from 0th
					swap=false;//if this unchanged not a single swap took place
					while(temp->next!=NULL)
					{
						if((temp->data.startbyteid)>(temp->next->data.startbyteid))
						{
							swap=true;
							start=temp->data.startbyteid;
							total=temp->data.totalbytes;
							temp->data.startbyteid=temp->next->data.startbyteid;
							temp->data.totalbytes=temp->next->data.totalbytes;
							temp->next->data.startbyteid=start;
							temp->next->data.totalbytes=total;									
						}	
						temp=temp->next;	
					}
				}
			}
			else
			 cout<<"Linked list is Empty so cannot be sorted"<<endl;	 
		}
		
		void poolmerging()
		{
			node<block>*temp=pool.head;int i=0;
			if(temp->next!=NULL)
			{
				
				while(temp->next!=NULL)
				{
					if((temp->data.totalbytes)==(temp->next->data.startbyteid ))
					{
						temp->data.totalbytes=temp->next->data.startbyteid+temp->data.totalbytes;
						pool.deletionbyindex(i+1);		
					}
					else
					{
						i++;
				
						temp=temp->next;
							
					}		
				}
				
			}
		
		}
		
		void terminateprogram(int id)
		{
			if(!pool.isEmpty())
			{
				node<program>*temp=programs.head,*ahead;
				int i=0,size;bool found=false;
			    while(temp!=NULL)
			    {
			    	if(temp->data.id==id)
			    	{
			    		found=true;
			    		ahead=temp->next;
			    		size=temp->data.sizereq;
			    		programs.deletionbyindex(i);
						block b(id,size);
						pool.insertionback(b);
						poolsorting();
						poolmerging();
			    		temp=ahead;
					}
					else
					{
						temp=temp->next;	
						i++;
						
					}
					
					
			    }
				if(!found)	
				 cout<<"Program of entered id does not exist"<<endl;
				
				
			}
			else  
			 cout<<"Linked List is Empty"<<endl;	
			
		}
		
		void displaypool()
		{
			if(!pool.isEmpty())
			{
				node<block>*temp=pool.head;
			    while(temp!=NULL)
			    {
					
					temp->data.displayblock();
					temp=temp->next;	
			    }
				cout<<"NULL"<<endl;	
			}
			else  
			 cout<<"Linked List is Empty"<<endl;	
		}
		
		void displayprograms()
		{
			if(!pool.isEmpty())
			{
				node<program>*temp=programs.head;
			    while(temp!=NULL)
			    {
					
					temp->data.displayprogram();
					temp=temp->next;	
			    }
				cout<<"NULL"<<endl;	
			}
			else  
			 cout<<"Linked List is Empty"<<endl;	
		}

};



int main()
{
	MemoryManagementSystem os(100,1);
	os.addprogramtoprograms(20);
	os.addprogramtoprograms(30);
	os.addprogramtoprograms(40);
	os.displaypool();
	os.displayprograms();
	
	cout<<endl;
	
	os.terminateprogram(0);
	os.addprogramtoprograms(10);
	os.displaypool();
	os.displayprograms();
	

	system("pause");
	return 0;
}
