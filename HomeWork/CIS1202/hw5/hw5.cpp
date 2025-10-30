// hw5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//February 27, 2025

#include <iostream>
#include <iomanip> 
using namespace std;

// Function prototypes
int getMenuItem();
void enterRents(float* rents, int counter);
void displayRents(float* rents, int counter);
float sumRents(float* rents, int counter);
void displayMemoryLocations(float* rents, int counter);
void selectionSort(float* rents, int counter);


//Main function
int main(){
    const int counter = 7; // Number of rent amounts
    int choice; // User menu selection
    float rents[counter]; // Array to store rent amounts

    do {
        choice = getMenuItem();

        if (choice == 1) {
            enterRents(rents, counter);
        }
        else if (choice == 2) {
            displayRents(rents, counter);
        }
        else if (choice == 3) {
            selectionSort(rents, counter);
        }
        else if (choice == 4) {
            sumRents(rents, counter);
        }
        else if (choice == 5) {
            displayMemoryLocations(rents, counter);
        }
        else if (choice == 6) {
            return 0; // Exit program
        }
        else {
            cout << "Invalid selection. Please enter a number 1-6: ";
            cin >> choice;
        }
    } while (choice != 6);

    return 0;
    


}


// Function to display menu and get user selection
int getMenuItem() {
    int num; //Declare an integer variable to store user input
    cout << "1. Enter rent amounts" << endl;
    cout << "2. Display rents" << endl;
    cout << "3. Sort rent amounts, low to high" << endl;
    cout << "4. Calculate the total rents" << endl;
    cout << "5. Display memory locations" << endl;
    cout << "6. Exit" << endl << endl;
    cout << "Enter selection: " << endl;

    cin >> num;
    return num;

}

// Function to input rent amounts
void enterRents(float* rents, int counter) {
    for (int i = 0;i < counter;i++) {
        cout << "Enter rent amount " << i + 1 << ": ";
        cin >> *(rents + i);
    }
}

// Function to display rent amounts
void displayRents(float* rents, int counter) {
    cout << "Rents:" << endl;
    for (int i = 0;i < counter;i++) {
        cout << fixed << setprecision(2) << *rents << endl;
        rents++;
    }
}

//Function to get the total rent amounts
float sumRents(float* rents, int counter) {
    float sum = 0;
    for (int i = 0;i < counter;i++) {
        sum += *(rents + i);
    }
    cout << fixed << setprecision(2) << sum<<endl;
    return sum;
}

// Function to display memory locations of rent values
void displayMemoryLocations(float* rents, int counter) {
    for (int i = 0;i < counter;i++) {
        cout << (rents + i) << endl;
        rents++;
    }
}

// Function to sort rent amounts using selection sort
void selectionSort(float* rents, int counter) {
    for (int i = 0;i < counter - 1;i++) {
        float* minPtr = rents + i; // Pointer to the minimum element
        for (int j = i + 1;j < counter;j++) {
            if (*(rents + j) < *minPtr) {
                minPtr = rents + j;
            }
        }
        if (minPtr != (rents + i)) {
            float temp = *(rents + i);
            *(rents + i) = *minPtr;
            *minPtr = temp;
        }

    }
}