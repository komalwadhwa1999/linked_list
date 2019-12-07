#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
void find(struct node *,int);

int main()
{
    int val;
    start=create_ll(start);
    start=display(start);
    printf("enter data to be searched:");
    scanf("%d",&val);
    find(start,val);
    
    return 0;
}

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

struct node *display(struct node *start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return start;
}

void find(struct node *start,int data)
{
  struct node * temp=start;
  while(temp != NULL)
  {
    if(temp->data == data){
      printf("%d found in list.\n", data);
      return;
    }
    temp = temp->next;
  }
  printf("%d not found in list.\n", data);
}


