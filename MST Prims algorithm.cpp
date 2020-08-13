
#include<stdint.h>
#include<iostream>
using namespace std;
#define  n 7

#define x INT_MAX
 int a[n+1][n+1]=
	{ {x,x,x,x,x,x,x,x,},
	  {x,x,25,x,x,x,5,x },
	  {x,25,x,12,x,x,x,10},
	  {x,x,12,x,8,x,x,x},
	  {x,x,x,8,x,16,x,14},
	  {x,x,x,x,16,x,20,18},
	  {x,5,x,x,x,20,x,x},
	  {x,x,10,x,14,18,x,x}
	};





class mini
{
	public:
			int i,j,data;
			
			mini()
			{
				i=j=-1;
				data=1000;
			}			
			
};

  mini min_cost()
 {
	int i,j;
	mini m;
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(a[i][j] < m.data)
			{
				m.data =a[i][j];
				m.i=i;
				m.j=j;
			}
		}
	}

	return m;
}


 int near[n+1]={-1,-1,-1,-1,-1,-1,-1,-1};        //initializing to -1
mini near_cost(int p,int q)
{
  //update nearest array 
	near[p]=near[q]=0;
	int vertex;
	for(int k=1;k<=n ;k++)
	{
		if(near[k]==0 );
		
		else if(near[k] == -1)
		{
			vertex=a[k][p]<a[k][q]?p:q	;
			near[k]=vertex;
		}
		else
		{
			//cout<<k<<" "<<near[k]<<" ;";
			vertex=a[k][p]<a[k][q]?p:q	;
		
		near[k]= a[k][near[k]] < a[k][vertex] ? near[k] : vertex;  //update statements	
		}	
	}
	
	///////////////////////////////////
   /*	
	cout<<"check near values :";
	for(int i=0;i<=n;i++)
		cout<<near[i]<<" ";
	cout<<endl;	
	*/
	////////////////////////////	
	mini m;
	
	m.data=a[1][near[1]];
	m.i=1;
	m.j=near[1];
	
	for(int i=2;i<=n;i++)
	{
		if(a[i][near[i]]<m.data)
		{
			m.data =a[i][near[i]];
			m.i=i;
			m.j=near[i];
		}
	}
	return m;	
}


int find_cost(int t[][n-1])
{
	int sum = 0;
	
	int i,j;
	
/*	for(i=0;i<n+1;i++)
		{
		 for(j=0;j<n+1;j++ )
			cout<<a[i][j]<<" ";
		cout<<endl;			
	}
*/	
	int p,q;
	
	for(int i=0;i<n-1;i++)
	{
		p=t[0][i];
		q= t[1][i];		
		sum = sum + a[ p ] [q ];    	
	}
	return sum;
}



void prims()
{
	int t[2][n-1]={0};
	int k;
	
	mini m;
	m= min_cost();
	t[0][0]=m.i;
	t[1][0]=m.j;
	
	for(k=0;k<n-2;k++)
	{
		m=near_cost(t[0][k],t[1][k]);
		
		//cout<<"check :"<<m.i<<" "<<m.j;
		
		
		t[0][k+1]=m.i;
		t[1][k+1]=m.j;
	}
	
	cout<<" \n The path is : "<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<" ( "<<t[0][i]<<" , "<<t[1][i]<<")"<<endl;
	}
	
	cout<<"\n The  cost of MST is :"<<find_cost(t);
	
	
}








main()
{
	
	
	
	prims();
	
		
}
