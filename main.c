#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define stacklenght 100

int counter = 0;

void push(float stack[stacklenght], float number);
void pop(float stack[stacklenght], char operator);
bool enoughnumbers(float stack[stacklenght]);
void reset(float stack[stacklenght]);
void ce(float stack[stacklenght]);

int main(void){
    char input[100];
    float number = 0;
    float stack[stacklenght];

    printf("\nRPN Calculator\n");
    printf("\nEnter Number Enter a Number or an Operator (/ * - +)\n");
    printf("Enter c to reset\n");
    printf("Enter e to delete the newest number\n");
    printf("Press q to quit\n");

    do {
        scanf("%s", input);

        switch (input[0]) {
            case 'q':
                break;
            case 'c':
                reset(stack);
                break;
            case 'e':
                ce(stack);
                break;
            case '+':
                pop(stack, input[0]);
                break;
            case'-':
                pop(stack, input[0]);
                break;
            case '*':
                pop(stack, input[0]);
                break;
            case '/':
                pop(stack, input[0]);
                break;
            default:
                number = strtold(input, NULL);
                printf("you entered %0.2lf\n", number);
                push(stack,number);
                break;
        }

    }while(input[0] != 'q');
}

void push(float *stack, float number) {
    if (counter >= stacklenght){
        printf("\nYou cannot enter any more numbers\n");
    } else {
        stack[counter] = number;
        ++counter;
    }
}

void pop(float *stack, char operator) {
    if (enoughnumbers(stack)){
        printf("\nYou need more numbers for this operation\n");
    } else {
        --counter;
        --counter;
        switch (operator) {
            case '+':
                stack[counter] = stack[counter] + stack[counter+1];
                break;
            case '-':
                stack[counter] = stack[counter] - stack[counter+1];
                break;
            case '*':
                stack[counter] = stack[counter] * stack[counter+1];
                break;
            case '/':
                stack[counter] = stack[counter] / stack[counter+1];
                break;
        }
        printf("\nResult: %0.2f\n", stack[counter]);
    }
}

bool enoughnumbers(float *stack) {
    if (counter <= 0) {
        return true;
    } else {
        return false;
    }
}

void reset(float *stack) {
    printf("\nCalculator emptied\n");
    counter = 0;
    for (int i = 0; i < stacklenght; ++i) {
        stack[i] = 0;
    }
}

void ce(float *stack) {
    printf("\nCalculator emptied\n");
    stack[counter-1] = 0;
    --counter;
}