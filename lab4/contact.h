// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#ifndef CONTACT_H
#define CONTACT_H

#define MAXCHARACTERS 1994

// Defines structure of a Contact
typedef struct contactInformation *contactInfo;

// Allocates memory for structure type contactInfo
contactInfo contactAllocation();

// Stores integer passed into function to the key value in contactInfo structure
void contactSetKey(contactInfo, int);

// Frees a contactInfo type structure
void freeContact(contactInfo);

// Prints a menu
void menu();

// Updates data in a contactInfo type strucutre
void updateContact(contactInfo, contactInfo);

// Prints data in a contactInfo type strucutre
void contactPrint(contactInfo);

// Compares the data of contactInfo type strucutures
int contactCompare(contactInfo, contactInfo);

// Stores data into a contactInfo type structure 
contactInfo contactFill(contactInfo, int, int);

#endif // End of contact.h