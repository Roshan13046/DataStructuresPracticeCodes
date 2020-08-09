//double hashing technique

#include<iostream>
using namespace std;

#define size 10




//finding nearest prime of size 
int nearest_prime()
{
	int n=size;
	for(int i=2 ;i< n;i++)
	{
		if(n % i == 0)
		{
			n--;
			i=2;
		}
	}
	return n;
}

// 1st hash  function
int hash_index1(int key)
{
	return(key % size);   //note:
}


//2nd hash function
int hash_index2(int key)
{
	int rprime = nearest_prime();    //note: rprime function calling

	return rprime-(key % rprime);  //note : 2nd hash function
}



//probe function to find free space for inserting the key
int probing(int h[],int key)
{
	
	int index1=hash_index1(key);
	int index2=hash_index2(key);
	int i=0;
	
	while(h[(index1 + i * index2  )%size] != 0)   //note: 
		i++;
		
	return (index1 + i*index2)%size;              //note:
}

//key insert function
void insert(int h[],int key)
{
	int index=hash_index1(key);
	
	if(h[index] != 0)
		index = probing(h,key);              
		
	h[index]=key;	
}



//key search function it return index /position of int key
int search(int h[],int key)
{
	int index1=hash_index1(key);  //hash1 fun call
 	int index2=hash_index2(key);  //hash2 fun call
	int i=0;
	
	while(h[(index1 + i* index2)%size] != key)  //note:only replace 0 with key in probing function
		i++;
	
	return (index1 + i*index2 )%size;	
}



//main function
main()
{
	int h[size]={0};         //intializing hash table to zero
	int n,key;
	
	
	cout<<" Enter how many keys to insert n : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Enter the key "<<i+1<<" : ";
		cin>>key;
		insert(h,key);       //insert function call
	}
	
	cout<<"\n Enter the key to search key : ";
	cin>>key;
	cout<<" The  key is present at index : "<<search(h,key);   //search fun call
	
	
	
}

