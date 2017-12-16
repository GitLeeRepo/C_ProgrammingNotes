////////////////////////////////////////////////////////////////////////////////////
// binarysearch.c
//
// Orig copied from:
//      https://www.tutorialspoint.com/data_structures_algorithms/binary_search_program_in_c.htm
//
// Modified by TK
//
// Binary search algorithm
/////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define MAX 20
int numOfElements = 0;


// array of items on which linear search will be conducted. 
int intArray[] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,21,24,27,30,33,34,38,41,43,45,49,51,55,60,63,66};

// forward declarations
void display();
int find(int data);
void printline(int count);

int main(void) {
    int searchValue = 55;

    numOfElements = sizeof intArray / sizeof (int);

    printf("Input Array (%d elements): ", numOfElements);
    display();

    printf("Enter search value: ");
    scanf("%d", &searchValue);
    printf("\n");

    printf("Search Value = %d\n", searchValue);
    printline(50);

    //find location of 1
    int location = find(searchValue);

    // if element was found 
    if(location != -1)
        printf("\nElement with a value of %d, found at location: %d\n", searchValue ,location);
    else
        printf("\nElement not found.\n");
}

void printline(int count) {
    int i;
    
    for(i = 0;i <count-1;i++) {
        printf("=");
    }
    
    printf("=\n");
}

int find(int data) {
    int lowerBound = 0;
    int upperBound = numOfElements -1;
    int midPoint = -1;
    int comparisons = 0;      
    int index = -1;

    while(lowerBound <= upperBound) {
        printf("Comparison %d\n" , (comparisons +1) );
        printf("lowerBound : %d, intArray[%d] = %d\n",lowerBound,lowerBound,
        intArray[lowerBound]);
        printf("upperBound : %d, intArray[%d] = %d\n",upperBound,upperBound,
        intArray[upperBound]);
        comparisons++;

        // compute the mid point
        // midPoint = (lowerBound + upperBound) / 2;
        midPoint = lowerBound + (upperBound - lowerBound) / 2;    

        // data found
        if(intArray[midPoint] == data) {
            index = midPoint;
            break;
        } else {
            // if data is larger 
            if(intArray[midPoint] < data) {
                // data is in upper half
                lowerBound = midPoint + 1;
            }
            // data is smaller 
            else {
                // data is in lower half 
                upperBound = midPoint -1;
            }
        }               
    }
    printf("Total comparisons made: %d" , comparisons);
    return index;
}

void display() {
    int i;
    printf("[");
    
    // navigate through all items 
    for(i = 0;i<numOfElements;i++) {
        printf("%d ",intArray[i]);
    }
    
    printf("]\n");
}

