////////////////////////////////////////////////////////////////////////////////////
// interpolsrch_sampl.c
//
// Interpolation search algorithm
//
// Orig copied from:
//      https://www.tutorialspoint.com/data_structures_algorithms/interpolation_search_in_c.htm
//
// Modified by TK, made several changes over the original, including modifying the 
// original condition in the find while loop which did not work correctly with 
// the 'not found' values.  Also added larger array, global stat tracking, and
// several refactors.  This is one of two versions, this version runs the search for
// every possible unique value between and including the lowest and hightest values.
//
// Refer to:
//      interpolsearch.c - same search with prompts for individual searches
/////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


// array of items on which interpolation search will be conducted. 
int list[] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,21,24,27,30,33,34,38,41,43,45,49,51,55,60,63,66};
int numOfElements;

int stats[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

// forward declarations
int find(int data);
void display();
void printline(int count);

int main() {
    //int searchValue = 66;

    numOfElements = sizeof list / sizeof (int);

    printf("\nInput Array (%d elements): ", numOfElements);
    display();

    printline(50);

    for (int searchValue = 0; searchValue <= 66; searchValue++) {
        printf("\tElement value %d: ", searchValue);
        int location = find(searchValue);

        // if element was found 
        if(location != -1)
            printf(" - found at position: %d\n", location);
        else
            printf(" - not found.\n");
    }

    printf("\nOverall statistics:\n");
    int i = 0;
    while (stats[i] != -1) {
        printf("%d comparisons occurred %d times\n", i, stats[i]);
        i++;
    }

    return 0;
}

int find(int data) {
    int lo = 0;
    int hi = numOfElements - 1;
    int mid = -1;
    int comparisons = 0;      
    int index = -1;

    // the original while is commented out, it doesn't handle 'not found' condition, 
    // changed to the new one which does correctly handle it
    //while(lo <= hi) {

    while ((list[hi] != list[lo]) && (data >= list[lo]) && (data <= list[hi])) {
        //printf("\nComparison %d  \n" , comparisons ) ;
        //printf("lo : %d, list[%d] = %d\n", lo, lo, list[lo]);
        //printf("hi : %d, list[%d] = %d\n", hi, hi, list[hi]);

        comparisons++;

        // probe the mid point 
        mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
        //printf("mid = %d\n",mid);

        // data found 
        if(list[mid] == data) {
            index = mid;
            break;
        } else {
            if(list[mid] < data) {
                // if data is larger, data is in upper half 
                lo = mid + 1;
            } else {
                // if data is smaller, data is in lower half 
                hi = mid - 1;
            }
        }               
    }

    printf("comparisons made: %d", comparisons); 
    stats[comparisons] = (stats[comparisons] == -1 ? 1 : stats[comparisons]+comparisons);

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
