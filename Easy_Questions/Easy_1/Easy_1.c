#include <stdio.h>
#include <string.h>

int Length_Of_Last_Word(char *);

int main() {
    
    char str[104];
    
    //Enter the Sentence
    printf("Enter the sentence :");
    scanf("%[^\n]%*c", str);
    
    int n=Length_Of_Last_Word(str);
    
    //Print the length of the last word
    printf("%d\n", n);
   

    return 0;
}


int Length_Of_Last_Word(char *s) {
	
    int length = 0;
     //i stores length of string
    int i = strlen(s)-1;

    // move i to last space
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Calculate the length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
