/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    bool single_zero_flag = 0;
    bool double_zero_flag = 0;
    bool triple_zero_flag = 0;
    for (int i=0; i<flowerbedSize;i++ ) {
        if(flowerbed[i]==0 ){
            if (single_zero_flag ==true || i == 0 || (i == flowerbedSize -2 ) ) {
                if(double_zero_flag == true) {
                    triple_zero_flag = true;
                }
                double_zero_flag = true; 
            }
        single_zero_flag = true;
        } else {
            single_zero_flag = 0;
            double_zero_flag = 0;
            triple_zero_flag = 0;
        }
        if(triple_zero_flag == true) {
            n--;
            single_zero_flag = 1;
            double_zero_flag = 0;
            triple_zero_flag = 0;
        }  
    }
    if( n==0 || (flowerbedSize == 1 && flowerbed[0]==0 )) {
        return true;
    } else {
        return false;
    }

}

int main() {
    int flowerbed[] = {1, 0, 0, 0, 1, 0, 0};  // Example test case
    int n = 2;
    int size = sizeof(flowerbed) / sizeof(flowerbed[0]);

    bool result = canPlaceFlowers(flowerbed, size, n);

    printf("Can place %d flowers: %s\n", n, result ? "true" : "false");

    return 0;
}
