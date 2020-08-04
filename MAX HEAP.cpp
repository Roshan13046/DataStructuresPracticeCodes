#include<iostream>
using namespace std;

void insert(int a[],int n)
{
	int i=n,temp=a[n];
	
	
	while(i>1 && temp>a[i/2])
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=temp;
	
	//return a;
}

int* create(int a[],int n)
{
	int i;
	
	for(i=2;i<n;i++)
		insert(a,i);
	return a;	
}

void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}





//delete heap gives sorted elements
int del(int a[],int n)
{
	
	int i=1,j=2*i;
	
	int val=a[1];
	a[1]=a[n];
	while(j < n-1)
	{
		if(a[j+1]>a[j])
			j=j+1;
		if(a[j]>a[i])	
			{
				swap(&a[i],&a[j]);	
				i=j;
				j=2*i;
			}
		else
			break;				
	}
	a[n]=val;
	return val;
}

void heapify(int a[],int n)
{
	int i=n,j=2*i;
	while(i>0)
	{
		if(j<n)
		{
			if(j+1 <= n)
			{
				if(a[j+1]> a[j])
					j=j+1;
				if(a[j]>a[i])	
				{
					swap(a[j],a[i]);
					heapify(a,j);
				}
			}
			
			else
			{
				if(a[j]>a[i])
				{
					swap(a[j],a[i]);
					heapify(a,j);
				}
			}
		}
		
		i=i-1;
		j=2*i;
	}
}




//display
void display(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}




main()
{
	int i,n,*a,*b;
	int choice,k,key;

do{
	
	cout<<" \n\n Enter your choice of operation : \n 0)exit \n 1)create \n 2) insert an element  \n 3)display in level order\n 4)delete heap \n 5)create heap \n  6)display heapify \n\n choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 0:
				exit(0);
				break;
		
		case 1://create
				cout<<"how many elements to insert n : ";
				cin>>n;
				n=n+1;k=0;
				a=new int [n+10];                               //can insert 10 xtra elements apart from n elements
				cout<<"enter array elements :";
				for(i=1;i<n;i++)
					cin>>a[i];
				a=create(a,n);
				break;
				
		case 2://insert
				cout<<"Enter the key element to insert : ";
				cin>>key;
				k++;
				a[n+k-1]=key;                                     
				insert(a,n+k-1);
				break;
				
		case 3://display heap
				cout<<"Heap is :";
				display(a,n+k)	;
				break;
				
		case 4://delete
				cout<<"The deleted heap element are : "; //deletd heap gives sorted order elements
				for(i=1;i<n+k;i++)                              
					cout<<del(a,n+k-i)<<" ";				
				break;			
		      	
		case 5://heapify      	
				cout<<"how many elements to insert";
				cin>>n;
				n=n+1;k=0;
				b=new int [n+10];                               //heapify logic fun problem not working
				cout<<"enter array elements :";
				for(i=1;i<n;i++)
					cin>>b[i];
				heapify(b,n);
				break;
		      	
		case 6://display heapify
				cout<<" Heapify  is : ";
				display(b,n+k)	;
				break;					      	
		      	
		default:
				cout<<"Invalid choice "<<endl            	;
				break;
		      			  
    }
			  		
		
}while(1);

}

