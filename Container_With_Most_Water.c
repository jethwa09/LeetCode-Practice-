/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
int maxArea(int* height, int heightSize) {
    uint32_t left = 0;
    uint32_t right = heightSize -1;
    uint32_t width, length ;
    uint32_t max_water_cap=0;
    while (left != right) {
        width = right -left;
        length = (height[left]>height[right] ?height[right] :height[left]);
        int water_cap = width * length;

        if (water_cap > max_water_cap) {
            max_water_cap=water_cap;
        }
        height[left]>height[right] ?height[right--] :height[left++];
    }
    return max_water_cap;
}
int main() {
    const int size = 100000;
    int* height = (int*)malloc(sizeof(int) * size);

    // Seed for reproducibility
    srand(42);

    // Generate a very difficult test case:
    // Mix of high values and dips
    for (int i = 0; i < size; i++) {
        if (i == 0 || i == size - 1) {
            height[i] = 10000; // high walls at ends
        } else {
            height[i] = rand() % 9999 + 1; // random in-between
        }
    }

    // Optional: you can print partial array to verify structure
    // for (int i = 0; i < 20; i++) printf("%d ", height[i]);
    // printf("...\n");

    int result = maxArea(height, size);
    printf("Max area (very large/difficult test case): %d\n", result);

    free(height);
    return 0;
}
