/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - main
Notes: Implementation file serving as the main driver for the program
************************************************************************ */
#include "main.h"

int main (int argc,char** argv) {
    cout << "******Beginning Coding 05 - Hash Tables******"
    /*Handles the initial parameters passed in*/
    if (argc != 2) { //Checks for additional arguments that are not intended
        cout <<  "You have specified too many or too few arguments. Please try again.";
        return 3;
    }
    //Obtains the char array from argv, and opens the file
    string userInput(argv[1]);
    ifstream filename;
    //Checks for the file, and exits if no file exists
    filename.open(userInput.c_str());
    if (!filename) {
        cout << "There is no file named : " << userInput << ". Please check for the file, and try again." << endl;
    }
    Hashing table;
    cout << boolalpha;
    cout << "table.isEmpty - ";
    cout << table.isEmpty();
    cout << endl;
    cout << "******Ending Coding 05 - Hash Tables******" << endl;
    return 0;
}