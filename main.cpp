/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 05 - Hash Tables
Purpose: Implementation - main
Notes: Implementation file serving as the main driver for the program
************************************************************************ */
#include "main.h"

int main (int argc,char** argv) {
    cout << "******Beginning Coding 05 - Hash Tables******" << endl;
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
    Hashing table; //The hash table
    int lineCount = 0; //holds the tally of lines in the file
    cout << boolalpha;
    cout << "table.isEmpty - ";
    cout << table.isEmpty();
    cout << endl << "> Number of table entries | ";
    try {
        lineCount = countLines(filename);
        cout << lineCount;
    }
    catch (...){
        cout << "An error occured. Unable to determmine amount of lines..";
        return 0;
    }
    filename.clear();
    filename.seekg(0);

    cout << endl << endl << "> Now loading data into hash table" << endl;
    int counter;
    while (!filename.eof()) {
        string fileString, container; // Container is used to parse data
        int id;
        string data;
        getline(filename, fileString);
        if (fileString == "\0"){ // checks for a blank line, and skips parsing if that's the csae
            continue;
        }
        for (int i = 0; i < fileString.size(); i++) {
            if (fileString[i] != ',') {
                container += fileString[i];
                continue;
            } else if (fileString[i] == ','){
                id = stoi(container);
                container = "";
            }
        }
        cout << id << ", " << container << " | table.add() = ";
        cout << table.add(id, container);
        cout << " | table.isEmpty() = ";
        cout << table.isEmpty() << endl;
    }
    table.printValues();
    cout << "# of Entries: " << table.getCountEntries();

    cout << endl << "> Finding values" << endl;
    //Searching for values in the 1st, 2nd, and 3rd parts of the chain
    cout << "Contains 131: ";
    cout << table.contains(131) << endl;
    cout << "Contains 238: ";
    cout << table.contains(238) << endl;
    cout << "Contains 195: ";
    cout << table.contains(195) << endl;
    cout << "Contains 1: ";
    cout << table.contains(1) << endl;
    cout << "Contains 922: ";
    cout << table.contains(922) << endl;

    cout << endl << "> Retrieving values" << endl;
    //Searching for values in the 1st, 2nd, and 3rd parts of the chain
    cout << "Contains 131: ";
    cout << table.getData(131) << endl;
    cout << "Contains 238: ";
    cout << table.getData(238) << endl;
    cout << "Contains 195: ";
    cout << table.getData(195) << endl;
    cout << "Contains 1: ";
    cout << table.getData(1) << endl;
    cout << "Contains 922: ";
    cout << table.getData(922) << endl;


    cout << endl << "******Ending Coding 05 - Hash Tables******" << endl;
    return 0;
}