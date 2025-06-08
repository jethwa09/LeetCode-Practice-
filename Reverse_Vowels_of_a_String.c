
/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


char* reverseVowels(char* s) {
    int size_string = strlen(s);
    int size_vowels ;
    int vowel_count =0;

    for(int i =0 ; i<size_string ; i++) {
        if (s[i]== 'a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
            vowel_count ++;
        }
    }
int count =0;
    char vowel_list[vowel_count+1];
    for(int i =0 ; i<size_string ; i++) {
        if (s[i]== 'a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
            vowel_list[count] = s[i];
            count ++;
        }
    }

    for(int i =0 ; i<size_string ; i++) {
        if (s[i]== 'a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') {
            s[i]= vowel_list[--vowel_count];
        }
    }
  return s;  
}



int main() {
    char s[] = "IceCreAm";
    printf("Output: %s\n", reverseVowels(s));  // Output: AceCreIm
    return 0;
}
