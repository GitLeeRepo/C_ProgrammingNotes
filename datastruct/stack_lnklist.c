// stack_lnklist.c
// copied from: Data Structures and Algorithms Made Easy
//              by Narasimha Karumanchi
// minimal modifications by me: (TK) in order to illustrate the operations
//
// Demonstrates creating and using a stack using a linked list

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5
struct Stack { 
    int data;
    struct Stack *next;
};

struct Stack *CreateStack() {
    return NULL;
}

int IsEmptyStack(struct Stack *top) {
    return (top == NULL);
}

int Push(struct Stack **top, int data){
    struct Stack *temp;
    temp = malloc(sizeof(struct Stack));
    if (!temp)
        return INT_MAX;
    temp->data = data;
    temp->next = *top;
    *top = temp;
    return data;
}

int Pop(struct Stack **top) {
    int data;
    struct Stack *temp;
    if (IsEmptyStack(*top)) {
        printf("Empty Stack\n");
        return INT_MIN;
    }
    temp = *top;
    *top = temp->next;
    data = temp->data;
    free(temp);
    return data;
}

int Top(struct Stack *top) {
    if(!IsEmptyStack(top))
        return INT_MIN;
    return top->next->data;
}

void DeleteStack(struct Stack **top) {
    struct Stack *temp, *p;
    if (*top == NULL)
        return;

    p = *top;
    while (p->next) {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    free(p);
}

int main() {
    struct Stack *S = CreateStack();
    
    printf("Note the empty stack error is intentional\n");

    printf("Push: %d\n", Push(&S, 1));
    printf("Push: %d\n", Push(&S, 2));
    printf("Push: %d\n", Push(&S, 3));
    printf("Push: %d\n", Push(&S, 4));
    printf("Push: %d\n", Push(&S, 5));

    printf("Pop: %d\n", Pop(&S));
    printf("Pop: %d\n", Pop(&S));
    printf("Pop: %d\n", Pop(&S));
    printf("Pop: %d\n", Pop(&S));
    printf("Pop: %d\n", Pop(&S));
    // one too many pops to test empty stack message
    printf("Pop: %d\n", Pop(&S));

    DeleteStack(&S);
}
