#include<iostream>
using namespace std;

//node class
class node
{	
  public:	
	int data;
	node* next;
};
//queue class 
class queue  :public node
{
	private:
		node *front,*rear;
		
	public:
		
		queue()  //default constructor
		{
			front =rear=0;
		}
		//function declarations
	    void insert(int );	
	    void display();
	    int delet();
	    int isempty();
	    int isfull();
	    int first();
	    int last();
};

//first fun def
int  queue:: first()
{
	int x=-1;
	if(   isempty()  )
		cout<<"Empty Queue";
	else
	{
		x=front->data;
	}	
	return x;	
}

//last fun def
int  queue:: last()
{
	int x=-1;
	if(   isempty()  )
		cout<<"Empty Queue";
	else
	{
		node *temp=front;
		
		while(temp->next)
		{
			temp=temp->next;
		}
		x=temp->data;
	}	
	return x;	
}

//isempty fun def
int queue::isempty()
{
	if(front ==0 && rear==0)
	{
    	return 1;   
	}
     else
		return 0;		
}

//isfull fun def
int queue::isfull()
{
	node *temp=new node;
	if(temp == 0 )
	{
    	return 1;   
	}
     else
		return 0;		
}

///delete fun def
int queue::delet()
{
	int x=-1;
	if(front ==0 && rear==0)
	{
		cout<<"Empty Queue";
	}
	else
	{
		if(front == rear)
		{
			node *temp=front;
			front=front->next;
			rear=rear->next;
			x=temp->data;
			delete temp;
		}
		else
		{
			node *temp=front;
			front=front->next;
			x=temp->data;
			delete temp;	
		}
		
	}
	cout<<"\nDelete :"<<x<<endl;
	return x;
}

//display fun def
void queue::display()
{
	cout<<" # The Queue is : ";
	node *temp=front;
	
	while(temp !=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

//insert fun def
void queue::insert(int x)
{
	node *temp=new node;
   if(temp ==0)
   	cout<<"Heap is full";
	else
	{ 
	    temp->data=x;
		temp->next=0;
		
		if(rear==0 && front==0)
		{	
			front=rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;	
		}  
	}     	
}

//main fun 
main()
{
	int n,x;
	
	queue q;
	
	do
	{
		cout<<"\n # Enter your choice of operation :\n 1)insert\n 2)display\n 3)delete\n 4)fiirst-element\n 5)last-element\n 6)exit\n\n choice : ";
	    cin>>n;
	 switch(n)
	{
	
	//insert
	case 1:
		cout<<"\n # How many elements to enter n = ";
		cin>>n;
		cout<<" # Enter the Data elements = ";
		for(int i=0;i<n;i++)
		{
			cin>>x;
			q.insert(x);
		}
		cout<<endl;
		break;
	
	//display 
	case 2:
		
		q.display();
		cout<<endl;
		break;
	
	//delete
	case 3:
		cout<<"\n # How many elements to delete : ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
	  		q.delet();
		}
		cout<<endl;
    	break; 	
	
	//first
	case 4:
		cout<<" \n # The First element is : "<<q.first();
		cout<<endl;
		break;
	
	//last
	case 5:
   		cout<<" \n # The Last element is : "<<q.last();
   		cout<<endl;
   		break;
   	
   	//last
   	case 6:
   		exit(0);
   		break;
   		
    //last    		
    default:
	    cout<<"Wrong choice";		
	}
			
	}while(1);
	

} 




