#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Observation.h"
#include "Metrics.h"
#include "Window.h"

// Function to initialize a new window
Window *createWindow()
{
    Window *window = (Window *)malloc(sizeof(Window));
    if (window == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for the window.\n");
        exit(EXIT_FAILURE);
    }

    window->observationCount = 0;

    return window;
}

// Function to insert an observation into the window
void insertObservation(Window *window, Observation observation)
{
    if (window->observationCount < 12)
    {
        window->observations[window->observationCount] = observation;
        window->observationCount++;
    }
    else
    {
        fprintf(stderr, "Error: Window is full. Cannot insert more observations.\n");
    }
}

// Function to calculate metrics based on observations in the window
// Function to calculate metrics based on observations in the window
Metrics calculateMetrics(const Window *window)
{
    Metrics metrics;

    // Example calculations (replace with actual formulas)
    // I) Pa RoC
    metrics.Pa_roc = (window->observations[window->observationCount - 1].Pa - window->observations[0].Pa) /
                     (float)(55.96); // TODO This is an approximate value, replace with a real measurement!!!!!!
    // II) Z_rot max-min
    float maxZ_rot = -99999999; // TODO: replace with floor value
    float minZ_rot = 99999999;  // TODO: replace with ceiling value
    for (int i = 0; i < window->observationCount; ++i)
    {
        if (window->observations[i].Z_rot > maxZ_rot)
        {
            maxZ_rot = window->observations[i].Z_rot;
        }
        if (window->observations[i].Z_rot < minZ_rot)
        {
            minZ_rot = window->observations[i].Z_rot;
        }
    }
    metrics.Z_rot_max_min = maxZ_rot - minZ_rot;

    // III) Z_g max
    metrics.Z_g_max = window->observations[0].Z_acc;
    for (int i = 0; i < window->observationCount; ++i)
    {
        if (window->observations[i].Z_acc > metrics.Z_g_max)
        {
            metrics.Z_g_max = window->observations[i].Z_acc;
        }
    }

    // IV) Z_g min
    metrics.Z_g_min = 99999999; // TODO: replace with ceiling value
    for (int i = 0; i < window->observationCount; ++i)
    {
        if (window->observations[i].Z_acc < metrics.Z_g_min)
        {
            metrics.Z_g_min = window->observations[i].Z_acc;
        }
    }

    // V) Y_g kurtosis (example calculation, replace with actual formula)
    // Note: This is a simplified example; may need to use a more advanced approach for accurate kurtosis calculation
    float meanY_g = 0.0;
    for (int i = 0; i < window->observationCount; ++i)
    {
        meanY_g += window->observations[i].Y_acc;
    }
    meanY_g /= window->observationCount;

    float sumSquaredDiff = 0.0;
    for (int i = 0; i < window->observationCount; ++i)
    {
        float diff = window->observations[i].Y_acc - meanY_g;
        sumSquaredDiff += diff * diff;
    }

    metrics.Y_g_kurtosis = sumSquaredDiff / window->observationCount;

    return metrics;
}

// Function to clear observations from the window and free memory, tysm chatgpt
void clearObservations(Window *window)
{
    for (int i = 0; i < window->observationCount; ++i)
    {
        // Assuming observations were dynamically allocated
        // Free the memory for each observation
        // Adjust this based on how your Observation structure is allocated
        // If no dynamic allocation was done, this part can be skipped
        // free(window->observations[i].someField); // Example, replace with your actual fields

        // Reset observation values to zero (optional)
        memset(&(window->observations[i]), 0, sizeof(Observation));
    }
    window->observationCount = 1;
}