// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "table.h"
#include "contact.h"

#define TEST 100000

int main(int argc, char *argv[])
{
    // Variable Declaration Section 
    int key;
    int tableSize;
    int startOfClock;
    int endOfClock;
    int c1;
    double contactInsertTime;
    double contactDeleteTime;
    double contactFindTime;
    double contactUpdateTime;
    double contactInsertTimeCol;
    double contactDeleteTimeCol;
    double contactFindTimeCol;
    double contactUpdateTimeCol;
    double insertCollision;
    double updateCollision;
    double deleteCollision;
    double findCollision;
    table_t table;

    tableSize = 51;
    table = Table_new(tableSize);

    srand(0);
   
    // This for loop will determine the Insert time when there are no Collisions
    startOfClock = clock();
    for (c1 = 0; c1 < 51; c1++)
    {
        contactInfo contact;
        contact = contactAllocation();
        key = c1;
        contact = contactFill(contact, key, c1);
        Table_insert(table, key, contact);
    }
    endOfClock = clock();
    contactInsertTime = (double)(endOfClock - startOfClock);
    contactInsertTime = contactInsertTime / CLOCKS_PER_SEC;
    contactInsertTime = contactInsertTime / 51;
    printf("\n\nAverage insert time with no collisions: %.3e s\n", contactInsertTime);

    // This for loop will determine the Update time when there are no Collisions
    startOfClock = clock();
    for (c1 = 0; c1 < 51; c1++)
    {
        contactInfo temporaryContact;
        temporaryContact = contactAllocation();
        key = c1;
        contactFill(temporaryContact, key, c1);
        Table_update(table, key, temporaryContact);
        free(temporaryContact);
    }
    endOfClock = clock();
    contactUpdateTime = (double)(endOfClock - startOfClock);
    contactUpdateTime = contactUpdateTime / CLOCKS_PER_SEC;
    contactUpdateTime = contactUpdateTime / 51;
    printf("Average update time with no collisions: %.3e s\n", contactUpdateTime);

    // This for loop will determine the Find time with no Collisions.
    startOfClock = clock();
    for (c1 = 0; c1 < 51; c1++)
    {
        key = c1;
        Table_find(table, key);
    }
    endOfClock = clock();
    contactFindTime = (double)(endOfClock - startOfClock);
    contactFindTime = contactFindTime / CLOCKS_PER_SEC;
    contactFindTime = contactFindTime / 51;
    printf("Average find time with no collisions: %.3e s\n", contactFindTime);

    // This for loop will determine the Delete time with no Collisions. 
    startOfClock = clock();
    for (c1 = 0; c1 < 51; c1++)
    {
        contactInfo contact;
        key = c1;
        contact = Table_remove(table, key);
        free(contact);
    }
    
    endOfClock = clock();
    contactDeleteTime = (double)(endOfClock - startOfClock);
    contactDeleteTime = contactDeleteTime / CLOCKS_PER_SEC;
    contactInsertTime = contactDeleteTime / 51;
    printf("Average delete time with no collisions: %.3e s\n", contactDeleteTime);

    
    // This for loop will determine the Insert time with Collisions
    startOfClock = clock();
    for (c1 = 0; c1 < TEST; c1++)
    {
        contactInfo contact;
        contact = contactAllocation();
        key = rand();
        contact = contactFill(contact, key, c1);
        Table_insert(table, key, contact);
    }

    endOfClock = clock();
    contactInsertTimeCol = (double)(endOfClock - startOfClock);
    contactInsertTimeCol = contactInsertTimeCol / CLOCKS_PER_SEC;
    contactInsertTimeCol = contactInsertTimeCol / TEST;
    printf("\nAverage insert time with collisions: %.3e s\n", contactInsertTimeCol);

    // This for loop will determine the Update time with Collisions.
    startOfClock = clock();
    for (c1 = 0; c1 < TEST; c1++)
    {
        contactInfo temporaryContact2;
        temporaryContact2 = contactAllocation();
        key = rand();
        contactFill(temporaryContact2, key, rand());
        Table_update(table, key, temporaryContact2);
        free(temporaryContact2);
    }
    endOfClock = clock();
    contactUpdateTimeCol = (double)(endOfClock - startOfClock);
    contactUpdateTimeCol = contactUpdateTimeCol / CLOCKS_PER_SEC;
    contactUpdateTimeCol = contactUpdateTimeCol / TEST;
    printf("Average update time with collisions: %.3e s\n", contactUpdateTimeCol);

    // This for loop will determine the Find time with Collisions
    startOfClock = clock();
    for (c1 = 0; c1 < TEST; c1++)
    {
        key = rand();
        Table_find(table, key);
    }
    endOfClock = clock();
    contactFindTimeCol = (double)(endOfClock - startOfClock);
    contactFindTimeCol = contactFindTimeCol / CLOCKS_PER_SEC;
    contactFindTimeCol = contactFindTimeCol / TEST;
    printf("Average find time with collisions: %.3e s\n", contactFindTimeCol);
    
    // This for loop will determine the Delete time with Collisions
    startOfClock = clock();
    for (c1 = 0; c1 < TEST; c1++)
    {
        contactInfo contact;
        key = rand();
        contact = Table_remove(table, key);
        free(contact);
    }
    
    endOfClock = clock();
    contactDeleteTimeCol = (double)(endOfClock - startOfClock);
    contactDeleteTimeCol = contactDeleteTimeCol / CLOCKS_PER_SEC;
    contactDeleteTimeCol = contactDeleteTimeCol / TEST;
    printf("Average delete time with collisions: %.3e s\n", contactDeleteTimeCol);

    // Formula to determine the Complexity value of Find, Update, Find, and Delete
    insertCollision = contactInsertTimeCol / contactInsertTime;
    updateCollision = contactUpdateTimeCol / contactUpdateTime;
    findCollision = contactFindTimeCol / contactFindTime;
    deleteCollision = contactDeleteTimeCol / contactDeleteTime;

    printf("\nComplexity of Insert: %.3f\n", insertCollision);
    printf("Comlexity of Update: %.3f\n", updateCollision);
    printf("Complexity of Find: %.3f\n", findCollision);
    printf("Complexity of Delete: %.3f\n\n", deleteCollision);
    
    // Frees the Table
    Table_free(&table);
    return 0;
}