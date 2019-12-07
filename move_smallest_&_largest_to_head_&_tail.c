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
struct node * shiftSmallLarge(struct node *);

int main()
{
    int val;
    start=create_ll(start);
    start=display(start);
    
    start=shiftSmallLarge(start);
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

struct node * shiftSmallLarge(struct node *org)
{
    if(org==NULL)
    return org;
    if(org->next==NULL)
    return org;
    struct node *s1=org;
    struct node *s2=org;
    struct node *min=org;
    struct node *max=org;
    int l=org->data;
    int s=org->data;
    
    while(s1!=NULL)
    {
        if(l<s1->data)
        {
            l=s1->data;
            max=s1;
        }
        if(s>s1->data)
        {
            s=s1->data;
            min=s1;
        }
        s1=s1->next;
    }
    
    struct node *curr=org;
    struct node *prev=curr;
    
    while(curr!=NULL)
    {
        if(curr->data==s || curr->data==l)
        {
            if(curr==org)
            {
                org=curr->next;
            }
            prev->next=curr->next;
            curr=curr->next;
        }
        else
        {
            prev=curr;
            curr=curr->next;
        }
    }
    
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=s;
    newnode->next=org;
    org=newnode;
    
    if(l!=s)
    {
        struct node *newn=(struct node *)malloc(sizeof(struct node));
        s2=org;
        while(s2->next!=NULL)
        {
            s2=s2->next;
        }
        newn->data=l;
        newn->next=NULL;
        s2->next=newn;
    }
    return org;
}


