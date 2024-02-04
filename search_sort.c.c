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
        printf("Enter roll no, name and marks 0f student %d \n", i);
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

void lin_search(struct student S[20], int n)
{
    int key;
    printf("Enter roll no to be searched\n");
    scanf("%d", &key);

    int i;
    for (i = 0; i < n; i++)
    {
        if (S[i].roll == key)
        {
            printf("Student Found:\n");
            printf("Roll No: %d\n", S[i].roll);
            printf("Name: %s\n", S[i].name);
            printf("Marks: %d\n", S[i].marks);
            break; // Stop searching once the key is found
        }
    }

    if (i == n)
    {
        printf("Roll no not found\n");
    }
}

void bin_search(struct student S[20], int n)
{
    int key;
    int flag = -1;

    printf("Enter roll no to be searched: ");
    scanf("%d", &key);

    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (key == S[mid].roll)
        {
            printf("Roll no \t Name \t Marks \n");
            printf("%d\t%s\t%d\n", S[mid].roll, S[mid].name, S[mid].marks);
            flag = 0;
            break;
        }
        else if (key < S[mid].roll)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (flag == -1)
        printf("Roll no not found\n");
}



void bubble_sort(struct student S[20], int n)
{
    int i, j;
    struct student temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (S[j].roll > S[j + 1].roll)
            {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
        printf("Iteration%d", i);
    }
}


void selection_sort(struct student S[20], int n)
{
    struct student temp;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (S[j].roll < S[min_index].roll)
            {
                min_index = j;
            }
        }

        temp = S[min_index];
        S[min_index] = S[i];
        S[i] = temp;
    }
}


void insertion_sort(struct student S[20], int n)
{
    int j;
    struct student temp;
    for (int i = 1; i < n; i++)
    {
        temp = S[i];
        int temp1 = S[i].roll;
        j = i - 1;
        while (j >= 0 && S[j].roll > S[i].roll)
        {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = temp;
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

        for (int i = 0; i < n; i++)
        {
            int d = (S[i].roll / div) % 10;
            bucket[d][count1[d]] = S[i].roll;
            count1[d]++;
        }

        int k = 0;
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j < count1[i]; j++)
            {
                S[k].roll = bucket[i][j];
                k++;
            }
        }

        div = div * 10;
    }
}


void shellsort(int arr[100], int n) {

    int temp, swapped = 0;
    int gap = n/2;
    int i;
    do
    {
       
        do
        {
            swapped = 0;
            for(i = 0; i<n-gap;i++)
            {
                if(arr[i]>arr[i+gap])
                {
                    temp = arr[i];
                    arr[i]=arr[i+gap];
                    arr[i+gap]=temp;
                    swapped = 1;
                }
            }
        }while(swapped==1);
    }while ((gap=gap/2) >=1);
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
    printf("Enter 1 for linear search\n2 for binary search\n3 for selection sort\n 4 for insertion\n 5 radix sort \n6 for Exit");

    
    scanf("%d", &choice);
   switch (choice)
    {

    case 1:{
        lin_search(S, n);
        break;
    }
    case 2:
{
        bin_search(S, n);
        break;
}
    case 3:
    {
        selection_sort(S, n);
        display_db(S, n);
        break;
    }
    case 4:
    {
        insertion_sort(S, n);
        display_db(S, n);
        break;
    }
    case 5:
    {
        radix_sort(S, n);
        display_db(S, n);

        break;
    }
    case 6:
    return EXIT_SUCCESS;
    break;
    }
}
    return EXIT_SUCCESS;
}
