/*
 * TODO: Add an appropriate descriptive comment here
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");


  
  printf ("%s", string1);
  printf ("%s", string2);
  printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  strcpy(string3, "day");
  ok = hasUniqueChars(string3);
  assert(ok);

  strcpy(string3, "dinner");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  strcpy(string3, "farm");
  ok = hasUniqueChars(string3);
  assert(ok);

  strcpy(string3, "a b cc\n");
  ok = hasUniqueChars(string3);
 
  
  printf("All test passed! \n");
  
  return 0;
}