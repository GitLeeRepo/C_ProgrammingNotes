// carray_vs_pointer.c
//
// Demonstrates the differences between strinng character arrays and pointers
// Refer to the inline comments for details

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declarations
void ChangeStrs1(char cArrayStr[], char *ptrStr);
void ChangeStrs2(char cArrayStr[], char **ptrStr);


int main(void) {
    char *strPtr;                          // allocates no memory
    char strCAr[40];                       // allocates 40 bytes of memory
    char *msgPtr = "Hello, World!";        // allocates 14 bytes of memory 
    char msgCAr[20] = "Hello, World!";     // allocates 20 bytes of memory
    char infoCAr1[40] = "Character Array"; // allocates 40 bytes of memory
    char infoCAr2[] = " vs Pointer";       // allocates 12 bytes of memory

    // strcat ok since infoCAr1 is big enough to hold both
    strcat(infoCAr1, infoCAr2);
    puts(infoCAr1);

    printf("The \"%s\" variable is defined as 'char infoCAr2[]' and has a sizeof=%zd and length=%zd\n", 
                                                    infoCAr2, sizeof infoCAr2, strlen(infoCAr2));

    // strPtr can be assigned string literal directory
    strPtr = "Tester pointer" ;
    printf("strPtr: \"%s\" with a sizeof=%zd and length=%zd\n", strPtr, sizeof strPtr, strlen(strPtr));
    // strCAr = "Test Char Array" is illegal for char array

    // for a char array use strcpy instead
    strcpy(strCAr, "Test array");
    printf("strCAr: \"%s\" with a sizeof=%zd  and length=%zd\n", strCAr, sizeof strCAr, strlen(strCAr));
    // but strcpy(strPtr, "Test Pointer") will corrupt memory

    
    strPtr = malloc(40);
    strcpy(strPtr, "test pointer - a bit longer");
    printf("strPtr: \"%s\" with a sizeof=%zd and length=%zd\n", strPtr, sizeof strPtr, strlen(strPtr));

    // ok to increment a string pointer
    msgPtr++;
    printf("msgPtr: \"%s\" after increment with a sizeof=%zd and length=%zd\n", 
                                                        msgPtr, sizeof msgPtr, strlen(msgPtr));
    // but ++msgCAr is illegal, you can't increment a character array

    // decrement str pointer back to the original
    msgPtr--;
    printf("msgPtr: \"%s\"  decremented back to orig with a sizeof=%zd and length=%zd\n", 
                                                        msgPtr, sizeof msgPtr, strlen(msgPtr));
 
    // no increment, but you can still use memory offsets with character arrays
    printf("msgCAr: \"%s\" (msgCAr+1) with a sizeof=%zd  and length=%zd\n", 
                                                        (msgCAr+1), sizeof (msgCAr+1), strlen(msgCAr+1));

    // and the original char array was unaltered
    printf("msgCAr: \"%s\" still intact with a sizeof=%zd  and length=%zd\n", 
                                                        msgCAr, sizeof msgCAr, strlen(msgCAr));

    // In this function call the contents of msgCAr are change by the function
    // but msgPtr is not changed because it still has the address of the original
    ChangeStrs1(msgCAr, msgPtr);   
    printf("msgCAr: \"%s\" changed in function with a sizeof=%zd  and length=%zd\n", 
                                                        msgCAr, sizeof msgCAr, strlen(msgCAr));
    printf("msgPtr: \"%s\" not changed by function with a sizeof=%zd and length=%zd\n", 
                                                        msgPtr, sizeof msgPtr, strlen(msgPtr));


    // In this function msgCAr is unchanged, but msgPtr passes the address of the pointer
    // itself (ptr to ptr) to the function, therefore it is changed in that it has the
    // address of a new string
    ChangeStrs2(msgCAr, &msgPtr);   
    printf("msgPtr: \"%s\" changed by 2nd function with a sizeof=%zd and length=%zd\n", 
                                                        msgPtr, sizeof msgPtr, strlen(msgPtr));
}

// example 1: change to the contents of the char array visible to the caller
//            but the changes to the pointer are not
void ChangeStrs1(char cArrayStr[], char *ptrStr) {
    strcpy(cArrayStr, "New cArray"); // change also visible to the caller
    ptrStr = "New Ptr"; // changed locally, but change not returned
}

// example 2: same for char array as in example 1, but now the string pointer
//            is also changed because the address of the pointer itself (ptr to ptr)
//            is passed in.  Also it ok to return the new address because string literals
//            are stored in the data segment rather than on the stack.
void ChangeStrs2(char cArrayStr[], char **ptrStr) {
    strcpy(cArrayStr, "New cArray");
    *ptrStr = "New Ptr"; // this time the change is returns, because the new address is returned
}


