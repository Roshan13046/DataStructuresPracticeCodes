#include<iostream>

using namespace std;
#include "classtreeheader.h"


class tree 
{ private:
	    node *root;
	
	public:
			tree()//default constructor
			{
				root=0;
			}
			void treecreate();
			
			void preorder(node *);
			void preorder()   //note: best use of function overloading
			{
			  preorder(root);	
			}
			
			void inorder(node *);
			void inorder()   
			{
				inorder(root);    //note: best use of function overloading
			}
			
			void postorder(node *);	
			void postorder()
			{
				postorder(root); //note: best use of function overloading
			}
			
					
};

void tree::treecreate()
{
	node *p,*t;
	int x;
	
	queue q(100);
	cout<<"Enter root value : ";
	cin>>x;
	root=new node;
	root->data=x;
	root->lchild = root->rchild=0;
	q.enqueue(root);
	
	while(! q.isempty())
    {
	
    	p= q.dequeue();
    	
    	cout<<"Enter left child value of "<<p->data<<" : ";
    	cin>>x;
    	if(x != -1)
    	{
    		t=new node;
    		t->data=x;
    		t->lchild=t->rchild=0;
    		p->lchild=t;
    		q.enqueue(t);
		}
		
		cout<<"Enter right child value of "<<p->data<<" : ";
    	cin>>x;
    	if(x != -1)
    	{
    		t=new node;
    		t->data=x;
    		t->lchild=t->rchild=0;
    		p->rchild=t;
    		q.enqueue(t);
		}
   }
}


void tree::preorder(node *p) 
{
     //nlr
     if(p)    //remember to put the terminating if condition
     {
      cout<<p->data<<" ";
	  preorder(p->lchild);	
	  preorder(p->rchild);     	
	 }

}

void tree::inorder(node *p)
{
	//lnr
	if(p)    //remember to put the terminating if condition
	{
	 inorder(p->lchild);
	 cout<<p->data<<" ";
	 inorder(p->rchild);	
	}

}

void tree::postorder(node *p)
{
	//lrn
	if(p)    //remember to put the terminating if condition
	{
     postorder(p->lchild);
	 postorder(p->rchild);
	 cout<<p->data<<" ";		
	}

}

main()
{
	tree t;
	t.treecreate();
	
	cout<<"\n# The PREORDER is : ";
//	t.preorder(root);                  //note:ERROR cant access private variable  root  from non member function 
	t.preorder();
	
	cout<<"\n# The INORDER is : ";
	t.inorder();
	
	cout<<"\n# The POSTORDER is : ";
	t.postorder();
}


