// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 2

#ifndef GUITAR_H
#define GUITAR_H

// Defining Delcaration Section
#define MAXCHARACTERS 1994

typedef int key_t;
typedef enum guitartype_e
{
    S = 'S', /* solid body */
    A = 'A', /* arch-top hollow body */
    T = 'T' /* semi-hollow (thinline) */
} guitartype_t;
typedef enum pickup_e
{
    H = 'H', /* humbucker */
    C = 'C', /* single coil */
    P = 'P', /* P90 */
    F = 'F', /* Filtertron */
    N = 'N' /* none */
} pickup_t;

typedef struct guitar_s 
{
    key_t id_number;
    char make[20];
    char model [20];
    char submodel[15];
    guitartype_t gtype;
    int year; /* year of manufacture */
    char finsh[25]; /* description of finish incuding color,binding, etc. */
    int strings; /* number of strings - usually 6 or 7 */
    int pickups; /* number of pickups */
    pickup_t neck; /* pickup type */
    pickup_t middle; /* pickup type */
    pickup_t bridge; /* pickup type */
} *guitar_t;

/* allocate a new struct guitar_s and return a pointer to it */
guitar_t guitar_init(void);

/* read from user all fields for a guitardb_guitar */
int guitar_fill(guitar_t);

/* set the id of a guitardb_guitar */
int guitar_setid(guitar_t, key_t);

/* get the id of a guitardb_guitar */
key_t guitar_getid(guitar_t);

/* prints a guitar */
int guitar_print(guitar_t);

/* returns 0 if equal, <0 if less than, >0 if greater than */
int guitar_compare(guitar_t, guitar_t);

void guitar_free(guitar_t);

#endif