/*
====================================================================
    Problem: Printing Pattern Using Loops
    Platform: HackerRank (Conditionals and Loops)
    Language: C
====================================================================
 DESCRIPTION:
Given an integer n, print a square pattern of size (2*n - 1) × (2*n - 1).
The pattern should display numbers decreasing from n on the outermost
layer toward 1 at the center.

Each layer forms a square boundary of the same number, with each inner
layer having a value one less than the layer before it.

--------------------------------------------------------------------
EXAMPLE INPUT:
4

EXPECTED OUTPUT:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
--------------------------------------------------------------------
LOGIC EXPLANATION:
For each cell (x, y) in the grid:
    • Compute its distance from all four sides:
        top = x
        left = y
        right = size - 1 - y
        bottom = size - 1 - x
    • The smallest of these values (minDist) tells us how deep the cell
      is inside the square.
    • The value to print is therefore (n - minDist).

--------------------------------------------------------------------
 TOPIC TAGS:
    Loops | Nested Loops | Pattern Printing | Logical Thinking

====================================================================
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int size = 2 * n - 1;

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            // Find the distance of (x,y) from each side
            int top = x;
            int left = y;
            int right = size - 1 - y;
            int bottom = size - 1 - x;

            // The minimum of these gives how deep we are inside
            int minDist = top;
            if (left < minDist) minDist = left;
            if (right < minDist) minDist = right;
            if (bottom < minDist) minDist = bottom;

            // Subtract that from n to get the correct number
            printf("%d ", n - minDist);
        }
        printf("\n");
    }

    return 0;
}
