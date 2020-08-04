class node
{
 public :
   		node *lchild,*rchild;
   		int data;
};

//faulty program
class stack_node
{
  public:		
         node* data1;
         stack_node * next;
  	
};






class stack
{
	
  public:		
   stack_node *top;
	
  public:
  	
  	stack()
  	{
  		top=0;
	}
  	
    void push(node * x)	
    {
    	
    	stack_node *t =new stack_node ;
    	if(t== 0)
    	{
    		cout<<"stack overflow";
		}
		else
		{
			t->data1 = x;
			t->next=top;
			top=t;
		}
	}
	
	node * pop()
	{
		node *p,*q;
		
		if(top == 0 )
		{
			cout<<"Empty stack";
		}
		else
		{
			p=top->data1;
			top=top->next;
			q=p;
			delete(p);
		}
		return q;
	}
	
	
	
};









class queue
{
	private:
			node **qdata;
			int size,front,rear;
	public:
			queue(int size)
			{
				this->size=size;
				front=rear=0;
				qdata=new node*[size];
			}
			
			void enqueue(node*);
			node* dequeue();
			int isempty();
};


void queue::enqueue(node* x)
{

   if((rear+1)%size == front	)
   	{
   		cout<<"queue is full\n";	
    }
    else
    {
    	rear=(rear+1)%size;
    	qdata[rear]=x;
	}
}




//delete function
node* queue::dequeue()
{
    node *x=0 ;   	
	if(front == rear)
	{
		cout<<" queue is empty can't be deleted\n";
	}
    else 
    {
    	front=(front+1)%size;
    	x=qdata[front];
	}
	return x ;
}


//isempty
int queue::isempty()
{
	return(front == rear);
}









