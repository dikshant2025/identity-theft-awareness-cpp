#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create an ifstream object to read the file
    ifstream inputFile("Resources.txt");

    // Check if the file is open and ready to be read
    if (inputFile.is_open()) {
        string line;
        cout << "--- File Contents ---" << endl;

        // Read each line from the file
        while (getline(inputFile, line)) {
            cout << line << endl; // Output the line to the console
        }

        inputFile.close(); // Close the file after reading
    } else {
        // If the file cannot be opened
        cout << "Error: Unable to open the file." << endl;
    }

    return 0;
}
