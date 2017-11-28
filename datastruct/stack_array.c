// stack_array.c
// copied from: Data Structures and Algorithms Made Easy
//              by Narasimha Karumanchi
// minimal modifications by me: (TK) in order to illustrate the operations
//
// Demonstrates creating and using a stack using a fixed length array

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5
struct ArrayStack {
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack() {
    // the structure that contains the stack 'array' within it
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));

    if (!S)
        return NULL;
    S->capacity = MAXSIZE;
    S->top = -1;  // set to empty to start
    // allocate memory for the array
    S->array=malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

int IsEmptyStack(struct ArrayStack *S) {
    return (S->top == -1);
}

int IsFullStack(struct ArrayStack *S) {
    return (S->top == S->capacity-1);
}

int Push(struct ArrayStack *S, int data){
    if (IsFullStack(S)) {
        printf("Stack Overflow\n");
        return INT_MAX;
    }
    else {
        S->array[++S->top] = data;
        return data;
    }
}

int Pop(struct ArrayStack *S) {
    if (IsEmptyStack(S)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    else
        return (S->array[S->top--]);
}

void DeleteStack(struct ArrayStack *S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}

int main() {
    struct ArrayStack *S = CreateStack();
    
    printf("Note the stack overflow and empty errors are intentional\n");

    printf("Push: %d\n", Push(S, 1));
    printf("Push: %d\n", Push(S, 2));
    printf("Push: %d\n", Push(S, 3));
    printf("Push: %d\n", Push(S, 4));
    printf("Push: %d\n", Push(S, 5));
    // one too many pushes to test stack overflow 
    printf("Push: %d\n", Push(S, 6));

    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    // one too many pops to test empty stack message
    printf("Pop: %d\n", Pop(S));

    DeleteStack(S);
}
