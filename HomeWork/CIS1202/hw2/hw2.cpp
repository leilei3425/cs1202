// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lei Zhang
// CIS 1202 803
// Feb 19, 2025
// Updated Mar. 5, 2025

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Function Prototypes
void loadArrays(string console[], float current_price[], int& counter);
void showArrays(string console[], float current_price[], int counter);
void lookUpPrice(string console[], float current_price[], int counter);
void sortPrices(string console[], float current_price[], int counter);
void highestPrice(string console[], float current_price[], int counter);
int showMenu();




// Main function to execute the program
int main() {
    int const SIZE = 20;  // Maximum number of consoles
    string console[SIZE];  // Array to store console names
    float current_price[SIZE];  // Array to store console prices
    int counter = 0;  // Counter to track the number of consoles

    loadArrays(console, current_price, counter);  // Load consoles and prices from file

    // If no records are found, exit the program
    if (counter == 0) {
        cout << "No records found. Exiting program." << endl;
        return 0;
    }

    int num;
    do {
        num = showMenu();  // Display menu and get user's choice

        // Perform the appropriate action based on the user's choice
        if (num == 1) {
            showArrays(console, current_price, counter);  // Display all consoles and prices
        }
        else if (num == 2) {
            lookUpPrice(console, current_price, counter);  // Look up the price of a particular console
        }
        else if (num == 3) {
            sortPrices(console, current_price, counter);  // Sort the consoles by price in descending order
        }
        else if (num == 4) {
            highestPrice(console, current_price, counter);  // Display the console with the highest price
        }
        else if (num == 5) {
            cout << "Exiting the program." << endl;  // Exit the program
            return 0;
        }
        else {
            cout << "Invalid choice! Please select again." << endl;  // Handle invalid input
        }
    } while (num != 5);  // Keep showing the menu until the user chooses to exit

    return 0;
}




// Function to load console names and prices from a file
void loadArrays(string console[], float current_price[], int& counter) {
    ifstream my_file("prices.txt");
    // Check if file exists and is opened successfully
    if (!my_file.is_open()) {
        cout << "Failed to open the file" << endl;
        exit(0);  // Exit the program if the file cannot be opened
    }

    int index = 0;  // Index to track lines read from file
    string line;
    // Read each line from the file
    while (getline(my_file, line, '\n')) {
        // If the line index is even, it's a console name, otherwise it's a price
        if (index % 2 == 0) {
            console[counter] = line;
        }
        else {
            current_price[counter] = stof(line);  // Convert price to float
        }
        index++;
        counter = int(index / 2);  // Increment counter every two lines (console, price)
    }

    my_file.close();  // Close the file after reading
}


// Function to display all console names and their corresponding prices
void showArrays(string console[], float current_price[], int counter) {
    int space = 30;  // Space to align console names and prices

    // Display headers for the table
    cout << "Console" << setw(60) << "Current Price" << setw(20) << endl;

    // Loop to display all consoles and their prices
    for (int row = 0; row < counter; row++) {
        // Align output and display console name and price in a table format
        cout << left << setw(space) << console[row]
            << right << setw(space) << fixed << setprecision(2) << current_price[row] << endl;
    }
    cout << endl << endl;
}


// Function to look up the price of a particular console by name
void lookUpPrice(string console[], float current_price[], int counter) {
    string name;

    cout << "Console name? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear any leftover input from the buffer

    getline(cin, name);  // Get console name from the user

    // Linear search through the console array to find the console
    for (int i = 0; i < counter; i++) {
        if (console[i] == name) {
            cout << "The current price of " << console[i] << " is $" << current_price[i] << "." << endl;
            return;  // Exit the function once the price is found
        }
    }
    cout << "Console not found." << endl;  // Display message if console is not found
    cout << endl << endl;
}


// Function to sort consoles and prices in descending order based on price
void sortPrices(string console[], float current_price[], int counter) {
    // Insertion sort to sort prices in descending order
    for (int i = 1; i < counter; i++) {
        float key_price = current_price[i];
        string key_console = console[i];
        int j = i - 1;

        // Shift elements to the right until the correct position is found for the current item
        while (j >= 0 && current_price[j] < key_price) {
            current_price[j + 1] = current_price[j];
            console[j + 1] = console[j];
            j = j - 1;
        }
        current_price[j + 1] = key_price;
        console[j + 1] = key_console;
    }
}


// Function to display the console with the highest price
void highestPrice(string console[], float current_price[], int counter) {
    string product_highest;
    float max_value = current_price[0];
    int index_max = 0;

    // Loop to find the console with the highest price
    for (int i = 0; i < counter; i++) {
        if (current_price[i] > max_value) {
            max_value = current_price[i];
            index_max = i;  // Update the index when a larger price is found
        }
    }

    product_highest = console[index_max];  // Get the console name with the highest price
    cout << "The " << product_highest << " has the highest price of $" << max_value << "." << endl;
    cout << endl;
}


// Function to display the main menu and return the user's choice
int showMenu() {
    int num;

    // Display the menu options to the user
    cout << "Console Pricing - Main Menu" << endl;
    cout << "1. Display all console prices" << endl;
    cout << "2. Look up the price of a particular console" << endl;
    cout << "3. Sort prices in descending order" << endl;
    cout << "4. Display the console with the highest price" << endl;
    cout << "5. Exit the program" << endl << endl;

    cin >> num;  // Get the user's choice
    return num;
}

