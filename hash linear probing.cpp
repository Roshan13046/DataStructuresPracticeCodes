#include<iostream>
using namespace std;

#define size 10

//index finder
int hash_index(int key)
{
	return(key % size);
}


//probe function for finding the vacant space in hash table to insert
int probing(int h[],int key)
{
	int index=hash_index(key),i=0;
	
	while(h[(index+i)%size] !=0)
		i++;
		
	return (index+i)%size ;
}





//insert funtion
void insert(int h[],int key)
{
	int index=hash_index(key);
	
	if(h[index] !=0)
		index=probing(h,key);
	
	h[index]=key;	
}

//search function
int search(int h[],int key)
{
	int index=hash_index(key),i=0;
	
	while(h[(index+i)%size] != key)
		i++;
	
	return(index +i)%size;	
}



main()
{
	int n,key,i;
	int h[size]={0};                              //hash table initialize to zero
	cout<<"Enter how many keys to insert n : ";
	cin>>n;            
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter the key "<< i+1<<" : ";
		cin>>key;   
		insert(h,key);                         //insert function call
	}
	
	cout<<"Enter the key to search key : ";
	cin>>key;
	cout<<"The key is present at index : "<<search(h,key);  //search function call
	
}






