#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    int marks;
};

void accept_db(struct student S[20], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter roll no, name and marks of student %d \n", i);
        scanf("%d%s%d", &S[i].roll, S[i].name, &S[i].marks);
    }
}

void display_db(struct student S[20], int n)
{
    int i;
    printf("roll no\tname\tmarks \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d \n", S[i].roll, S[i].name, S[i].marks);
    }
}

void radix_sort(struct student S[20], int n)
{
    int bucket[10][20];
    int count1[10];

    int largest = S[0].roll;
    for (int i = 1; i < n; i++)
    {
        if (S[i].roll > largest)
            largest = S[i].roll;
    }

    int count = 0;
    while (largest > 0)
    {
        largest = largest / 10;
        count++;
    }

    int div = 1;
    for (int pass = 0; pass < count; pass++)
    {
        for (int j = 0; j <= 9; j++)
            count1[j] = 0;

        struct student temp[20];
        for (int i = 0; i < n; i++)
        {
            int d = (S[i].roll / div) % 10;
            bucket[d][count1[d]] = i;
            count1[d]++;
        }

        int k = 0;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j < count1[i]; j++)
            {
                temp[k] = S[bucket[i][j]];
                k++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            S[i] = temp[i];
        }

        div = div * 10;
    }
}

void bucketSort(struct student arr[], int n)
{
    int maxRoll = arr[0].roll;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].roll > maxRoll)
        {
            maxRoll = arr[i].roll;
        }
    }

    struct student buckets[maxRoll + 1];
    memset(buckets, 0, sizeof(buckets));

    for (int i = 0; i < n; i++)
    {
        buckets[arr[i].roll] = arr[i];
    }

    int index = 0;
    for (int i = 0; i <= maxRoll; i++)
    {
        if (buckets[i].roll != 0)
        {
            arr[index++] = buckets[i];
        }
    }
}

int main(void)
{
    int n;
    struct student S[20];
    printf("Enter number of students \n");
    scanf("%d", &n);
    accept_db(S, n);
    display_db(S, n);
    int choice;
    while (1)
    {
        printf("Enter 1 for Radix sort\nEnter 2 for bucket sort\nEnter 3 to Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            radix_sort(S, n);
            display_db(S, n);
            break;
        }
        case 2:
        {
            bucketSort(S, n);
            display_db(S, n);
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
        }
    }
    return 0;
}
