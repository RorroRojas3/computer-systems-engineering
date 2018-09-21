// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 2

#ifndef GUITARDB_H
#define GUITARDB_H

// Library Declaration Section
#include "guitar.h"

typedef struct guitardb_s
{
    // Variable declaration section
    struct list *list;
} *guitardb_t;

/* initialize a new guitar database */
guitardb_t guitardb_init(void);

/* add a guitar to the database */
key_t guitardb_add(guitardb_t, guitar_t);

/* lookup a guitar by id return a pointer to it */
guitar_t guitardb_lookup(guitardb_t, key_t);

/* delete guitar from database, return pointer to it, do not free */
guitar_t guitardb_delete(guitardb_t, key_t);

/* reports all of the guitars in the database with it’s key, make,
model, and year, etc. */
void guitardb_report(guitardb_t);

/* free all resources used by the guitar database, remove everything
from the linked list and free all pointers there before finalizing the
list */
void guitardb_finalize(guitardb_t);

#endif