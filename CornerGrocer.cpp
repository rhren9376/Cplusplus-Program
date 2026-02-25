/*******************************************************
Name: Richard Hren
Course: CS 210 - Programming Languages
Instructor: Kyle Richbourg
Assignment: Project Three Corner Grocer Item Tracker
Date: February 20, 2026

Description:
This program analyzes a daily grocery purchase record
for the Corner Grocer. The program reads an input text
file containing items purchased throughout the day and
counts how many times each item appears. The data is
stored using a map container and written to a backup
file named "frequency.dat".

The user interacts with the program through a menu
system that allows them to:
1. Search for a specific item and display its frequency
2. Display all items and their purchase counts
3. Display a histogram of item frequencies
4. Exit the program

The program demonstrates object oriented design,
file input/output, input validation, and modular
program structure using functions and a class.
********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <cctype>

using namespace std;

class ItemTracker {
private:
    // Map container storing item name (key) and frequency count (value)
    map<string, int> itemCounts;

    // Converts a string to lowercase (used for case-insensitive search)
    static string ToLower(string s) {
        for (char& ch : s) {
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        }
        return s;
    }

    // Removes leading and trailing whitespace from a string
    static string Trim(const string& s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        if (start == string::npos) return "";
        size_t end = s.find_last_not_of(" \t\r\n");
        return s.substr(start, end - start + 1);
    }

public:

    // Reads input file and counts frequency of each item
    bool LoadFromFile(const string& inputFileName) {
        ifstream inFS(inputFileName);

        // Validate file opening
        if (!inFS.is_open()) {
            cout << "Error: Could not open input file: "
                << inputFileName << endl;
            return false;
        }

        string item;

        // Read each line and count occurrences
        while (getline(inFS, item)) {
            item = Trim(item);
            if (!item.empty()) {
                itemCounts[item]++;
            }
        }

        inFS.close();
        return true;
    }

    // Creates backup file containing all items and their frequencies
    bool WriteFrequencyFile(const string& outputFileName) const {
        ofstream outFS(outputFileName);

        if (!outFS.is_open()) {
            cout << "Error: Could not create output file: "
                << outputFileName << endl;
            return false;
        }

        for (const auto& pair : itemCounts) {
            outFS << pair.first << " "
                << pair.second << endl;
        }

        outFS.close();
        return true;
    }

    // Returns frequency of a specific item (case-insensitive)
    int GetItemFrequency(const string& userItem) const {
        string target = ToLower(Trim(userItem));

        for (const auto& pair : itemCounts) {
            if (ToLower(pair.first) == target) {
                return pair.second;
            }
        }
        return 0; // Item not found
    }

    // Displays all items with purchase counts
    void PrintAllFrequencies() const {
        for (const auto& pair : itemCounts) {
            cout << pair.first << " "
                << pair.second << endl;
        }
    }

    // Displays histogram using asterisks to represent frequency
    void PrintHistogram() const {
        for (const auto& pair : itemCounts) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Displays menu and validates user input
int GetMenuChoice() {
    int choice;

    while (true) {
        cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1 - Look up an item\n";
        cout << "2 - Print all items with quantities\n";
        cout << "3 - Print histogram\n";
        cout << "4 - Exit\n";
        cout << "Select an option (1-4): ";

        // Validate numeric input
        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid input. Please enter a number from 1 to 4.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {

    // Input and output file names
    const string inputFile =
        "CS210_Project_Three_Input_File.txt";
    const string outputFile = "frequency.dat";

    ItemTracker tracker;

    // Load item data from file
    if (!tracker.LoadFromFile(inputFile)) {
        return 1;
    }

    // Automatically create backup file at program start
    tracker.WriteFrequencyFile(outputFile);

    int choice = 0;

    // Main menu loop
    while (choice != 4) {
        choice = GetMenuChoice();

        if (choice == 1) {
            string item;
            cout << "Enter the item you want to look up: ";
            getline(cin, item);

            int freq = tracker.GetItemFrequency(item);

            cout << "Frequency of \""
                << item << "\": "
                << freq << endl;
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
    }

    cout << "Goodbye.\n";
    return 0;
}