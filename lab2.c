// Hotel structure accepts the name of a room, its price per night and the area of the room in square feet. Write a code to initialise an array of 'n' hotel rooms from input. Pass the array to a function Ratio_Order. Calculate the squarefeet/price ratio for each of the rooms. Larger the ratio, the better it is for a customer. So sort the array in Descending order based on the ratios calculated and display. The displayed ratio must have two decimal values. Note that the price for a room is never 0. In case of a tie maintain the order same as in input.

// Input Format

// number of inputs
// room1_name room1_price room1_squarefeet
// room2_name room2_price room2_squarefeet
// Constraints

// 0 <= room_price <= 100000
// 0 <= room_squarefeet <= 10000
// Output Format

// room1_name room1_price room1_squarefeet room1_ratio
// room2_name room2_price room2_squarefeet room2_ratio
// Sample Input 0

// 3
// green 1000 1000
// red 1000 2000
// blue 1000 100
// Sample Output 0

// red 1000 2000 2.00
// green 1000 1000 1.00
// blue 1000 100 0.10
// Sample Input 1

// 4
// garden 10000 200
// ocean 15000 500
// skyline 12000 600
// pool 11000 300
// Sample Output 1

// skyline 12000 600 0.05
// ocean 15000 500 0.03
// pool 11000 300 0.03
// garden 10000 200 0.02
#include <stdio.h>
#include <stdlib.h>

struct Hotel
{
    char name[100];
    int price;
    int squarefeet;
    float ratio;
};

void Ratio_Order(struct Hotel rooms[], int n)
{
    // Calculate the squarefeet/price ratio for each room
    for (int i = 0; i < n; i++)
    {
        rooms[i].ratio = (float)rooms[i].squarefeet / rooms[i].price;
    }

    // Sort the array in descending order based on the ratios
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (rooms[j].ratio < rooms[j + 1].ratio)
            {
                struct Hotel temp = rooms[j];
                rooms[j] = rooms[j + 1];
                rooms[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %.2f\n", rooms[i].name, rooms[i].price, rooms[i].squarefeet, rooms[i].ratio);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Hotel rooms[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", rooms[i].name, &rooms[i].price, &rooms[i].squarefeet);
    }

    Ratio_Order(rooms, n);

    return 0;
}