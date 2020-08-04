#include<math.h>
#include<iostream>
using namespace std;



struct node
{
	node *lchild ,*rchild;
	int data,height;
	}*root =0;



//node height 

int node_height(node* p)
{
	int hl,hr;
	
	hl=p->lchild && p ? p->lchild->height:0;
	hr=p->rchild && p ? p->rchild->height:0;
	
return hl > hr ? hl+1 : hr+1;                             //height starts from 1
}

//balannce factor
int bal_factor(node * p)
{
	int hl,hr;
	
	hl=p->lchild && p?p->lchild->height:0;
	hr=p->rchild && p?p->rchild->height:0;
	
	return hl-hr;
}

//ll rotation
node* ll_rotation(node *p)
{
	node* pl=p->lchild;
	node* plr=pl->rchild;
	
	p->lchild=plr;
	pl->rchild=p;
	
	p->height=node_height(p);
	pl->height=node_height(pl);
	
	if(pl == root)
		root=pl;
		
	return pl;
	
}

//rr_rotation
node* rr_rotation(node*p)
{
	
	node *pr=p->rchild;
	node *prl=pr->lchild;
	
	
	p->rchild=prl;
	pr->lchild=p;
	
	p->height=node_height(p);
	pr->height=node_height(pr);
	
	if(pr == root)
		root=pr;
	
	return pr;
		
}

//rl rotaion
node* rl_rotation(node * p) 
{
	node *pr=p->rchild;
	node *prl=pr->lchild;
	
	p->rchild = prl->lchild;
	pr->lchild = prl->rchild;
	
	prl->lchild=p;
	prl->rchild=pr;
	
	//height changes
	pr->height=node_height(pr);
	p->height=node_height(p);
	prl->height=node_height(prl);
	
	if(prl == root)
		root=prl;
	
	return prl;	
	
}


//lr rotaion
node* lr_rotation(node * p)
{
	node *pl=p->lchild;
	node *plr= pl->rchild;

	p->lchild=plr->rchild;	
	pl->rchild=plr->lchild;

	plr->lchild=pl;
	plr->rchild=p;
	
	//height changes
	pl->height=node_height(pl);
	p->height=node_height(p);
	plr->height=node_height(plr);
	
	
	
	
	if(plr == root)
		root=plr;
		
	return plr;	
}



//insert function
node* rinsert(node *p,int key)
{
	node *t;
	
	if(p==0)
	{
		t=new node;
		t->lchild=t->rchild=0;
		t->data=key;
		t->height=1;
		return t;
	}
	
	else if(key > p->data)
		p->rchild=rinsert(p->rchild,key);
		
	else if(key < p->data)
		p->lchild=rinsert(p->lchild,key);
	
	p->height=node_height(p);
	
	if(bal_factor(p)== 2 && bal_factor(p->lchild) == 1  )
		return ll_rotation(p);
		
	else if(bal_factor(p)==2 && bal_factor(p->lchild)==-1)
		return lr_rotation(p);
	
	else if(bal_factor(p)==-2 && bal_factor(p->rchild)==-1 )
		return rr_rotation(p);
		
	else if(bal_factor(p)==-2 && bal_factor(p->rchild)==1)	
		return rl_rotation(p);
		
	return p;	
}

//level order
void pre_order(node * p)
{
	if(p)
	{
		cout<<p->data <<" ";
		pre_order(p->lchild);
		pre_order(p->rchild);
	}
}

//prdecessor function
node* inpredecessor(node *t)
{
	while(t && t->rchild !=0)
		t=t->rchild;
	return t;	
}

//insuccessor function
node* insuccessor(node *t)
{
	while(t && t->lchild !=0)
		t=t->lchild;
	return t;	
}







//delete function
node* delet(node *p ,int key)
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
		if(node_height(p->lchild) > node_height(p->rchild))
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
	

	p->height=node_height(p);
	if(bal_factor(p)== 2 && bal_factor(p->lchild) == 1  )
		return ll_rotation(p);
		
	else if(bal_factor(p)==2 && bal_factor(p->lchild)==-1)
		return lr_rotation(p);
	
	else if(bal_factor(p) == 2 && bal_factor(p->lchild)==0)
		return ll_rotation(p);       // or lr_rotation(p); can also do
	
	
	else if(bal_factor(p)==-2 && bal_factor(p->rchild)==-1 )
		return rr_rotation(p);
		
	else if(bal_factor(p)==-2 && bal_factor(p->rchild)==1)	
		return rl_rotation(p);
		
	else if(bal_factor(p)== -2 && bal_factor(p->rchild)==0)	
		return rr_rotation(p);    //or rl_rotation(p); can also do
		

	return p;
}





//height funcion
int  height( node *p) 
{
	int x , y;
	x = height(p->lchild);
	y = height(p->rchild);
	
	return (x>y ? x+1 : y+1 ); 
}

//max nodes
int max_nodes(int h)
{
	return (pow(2,h)-1 ) ;
}


//min nodes
int min_nodes(int h)
{
	if(h==0)
		return 0;
	else if(h==1)	
		return 1;
	else
		return min_nodes(h-2) + min_nodes(h-1) + 1 ;	
}

//







main()
{
	int n,key,choice;
	
do{
	
	cout<<" \n\n Enter your choice of operation : \n 0)exit \n 1)insert \n 2) delete \n 3)display in pre order \n 4)max nodes for given height of AVL tree \n 5)Min nodes for given AVL height \n\n choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 0:
				exit(0);
				break;
		
		case 1:
				cout<<"Total no elments n : ";
				cin>>n;
				for(int i=0;i<n;i++)		
				{
					cout<<"Enter the element : ";
					cin>>key;
					root=rinsert(root,key)	;
				}
				break;
				
		case 2:
				cout<<"\nEntr the element to delete key : ";
				cin>>key;
				root=delet(root,key);
				break;	
				
		case 3:
			
				cout<<"The preorder of AVl tree is : ";
				pre_order(root);
				break;
				
		case 4:
		      	cout<<"Enter the AVL height : ";
		      	cin>>key;
		      	cout<<"Maximum no of Nodes in AVL tree : "<<max_nodes(key);
		      	break;
		      	
		      	
		case 5:
		      	cout<<"Enter the AVL height : ";
		      	cin>>key;
		      	cout<<"MINIMUM no of Nodes in AVL tree : "<<min_nodes(key) ;
		      	break;
		      	
		default:
				cout<<"Invalid choice "<<endl            	;
				break;		      				  
   }			  				
}while(1);

}

