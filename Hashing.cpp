/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - Hashing
Notes:   Implementation file for the hash table class
************************************************************************ */
#include "Hashing.h"

Hashing::Hashing() {
    for (int i =0; i < 19; i++) {
        hashtable[i] = nullptr;
    }
};


bool Hashing::isEmpty() { //checks to see if the hash table is empty
    for (int i =0 ; i <=20; i++) {
        if (hashtable[i] != nullptr){
            return false;
        }
    }
    return true;
}

bool Hashing::add(int value, string string) { //adds entries to the able
    int index = -1;
    Node* temp = new Node;
    Node* nullchecker = new Node;
    Node* previous = new Node;
    temp->id = value;
    temp->data = string;
    temp->forward = nullptr;
    index =  value % 19;
    nullchecker = hashtable[index];
    if (nullchecker == nullptr) {
        hashtable[index] = temp;
        return true;
    }
    while (nullchecker!= nullptr) {
        previous = nullchecker;
        nullchecker = nullchecker->forward;
    }if (nullchecker == nullptr){
        nullchecker = temp;
        previous->forward = nullchecker;
        nullchecker->forward = nullptr;
        return true;
    }
    return false;
}

/*
 * Debug methods - used for troubleshooting program. COmmented out for submission
 */
/*
void Hashing::print() {
    for (int i =0; i < 19; i++) {
        cout << hashtable[i] << endl;
    }
};
*/