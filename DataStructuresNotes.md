# Overview

Notes on various data structures as implemented in the C programming language

# References

* [Data Structures and Algorithms - tutorialspoint.com](https://www.tutorialspoint.com/data_structures_algorithms/index.htm)

# Concepts and Terminology

* **Data Structure** - a means of storing and organizing data in structured way that is optimal and useful for a given requirement.  They include files, arrays, linked lists, stacks, queues, dictionaries, hash tables, trees, graphs, etc.  There are two general types:
    * **Linear Data Structures** - the elements of the data structure are organized in a linear manner that are typically accessed sequentially. such as arrays, linked lists, stacks and queues
    * **Non-Linear Data Structures** - data elements are stored and accessed in a non-linear manner, the include trees and graphs.
* **Node** - the node provides the basis of many data structures, such as linked lists.  It contains data and provides a means of connectin to other nodes through object data pointers (typical names for these pointers are Next, Prev, Head, Tail).

# Examples

## Single Link List

```c
// singlelink.c
//
// Demonstrate a simple single linked list

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
```
