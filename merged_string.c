/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {

    int size_merged = (strlen(word1) + strlen(word2));
    char* merged = malloc((size_merged + 1) * sizeof(char));
    int count1 = 0;
    int count2 = 0;
    int i=0;
    while( count1<(strlen(word1)) && count2<(strlen(word2))) {
            merged[i] = word1[count1];
            merged [i+1] = word2[count2];
            count1++;
            count2++;
            i+=2;
    }

        while( count1 < (strlen (word1 ) ) ) {
            merged[i] = word1[count1];
            count1++;
            i++;
    }
    
            while( count2 < (strlen (word2 ) ) ) {
            merged[i] = word2[count2];
            count2++;
            i++;
    }
    merged[size_merged] = '\0';
    return merged;
}




int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    char* result = mergeAlternately(word1, word2);
    printf("Merged: %s\n", result);  // Output: apbqcr
    free(result);
    return 0;
}
