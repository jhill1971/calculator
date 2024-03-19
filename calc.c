#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

// Define a stack structure
typedef struct{
    double items[STACK_SIZE];
    int top;
}Stack;

// Function prototypes
void initStack(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
double calculate(char operator, double operand1, double operand2);

int main(int argc, char *argv[]){
    Stack stack;
    double result;
    char *token;

    // Initialize the stack
    initStack(&stack);

    // Process command-line arguments
    for (int i = 1; i < argc; i++){
        token = argv[i];

        // Check if the token is a number
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))){
            // Convert the token to a double and push it to the stack
            push(&stack, atof(token));
        } else {
            // Token is an operator
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);

            // Perform the calculation and push the result onto the stack
            result = calculate(token[0], operand1, operand2);
            push(&stack, result);
        }
    }
    
    // Ensure there's only one element left in the stack (the final result)
    if (stack.top != 1) {
        printf("Error: Invalid expression. \n");
        return 1;
    }

    // Print the final result
    printf("Result: %.2f\n", result);

    return 0;
}

/* Initialize the stack  */
void initStack(Stack *s){
    s->top = 0;
}

/* Push an item onto the stack  */
void push(Stack *s, double value){
    if (isFull(s)) {
        printf("Error: Stack Overflow.\n");
        exit(1);
    }
    s->items[s->top++] = value;
}

/* Pop an item from the stack */
double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack Overflow.\n");
        exit(1);
    }
    return s->items[--s->top];
}

/* Check if the stack is empty  */
int isEmpty(Stack *s) {
    return s->top == 0;
}

/* Check if the stack is full  */
int isFull(Stack *s){
    return s->top == STACK_SIZE;
}

/* Perform a calculation based on the operator  */
double calculate(char operator, double operand1, double operand2){
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case 'x':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0){
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return operand1/operand2;
        default: 
            printf("Error: Invalid Operator.\n");
            exit(1);
    }
}
