#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *display(struct node *);

int main()
{
    start=create_ll(start);
    start=display(start);
    
    start=insert_beg(start);
    start=display(start);
    
    start=insert_end(start);
    start=display(start);
    
    start=insert_before(start);
    start=display(start);
    
    start=insert_after(start);
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
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *newnode;
    int num;
    printf("\nenter the data:");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *newnode,*ptr;
    int num;
    printf("\nenter the data:");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=newnode;
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *newnode,*ptr,*preptr;
    int num,val;
    printf("\nenter the data:");
    scanf("%d",&num);
    printf("\nenter the value before which you want to insert:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *newnode,*ptr,*preptr;
    int num,val;
    printf("\nenter the data:");
    scanf("%d",&num);
    printf("\nenter the value after which you want to insert:");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
