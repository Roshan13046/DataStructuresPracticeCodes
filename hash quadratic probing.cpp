
//note: only replace i places with i*i and don't replace i++ in linear probing to make quadratic probing 


#include<iostream>
using namespace std;


#define size 10

//index finding function
int hash_index(int key)
{
	return(key%size);
}

//probe function to find the vacant place to insert the key 
int probing(int h[],int key)
{
	int index=hash_index(key),i=0;
	
	while(h[(index+i*i)%size] != 0 )    //note : Quadratic probing replace i with i*i
		i++;
		
	return (index + i*i)%size;
}



//insert fuction
void insert(int h[],int key)
{
	int index=hash_index(key);
	
	if(h[index] !=0 )
		index=probing(h,key);
	
	h[index]=key;
}

//searh function
int search(int h[],int key)
{
	int index=hash_index(key),i=0;
	
	while(h[(index+i*i)%size] != key)
		i++;
	
	return (index+i*i)%size;
}


//main
main()
{
	int h[size]={0};
	int key,n;
	
	cout<<"Enter how many elements to eneter n :";
	cin>>n;
	for(int i=0 ;i<n;i++)
	{
		cout<<"Enter the key "<<i+1<<" : ";
		cin>>key;
		insert(h,key); //insert call
	}
	
	cout<<"Enter the key to searh key : ";
	cin>>key;
	cout<<"The key is present at index : "<<search(h,key);  //search call
		
}
