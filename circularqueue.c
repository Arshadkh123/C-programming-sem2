#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 05
int q[Max];
int front=-1;
int rear=-1;
void push(int);
void pop();
void display();
void main()
{
    int ch,val;
    while(1)
    {
        printf("\npress 1 to push 2 to pop 3 to display and 4 to exit:");
        printf("\n Enter the choice=");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value:");
            scanf("%d",&val);
            push(val);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Wrong choice:");
        }
        getch();
        //return 0;
    }
}
    void push(int num)
    {
        if((rear+1)%Max==front)
        printf("Queue is Full:");
        else if(front==-1 && rear==-1)
         {
            front=rear=0;
            q[rear]=num;
         }
         else{ 
            rear=(rear+1)%Max;
            q[rear]=num;
        }
    }
    void pop()
    {
        if(front==-1 && rear==-1)
        printf("\nQueue is empty:");
       // int res=q[front];
        if(front==rear)
        { 
            printf("%d",q[front]);
        front=rear=-1;
        }
        else{
            printf("%d",q[front]);
            front=(front+1)%Max;
        }
    }
    void display()
    {
        int i=front;
        if(front==-1 && rear==-1)
        printf("\nQueue is empty:");
        else
        {
            printf("Queue is:");
            while(i!=rear){
                printf("%d \t",q[i]);
                i=(i+1)%Max;
            }
            printf("%d",q[rear]);
        }
    }