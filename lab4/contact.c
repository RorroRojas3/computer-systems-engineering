// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

// Defines structure of a Contact
typedef struct contactInformation
{
    int phoneNumber;
    int key;
} *contactInfo;

// Allocates memory for structure type contactInfo
contactInfo contactAllocation()
{
    contactInfo contact;
    contact = (contactInfo)calloc(1, sizeof(struct contactInformation));
    return contact;
}

// Stores integer passed into function to the key value in contactInfo structure
void contactSetKey(contactInfo contact, int key)
{
    contact->key = key;
}

// Frees a contactInfo type structure
void freeContact(contactInfo contact)
{
    free(contact);
}

// Prints a menu
void contactPrint(contactInfo contact)
{
    // printf("Name: %s\n", contact->name);
    printf("Phone number: %d\n\n", contact->phoneNumber);
}

// Updates data in a contactInfo type strucutre
void updateContact(contactInfo searchContact, contactInfo newContact)
{
    // strcpy(searchContact->name, newContact->name);
    searchContact->phoneNumber = newContact->phoneNumber;
}

// Prints data in a contactInfo type strucutre
void menu(void)
{
     // Asks the user to enter a command and prints those commands
    printf("**********************************************\n");
    printf("Please enter any of these commands:\n");
    printf("Add - Adds contact to Table\n");
    printf("Delete - Deletes contact from Table\n");
    printf("Update - Updates contact information already stored in Table");
    printf("Lookup - Display contact information\n");
    printf("HELP - Prints menu\n");
    printf("QUIT - Exits Program\n");
    printf("**********************************************\n\n");
}

// Compares the data of contactInfo type strucutures
int contactCompare(contactInfo searchContact, contactInfo tableContact)
{
    if (searchContact->key == tableContact->key)
    {
        return 0;
    }
    else
    {
        return -1;
    }
};

// Stores data into a contactInfo type structure
contactInfo contactFill(contactInfo contact, int key, int phoneNumber)
{
    contact->key = key;
    contact->phoneNumber = phoneNumber;
    return contact;
}