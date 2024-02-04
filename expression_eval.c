#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[5];
int top = -1;
int size = sizeof(stack) / sizeof(stack[0]);
void push(int ele)
{
     if (top == size - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = ele;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int t;
    t = stack[top];
    top--;
    return t;
}



void expr_eval(char post[20])
{
    int res = 0, op1 = 0, op2 = 0;
    for (int i = 0; post[i] != '\0'; i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            push(post[i] - '0');
        }
        else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/')
        {
            op2 = pop();
            op1 = pop();
            switch (post[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                if (op2 != 0)
                {
                    res = op1 / op2;
                }
                else
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                break;
            }
            push(res);
        }
    }
    printf("Result=%d\n", pop());
}

int main()
{
    char post[20];
    printf("Enter postfix expression: ");
    scanf("%s", post);
    expr_eval(post);
    return 0;
}
