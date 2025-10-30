// hwfinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
//CIS 1202 803
//May 06 2025


#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include "CalorieTracker.h"
using namespace std;


// Function prototypes
void displayMenu();
bool isValidInt(int input);
void init_file();
void loadEntriesFromFile(vector<DetailedCalorieTracker>& entries);
void saveEntriesToFile(const vector<DetailedCalorieTracker>& entries);
Date parseDate(const string& dateStr);
FoodCategory parseFoodCategory(const string& foodStr);
MealType parseMealType(const string& mealStr);


int main()
{
    vector<DetailedCalorieTracker> entries;
    // initialize entries, create empty file
    init_file();
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after reading number

        if (choice == 1) {
            string dateStr, foodStr, mealTypeStr;
            int cal;

            cout << "Enter date (MM-DD-YYYY): ";
            getline(cin, dateStr);

            cout << "Enter food category (Fruits/Vegetables/Grains/Protein/Dairy/Sweets/Beverages): ";
            getline(cin, foodStr);

            cout << "Enter calories: ";
            cin >> cal;
            while (!isValidInt(cal)) {
                cout << "Calories must be positive. Re-enter: ";
                cin >> cal;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after reading number

            cout << "Enter meal type (breakfast/lunch/dinner/snack): ";
            getline(cin, mealTypeStr);

            // Parse inputs to create proper objects
            Date date = parseDate(dateStr);
            FoodCategory foodCategory = parseFoodCategory(foodStr);
            MealType mealType = parseMealType(mealTypeStr);

            loadEntriesFromFile(entries);
            DetailedCalorieTracker newEntry(date, foodCategory, cal, mealType);
            entries.push_back(newEntry);
            saveEntriesToFile(entries);
        }
        else if (choice == 2) {
            loadEntriesFromFile(entries);
            cout << setw(12) << "Date"
                << setw(15) << "Food Category"
                << setw(10) << "Calories"
                << setw(10) << "Meal" << "\n";
            cout << "---------------------------------------------------\n";
            
            for (int i = 0;i < entries.size();i++) {
                entries[i].displayEntry();
            }
            
        }
        else if (choice == 3) {
            loadEntriesFromFile(entries);
            int total = 0;
            for (int i = 0; i < entries.size(); i++) {
                total += entries[i].getCalories();
            }
            cout << "Total Calories: " << total << endl;
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    cout << "Exiting Calorie Tracker. Goodbye!\n";
    return 0;
}

//show menu
void displayMenu() {
    cout << "\n==== Calorie Tracker ====\n";
    cout << "1. Add Entry\n";
    cout << "2. Show All Entries\n";
    cout << "3. Show Total Calories\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

//check input
bool isValidInt(int input) {
    return input >= 0;
}

//initial Calories.dat
void init_file() {
    ofstream outFile("calories.dat", ios::binary | ios::trunc);
    if (outFile) {
        cout << "Calorie data file initialized successfully.\n";
        outFile.close();
    }
    else {
        cout << "Failed to initialize calorie data file.\n";
    }
}

void loadEntriesFromFile(vector<DetailedCalorieTracker>& entries) {
    ifstream inFile("calories.dat", ios::binary);
    DetailedCalorieTracker entry;
    entries.clear();

    if (inFile) {
        while (inFile.read(reinterpret_cast<char*>(&entry), sizeof(DetailedCalorieTracker))) {
            entries.push_back(entry);
        }
        inFile.close();
        cout << "All entries loaded successfully.\n";
    }
    else {
        cout << "Error loading file to entries.\n";
    }
}

void saveEntriesToFile(const vector<DetailedCalorieTracker>& entries) {
    ofstream outFile("calories.dat", ios::binary | ios::trunc);
    if (outFile) {
        for (const auto& entry : entries) {
            outFile.write(reinterpret_cast<const char*>(&entry), sizeof(DetailedCalorieTracker));
        }
        outFile.close();
        cout << "All entries saved successfully.\n";
    }
    else {
        cout << "Error saving entries to file.\n";
    }
}

// Parse date string in format MM-DD-YYYY to Date object
Date parseDate(const string& dateStr) {
    int month = 0, day = 0, year = 0;
    sscanf_s(dateStr.c_str(), "%d-%d-%d", &month, &day, &year);
    return Date(year, month, day);
}

// Parse food category string to FoodCategory enum
FoodCategory parseFoodCategory(const string& foodStr) {
    string foodLower = foodStr;
    for (auto& c : foodLower) c = tolower(c);

    if (foodLower.find("fruit") != string::npos) return Fruits;
    if (foodLower.find("vegetable") != string::npos) return Vegetables;
    if (foodLower.find("grain") != string::npos) return Grains;
    if (foodLower.find("protein") != string::npos ||
        foodLower.find("meat") != string::npos) return Protein;
    if (foodLower.find("dairy") != string::npos ||
        foodLower.find("milk") != string::npos) return Dairy;
    if (foodLower.find("sweet") != string::npos ||
        foodLower.find("dessert") != string::npos ||
        foodLower.find("candy") != string::npos) return Sweets;
    if (foodLower.find("beverage") != string::npos ||
        foodLower.find("drink") != string::npos) return Beverages;

    // Default
    return Fruits;
}

// Parse meal type string to MealType enum
MealType parseMealType(const string& mealStr) {
    string mealLower = mealStr;
    for (auto& c : mealLower) c = tolower(c);

    if (mealLower.find("breakfast") != string::npos) return breakfast;
    if (mealLower.find("lunch") != string::npos) return lunch;
    if (mealLower.find("dinner") != string::npos) return dinner;

    // Default to snack for anything else
    return snack;
}
