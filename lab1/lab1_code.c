#include <stdio.h>
#include <stdio.h>
#define N 5
int stack[N];
int top=-1;

void push()
{
    int x;
    printf("enter element\n");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    int y;
    if (top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        y=stack[top];
        top--;
        printf("popped element=%d\n",y);
    }
}

void peek()
{
    if (top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("top element=%d\n",stack[top]);
    }
}

void display()
{
    if (top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        int i;
        for (i=0;i<N;i++)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void main()
{
    int ch;
    do
    {
        printf("\n");
        printf("0.exit\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("invalid choice\n");
            break;
        }
    } while (ch!=0);
}
