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
    infile.open("Risk_Factor.txt");

    // Display instructions
    cout << "\nHere are the Risk Factors listed and their keywords. Please follow the instructions below:\n" << endl;
    cout << "Weak Passwords = Weak" << endl;
    cout << "Unsecure Wi-Fi = Unsecure" << endl;
    cout << "Phishing Scams = Phishing" << endl;
    cout << "Social Media Oversharing = Oversharing" << endl;
    cout << "Data Breaches = Breaches" << endl;
    cout << "Mail Theft = Mail Theft" << endl;
    cout << "Disposing of Documents Incorrectly = Disposing" << endl;
    cout << "Lost or Stolen Personal Devices = Devices" << endl;
    cout << "Stolen Wallet or ID = Wallet" << endl;
    cout << "Using Unsafe Websites = Websites" << endl;
    cout << "Insufficient Credit Monitoring = Insufficient" << endl;
    cout << "Providing Information to Unknown Callers = Providing" << endl;

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
