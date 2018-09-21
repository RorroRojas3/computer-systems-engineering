// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 3
// © Rodrigo Rojas. All Rights Reserved. 

#ifndef STRUCTURES_H
#define STRUCTURES_H

// Typedef that defines structure request_s to have three disk_queue_t pointers name head, current, and tail
typedef struct request_s
{
    int track;
    double arrival_time;
    double start_time;
    double finish_time;
} *request_t;

// Typedef that defines strucutre of event_s which has a event_type, event_time, and a request_t request 
typedef struct event_s
{
    int event_type;
    double event_time;
    request_t request;
} *event_t;


#endif