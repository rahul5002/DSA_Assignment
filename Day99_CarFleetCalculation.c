#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int position;
    int speed;
    double time;
} Car;

int compareCars(const void* a, const void* b)
{
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;

    // Sort in descending order of position (cars closest to the target come first)
    if (carA->position > carB->position)
    {
        return -1;
    }
    if (carA->position < carB->position)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int target, n;
    if (scanf("%d %d", &target, &n) != 2 || n <= 0)
    {
        return 0;
    }

    Car* cars = (Car*)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cars[i].position);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cars[i].speed);
        // Calculate the time required to reach the target
        cars[i].time = (double)(target - cars[i].position) / cars[i].speed;
    }

    // Step 1: Sort cars by their starting position in descending order
    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double maxTime = 0.0;

    // Step 2: Iterate through cars and count fleets
    for (int i = 0; i < n; i++)
    {
        // If the current car takes more time than the fleet ahead of it, it forms a new fleet
        if (cars[i].time > maxTime)
        {
            fleets++;
            maxTime = cars[i].time;
        }
        // Otherwise, it catches up and merges into the existing fleet ahead
    }

    printf("%d\n", fleets);

    free(cars);
    return 0;
}