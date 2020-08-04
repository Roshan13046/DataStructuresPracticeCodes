#include<bits/stdc++.h>
using namespace std;

struct node{
    int f;
    char d;
    node*left,*right;

    node(int fre,char data,node*l,node*r){
        f=fre;
        d=data;
        left=l;
        right=r;
    }
};

node*compare(queue<node*>&q1,queue<node*>&q2)
{
    node *t=0;
    if(q1.empty())
    {
        t=q2.front();
        q2.pop();
    }
    else if(q2.empty()){
        t=q1.front();
        q1.pop();
    }
    else{
      if(q1.front()->f < q2.front()->f)
      {

          t=q1.front();q1.pop();
      }
      else{
          t=q2.front();q2.pop();
      }
    }

    return t;
}
void print_code(node *t,int arr[],int i)
{
    if(t->left)
    {
        arr[i]=0;
        print_code(t->left,arr,i+1);
    }
    if(t->right)
    {
        arr[i]=1;
        print_code(t->right,arr,i+1);
    }
    if(t->left==0 &&  t->right==0)
    {
        cout<<t->d<<" : ";
        for(int j=0;j<i;j++)
            cout<<arr[j];
        //cout<<" ,"    ;
    }
}




void build_tree(char data[],int freq[],int n )
{
    queue<node*>q1,q2;
    for(int i=0;i<n;i++)
    {
        node*t=new node(freq[i],data[i],0,0);
        q1.push(t);
    }

    while(!q1.empty() && q1.size())
    {
        node *left = compare(q1,q2);
        node* right =compare(q1,q2);

        node* temp = new node(left->f+right->f,'$',left,right);
        q2.push(temp);
    }
    int arr[n];
    print_code(q2.front(),arr,0);

}



int main()
{
    char data[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};

    build_tree(data,freq,6);

}
