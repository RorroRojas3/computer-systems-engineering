// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 2

#ifndef LIST_H
#define LIST_H

typedef struct list *list_t;

typedef void *data_t;

typedef int (*cmpfunc)(data_t, data_t);

/* create a new empty list */
list_t list_init();

/* insert at head of list */
int list_insert(list_t, data_t);

/* append to tail of list */
int list_append(list_t, data_t);

/* find and sets current item using callback compare function */
data_t list_find(list_t, data_t, cmpfunc);

/* return item at head of list, set current item */
data_t list_first(list_t);

/* return next item after current item */
data_t list_next(list_t);

/* return prev item before current item */
data_t list_prev(list_t);

/* return item at tail of list, set current item */
data_t list_last(list_t);

/* before current item */
int list_insert_before(list_t, data_t);

/* after current item */
int list_insert_after(list_t, data_t);

/* remove current item */
int list_remove(list_t);

/* free all resources allocated by the list */
int list_finalize(list_t);

#endif
