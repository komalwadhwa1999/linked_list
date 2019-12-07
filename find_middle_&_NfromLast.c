#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node *create_ll(struct node *start)
{
    struct node *newnode,*ptr;
    int num;
    printf("\nenter -1 to end.");
    printf("\nenter the data:");
    scanf("%d",&num);
    while(num!=-1)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("\nenter the data:");
        scanf("%d",&num);
    }
    return start;
}

int findMiddle(struct node* head) 
{
  if(head==NULL)
    return -1;
  int a[100],k=0;
  while(head!=NULL)
  {
    a[k]=head->data;
    k++;
    head=head->next;
  }
  int mid=k/2;
  return a[mid];

}

int findNLast(struct node* head,int n)
{
   if(head==NULL)
    return -1;
  int a[100],k=0;
  while(head!=NULL)
  {
    a[k]=head->data;
    k++;
    head=head->next;
  }
  if(k>n)
  return a[k-n];
  else
    return a[k-1];

}


int main()
{
    start=create_ll(start);
    int m=findMiddle(start);
    int n;
    printf("enter the value of N:");
    scanf("%d",&n);
    int k=findNLast(start,n);
    printf("mid value = %d\n",m);
    printf("value of Nth node from last = %d",k);
    
    return 0;
}


