#include<iostream>
using namespace std;




struct node
{
	int data;
	char color;
	node*lchild,*parent,*rchild;
	
}*root=0,*t;








//left rotate
node* left_rotate(node* x)
{
	node* y=x->rchild;
	x->rchild=y->lchild;
	y->lchild->parent=x;
	y->parent=x->parent;
	if(x->parent == 0)
		root=y;
	else if(x==x->parent->lchild)	
		x->parent->lchild=y;
	else
		x->parent->rchild=y;
	y->lchild=x;
	x->parent=y;
	
	return x;		
}


//right rotate
node* right_rotate(node* x)
{
	node* y=x->lchild;
	x->lchild=y->rchild;
	y->rchild->parent=x;
	y->parent=x->parent;
	if(x->parent == 0)
		root=y;
	else if(x==x->parent->rchild)	
		x->parent->rchild=y;
	else
		x->parent->lchild=y;
	y->rchild=x;
	x->parent=y;
		
	return x;		
}



node* fixup(node *p,node *z )
{
	node*y;
	
	while(z->parent->color == 'r' ) 
	{		
		if(z->parent == z->parent->parent->lchild)
		{
			y=z->parent->parent->rchild;
			if(y->color == 'r')
			{			
				z->parent->color ='b';
				y->color='b';
				z->parent->parent->color='r';
				z=z->parent->parent;
			}
			else if(z == z->parent->rchild)
			{
				z=z->parent;
				z=left_rotate(z);//changes
				z->parent->color='b';
				z->parent->parent->color='r';
				z->parent->parent=right_rotate(z->parent->parent);
			}
		}
		
		
		else if(z->parent == z->parent->parent->rchild)
		{		
			y=z->parent->parent->lchild;		
		   	   
			if(y->color == 'r' )
			 {
				z->parent->color ='b';
				y->color='b';
				z->parent->parent->color='r';
				z=z->parent->parent;	
			 }
			 else if(z == z->parent->lchild)
			 {				
				z=z->parent;
				z=right_rotate(z);
				z->parent->color='b';
				z->parent->parent->color='r';
				z->parent->parent=left_rotate(z->parent->parent);
			 }
	
			
		}
		
		root->color='b';
	}
	return z;
}




//in successor function
node* inorder_successor(node* t)
{
	while(t && t->lchild !=0)
		t=t->lchild;
	return t;	
}


//del fixup fun
void del_fixup(node* x)
{
	
	node* lw=x->parent->lchild; //w
	node* rw=x->parent->rchild; //w
	 
	 
	
	if(lw == x  ) //deleted node is lchild
	{
	 	if(rw->color=='r')                             //case 1
	 	{
	 		rw->color='b';
	 		if(x->parent->color=='b')
	 			x->parent->color='r';
	 		else if(x->parent->color=='r')
	 			x->parent->color='b';	
	 		x->parent=left_rotate(x->parent);	
		}
		
		else if(rw->color =='b' && rw->lchild==0 && rw->rchild==0) //case 2 
		{
			rw->color ='r';
			x=x->parent;
		}
		
		
		else if(rw->color =='b' && rw->lchild->color=='r')                 //case 3
		{
			rw->color ='r';
			right_rotate(rw);
		}
		
		
		else if(rw->color=='b' && rw->rchild->color=='r')            //case 4
		{
			rw->color ='r';
			x->parent->color='b';
			
			if(rw->rchild->color=='b')
				rw->rchild->color='r';
			else if(rw->rchild->color=='r')
				rw->rchild->color='b';
				
			left_rotate(x->parent);
			root=x;	
		}		
	}
	 
	else if(rw==x)  //deleted node is rchild
	 {
	 	if(lw->color=='r')                             //case 1
	 	{
		 
	 		lw->color='b';
	 		if(x->parent->color=='b')
	 			x->parent->color='r';
	 		else if(x->parent->color=='r')
	 			x->parent->color='b';	
	 		x->parent=right_rotate(x->parent);	
		} 
		
		else if(lw->color =='b' && lw->lchild==0 && lw->rchild==0) //case 2 
		{
			lw->color ='r';
			x=x->parent;
		}
		
		
		else if(lw->color =='b' && lw->lchild->color=='r')                 //case 3
		{
			lw->color ='r';
			left_rotate(lw);
		}
		
		
		else if(lw->color=='b' && lw->rchild->color=='r')            //case 4
		{
			lw->color ='r';
			x->parent->color='b';
			
			if(lw->rchild->color=='b')
				lw->rchild->color='r';
			else if(lw->rchild->color=='r')
				lw->rchild->color='b';
				
			right_rotate(x->parent);
			root=x;	
		}	
	 }
  x->color='b';	
}






//deletion fun
node* del(node *z)
{
	node* y=0,*x=0;
	
	if(z->lchild == t || z->rchild== t) //t= nil t
		y=z;
	else
		y=inorder_successor(z)		;
	if(y->lchild != t)	
		x=y->lchild;
	else
		x=y->rchild;	
	
	x->parent=y->parent;
	if(y->parent == t)        //delete root node
		root=x;
	else if(y== y->parent->lchild)	
		y->parent->lchild=x;
	else
		y->parent->rchild=x;	
	
	if(y != z)
		z->data=y->data;
	
	if(y->color == 'b')
		x=del_fixup(x);
	
	return y;
}









//insert function
void insert(node * x,int key)
{
//*********************************************************************	//fault in using nil pointer
	  	t=new node;
	  	t->data=-1;
	  	t->lchild=t->rchild=t->parent=0;
	  	t->color='b';
	
//************************************************************************************************************	
	
	node *z=new node;
	z->data=key;
	z->lchild=z->rchild=t;
	z->color='r';
	z->parent=t;
	
	node* y=0;
	
	while(x!=0)
	{
		y=x;
		if(z->data < x->data)
			x=x->lchild;
		else
			x=x->rchild;			
	}
	
	z->parent=y;
	if(y == 0)
		root=z;
	else if (z->data <y->data)
		y->lchild=z;
	else
		y->rchild=z;
	
	
	root->color='b';
	if(z->parent !=0 && z->parent!=root )
		z=fixup(root,z)	;
 
}

void pre_order(node *p)
{
	if(p !=t )//
	{
		cout<<p->data<<" ";
		pre_order(p->lchild);
		pre_order(p->rchild);
	}
}




main()
{
	int i,n,key;
	
	
	cout<<"How many elements to enter n : ";
	cin>>n;
	cout<<"Enter the elmemnts : ";
	for(i=0;i<n;i++)
	{
		cin>>key;	
		insert(root,key);	
	}
	
	cout<<" \n The preorder traversal is : ";
	pre_order(root);
	
	
}
