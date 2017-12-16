////////////////////////////////////////////////////////////////////////////////////
// interpolsearch.c
//
// Interpolation search algorithm
//
// Orig copied from:
//      https://www.tutorialspoint.com/data_structures_algorithms/interpolation_search_in_c.htm
//
// Modified by TK, made several changes over the original, including modifying the 
// original condition in the find while loop, which did not work correctly with 
// the 'not found' values.  Also added larger array, and made several refactors
// This is one of two versions, this version prompts the user for a value to
// search for.
//
// Refer to:
//      interpolsrch_sampl.c - same search that performs the search for every
//              unique value between the low and high values
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


// array of items on which interpolation search will be conducted. 
int list[] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,21,24,27,30,33,34,38,41,43,45,49,51,55,60,63,66};
int numOfElements;

// forward declarations
int find(int searchValue);
void display();
void printline(int count);

int main() {
    int searchValue = 66;

    numOfElements = sizeof list / sizeof (int);

    printf("\nInput Array (%d elements): ", numOfElements);
    display();

    printf("Enter search value: ");
    scanf("%d", &searchValue);
    printf("\n");

    printf("Search Value = %d\n", searchValue);
    printline(50);

    //find location of 33
    int location = find(searchValue);

    // if element was found 
    if(location != -1)
        printf("\nElement value %d found at location: %d\n", searchValue, location);
    else
        printf("\nElement value %d not found.\n", searchValue);

    return 0;
}

int find(int searchValue) {
    int lo = 0;
    int hi = numOfElements - 1;
    int mid = -1;
    int comparisons = 0;      
    int index = -1;

    // the original while is commented out, it doesn't handle 'not found' condition, 
    // changed to the new one which does correctly handle it
    //while(lo <= hi) {

    while ((list[hi] != list[lo]) && (searchValue >= list[lo]) && (searchValue <= list[hi])) {
        printf("\nComparison %d  \n" , comparisons ) ;
        printf("lo : %d, list[%d] = %d\n", lo, lo, list[lo]);
        printf("hi : %d, list[%d] = %d\n", hi, hi, list[hi]);

        comparisons++;

        // probe the mid point 
        mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (searchValue - list[lo]));
        printf("mid = %d\n",mid);

        // searchValue found 
        if(list[mid] == searchValue) {
            index = mid;
            break;
        } else {
            if(list[mid] < searchValue) {
                // if searchValue is larger, searchValue is in upper half 
                lo = mid + 1;
            } else {
                // if searchValue is smaller, searchValue is in lower half 
                hi = mid - 1;
            }
        }               
    }

    printf("\nTotal comparisons made: %d", comparisons);
    return index;
}

void display() {
    int i;
    printf("[");
    
    // navigate through all items 
    for(i = 0;i<numOfElements;i++) {
        printf("%d ",list[i]);
    }
    
    printf("]\n");
}

void printline(int count) {
    int i;
    
    for(i = 0;i <count-1;i++) {
        printf("=");
    }
    
    printf("=\n");
}
