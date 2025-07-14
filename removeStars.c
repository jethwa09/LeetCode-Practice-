// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>  // for malloc, calloc, free
#include <string.h>  // for strlen

char* removeStars(char* s);
int main() {
    char input[] = "leet**cod*e";
    char* output = removeStars(input);
    printf("Result: %s\n", output);  // Should print: lecoe
    free(output); // free the memory
    return 0;
}


char* removeStars(char* s) {
    int string_size = strlen(s);
    char * my_string = (char *)calloc (sizeof(char),(string_size+1));
    int stack_pointer = 0;

    for(int a = 0 ; a < string_size ; a++) {
        if (s[a]!='*') {
            my_string[stack_pointer++] =s[a];
        }
        else if (s[a]=='*') {
            my_string[--stack_pointer] ='\0';
        }
    }
    return  my_string; 
}

