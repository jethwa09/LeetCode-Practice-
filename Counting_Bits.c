//Counting Bits
/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 */

#include <stdio.h>
#include <stdlib.h>

// Bitwise-optimized countBits function
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {

    int * ans = malloc ((n+1)*sizeof(int));
    *returnSize = n + 1; 
    for (;n>-1;n--) 
    {   
        int temp = n;
        int ones = 0;
        int reminder = 0;
        while(temp>0)
        {
            reminder = temp%2;
            temp=temp/2;
            ones = ones + reminder;
        }
        ans[n] = ones;
    } 
    return ans;
}

// Main function to test
int main() {
    int n = 999999;
    int size;
    int* result = countBits(n, &size);

    printf("Number of 1s in binary representation from 0 to %d:\n", n);
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", i, result[i]);
    }

    // Don't forget to free the allocated memory
    free(result);
    return 0;
}
