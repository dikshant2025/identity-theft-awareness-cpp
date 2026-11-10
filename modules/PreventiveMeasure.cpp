#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream infile;
    string line;
    string keyword;
    char choice = 'y';


    // Check if the file is successfully opened
    infile.open("PreventiveMeasure.txt");

    // Display instructions
    cout << "\nHere are the Preventive Measure listed and their keywords. Please follow the instructions below:\n" << endl;
    cout << "Enable Two-Factor Authentication = Factor" << endl;
    cout << "Shared Sensitive Documents = Shared" << endl;
    cout << "Monitor Financial Statements = Monitor" << endl;
    cout << "Use Secure Networks = Networks" << endl;
    cout << "Be Cautious with Apps = Cautious" << endl;
    cout << "Report Suspicious Activity = Report" << endl;

    while (choice == 'y') {
        // Ask for a keyword
        cout << "\nEnter a keyword to filter lines or leave blank to access all at once: ";
        cin.ignore(); // Ignore leftover newline
        getline(cin, keyword);

        // Reset file position and flags
        infile.clear();
        infile.seekg(0);
        bool found = false;

        // Search through the file
        while (getline(infile, line)) {
            if (keyword.empty() || line.find(keyword) != string::npos) {
                cout << "\n" << line << "\n";
                found = true;
            }
        }

        // Notify if no lines matched
        if (!found) {
            cout << "\nNo lines matched the keyword \"" << keyword << "\".\n";
        }

        // Ask if the user wants to continue
        cout << "\nDo you want to look up another point or exit? (y/n): ";
        cin >> choice;
    }

    // Close the file
    infile.close();
    cout << "\nProgram terminated. Thank You!!\n" << endl;
    return 0;
}