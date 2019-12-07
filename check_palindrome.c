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

int  checkPalindrome(struct node* head) 
{
  int a[100];int k=0;
  if(head==NULL)
    return 0;
  while(head!=NULL)
  {
    a[k]=head->data;k++;
    head=head->next;
  }
  int b[100];int c=0;int x=0;int l=k;
  for(int i=k-1;i>=0;i--)
  {
    b[x]=a[i];x++;
  }

  int flag=1;
  for(int i=0;i<l;i++)
  {
    flag=1;
   if(a[i]!=b[i])
   {
     flag=0;
     break;
   }
  }
  if(flag==1)
    return 1;
  else 
    return 0;

}

int main()
{
    start=create_ll(start);
    int x=checkPalindrome(start);
    if(x==1)
    printf("yes");
    else
    printf("no");
    
    return 0;
}


