// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#ifndef TABLE_H
#define TABLE_H


typedef void *data_t;

typedef int key_t;

typedef struct table *table_t; /* define struct table int table.c */

table_t Table_new(int); /* initialize the table */

int Table_insert (table_t, key_t, data_t); /* insert one item */

data_t Table_find (table_t, key_t); /* find an item with key */

int Table_update(table_t, key_t, data_t); /* update item data in place */

data_t Table_remove (table_t, key_t); /* remove one item */

void Table_free (table_t *); /* free the entire table */


#endif // End of table.h