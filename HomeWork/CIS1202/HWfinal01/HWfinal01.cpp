#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Basic structure to hold each calorie entry
struct CalorieEntry {
    string date;
    string foodCategory;
    int calories;
    string mealType;

    void display() {
        cout << date << " | " << foodCategory << " | " << calories << " | " << mealType << endl;
    }
};

// Show the menu options
void displayMenu() {
    cout << "\n=== Calorie Tracker Menu ===\n";
    cout << "1. Add Entry\n";
    cout << "2. Show All Entries\n";
    cout << "3. Show Total Calories\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Save a new entry to the text file
void saveEntryToFile(const CalorieEntry& entry) {
    ofstream file("calories.dat", ios::app); // using .dat, but still text format
    if (file.is_open()) {
        file << entry.date << "," << entry.foodCategory << ","
            << entry.calories << "," << entry.mealType << endl;
        file.close();
    }
    else {
        cout << "Could not open file to save data.\n";
    }
}

// Load all entries from the file into a vector
vector<CalorieEntry> loadEntriesFromFile() {
    vector<CalorieEntry> entries;
    ifstream file("calories.dat");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            CalorieEntry entry;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

            entry.date = line.substr(0, pos1);
            entry.foodCategory = line.substr(pos1 + 1, pos2 - pos1 - 1);
            entry.calories = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            entry.mealType = line.substr(pos3 + 1);

            entries.push_back(entry);
        }
        file.close();
    }
    return entries;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == 1) {
            CalorieEntry newEntry;

            cout << "Enter date (MM-DD-YYYY): ";
            getline(cin, newEntry.date);

            cout << "Enter food category: ";
            getline(cin, newEntry.foodCategory);

            cout << "Enter calories: ";
            cin >> newEntry.calories;
            while (newEntry.calories < 0) {
                cout << "Calories must be non-negative. Try again: ";
                cin >> newEntry.calories;
            }
            cin.ignore();

            cout << "Enter meal type (breakfast/lunch/dinner/snack): ";
            getline(cin, newEntry.mealType);

            saveEntryToFile(newEntry);
            cout << "Entry added successfully.\n";

        }
        else if (choice == 2) {
            vector<CalorieEntry> entries = loadEntriesFromFile();
            cout << "\nDate       | Category      | Calories | Meal\n";
            cout << "-----------------------------------------------\n";
            for (const auto& entry : entries) {
                entry.display();
            }

        }
        else if (choice == 3) {
            vector<CalorieEntry> entries = loadEntriesFromFile();
            int totalCalories = 0;
            for (const auto& entry : entries) {
                totalCalories += entry.calories;
            }
            cout << "Total Calories Consumed: " << totalCalories << endl;

        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
