#include<iostream>
using namespace std;




//hash index function
int hash_index(int key)
{
	return (key % 10);
}




/////////////////////////////////////link list functions////////////////////////////////////////////////////////////

struct node 
{
	int data;
	node *next ;
};
		
//insert and delete work is remaining 
void link_insert(node **list,int x)
{
	node *t=new node;
	t->data=x;
	t->next =0;
	
	node *p= *list;
	if(*list == 0)
		*list=t;
	else
	{
		while(p->next)
			p=p->next;
		p->next =t;	
	}
}

int link_delet(node**list,int key )
{
	int x = -1;
	node *p= *list;
	node *q=0;
	
	while(  p)
	{
	   if(	p->data != key)
		{
			q=p;
		    p=p->next;
		}
		else
			break;
	}
	
	if(p == 0)
		cout<<"Key not present ";
		

	else
	{
		if( p == *list)       //if first node
		{
			x=(*list)->data;
			p=*list;
			*list=(*list)->next;
			delete p;
		}
		else               //other than first node   
		{
			q->next=p->next;
			x=p->data;
			delete p;
		}
	}
   return x;	
}

int link_search(node *p,int key)
{
	while(p)
	{
		if(p->data == key)
			{
				cout<<"Key is present at index : ";
				return (hash_index(key));
			}
		else
			p=p->next;	
	}	
	
	cout<<"Key not found : ";
	return -1 ;		
}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














#define size 10
int main()
{
	
	int i,key,temp;
	node **ht=new node*[size];                   //note:node **ht
	
	
	
	for(i=0;i<10;i++)                 //initializing to null
		ht[i]=0;
	
	
	cout<<"Enter the how many keys to insert in hash";
	cin>>temp;
	for(i=0;i<temp;i++)
	{
		cout<<"Enter the key "<< i+1<<": ";
		cin>>key;
		link_insert(&ht[ hash_index(key) ],key);	
	}
	
	
	cout<<"Enter key to search  key : ";
	cin >> key;
	temp=link_search(ht[ hash_index(key) ],key);
	cout<<temp<<endl ;


	cout<<"Enter key to delete  key : ";
	cin >> key;
	temp=link_delet(&ht[ hash_index(key) ],key);
	cout<<"the deleted element is : "<<temp;
}



