//Conversion of Infix expression to postfix expression using stack.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop an element from the stack
char pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Function to return the precedence of operators
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char* expression) {
    char output[MAX];
    int i, k = 0;

    for (i = 0; i < strlen(expression); i++) {
        char token = expression[i];

        // If the token is an operand, add it to the output
        if (isalnum(token)) {
            output[k++] = token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            push(token);
        }
        // If the token is ')', pop and output from the stack until '(' is encountered
        else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop();  // Pop '(' from the stack
        }
        // If the token is an operator
        else if (isOperator(token)) {
            while (top != -1 && precedence(stack[top]) >= precedence(token) && token != '^') {
                output[k++] = pop();
            }
            push(token);
        }
    }

    // Pop all the operators from the stack
    while (top != -1) {
        output[k++] = pop();
    }
    
    output[k] = '\0';  // Null terminate the output string
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char expression[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);

    return 0;
}
