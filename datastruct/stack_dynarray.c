// stack_dynarray.c
// copied from: Data Structures and Algorithms Made Easy
//              by Narasimha Karumanchi
// minimal modifications by me: (TK) in order to illustrate the operations
//
// Demonstrates creating and using a stack using a dynamic length array

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5
struct DynArrayStack {
    int top;
    int capacity;
    int *array;
};

struct DynArrayStack *CreateStack() {
    // the structure that contains the stack 'array' within it
    struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));

    if (!S)
        return NULL;
    S->capacity = 1; // artificially low for demo purposes
    S->top = -1;  // set to empty to start
    // allocate memory for the initial size of the array
    S->array=malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

void DoubleStack(struct DynArrayStack *S) {
    S->capacity *= 2;
    // reallocate the array, doubling it in size
    S->array = realloc(S->array, S->capacity * sizeof(int));
}

int IsEmptyStack(struct DynArrayStack *S) {
    return (S->top == -1);
}

int IsFullStack(struct DynArrayStack *S) {
    return (S->top == S->capacity-1);
}

int Push(struct DynArrayStack *S, int data){
    if (IsFullStack(S)) {
        DoubleStack(S);
        printf("Expanding Stack Size (doubling to %d)\n", S->capacity);
    }
    S->array[++S->top] = data;
    return data;
}

int Pop(struct DynArrayStack *S) {
    if (IsEmptyStack(S)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    else
        return (S->array[S->top--]);
}

void DeleteStack(struct DynArrayStack *S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}

int main() {
    struct DynArrayStack *S = CreateStack();
    
    printf("Note the empty stack error is intentional\n");

    printf("Push: %d\n", Push(S, 1));
    printf("Push: %d\n", Push(S, 2));
    printf("Push: %d\n", Push(S, 3));
    printf("Push: %d\n", Push(S, 4));
    printf("Push: %d\n", Push(S, 5));
    printf("Push: %d\n", Push(S, 6));

    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    printf("Pop: %d\n", Pop(S));
    // one too many pops to test empty stack message
    printf("Pop: %d\n", Pop(S));

    DeleteStack(S);
}
