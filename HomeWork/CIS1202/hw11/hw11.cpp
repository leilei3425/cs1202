// hw11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lei Zhang
// CIS 1202 803 
// April 08 2025

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for products
const int NAME_SIZE = 40;
struct Product {
    long number;
    char name[NAME_SIZE];
    double price;
    int quantity;
};

// Function prototypes
int showMenu();
void createFile(); 
void displayFile(fstream&);
void displayRecord(fstream&, int);
void modifyRecord(fstream&);

int main() {
    createFile();  // create and overwrite the file at the start

    fstream file("inventory.dat", ios::in | ios::out | ios::binary);// both read and write
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice;
    do {
        choice = showMenu();

        switch (choice) {
        case 1:
            displayFile(file);
            break;
        case 2: {
            cout << "Enter record number to be displayed:" << endl;
            int num;
            cin >> num;
            displayRecord(file, num);
            break;
        }
        case 3:
            modifyRecord(file);
            break;
        case 4:
            return 0; // Exit program

        }
    } while (choice != 4);

    file.close();  // File close 
    return 0;
}

// Function to show menu
int showMenu() {
    char choice;
    // infinite loop untill the user give a valid choice
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display the entire inventory\n";
        cout << "2. Display a particular product\n";
        cout << "3. Modify a product\n";
        cout << "4. Exit the program\n";
        cout << "Enter your choice (1-4): ";

        cin >> choice;

        if (choice >= '1' && choice <= '4') {
            return choice - '0'; // Convert char digit to int
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

}

// Create inventory file (called only once)
void createFile() {
    fstream file("inventory.dat", ios::out | ios::binary);// only write

    for (int i = 0; i < 5; i++) {
        Product p;
        p.number = i;
        string temp = "Dog_" + to_string(i);
        strcpy_s(p.name, temp.c_str());
        p.price = i + 10;
        p.quantity = i + 5;

        file.write(reinterpret_cast<char*>(&p), sizeof(p));
    }

    file.close();
}

// Display all records
void displayFile(fstream& file) {
    Product p;
    file.clear();
    file.seekg(0, ios::beg);

    int i = 0;
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        cout << "\nRecord #" << i << "\n";
        cout << "Product Number: " << p.number << "\n";
        cout << "Name: " << p.name << "\n";
        cout << "Price: $" << p.price << "\n";
        cout << "Quantity: " << p.quantity << "\n";
        i++;
    }
    file.clear();
}

// Display a specific record
void displayRecord(fstream& file, int num) {
    Product p;
    file.clear(); // Reset the EOF/fail state
    file.seekg(0, ios::beg); // seeks to the first record

    int i = 0;
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (num == i) {
            cout << "\nRecord #" << i << "\n";
            cout << "Product Number: " << p.number << "\n";
            cout << "Name: " << p.name << "\n";
            cout << "Price: $" << p.price << "\n";
            cout << "Quantity: " << p.quantity << "\n";
            break;
        }
        i++;
    }
    file.clear(); // Reset the EOF/fail state
}

// Modify a record
void modifyRecord(fstream& file) {
    
    char tmp;
    int num;
    //check if input is valid
    while (true) {
        cout << "Enter record number to be modified:\n";
        cin >> tmp;
        if (isdigit(tmp)) {
            num = tmp - '0';
            break;
        }
        else {
            cout << "Invalid input, please input number!\n";
            continue;
        }
    }

    Product p;
    file.clear(); // Reset the EOF/fail state
    file.seekg(0, ios::beg); // seeks to the first record

    int i = 0;
    streampos pos; // use to locate write position
    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (num == i) {
            cout << "Enter the new data.\n";
            cout << "Product number: ";
            cin >> p.number;

            cout << "Product name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string name;
            getline(cin, name);
            strcpy_s(p.name, name.c_str());

            cout << "Price: ";
            cin >> p.price;

            cout << "Quantity: ";
            cin >> p.quantity;

            pos = file.tellg();
            file.seekp(pos - static_cast<streamoff>(sizeof(p)));
            file.write(reinterpret_cast<char*>(&p), sizeof(p));
            break;
        }
        i++;
    }
    file.clear();// Reset the EOF/fail state
}
