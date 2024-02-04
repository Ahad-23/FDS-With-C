#include <stdio.h>
#include <stdlib.h>

int rear = -1; // for insertion
int front = -1; // for deletion
int q[3];

int size = sizeof(q) / sizeof(q[0]);

int qempty()
{
    if(front == -1 || front > rear)
        return 1; 
    else
        return 0;
}

int qfull()
{
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

void insert(int ele) {
    if (qfull() == 0) {
        if (front == -1) {
            front = 0;
        }
        rear++;
        q[rear] = ele;
        printf("Job %d added to the queue.\n", ele);
    } else {
        printf("Queue is full. Cannot add job.\n");
    }
}

int deleteJob() {
    int deletedJob = -1;
    if (qempty() == 0) {
        deletedJob = q[front];
        front++;
        printf("Job %d deleted from the queue.\n", deletedJob);
    } else {
        printf("Queue is empty. Cannot delete job.\n");
    }
    return deletedJob;
}

void display() {
    if (qempty() == 0) {
        printf("Queue contents:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", q[i]);
        }
    } else {
        printf("Queue is empty.\n");
    }
}

int main() {
    int choice, job;

    while (1) {
        printf("\nEnter choice:\n1. Add\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter job ID: ");
                scanf("%d", &job);
                insert(job);
                break;

            case 2:
                deleteJob();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
