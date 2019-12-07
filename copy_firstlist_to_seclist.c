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

struct node *display(struct node* head)
{
   struct node *temp=head;
  while(temp!=NULL)
  {   
    printf("%d-",temp->data);
    temp=temp->next;
  }

}

struct node *copyList(struct node *org)
{
  struct node *cur=org;
  struct node *newl=NULL;
  struct node *tail=NULL;
  while(cur!=NULL)
  {
   if(newl==NULL)
   {
      newl=(struct node*)malloc(sizeof(struct node));
      newl->data=cur->data;
      newl->next=NULL;
      tail=newl;
   }
    else
    {
      tail->next=(struct node*)malloc(sizeof(struct node));
      tail=tail->next;
      tail->data=cur->data;
      tail->next=NULL;
    }
    cur=cur->next;
  }
  return newl;

}

int main()
{
    start=create_ll(start);
    start=copyList(start);
    start=display(start);
    
    return 0;
}


