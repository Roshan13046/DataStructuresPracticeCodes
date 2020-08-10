

#include<iostream>
using namespace std;

#define n 7


///////////////////////////////////////////////////////////header file queue using link list///////////////////////////////////////////////////////


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
	    int delet();
	    int isempty();
	
};


//isempty fun def
int queue::isempty()
{
	if(front == 0 && rear== 0)
	{
    	return 1;   
	}
     else
     {
     //	cout<<"Is not empty";
    	return 0; 	
	 }
	
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
	return x;
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//bfs function
void bfs(int a[][n+1],int start)
{
	
	int visited[n+1]={0};
	int u,v;
	queue q;
	
	
	cout<<start<<" ";
	visited[start]=1;
	q.insert(start);
	
	while( ! q.isempty())
	{
		u=q.delet();
	
		for(v=1;v<=n;v++)
		{
			if(a[u][v] == 1 && visited[v] == 0)
			{
				cout<<v<<" ";
				visited[v]=1;
				q.insert(v);
			}
		}
	}
}
//////////////////////////////////////////stack function for dfs ///////////////////////////////////////////////////////////////////

class stack
{
	
  public:		
   node *top;
	
  public:
  	
  	stack()
  	{
  		top=0;
	}
  	
    void push(int x)	
    {
    	
    	node *t =new node ;
    	if(t== 0)
    	{
    		cout<<"stack overflow";
		}
		else
		{
			t->data = x;
			t->next=top;
			top=t;
		}
	}
	
	int pop()
	{
		node *p;
		int x;
		
		if(top == 0 )
		{
			cout<<"Empty stack";
		}
		else
		{
			p=top;
			x=top->data;
			top=top->next;
			delete(p);
		}
		return x;
	}
	
	int isempty()
	{
		if(top == 0 )
			return 1;
		else
			return 0;	
	}
	
	
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






//dfs function
//bfs function
void dfs(int a[][n+1],int start)
{
	
	int visited[n+1]={0};
	int u,v;
	stack s;
	
	
	cout<<start<<" ";
	visited[start]=1;
	s.push(start);
	
	while( ! s.isempty())
	{
		u=s.pop();
	
		for(v=1;v<=n;v++)
		{
			if(a[u][v] == 1 && visited[v] == 0)
			{
				cout<<v<<" ";
				visited[v]=1;
				s.push(v);
			}
		}
	}
}

//dfs using recursion
void recursive_dfs(int a[][n+1],int start)
{
	static int visited[n+1]={0};

	if( visited[start]== 0)
	{
		cout<<start<<" ";
		visited[start]=1;
		
		for(int v=1;v<=n;v++)
		{
			if(a[start][v] == 1 && visited[v]==0)
				recursive_dfs(a,v);
		}
		
	}
}




main()
{
	int a[n+1][n+1]=
	{ 0,0,0,0,0,0,0,0,
	  0,0,1,1,1,0,0,0,
	  0,1,0,1,0,0,0,0,
	  0,1,1,0,1,1,0,0,
	  0,1,0,1,0,1,0,0,
	  0,0,0,1,1,0,1,1,
	  0,0,0,0,0,1,0,0,
	  0,0,0,0,0,1,0,0            
	};
	int choice,start;

	
	
	do{
		cout<<"\n\n Enter your choice of operation \n 0)exit \n 1)BFS \n 2)DFS using stack  \n 3)recursive DFS \n\n choice : ";
	    cin>>choice;
	    cout<<endl;
		switch(choice)
		{
			case 0:
					exit(0);
			
			case 1:
					cout<<" Enter from which vertex to start : ";
					cin>>start;
					cout<<"\n * Breadth first search is : ";
					bfs(a,start);
					break;
	    
	    	case 2:
	    			cout<<" Enter from which vertex to start : ";
					cin>>start;
	    			cout<<"\n * Depth first rule is :";
	    			dfs(a,start);
	    			break;
	    		
	    	case 3:
	    			cout<<" Enter from which vertex to start : ";
					cin>>start;
					cout<<"\n * Recursive Depth first rule is :"; ///working problem if same recursion case is run again and again
	    			recursive_dfs(a,start);
	    			break;
	    		
			
			default:
				cout<<"Invalid  choice";
			
		}
		cout<<"\n\n***************************************************************************************************************";
				
	}while(1);
	
	
}









