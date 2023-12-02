#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a string is a palindrome
int is_String_Palindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to find the shortest palindrome by adding characters in front of the given string
char* string_shortestPalindrome(char* s) {
    int len = strlen(s);
    
    // Check if the entire string is already a palindrome
    if (is_String_Palindrome(s, 0, len - 1)) {
        return s;
    }

    // Find the length of the longest palindrome prefix
    int prefixLen = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (is_String_Palindrome(s, 0, i)) {
            prefixLen = i + 1;
            break;
        }
    }

    // Create a new string with the reverse of the remaining part added to the beginning
    char *result = (char*)malloc(sizeof(char) * (2 * len - prefixLen + 1));
    strcpy(result, s + prefixLen);
    strcat(result, s);

    return result;
}

int main() {
    char s1[] = "aacecaaa";
    
    char *result1 = string_shortestPalindrome(s1);
    
    printf("Input: s= %s\nOutput: %s\n\n", s1, result1);
   
    // Don't forget to free the allocated memory
    free(result1);
    

    return 0;
}
