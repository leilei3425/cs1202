// hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Lei Zhang
// CIS 1202 803
//March 10,2025

#include <iostream>
#include <string>
using namespace std;

// Structure to store win/loss records
struct WinLoss {
    int wins;
    int losses;
};

// Structure to store team records
struct Team {
    string name;
    WinLoss total;
    WinLoss home;
    WinLoss away;
   
};

// Function prototypes
int menu();
WinLoss getWinLoss(string);
void displayWinLoss(WinLoss);
Team getTeam();
void displayTeam(Team);
void findTeam(Team[], int);


int main(){
    
    const int SIZE = 10;
    Team teams [SIZE];


    int counter = 0;
    int choice; // User menu selection

    do {
        choice = menu();

        switch (choice) {
        case 1:           
            teams[counter] = getTeam();
            counter++;
            break;

        case 2:
            for (int i = 0; i < counter; i++) {
                displayTeam(teams[i]);
            }
            break;

        case 3:
            findTeam(teams, counter);
            break;

        case 4:
            return 0; // Exit program

        default:
            cout << "Invalid selection. Please enter a number 1-4: \n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            break;
        }
    } while (choice != 4);

    return 0;
}

int menu() {
    char num; //Declare an variable to store user input
    cout << "1. Enter a new team" << endl;
    cout << "2. Display all teams" << endl;
    cout << "3. Display a particular team" << endl;
    cout << "4. Exit the program" << endl;

    cin >> num;

    if (num >= '1' && num <= '4') {
        return num - '0';  // Convert char to int
    }
    // invalid input
    return -1;
}

// Function to get the win/loss record from user input
WinLoss getWinLoss(string str) {
    WinLoss wl;
    cout << "Enter the " << str << " wins: ";
    cin >> wl.wins;
    cout << "Enter the " << str << " losses: ";
    cin >> wl.losses;
    return wl;
}

// Function to display the win-lose record
void displayWinLoss(WinLoss wl) {
    cout << wl.wins << "-" << wl.losses << endl;//
}

// Function to get team details from user input
Team getTeam() {
    Team new_team;

    cout << "Team name? ";
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // input name with space
    getline(cin, new_team.name);

    // Get win/loss records for home and away games
    new_team.home = getWinLoss("home");
    new_team.away = getWinLoss("away");
    // Calculate total wins and losses by summing home and away records
    new_team.total.wins= new_team.away.wins + new_team.home.wins;
    new_team.total.losses = new_team.away.losses + new_team.home.losses;
    
    return new_team;
}

// Function to display the details of a team
void displayTeam(Team team) {
    cout << team.name << endl;
    
    cout << "Total record "; 
    displayWinLoss(team.total);

    cout << "Home record ";
    displayWinLoss(team.home);

    cout << "Away record ";
    displayWinLoss(team.away);

}

// Function to find a special team
void findTeam(Team teams[] , int counter) {
    string name;
    cout << "Team name? ";

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // input name with space
    getline(cin, name);

    bool found = false;
    for (int i = 0;i < counter;i++) {
        if (teams[i].name == name) {
            //print team
            displayTeam(teams[i]);
            found = true;
        }
    }

    // check if no team found
    if (!found) {
        cout << "Team not found." << endl;
    }
}