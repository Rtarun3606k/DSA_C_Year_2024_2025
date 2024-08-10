// tower of hanoi program day-3
#include <stdio.h>
#include <stdlib.h>
// 2^n-1
//  Function to solve the Tower of Hanoi puzzle
// for 3 discs
//  A, C, B are the tower names
//  A is the source tower
//  C is the destination tower
//  B is the auxiliary tower
//  n is the number of discs
//  2^3 - 1 = 7 moves to solve the tower

// Function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination); // tower of hanoi
        return;                                                     // tower of hanoi
    }
    towerOfHanoi(n - 1, source, destination, auxiliary); // tower of hanoi
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination); // tower of hanoi to check the condition
}

int main()
{
    printf("Enter the number of disks: "); // tower of hanoi
    int n;                                 // tower of hanoi
    scanf("%d", &n);                       // tower of hanoi
    towerOfHanoi(n, 'A', 'B', 'C');        // tower of hanoi called
    return 0;                              // tower of hanoi
}