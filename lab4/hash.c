// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 4

#include "hash.h"

// Returns Hash value by modding the passed key with the table size of the Table
int hashFunction(int tableSize, int key)
{
    return key % tableSize;
}