#include<iostream>
using namespace std;

#include<stdint.h>

//swap function
void swap(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

//note: call by address in swap is working for qick and selection sort otherwiae giving wrong outputs for swap () function
void swap2(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}


//bubble sort function
void bubble_sort(int a[],int n)
{
	int flag =0;
	
	for(int i=0;i<n-1;i++)        //passes loop
	{
		for(int j=0;j<n-1-i;j++) //comparison loop 
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);	    // already stable 
				flag=1;              
			}
		}
		if(flag == 0)                  //adaption 
			break;
	}	
}

//insertion sort 
void insertion_sort(int a[],int n)
{
	int i , j ,x ;
	for(i =1 ; i<n ;i++)           //no of passes loop 
	{
		j=i-1; 
		x=a[i];
		
		while(a[j]> x && j>-1)    //note : j>-1    //no of comparisons loop 
		{
			swap(a[j],a[j+1]);        
			j--;
		}
		a[j+1]=x ;                      // already adaptive and stable
	}
}

//selection sort : working with indexes and k pass gives k th min element
void selection_sort(int a[], int n)
{
	int i,j,k;
	
	for(i=0 ;i<n-1; i++ ) // no of passes n
	{
		j=k=i;
		for(j=j+1;j<n; ) // comparison loops
		{
			if(a[k]>a[j])
			{
				k=j;
				j=j+1;
			}
			else
				j=j+1;
		}
		swap2(&a[i],&a[k]);                         
	}
}


//partition function
int partition(int a[],int low ,int high)
{
	int i=low,j=high;
	int pivot=a[low];
	
	
	do{
		do
		{
		  i++;		
		}while(a[i]<=pivot);  //note :condition is for continuation of loop ans not for stop
		
		do
		{
			j--;
		}while(a[j]>pivot);   // note: condition is for continuation of loop and not for stop
		
		
		if(i<j)              // note: condition
			swap2(&a[i],&a[j]);  // note:
			
	}while(i<j);              //note:condition
	
	swap2(&a[low],&a[j]); //note:
    
	return j;  
}


//Quick sort function
void Quick_sort(int a[],int low,int high)
{
	int j;
	
	if(low < high)           //note: it's condition for min two elements require for quick sort
	{
		j=partition(a,low,high) ;  //index j is partition index 
		
		Quick_sort(a,low,j);       // left partition  // note: low to j is for left part
		
		Quick_sort(a,j+1,high);  //right partition    //note: j+1 to high is for right part
		
	}
}

//merge 
void merge(int a[],int low,int mid ,int high)
{
	int i=low,j=mid+1,k=low;
	int b[100];
	
	
    while(i<=mid && j<=high)
    {
    	if(a[i]<a[j])
    		b[k++]=a[i++];
    		
    	if(a[i]>a[j])
			b[k++]=a[j++];
			
	}
	for(;i<=mid;)
		b[k++]=a[i++];
		
	for(;j<=high;)
		b[k++]=a[j++];
		
	//copying all the elements of b array into a array
	for(i=low;i<=high;i++)	
		a[i]=b[i];
}

//merge sort function
void iterative_merge_sort(int a[],int n)
{
	int p,i,low,mid,high;
	
	for(p=2;p<=n;p=p*2)             //no of passes loop
	{
		for(i=0;i+p-1<n;i=i+p)  //merging lists loop
		{
			low=i;
			high=i+p-1;
			mid=(low + high)/2 ;
			
			merge(a,low,mid,high);
		}
		if(p/2 < n)                  /// for odd number of elements
			merge(a,0,(p/2-1) ,n-1);       //Note :imp arguments values
	}
}

//recursive merge function
void recursive_merge_sort(int a[],int low,int high)
{
	int mid;
	
	if(low < high)
	{
		mid= (low+high) /2;
		
		recursive_merge_sort(a,low,mid);
		
		recursive_merge_sort(a,mid+1,high);
		
		merge(a,low,mid,high);
	}
}


//max element function foor count sort
int find_max(int a[],int n)
{
	int max=a[0],i;
	
	for( i=1;i<n;i++)
		max=max>a[i]?max:a[i];
	
	return max;	
}





//count sort function
void count_sort(int a[],int n)
{
	int max=find_max(a,n),i,j;
	int *count=new int [max+1];         //note: count array size is (max+1)
	
	for(i=0;i<max+1;i++)
		count[i]=0;                          //count array initialize to zero
	
	for(i=0;i<n;i++)                      //counting loop
		count[a[i]]++;
		
	i=j=0;
	
	while(j < (max+1))                     //copying index of count to array a loop  
	{
		if(count[j]>0)
		{
			a[i++]=j;
			count[j]--;
		}
		else
			j++;
	}
}

/////////////////for use in bin/bucket sort and radix sort techniques/////////////////////////////////

struct node 
{
	int data;
	node *next ;
};
		
//insert and delete work is remaining 
void insert(node* &bin,int x)
{
	node *t=new node;
	t->data=x;
	t->next =0;
	
	node *p=bin;
	if(bin==0)
		bin=t;
	
	else
	{
		while(p->next)
			p=p->next;
	}
}

