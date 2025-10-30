// hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//February 24, 2025
//Updated Mar. 5, 2025

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Function prototypes
bool valid(char vin[17]); // Checks if the VIN is valid according to given rules
void origin(char vin[17], char ogn[]); // Determines the origin of the vehicle
int year(char vin[17]); // Determines the year of manufacture


int main(){
    char VIN[] = "1F3565ABCDEFGHIJKLMNOP";
    char ogn[20];

    cout << "Testing the VIN " <<VIN<< endl;

    if (valid(VIN)) {
        cout << "VIN is valid" << endl;
        origin(VIN, ogn);

        cout << "Origin: " << ogn << endl;
        cout << "Year: " << year(VIN) << endl;

    }
    else {
        cout << "VIN is not valid" << endl;
    }
    
    return 0;
}

// Function to check if the VIN is valid
bool valid(char vin[17]) {

    // must be 17 long
    if (strlen(vin) != 17) {
        return false;
    }

    for (int i = 0;i < 17;i++) {
        // skip all digital
        if (isdigit(vin[i])) {
            continue;
        }

        // if its not abc
        if (!isalpha(vin[i])) {
            return false;
        }

        // can not be lower
        if (!isupper(vin[i])) {
            return false;
        }

        // from here, all vin[i] must be a upper case letter!!!  
        if (vin[i] == 'I' || vin[i] == 'O' || vin[i] == 'Q' || vin[i] == 'Z' || vin[i] == 'U') {
            return false;
        }

    }

    return true;

}

// Function to determines the origin of the vehicle
void origin(char vin[17], char ogn[]) {


    if (vin[0] >= 'A' && vin[0] <= 'H') {
        strcpy_s(ogn, 20, "Africa");
    }

    else if (vin[0] >= 'J' && vin[0] <= 'R') {
        strcpy_s(ogn, 20, "Asia");
    }

    else if (vin[0] >= 'S' && vin[0] <= 'Y') {

        strcpy_s(ogn, 20, "Europe");
    }

    else if (vin[0] >= '1' && vin[0] <= '5') {

        strcpy_s(ogn, 20, "North America");
    }

    else if (vin[0] >= '6' && vin[0] <= '7') {

        strcpy_s(ogn, 20, "Oceania");
    }

    else if (vin[0] >= '8' && vin[0] <= '0') {

        strcpy_s(ogn, 20, "South America");
    }
    else {

        strcpy_s(ogn, 20, "unknown");
    }
}

// Function to determines the year of manufacture
int year(char vin[17]) {
    int year = 0;
    if (vin[9] == 'P') {
        year = 1993;
    }
    // calculate base ASCII
    if (vin[9] >= 'R' && vin[9] <= 'T') {
        //cout << "here1" << endl;
        //cout << vin[9] << endl;
        //cout << int(vin[9]) << endl;
        year = int(vin[9]) - 82 + 1994;
    }
    if (vin[9] >= 'V' && vin[9] <= 'Y') {
        year = int(vin[9]) - 86 + 1997;
    }

    if (vin[9] >= '1' && vin[9] <= '9') {
        year = int(vin[9]) - 49 + 2001;
    }

    if (vin[9] >= 'A' && vin[9] <= 'H') {
        year = int(vin[9]) - 65 + 2010;
    }

    if (vin[9] >= 'J' && vin[9] <= 'M') {
        year = int(vin[9]) - 74 + 2019;
    }

    return year;
}


