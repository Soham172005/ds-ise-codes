//Evaluation of Postfix expression using Stack#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for the stack
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i;

    // Process each character in the expression
    for (i = 0; expression[i]; ++i) {
        // If the character is a number, push it onto the stack
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');  // Convert char to int
        }
        // If the character is an operator, pop two elements and apply the operator
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (expression[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }

    // The result is the last item on the stack
    return pop(stack);
}

// Main function to test the evaluation
int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    printf("Result of evaluation: %d\n", evaluatePostfix(expression));
    return 0;
}
