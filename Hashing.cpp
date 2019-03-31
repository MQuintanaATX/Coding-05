/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - Hashing
Notes:   Implementation file for the hash table class
************************************************************************ */
#include "Hashing.h"

bool Hashing::isEmpty() { //checks to see if the hash table is empty
    for (int i; i <=20; i++) {
        if (hashtable[i] != nullptr){
            return false;
        }
    }
    return true;
}