int delet(node * &bin)
{
	int x=bin->data;
	
	node *t=bin;
	bin=bin->next;
	delete t;
	return x;
}



/////////////////////////////////////////////////////////////////////////////////////////////////



//bucket or bin sort
void bin_sort(int a[],int n)
{
	int max=find_max(a,n),i,j;
	
	node** bins=new node*[max+1];
	
	for(i=0;i<max+1;i++)
		bins[i]=NULL;                     //initiializing to null 
	
	for(i=0;i<n;i++)
		insert( bins[a[i]],a[i]);
	
	i=j=0;
	
	while(i < max+1)
	{
		while(bins[i]!= NULL)
		{
			a[j++]=delet(bins[i]);
		}	
		i++;
    }
}




//radix sort
void radix_sort(int a[],int n )
{
	int max = find_max(a,n),i,j;
	int size =10;  
	node **bins= new node*[size];                 //node size is equal to type of data size of decimal=10, binary=2, octal=8 , hexadecimal=16 etc
	
	for(i=0;i < size;i++)
		bins[i]=0;                     //initiializing to null 
	
	
	int passes = 0;
	while(max%10)                       //no of passes calculation
	{
		passes++;	
		max=max/10;
	}
	
	int div=1000;                             ///note            //changes
	for(int p=1;p <= passes;p++)
	{
		for(i=0;i<n;i++)
			insert(bins[(a[i]/div)%10],a[i]);       //note only change :  div 
	
		i=j=0;
	
		while(i < size)
		{
			while(bins[i]!= NULL)
			{
				a[j++]=delet(bins[i]);
			}		
			i++;
    	}
		
		///div= div*10 ;		//note: 
		div=div /10 ;
	}
}

//shell sort 

// ***********************very imp note ::note:replace all ones with gap  variable in insertion sort******************************************************
void shell_sort(int a[],int n)
{
	int gap,i,j,x;
	
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			j=i-gap;
			x=a[i];
			
			while(a[j]>x && j>-1)   
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			
			a[j+gap]=x;            
		}
	}	
}











#define n 4
main()
{
	int a[]={54 ,546 ,548 ,60},i ;       //note : INT_MAX is predefined constant and include <stdint.h> header also its done for Quick sort infinite value
	int choice;
	int b[]={ 2,33,1,40,6,5,INT_MAX} , m=7;
	
	
	do
	{
	
    	cout<<"\n Enter your choice of sort : \n" ;
    	cout<<" 0) exit \n 1) bubble sort \n 2) insertion sort \n 3)selection sort \n 4)Quick sort \n 5)Iterative Merge sort \n 6) Recursive merge sort \n 7) Count sort  \n 8) Bin sort   \n 9) Radix sort \n 10) Shell sort  \n\n choice : ";
    	cin>>choice;
 	    
   		switch(choice)
   		{
   			case 0 :
   				   	exit(0);
   				   
   			case 1:		
					cout<<"\n Bubble sort is : ";
					bubble_sort(a,n);
					for(i=0;i<n;i++)
						cout<<a[i]<< " ";
					break;
				
			case 2:	
					cout<<"\n Insertion  sort is : ";
					insertion_sort(a,n);
					for(i=0;i<n;i++)
						cout<<a[i]<< " ";
					break;
				
			case 3:
					cout<<"\n Selection sort is : ";
					selection_sort(a,n);
					for(i=0;i<n;i++)
						cout<<a[i]<< " ";
					break;
		    case 4:
					cout<<"\n Quick sort is : ";
					Quick_sort(b,0,m-1);             //note:function calling arguments low=0, high=n-1
					
					for(i=0;i<m-1;i++)
						cout<<b[i]<< " ";              //quick sort not working properly
					break;
			case 5:
					cout<<"\n Iterative Merge sort is : ";
					iterative_merge_sort(a,n);             
					
					for(i=0;i<n;i++)
						cout<<a[i]<< " ";           
					break;		
			
			case 6:
					cout<<"\n Recursive Merge sort is : ";
					recursive_merge_sort(a,0,n-1);        //note:function calling arguments low=0, high=n-1
					
					for(i=0;i<n;i++)
						cout<<a[i]<< " ";              
					break;		
					
			case 7:
					cout<<"\n Count sort is : ";
					count_sort(a,n);       
					
					for(i=0;i<n;i++)
						cout<<a[i]<<" ";              
					break;		
					
					
			case 8:
					cout<<"\n Bin sort is : ";
					bin_sort(a,n);       
					for(i=0;i<n;i++)
						cout<<a[i]<<" ";              
					break;				
					
			case 9:
					cout<<"\n Radix sort is : ";
					radix_sort(a,n);       
					for(i=0;i<n;i++)
						cout<<a[i]<<" ";              
					break;				
							
			case 10:
					cout<<"\n Shell sort is : ";
					shell_sort(a,n);       
					for(i=0;i<n;i++)
						cout<<a[i]<<" ";              
					break;				
							
			default:
					cout<<" Invalid choice \n";				
	 	}
	}while(1);
}
