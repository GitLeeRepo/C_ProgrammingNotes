////////////////////////////////////////////////////////////////////////////////////////////
// strinit_examples.c
//
// Examples of various string initializations
//
// Refer to:
//      carray_vs_pointer.c - focuses on differences between string char arrays & pointers
///////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>


int main(void) {
    char str1[80] = "Hello, World!"; // buffer bigger than the string, it can safely be filled up to 80 chars (include null terminator)
    char str2[] = "Hello, World!";   // buffer (14 bytes) the same size as the string, including null terminator
    char *str3 = "Hello, World!";    // buffer (14 bytes) pointer version of prior examples
    char str4[80] = "";              // empty string, the first byte is set to null ('\0')
    char str5[80] = { '\0' };        // the entire buffer is filled with nulls ('\0')

    printf("After changes\n");
    printf("str1: %s\n", str1); 
    printf("str2: %s\n", str2); 
    printf("str3: %s\n", str3); 
    printf("str4 (empty): %s\n", str4); 
    printf("str5 (empty): %s\n", str5);
 
    // after declaration they can also be initialized
    strcpy(str1, "Hello, World!  How are you?");  // a slightly longer version of the declaration (ok since it has an 80 byte buffer)
    strcpy(str2, "Hey, World!");  // ok since it is smaller than original buffer)
    str3 = "Hello, World! How are you?"; // bigger than orig, but ok since this pointer now points to a new string
    str4[0] = '\0';   // first byte nulled, the equivellent of its declaration initializtion
    memset(str5, '\0', sizeof str4); // filled with all nulls, the equivellent of its declaration iniialization

    printf("After changes\n");
    printf("str1: %s\n", str1); 
    printf("str2: %s\n", str2); 
    printf("str3: %s\n", str3); 
    printf("str4 (empty): %s\n", str4); 
    printf("str5 (empty): %s\n", str5);     
}

