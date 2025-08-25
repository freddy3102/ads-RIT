#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *temp;
struct node *head;

void insertbeg()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertend()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

void insertpos()
{
    int pos,i;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter the position:");
    scanf("%d",&pos);
    printf("enter the data:");
    scanf("%d",&newnode->data);
    temp=head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
        
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void deletebeg()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        printf("%d is deleted",temp->data);
        free(temp);
    }
}
void deleteend()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    
}

void deletepos()
{
    struct node *temp2;
    int i,pos;
    printf("enter the position:");
    scanf("%d",&pos);
    temp=head;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
    
}

void traversal()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    
}

void search()
{
    int flag=0,pos=1,s;
    printf("enter the element to be searched:");
    scanf("%d",&s);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==s)
        {
            flag=1;
        }
        pos++;
        temp=temp->next;
    }
    if(flag==1)
    printf("\nelement %d is found at position %d",s,pos);
    else
    printf("element not found");
    
}

void main()
{
    int d;
    while(1)
    {
        printf("\n1.traversal\n2.search\n3.insertionbeg\n4.insertionpos\n5.insertionend\n6.deletionbeg\n7.deletionpos\n8.deletionend\n9.exit\nenter the choice:");
        scanf("%d",&d);
        switch(d)
        {
            case 1:traversal();
            break;
            case 2:search();
            break;
            case 3:insertbeg();
            break;
            case 4:insertpos();
            break;
            case 5:insertend();
            break;
            case 6:deletebeg();
            break;
            case 7:deletepos();
            break;
            case 8:deleteend();
            break;
            case 9:exit(0);
            default: printf("Invalid choice");
}
}
}