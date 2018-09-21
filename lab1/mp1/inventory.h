// Name: Rodrigo Ignacio Rojas Garcia
// Course Number: ECE 2230 
// Section: 001
// Semester: Spring 2017
// Assignment Number: 1.5

#ifndef INVENTORY_H
#define INVENTORY_H

// Defines the maximum number of characters in character array
#define MAXCHARACTERS 80
// Defines the maximum number of inventories that can be created
#define MAXINVENTORIES 8
// Defines the maximum number of items that can be stored in an inventory 
#define MAXITEMS 5
// Defines the maximum number of characters that can be in the description of an item
#define MAXDESCRIPTION 16

// Defines the structure of an inventory
struct inventory 
{
    int location;
    struct inventory_item *items[MAXITEMS]; // Array of structures that point to different items
};

// Defines the structure of an invetory item
struct inventory_item 
{
    int item_key; // Used as a unique locator for an item
    int item_type; // 0.- Armor, 1.- Sword, 2.- Shield, 3.- Scroll, 4.- Potion // Stores a number which references the type of item entered
    char description[MAXDESCRIPTION]; // Stores a 15 character description of item entered
    float power; // Stores power of item entered
    int modifier; // Stores how the item modifes the player
};

// Defines needed functions of an iventory management with following API:
struct inventory *inventory_create();
int inventory_add(struct inventory*, struct inventory_item*);
struct inventory_item *inventory_lookup(struct inventory *, int);
int inventory_delete(struct inventory *, int);
struct inventory_item *inventory_first(struct inventory *);
struct inventory_item *inventory_next(struct inventory*);
int inventory_destroy(struct inventory*);

#endif
