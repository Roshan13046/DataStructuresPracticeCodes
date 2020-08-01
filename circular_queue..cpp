#include <iostream>
using namespace std;

template <class t>
class queue
{
	t *data;
	int size,front,rear;//FRONT AND REAR ARE INDEX POINTERS
	
	public:
		queue(int size)       //default constructor
		{
			front=0;
			rear=0;
			this->size=size +1 ;//note: using (size+1) as front index pointer always points to empty block
			data=new t [this->size]; 
		}
		//declarations 
		void insert(t ); //note to add valid index conditions
		void display();
		t delet();
		int isfull();
		int isempty();
		void first();
		void last();

};




//insert function
template<class t>
void queue<t>::insert(t x)
{

   if((rear+1)%size == front	)
   	{
   		cout<<"queue is full\n";	
    }
    else
    {
    	rear=(rear+1)%size;
    	data[rear]=x;
	}
}



//delete function
template<class t>
t queue<t>::delet()
{
    int x=-1 ;   	
	if(front == rear)
	{
		cout<<" queue is empty can't be deleted\n";
	}
    else 
    {
    	front=(front+1)%size;
    	x=data[front];
	}
	return x ;
}

//display function
template<class t>
void queue<t>::display()
{
	int i=(front+1);
	
	do                  //note to use do while loop only and also note terminating condition of it .
	{
     	cout<<data[i]<<" "; 		
     	i=(i+1)%size;
	}while(i!=(rear+1)%size);
}

//isfull check
template<class t>
int queue<t>::isfull()
{
	
	if((rear+1) %size == front )
	{
		return 1;
	}
	
	else
	  return 0;
	    
}

//isempty check
template<class t>
int queue<t>::isempty()
{
	if(front == rear)
	{
		return 1;
	}
	else
	 return 0;
}

//find first
template<class t>
void queue<t>::first()
{
	if(isempty())
		cout<<" \nQueue is Empty \n";
	else
		cout<<"\nThe first data is :"<< data[(front+1)%size]<<endl; 
	
 } 

//find last
template<class t>
void queue<t>::last()
{
	if(	isempty())
	 cout<<" \nEmpty Queue"<<endl;
	else
	 cout<<"\nThe last data is :"<<data[rear]<<endl; 	
 } 

//main function 
main()
{
  int i,n,x;
  
  cout<<"Enter Queue size :";
  cin>>n;
  queue<int> q(n);               //object formed
  
do{
	cout<<" \nEnter your choice\n 1)insert\n 2)display\n 3)delete\n 4)is full\n 5)is empty\n 6)first element\n 7)last element\n 8)exit\n\n choice : ";
	cin>>n;
    switch(n)
  {
	  
  case 1:	
        //insert  
  		cout<<"How many elements to input n =";
  		cin>>n;
        
  		cout<<"Enter the elements :";
  		for( i=0;i<n;i++)
  		{
  			cin>>x;
        	q.insert(x);
    	}	
    	break;
    
    
 case 2:   
 		//display
 		cout<<" The Queue is : ";
  		q.display();
  		break;
  		
 case 3: 		
 		//delete 
  		cout<<"\nHow many elements to delete :";
  		cin>>n;
  		for( i=0;i<n;i++)
  		{
  			q.delet();
  		}
  		break;
  
  case 4:
  		//isfull   
   		if(q.isfull())
    		cout<<"\nQueue is full"; 
   		else
    		cout<<"\nQueue is not full"; 
		break;
  
  case 5: 
  		//isempty   
   		if(q.isempty())
    		cout<<"\nQueue is empty"; 
   		else
    		cout<<"\nQueue is not empty"; 
    	break;
     
   case 6:
    
  		//first data
    	q.first(); 
    	break;
	 
   case 7:	 
  		//last data
    	q.last();
    	break;
    
   case 8:
	     exit(0); 
    
   default:
    	cout<<"Wrong choice"; 	
	}  	
 }while(1); 
	

}
