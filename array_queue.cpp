#include <iostream>
using namespace std;

template <class t>
class queue
{
	t *data;
	int size,front,rear;//FRONT AND REAR ARE INDEX POINTERS
	
	public:
		queue(int s)       //default constructor
		{
			front=-1;
			rear=-1;
			size=s;
			data=new t [size];
		}
		//declarations 
		void insert(t );
		void display();
		void delet();
		void isfull();
		void isempty();
		void first();
		void last();

};




//insert function
template<class t>
void queue<t>::insert(t x)
{

   if(front== size-1)	
   	{
   		cout<<"queue is full";	
    }
    else
    {
    	rear++;
    	data[rear]=x;
	}
}



//delete function
template<class t>
void queue<t>::delet()
{
	if(front == rear)
	{
		cout<<"queue is empty";
	}
    else 
    {
    	front++;
	}
}

//display function
template<class t>
void queue<t>::display()
{
	if(front == rear)
		cout<<"Empty Queue\n";
		
	
	else if(front == -1)
	{
		cout<<"The Queue is :";
		for(int i=0  ;i<=rear;i++)
			cout<<data[i]<<" ";
	    cout<<endl;
	}	
	else
    {
      cout<<"The Queue is :";
	 for( int i=front+1;i<=rear;i++)
	 { 
		cout<<data[i]<<" ";
	 } 
	 cout<<endl;	
	}
	
}

//isfull check
template<class t>
void queue<t>::isfull()
{
	if(rear == size-1 && front!=rear)
		cout<<"Queue is full"<<endl;
	else
	   cout<<"Queue is not full"<<endl;
	    
}

//isempty check
template<class t>
void queue<t>::isempty()
{
	if(front ==rear)
		cout<<"Queue is empty"<<endl;
	else
	    cout<<"Queue is not empty "<<endl;	
}

//find first
template<class t>
void queue<t>::first()
{
	if(rear==-1 || front == rear)
	 cout<<"Empty Queue"<<endl;
	else
	 cout<<"The first data is :"<< data[front+1]<<endl; 
	
 } 

//find last
template<class t>
void queue<t>::last()
{
	if(rear==-1 || front == rear)
	 cout<<"Empty Queue"<<endl;
	else
	 cout<<"The last data is :"<<data[rear]<<endl; 	
 } 

//main function 
main()
{
  
  int i,n,x;
 
     
//insert  
  cout<<"How many elements to input n =";
  cin>>n;
  
   queue<int> q(n);               //object formed
  
  cout<<"Enter the elements :";
  for( i=0;i<n;i++)
  	{
  		cin>>x;
        q.insert(x);
    }	
    
 //display
  q.display();
 
 //delete 
  cout<<"\nHow many elements to delete :";
  cin>>n;
  for( i=0;i<n;i++)
  {
  	q.delet();
  }
  q.display();
  
  //isfull   
   q.isfull(); 
   
  //isempty   
   q.isempty();  
    
  //first data
    q.first(); 
	 
  //last data
    q.last();
  
}
