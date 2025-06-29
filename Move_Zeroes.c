/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

#include <stdio.h>



// Function to print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void moveZeroes(int* nums, int numsSize) {
    for (int a = 0; a < numsSize -1  ; a ++ ) { 
        for (int b=0; b< numsSize -1-a;b++ ) {
            if (nums[b] == 0 && nums[b+1] != 0) {
                nums[b] = nums[b] ^nums[b+1];
                nums[b+1] = nums[b] ^nums[b+1];
                nums[b] = nums[b] ^nums[b+1];
            } else {
                continue;
            }
        }
    }
}
//below is not my methord but its a really smart methord to dothis , i liked this 
/*
void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[count++] = nums[i];
        }
    }

    for (int j = count; j < numsSize; j++) {
        nums[j] = 0;
    }
    
}*/
// Main function to test
int main() {
    int nums[] = {0, 1, 0, 3, 12,0,2,3,4,5,6,7,8,9,0,0,00,34,7,0,5,0,4,0,2,0,4,0,6,8,0};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    printArray(nums, size);

    moveZeroes(nums, size);

    printf("After moveZeroes: ");
    printArray(nums, size);

    return 0;
}
