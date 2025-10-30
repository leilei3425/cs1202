// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lei Zhang
// CIS 1202
// Feb. 11, 2025
// updated Mar. 5, 2025

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function prototypes
void loadArrays(string product[], int quantity[], float cost[], int& counter);
void calculateValues(int quantity[], float cost[], float value[], int counter);
void displayTable(string product[], int quantity[], float cost[], float value[], int counter);
vector<string> split_string(const string &);


int main()
{
    int const SIZE = 20;
    int counter = 0;

    string product[SIZE];
    int quantity[SIZE];
    float cost[SIZE];
    float value[SIZE];

    loadArrays(product, quantity, cost, counter);

    calculateValues(quantity, cost, value, counter);

    displayTable(product, quantity, cost, value, counter);

}


// Function to split string based on space
// reference: https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
vector<string> split_string(const string& str) {
    istringstream iss(str);
    vector<string> tokens;
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}


// Function to load product data from a file into arrays
void loadArrays(string product[], int quantity[], float cost[], int& counter) {
    ifstream my_file("inventory.txt");
    if (!my_file.is_open()) {
        cout << "Failed to open the file" << endl;
        return;
    }

    string line;
    while (getline(my_file, line, '\n')) {
        vector<string> token = split_string(line);

        if (token.size() == 3) { // Ensure correct format
            product[counter] = token[0];
            quantity[counter] = stoi(token[1]);
            cost[counter] = stof(token[2]);
            counter++;
        }
    }
    my_file.close();
}

// Function to calculate the total value of each product
void calculateValues(int quantity[], float cost[], float value[], int counter) {
    for (int i = 0; i < counter; i++) {
        value[i] = quantity[i] * cost[i];
    }
}

// Function to display the inventory table and summary
void displayTable(string product[], int quantity[], float cost[], float value[], int counter) {
    int space = 20;
    cout << left << setw(space) << "Product Code" << right << setw(space) << "Quantity on Hand"
        << right << setw(space) << "Cost Each" << right << setw(space) << "Total Value" << endl;

    for (int row = 0; row < counter; row++) {
        cout << left << setw(space) << product[row] << right << setw(space) << quantity[row]
            << right << setw(space) << fixed << setprecision(2) << cost[row]
            << right << setw(space);

        if (value[row] > 9000) {
            cout << fixed << setprecision(2) << value[row] << " !!!";
        }
        else {
            cout << fixed << setprecision(2) << value[row];
        }
        cout << endl;
    }

    // Find the product with the highest inventory value
    string product_highest;
    float max_value = value[0];
    int index_max = 0;
    for (int i = 1; i < counter; i++) {
        if (value[i] > max_value) {
            max_value = value[i];
            index_max = i;
        }
    }
    product_highest = product[index_max];
    cout << "The product with the highest inventory value is " << product_highest << "." << endl;

    // Calculate the average cost of inventory items
    float total_value = 0, total_qt = 0;
    for (int i = 0; i < counter; i++) {
        total_value += value[i];
        total_qt += quantity[i];
    }
    float cost_avg = total_value / total_qt;
    cout << fixed << setprecision(2);
    cout << "The average cost of an inventory item is $" << cost_avg << "." << endl;
}

