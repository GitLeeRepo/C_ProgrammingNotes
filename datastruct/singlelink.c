// singlelink.c
//
// Demonstrate a simple singley linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[20];
    int age;
    struct person* next;
};

// add to the list
struct person* add(char * name, int age, struct person* node) {
    struct person* curr = malloc(sizeof(struct person));

    // check if it is the initial head, if so set it to current, otherwise
    // assume node is the current end of list, assign its next to the new node
    if (node == NULL)
        node = curr;
    else
        node->next = curr;

    strcpy(curr->name, name);
    curr->age = age;
    curr->next = NULL; // now curr is the end of the list

    // return the newly added node
    return curr;
}

// print starting at node (normally head) and then walk the list printing each entry
void print(struct person* node) {
    struct person* curr = node;

    while (curr) {
        printf("%s is %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main(void) {
    struct person *head = NULL; // the start of the list
    struct person *currnode;

    // for the 1st one return as the new (non-NULL) head
    head = add("Bill", 33, head);
    // the remaining ones return as current node
    currnode = add("Bob", 44, head);
    currnode = add("Sally", 28, currnode);
    currnode = add("Jill", 31, currnode);

    // print each item on list starting at head
    print(head);
}
