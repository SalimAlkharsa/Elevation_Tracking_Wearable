#include <stdio.h>

#define MAX_CAPACITY 3 // 3 sensors with 5 samples each
#define CHUNK_SIZE 3   // Chunk size refers to the number of sensor data samples (aka number of sensors)

typedef struct
{
    float data[MAX_CAPACITY];
    int length;
    int capacity;
} Slice;

// Function to initialize a new slice
Slice initializeSlice()
{
    Slice slice;
    slice.length = 0;
    slice.capacity = MAX_CAPACITY;
    return slice;
}

// Function to add elements to the slice
void addToSlice(Slice *slice, float values[], int numValues)
{
    if (slice->length + numValues > slice->capacity)
    {
        printf("Error: Slice capacity exceeded.\n");
        return;
    }

    for (int i = 0; i < numValues; i++)
    {
        slice->data[slice->length++] = values[i];
    }
}

// Function to add sensor data to slices 1 to 5
void addSensorDataToSlices(Slice slices[], int numSlices, float values[], int numValues)
{
    // Check if the first slice has space
    if (slices[0].length < MAX_CAPACITY)
    {
        addToSlice(&slices[0], values, CHUNK_SIZE);
    }
    else
    {
        // If the first slice is full, move data to the next slice and reset the first slice
        for (int i = numSlices - 1; i > 0; i--)
        {
            slices[i] = slices[i - 1];
        }
        slices[0] = initializeSlice();
        addToSlice(&slices[0], values, CHUNK_SIZE);
    }
}

// Function to print the elements of the slice
void printSlice(Slice slice)
{
    printf("Slice elements: ");
    for (int i = 0; i < slice.length; i++)
    {
        printf("%.2f ", slice.data[i]);
    }
    printf("\n");
}