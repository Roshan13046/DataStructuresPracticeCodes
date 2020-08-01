class node
{
 public :
   		node *lchild,*rchild;
   		int data;
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









