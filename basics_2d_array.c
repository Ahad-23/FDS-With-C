#include <stdio.h>
#include <stdlib.h>

void input(int r,int c,int arr[50][50])
{
for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
    printf("Enter value at (%d,%d)",i,j);
    scanf("%d",&arr[i][j]);
    }
    printf("\n");
}
}

void otp(int a,int b, int ar[50][50])
{
for(int i=0;i<a;i++)
{
for(int j=0;j<b;j++)
{
printf("%d",ar[i][j]);
printf("\t");
}
printf("\n");
}

}

void sum(int r,int c,int n1[50][50],int n2[50][50],int s[50][50])
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
s[i][j]=n1[i][j]+n2[i][j];
}
}
}

void sub(int r,int c,int n1[50][50],int n2[50][50],int s[50][50])
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
s[i][j]=n1[i][j]-n2[i][j];
}
}
}

void transpose(int r, int c, int n1[50][50], int s[50][50])
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            s[j][i] = n1[i][j];  // Swap indices here for transposing
        }
    }
}


void multi(int r1,int c1,int n1[50][50],int r2,int c2,int n2[50][50], int s[50][50])
{
    if(c1==r2)
    {
for(int i=0;i<r1;i++)
{
for (int j=0;j<c2;j++)
{
for(int k=0;k<c1;k++)
{
s[i][j]=s[i][j]+ (n1[i][k]*n2[k][j]);
}
}
}
    }
    else
    printf("wrong array inputs");
}

int main()
{
int row,col;
int array[50][50];
int row2,col2;
int array2[50][50];
int ans[50][50];
int choice;
while(1)
{
printf("Enter 1 for addn of matrices,2 for subtraction,3 for transpose and 4 for multiplication");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter number of rows for first array\n");
scanf("%d",&row);
printf("Enter number of columns for first array\n");
scanf("%d",&col);
printf("Enter the elements of the first array\n");
input(row,col,array);
otp(row,col,array);
printf("Enter number of rows for second array\n");
scanf("%d",&row2);
printf("Enter number of columns for second array\n");
scanf("%d",&col2);
printf("Enter the elements of the second array\n");
input(row2,col2,array2);
otp(row2,col2,array2);
if(row==row2&&col==col2)
{

printf("Sum of these two arrays:\n");
sum(row,col,array,array2,ans);
otp(row,col,ans);
}

break;

case 2:

printf("Enter number of rows for first array\n");
scanf("%d",&row);
printf("Enter number of columns for first array\n");
scanf("%d",&col);
printf("Enter the elements of the first array\n");
input(row,col,array);
otp(row,col,array);
printf("Enter number of rows for second array\n");
scanf("%d",&row2);
printf("Enter number of columns for second array\n");
scanf("%d",&col2);
printf("Enter the elements of the second array\n");
input(row2,col2,array2);
otp(row2,col2,array2);
if(row==row2&&col==col2)
{
printf("Subtraction of these two arrays:\n");
sub(row,col,array,array2,ans);
otp(row,col,ans);
}
break;
case 3:
printf("Enter number of rows \n");
scanf("%d",&row);
printf("Enter number of columns\n");
scanf("%d",&col);
printf("Enter the elements\n");
input(row,col,array);
otp(row,col,array);
printf("Transposed matrix \n");
transpose(row, col,array,ans);
otp(row,col,ans);
break;
case 4:
printf("Enter number of rows for first array\n");
scanf("%d",&row);

printf("Enter number of columns for first array\n");
scanf("%d",&col);

printf("Enter the elements of the first array\n");
input(row,col,array);

otp(row,col,array);
printf("Enter number of rows for second array\n");

scanf("%d",&row2);
printf("Enter number of columns for second array\n");

scanf("%d",&col2);
printf("Enter the elements of the second array\n");

input(row2,col2,array2);
otp(row2,col2,array2);
multi(row,col,array,row2,col2,array2,ans);
otp(row,col2,ans);
break;
case 5:
return EXIT_SUCCESS;
break;
}
}
return EXIT_SUCCESS;
}