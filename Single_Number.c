
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1
*/
#include <stdio.h>

//my solution, not the best but it works 
int singleNumber(int* nums, int numsSize) 
{
    
    for(int a = 0 ; a < numsSize ; a++) 
    {
        bool match_flag = false;
        for(int b = 0; b< numsSize; b++) 
        {
            if(a != b && nums[a] == nums[b])
            {
                match_flag = true;
                break;
            }
        }
        if(match_flag == false)
        {
            return nums[a];
        }
    }
    return -1;
}
// XOR-based solution
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

int main() {
    int nums[] = {2, 3, 5, 4, 5, 3, 4};  // 2 is the unique number
    int size = sizeof(nums) / sizeof(nums[0]);

    int unique = singleNumber(nums, size);

    printf("The single number is: %d\n", unique);

    return 0;
}
