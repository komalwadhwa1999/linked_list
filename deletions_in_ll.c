#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *display(struct node *);

int main()
{
    start=create_ll(start);
    start=display(start);
    
    start=delete_beg(start);
    start=display(start);
    
    start=delete_end(start);
    start=display(start);
    
    start=delete_node(start);
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

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    int val;
    printf("\n enter the value of the node to be deleted:");
    scanf("%d",&val);
    if(ptr->data==val)
    {
        start=delete_beg(start);
        return start;
    }
    else
    {
        while(ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}
