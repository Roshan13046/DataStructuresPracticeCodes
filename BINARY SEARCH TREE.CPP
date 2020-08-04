#include<iostream>
using namespace std;
#include "classtreeheader.h "  ;


class bst
{
	public:
			node *root;
		

	public:
			bst()  //default constructor
			{
				root = 0;	
			}
		    void create( int ) ;		    
		   
		    node* search(int ) ;
		    node* rsearch(int key) 
		    {	
		    	rsearch(root , key);
			}
			node* rsearch(node* , int );
		    
		    void inorder( node * );
		    void inorder()
			{
				inorder(root);
			}
            			
			node* delet(node *, int);
			node* delet(int key)
			{
				 return delet(root, key);
			}
			
			
			node* inpredecessor(node *);
			node* insuccessor(node*);
		    int height(node*);
		    
		    //generate tree from preorder
		    
		    void create_pre(int  [],int );

};


void bst ::create_pre(int pre[],int n)
{
	stack stk;
	node *t,*p;
	int i=0;
	
	root= new node;
	root->data = pre[i];
	root->lchild=root->rchild=0;
	p=root;
	i++;
	while(i<n)
	{
		if(pre[i] < p->data)
		{
			t=new node;
			t->data=pre[i];
			t->lchild=t->rchild=0;
			stk.push(p);
			p->lchild=t;
			p=t;
			i++;
		}
		
		else if(pre[i] > p->data)
		{
			
			t=new node;
			t->data=pre[i];
			t->lchild=t->rchild=0;
			if( pre[i] <  stk.top->data1->data)
			{
			  p->rchild=t;
			  p=t;
			  i++;	
			}
			else
			{
				p=stk.pop();
			}
		}
	}
	
	
	
	
	
}



node* bst :: delet(node *p ,int key)
{
	 node *q=0;	
	
	if(p == 0)                    
		return 0;
	if(p->lchild == 0 && p->rchild==0)	//leaf node logic
	{
		if(p == root)    // if root logic
			root=0;
		delete p;
		return 0;	
	}
	
	if(key < p->data)
		p->lchild = delet(p->lchild,key);
		
	else if(key > p->data)
		p->rchild = delet(p->rchild,key);	
		
	else if(key == p->data)	
	{
		if(height(p->lchild) > height(p->rchild))
		{
			q = inpredecessor(p->lchild);            //modification of more than one node
			p->data = q->data;
			p->lchild = delet( p->lchild , q->data );
		}
		else
		{
			q = insuccessor(p->rchild);
			p->data = q->data;
			p->rchild = delet( p->rchild, q->data ); //modification of more than one node
		}
	}
//	cout<<"Delet working \n";
	return p;
}
//prdecessor function

node* bst:: inpredecessor(node *t)
{
	while(t && t->rchild !=0)
		t=t->rchild;
	return t;	
}

//insuccessor function

node* bst:: insuccessor(node *t)
{
	while(t && t->lchild !=0)
		t=t->lchild;
	return t;	
}

//height funcion

int bst :: height( node *p) 
{
	int x , y;
	x = height(p->lchild);
	y = height(p->rchild);
	
	return (x>y ? x+1 : y+1 ); 
}



//create function
void bst :: create(int key)
{
	node *p,*follower;
	node *t=root;
	
	if(root== 0)
	{
	    p=new node() ;
		p->data	= key;
		p->lchild=p->rchild=0;
		root = p;
	}
	//search element
	else
	{
		while( t != 0)
		{
			follower = t;
		
			if(key < t->data)
			{
				t=t->lchild;
			}
			else if(key > t->data)
			{
				t=t->rchild;
			}
			else
				return ;
		}
		p=new node ;
		p->data =key;
		p->lchild=p->rchild=0;
		
		if(key < follower->data)
		{
			follower->lchild = p;
		}
		else
		{
			follower->rchild = p;
		}
	}
}







//iterative search
node* bst :: search(int key)
{
	node *t=root;
	while(t != 0 )
	{
		if(key == t->data)
			return t;
			
		else if(key >t->data)
			t=t->rchild;
		else
			t=t->lchild;		
	}
	cout<<" Not found \n";
	return 0;
}


//recursive search
node* bst:: rsearch(node *t ,int key)	
{
	if(t== 0)
		return 0;
	else if(key == t->data)	
		return t;
	else if(key < t->data)	
		return (rsearch(t->lchild ,key));
	else if(key > t->data)	
		return (rsearch(t->rchild , key));	
}


//inorder function
void bst::inorder(node *p) 
{
	if(p)
	{
		inorder(p->lchild);
		cout<< p->data<<" ";
		inorder(p->rchild);
	}
}


//main function
main()
{
	bst b;
	node *temp=0;
	int n, i ,key,a[100];
	
	
	
	//iterative create
	cout<<" How many elments to enter : ";
	cin>> n;
	for( i = 0 ; i<n ;i++)
	{
		cout<<" Enter Elment no "<< i+1 <<" : ";
		cin>>key;
		b.create(key);
	}
	
	//search
	cout<<" Enter search element : ";
	cin>>key;
	cout<<" The search term is at node address :" << b.search(key)<<endl;
	
	//recursive search
	cout<<" Enter recursive search element : ";
	cin>>key;
	temp = b.rsearch(key);
	if(temp !=0 )
		cout<<" The search term is at node address :" <<temp<<endl;
	else
		cout<<"Element  not found ";
	
	//inorder display
	cout<<" The Inorder Traversal is : ";
	b.inorder();
	
	
	
	
	//generate tree from preorder traversal
	cout<<"Total elements of new tree n = ";
	cin>>n;
	cout<<"Enter the preorder form of new tree : ";
	for(i=0 ;i<n;i++)
	{
	  	cin>>a[i];	
	}
	bst bnew;
    bnew.create_pre(a,n);
	bnew.inorder();
	
	
	//delete 
	cout<<" \n Enter the element to delete : ";         //not working properly
	cin>>key;
	b.delet(key);
	
	//inorder display 
	cout<<"\n The Inorder Traversal is : ";
	b.inorder();
}

























/*

void print(struct node *root, int k)
{
    if (root != NULL && count <= k)
    {
        print(root->right, k);
        count++;
        if (count == k)
          printf("%d ", root->data);
       print(root->left, k);
    }
}
A









A Binary Search Tree (BST) stores values in the range 37 to 573. Consider the following sequence of keys.

I.  81, 537, 102, 439, 285, 376, 305

II. 52, 97, 121, 195, 242, 381, 472

III. 142, 248, 520, 386, 345, 270, 307

IV. 550, 149, 507, 395, 463, 402, 270 

Suppose the BST has been unsuccessfully searched for key 273. Which all of the above sequences list nodes in the order in which we could have encountered them in the search?
A
II and III only
B
I and III only
C
III and IV only
D
III only

















Consider the following Binary Search Tree

               10
             /    
            5      20
           /      /             
          4     15    30
               /  
              11       
If we randomly search one of the keys present in above BST, what would be the expected number of comparisons?
2.75
B
2.25
2.57
D
3.25


*/
