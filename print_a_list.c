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

void forwardPrint(struct node* head)
{
   struct node *temp=head;
  while(temp!=NULL)
  {   
    printf("%d-",temp->data);
    temp=temp->next;
  }

}

void backwardPrint(struct node* head)
{
 if(head==NULL)
   return;
  backwardPrint(head->next);
  printf("%d-",head->data);
}

int main()
{
    int val;
    start=create_ll(start);
    printf("FORWARD PRINTING:");
    forwardPrint(start);
    printf("\nBACKWARD PRINTING:");
    backwardPrint(start);
    
    
    return 0;
}


