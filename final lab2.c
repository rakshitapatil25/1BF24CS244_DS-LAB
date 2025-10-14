#include <stdio.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char elem) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = elem;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main() 
{
    char infix[MAX], postfix[MAX];
    char ch, elem;
    int i = 0, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    push('#');  // Sentinel to mark bottom of stack

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == ')') {
            while (stack[top] != '(' && stack[top] != '#') {
                postfix[k++] = pop();
            }
            if (stack[top] == '(')
                pop();  // Remove '(' from stack
            else {
                printf("Error: Mismatched parentheses\n");
                return 1;
            }
        } else {
            // Operator encountered
            while (precedence(stack[top]) >= precedence(ch)) {
                if (stack[top] == '#')  // Stop at bottom sentinel
                    break;
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (stack[top] != '#' && top != -1) {
        if (stack[top] == '(') {
            printf("Error: Mismatched parentheses\n");
            return 1;
        }
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
}
