/*
 * hasUniqueChars.c
 * 
 *This file contains a function that checks if a given string contains all unique characters.
 * It uses bitwise operations to efficiently track the characters it encounters.
 * If the string contains non-printing characters or if there are duplicate characters (other than spaces),
 * the program either exits with an error or returns false.
 * 
 * Author: Bambi Nguyen
 */

#include <stdio.h>  // fprintf, printf
#include <stdlib.h> // exit() defined here
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations
#include <stdbool.h>  // to define a boolean type and true, false
                      // see https://en.wikibooks.org/wiki/C_Programming/stdbool.h

#include "binary_convert.h"


/*
 * This function is for debugging by printing out the value
 * of an input insigned long as a binary string.
 */
void seeBits(unsigned long value, char *debug_text) {
  
  // string to represent binary value of variable value
  char *bin_str;

  bin_str = ulong_to_bin_str(value);
  printf("%s%s\n", debug_text, bin_str);
  free(bin_str);
  
}

/*
 * Given an input string of chars, check for any non-printing
 * characters and print an error and exit if the string has any.
 */
void checkInvalid(char * inputStr) {
  char nextChar;
  int i;
  
  for(i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // if nextChar is invalid (31 or less or 127 as an ascii char code), then bail out
    if ((nextChar <= 31 ) || (nextChar == 127)) {
      fprintf(stderr, "invalid character in string\n");
      exit(EXIT_FAILURE);
    }
  }
}


/*
 *Checks if a given string contains all unique characters.
 * It iterates through the input string, ignoring spaces, and checks if any
 * character has appeared before using bitwise operations on two bit vectors.
 */
bool hasUniqueChars(char * inputStr) {
  // Bail out quickly if any invalid characters
  checkInvalid(inputStr);
  
  int i;   // Loop counter
  
  // Two bit vectors to track characters
  unsigned long checkBitsA_z = 0;   // For A-Z, a-z, and other higher ASCII characters
  unsigned long checkBitsexcl_amp = 0;  // For ! through @

  char nextChar;         // Next character in the string

  for (i = 0; i < strlen(inputStr); i++) {
    nextChar = inputStr[i];

    // Ignore spaces (' ')
    if (nextChar == ' ') {
      continue;
    }

    // Handle characters from 'A' to 'z' (ASCII 65 to 126)
    if (nextChar >= 65 && nextChar <= 126) {
      // Calculate the bit position for the character
      unsigned long bitMask = 1UL << (nextChar - 65);
      
      // Check if the bit is already set
      if (checkBitsA_z & bitMask) {
        // Character is a duplicate
        return false;
      }

      // Set the bit for this character
      checkBitsA_z |= bitMask;
    }
    
    // Handle characters from '!' to '@' (ASCII 33 to 64)
    else if (nextChar >= 33 && nextChar <= 64) {
      unsigned long bitMask = 1UL << (nextChar - 33);

      // Check if the bit is already set
      if (checkBitsexcl_amp & bitMask) {
        // Character is a duplicate
        return false;
      }

      // Set the bit for this character
      checkBitsexcl_amp |= bitMask;
    }

    else {
      fprintf(stderr, "Character out of expected range: %c\n", nextChar);
      exit(EXIT_FAILURE);
    }
  }

  // No duplicates found
  return true;
}
