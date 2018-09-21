// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "list.h"
#include "hash.h"
#include "contact.h"

/*  Defines structure of a table which contains a double pointer of type list_t and an integer
    which stores the table size of the Table.
 */
typedef struct table 
{
    list_t *listArray;
    int tableSize;
} *table_t;

/*  Function Table_new will allocate memory for variabel hashTable of type table_t, then it will set 
    it's tableSize value by setting it to table_size passed in function. Then it will
    allocate memory for virable listArray inside the Table and will allocate memory for each list
    by using function list_init(). 
*/
table_t Table_new(int table_size) 
{
    table_t hashTable;
    int c1;
    hashTable = (table_t)calloc(1, sizeof(struct table));
    if (hashTable != NULL)
    {
        hashTable->tableSize = table_size;
        hashTable->listArray = (list_t *)calloc(table_size, sizeof(list_t));
        if (hashTable->listArray != NULL)
        {
            for (c1 = 0; c1 < table_size; c1++)
            {
                hashTable->listArray[c1] = list_init();
            }
        }
        else
        {
            free(hashTable);
            hashTable = NULL;
        }
    }
    return hashTable;
}

/*  Function Table_insert will first get the hash value by calling hashFunction() function. Then, it will start to search if there are
    any items in stored in the list of calculated hash value. If there is nothing in that linked list, it will call function list_appen()
    immediately and store the value passed in contact into the linked list. If there is at least one item in the list, then it will proceed
    to check if the item passed in the function has the same key value as the item already stored on the linked list by calling function
    contactComapare(). If the key value matches, then it will return a -1 meaning that you cannot store an data in the linked list
    with the same key. If not true, it will call list_append() and will store the data in the linked list. 

*/
int Table_insert (table_t table, key_t key, data_t contact)
{
    contactInfo searchContact;
    int index;
    int insertResult;
    int comparisonResult;
    index = hashFunction(table->tableSize, key);
    contactSetKey(contact, key);
    searchContact = list_first(table->listArray[index]);
    if (searchContact == NULL)
    {
        // contactFill(contact, key);
        insertResult = list_append(table->listArray[index], contact);
        if (insertResult == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
       while (searchContact != NULL)
       {
           comparisonResult = contactCompare(searchContact, contact);
           if (comparisonResult == 0)
           {
               return -1;
           }
           else
           {
               searchContact = list_next(table->listArray[index]);
           }
       }
    }
    // contactFill(contact, key);
    insertResult = list_append(table->listArray[index], contact);
    if (insertResult == 0)
    {
         return 0;
    }
    else
    {
        return -1;
    }
}

/*  Function Table_find will first determine the hash value by calling function hashFunction(). Then
    allocate memory for a temporary contactInfo structure variable and store the key passed in the function
    by calling function contactSetKey(). Then function list_find() is called to look for data in
    the linked list that contains the same key value. If true, it will return the address of the data and
    set it to variable searchContact and will return the address. If not true, it will return a NULL, and
    a NULL will be returned as well.   
*/
data_t Table_find (table_t table, key_t key)
{
    contactInfo temporaryContact;
    data_t searchContact;
    int index;
    index = hashFunction(table->tableSize, key);
    temporaryContact = contactAllocation();
    contactSetKey(temporaryContact, key);
    searchContact = list_find(table->listArray[index], temporaryContact, (cmpfunc)contactCompare);
    if (searchContact != NULL)
    {
        freeContact(temporaryContact);
        return searchContact;
    }
    else
    {
        freeContact(temporaryContact);
        return NULL;
    }
}

/*  Function Table_update will first use function hashFunction() to determine the hash value according
    to the key value passed in the function. Then it will see if there is any data stored in the linked
    list according to this hash value. If true, it will search for the value in the entire linked
    list and if it finds it, it will update the data, and a 0 is returned. If not true, it will
    return a -1.
*/
int Table_update(table_t table, key_t key, data_t newContact)
{
    contactInfo searchContact;
    int index;
    int compareResult;
    // contactSetKey(newContact, key);
    index = hashFunction(table->tableSize, key);
    searchContact = list_first(table->listArray[index]);
    while (searchContact != NULL)
    {
        compareResult = contactCompare(searchContact, newContact);
        if (compareResult == 0)
        {
            // newContact = contactFill(newContact, key);
            updateContact(searchContact, newContact);
            return 0;
        }
        else
        {
            searchContact = list_next(table->listArray[index]);
        }
    }
    return -1;
}

/*  Fuction Table_remove will first call function hashFunction() to determine the hash value using the key
    passed in the function. Then it will call function Table_find() to see if there is an data
    on the list that contains the key passed in the function. If true, it will call list_remove() function
    which will free memory of the node and will return the address of the data. If not true, it returns
    a NULL. 
*/
data_t Table_remove (table_t table, key_t key)
{
    int removeResult;
    int index;
    contactInfo searchContact;
    index = hashFunction(table->tableSize, key);
    searchContact = Table_find(table, key);
    if (searchContact != NULL)
    {
        removeResult = list_remove(table->listArray[index]);
        if (removeResult == 0)
        {
            return searchContact;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

/*  Fucntion Table_free will enter a for loop that will enter a for loop that will run until
    it reaches the value of tableSize. Then it will look for the first item in each
    array of list, if it exits an item in the list, it will go through it and free
    each data in that list. If there is no data in that list, it will skip and go to the next one.
    Then, it enters another for loop that will run until it reahes the value of tableSize as well.
    Inside the loop function list_finalize() is called to free all linked lists. Finally
    the listArray pointer will be freed and the table as well. 
 */
void Table_free (table_t *table)
{
    int c1;
    contactInfo temporaryContact;
    for (c1 = 0; c1 < (*table)->tableSize; c1++)
    {
        temporaryContact = list_first((*table)->listArray[c1]);
        while (temporaryContact != NULL)
        {
            free(temporaryContact);
            temporaryContact = list_next((*table)->listArray[c1]);
        }
    }
    for (c1 = 0; c1 < (*table)->tableSize; c1++)
    {

        list_finalize((*table)->listArray[c1]);
    }
    free((*table)->listArray);
    free(*table);
}