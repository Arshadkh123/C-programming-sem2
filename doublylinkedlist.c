#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *create(struct node);
void display(struct node);
void main()
{
    struct node *d;
    int ch,h;
    while(1){ 
    printf(" press 1 to create 2 to display and 3 to exit");
     printf("\n Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n Enter data:");
            scanf("%d",&h);
           d=create(h);
            break;
            case 2:
            display(h);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Wrong choice:");
        }
    }
}
struct node *create(struct node *head)
{
    struct node *p,*q;
    p=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        p->prev=p->next=NULL;
        head=p;
    }
    else{
        q=head;
        while(q->next != NULL)
        {
            q=q->next;
        }
        p->prev=q;
        p->next=NULL;
        q->next=p;
    }
    return head;
}
void display(struct node *head)
{
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("\n Node is empty:");
    }
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}