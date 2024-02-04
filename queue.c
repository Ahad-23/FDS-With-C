#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rear=-1; // for insertion
int front=-1;// for deletion
int q[20];
int size=sizeof(q);
void insert(int ele)
{
    rear++;
    q[rear]=ele;
}

int delete ()
{
    front++;
    return(q[front]);
}

int qempty()
{
    if(front==rear)
    return 1; 
    else
    return 0;
}


int qfull()
{
if (rear==size-1)
return 1;
else
return 0;
}


void display()
{
    for(int i=1;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}


 int main()
 {
    int choice;
    printf("Enter choice\n 1.Add \n 2.Delete \n 3. Display \n4,Exit");
    scanf("%d",&choice);
    while(1)
    {
        switch(choice)
        {
            case 1:
            {
                int id;
                printf("Enter data");
                scanf("%d",id);
                insert(id);
                break;
            }

            case 2:{
            int del=delete();
           printf("Delete job %d",del);
           break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            return EXIT_SUCCESS;
        
        }
    }
 }