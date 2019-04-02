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

bool Hashing::add(int value, string data) { //adds entries to the able
    int index = -1;
    Node* temp = new Node;
    Node* nullchecker = new Node;
    Node* previous = new Node;
    temp->id = value;
    temp->data = data;
    temp->forward = nullptr;
    index =  value % 19;
    nullchecker = hashtable[index];
    if (nullchecker == nullptr) {
        hashtable[index] = temp;
        counter++;
        return true;
    }
    while (nullchecker!= nullptr) {
        previous = nullchecker;
        nullchecker = nullchecker->forward;
    }if (nullchecker == nullptr){
        nullchecker = temp;
        previous->forward = temp;
        temp->forward = nullptr;
        counter++;
        return true;
    }
    throw "false";
}

bool Hashing::contains(int value) {
    Node* temp = new Node;
    for (int i =0; i < 19; i++) {
        temp = hashtable[i];
        while (temp != nullptr){
            if (temp->id == value){
                return true;
            }
            temp = temp ->forward;
        }
    }
    return false;
}

string Hashing::getData(int value){
    Node* temp = new Node;
    for (int i =0; i < 19; i++) {
        temp = hashtable[i];
        while (temp != nullptr){
            if (temp->id == value){
                return temp->data;
            }
            temp = temp ->forward;
        }
    }
    return "NOT FOUND";
}

int Hashing::getCountEntries() {
    return counter;
}
/*
 * Debug methods - used for troubleshooting program. Commented out for submission
 */

void Hashing::printAddress(){
    for (int i =0; i < 19; i++) {
        cout << hashtable[i] << endl;
    }
};

void Hashing::printValues() {
    Node* temp = new Node;
    for (int i =0; i < 19; i++) {
        temp = hashtable[i];
        cout << hashtable[i] << endl;
        while (temp != nullptr){
            cout << temp->id << ", " << temp->data;
            cout << " -> ";
            temp = temp ->forward;
        }
        cout << endl;

    }
    cout << "Total: " << counter << endl;
}

