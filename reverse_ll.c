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
struct node* revNodes (struct node*) ;

int main()
{
    int val;
    start=create_ll(start);
    start=display(start);
   
    start=revNodes (start);
    start=display(start);
    
    
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

struct node* revNodes (struct node* head) 
{
      struct node* current = head; 
    struct node* next; 
    struct node* prev = NULL; 
  

    while (current != NULL) 
    { 
       next  = current->next; 
       current->next = prev; 
       prev = current; 
       current = next; 
    } 

    return prev;

}
