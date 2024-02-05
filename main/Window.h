// Window.h
#ifndef WINDOW_H
#define WINDOW_H

#include "Observation.h"
#include "Metrics.h"

typedef struct
{
    Observation observations[12];
    int observationCount;
    Metrics metrics;
} Window;

Window *createWindow();
void insertObservation(Window *window, Observation observation);
Metrics calculateMetrics(const Window *window);
void clearObservations(Window *window);

#endif // WINDOW_H
