/*
Identity Theft Prevention: Interactive Guide
Group project (Group 4)
Sections: Introduction, Risk Factors, Preventive Measures, Quiz, Resources
Author: Dikshant Shrestha
Date: 11/24/2024
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()
using namespace std;

const int MAX_QUESTIONS = 30;       // Based on the maximum number of questions
const int LINES_PER_QUESTION = 7;  // Number of lines per question block (excluding blank line)
const int QUESTIONS_TO_DISPLAY = 5; // Number of questions to display in each run

// Function to handle the quiz logic
void runQuiz(const string& fileName) {
    ifstream quizFile(fileName);
    if (!quizFile.is_open()) {
        cout << "Error: Could not open the quiz file." << endl;
        return;
    }

    // Read entire file into an array of strings
    string lines[MAX_QUESTIONS * LINES_PER_QUESTION];
    int lineCount = 0;

    while (getline(quizFile, lines[lineCount]) && lineCount < MAX_QUESTIONS * LINES_PER_QUESTION) {
        if (!lines[lineCount].empty()) {
            lineCount++;
        }
    }
    quizFile.close();

    int totalQuestions = lineCount / LINES_PER_QUESTION;
    if (totalQuestions == 0) {
        cout << "No valid questions found in the file!" << endl;
        return;
    }

    srand(static_cast<unsigned>(time(nullptr))); // different questions each run
    bool usedQuestions[MAX_QUESTIONS] = {false}; // To track which questions have already been used
    int score = 0;

    for (int i = 0; i < QUESTIONS_TO_DISPLAY; i++) {
        int questionIndex;

        do {
            questionIndex = rand() % totalQuestions;
        } while (usedQuestions[questionIndex]);

        usedQuestions[questionIndex] = true;

        int baseIndex = questionIndex * LINES_PER_QUESTION;

        cout << "\n" << lines[baseIndex] << "\n";
        cout << lines[baseIndex + 1] << "\n";
        cout << lines[baseIndex + 2] << "\n";
        cout << lines[baseIndex + 3] << "\n";
        cout << lines[baseIndex + 4] << "\n";

        string userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == lines[baseIndex + 5] || userAnswer == string(1, toupper(lines[baseIndex + 5][0]))) {
            cout << "Correct! " << lines[baseIndex + 6] << "\n";
            score++;
        } else {
            cout << "Incorrect. " << lines[baseIndex + 6] << "\n";
        }
    }

    cout << "\nYour total score: " << score << "/" << QUESTIONS_TO_DISPLAY << "\n";
}

int main() {
    cout << "\nHi Everyone! We are Group 4, and we will be discussing about Identity Theft Prevention." << endl;
    cout << "Please select a section below to get started:" << endl;
    cout << "\nIntroduction\nRiskfactor\nPreventive\nQuiz\nResources\n" << endl;
    ifstream infile;
    string line, keyword, input;
    char continueChoice = 'y';
    char riskChoice = 'y';
    char preventiveChoice = 'y';

    enum Section { Riskfactor, Quiz, Introduction, Preventive, Resources };
    string sectionNames[] = {"Riskfactor", "Quiz", "Introduction", "Preventive", "Resources"};

    while (continueChoice == 'y' || continueChoice == 'Y') {
        cout << "Choose a Section: ";
        cin >> input;

        Section section;
        bool validInput = false;

        for (int i = 0; i < 5; ++i) {
            if (input == sectionNames[i]) {
                section = static_cast<Section>(i);
                validInput = true;
                break;
            }
        }

        if (!validInput) {
            cout << "Invalid section entered. Please try again.\n";
            continue;
        }

        switch (section) {
            case Introduction:
                cout << "\nIdentity theft occurs when someone steals personal information, such as your name, Social Security number, or credit card details, to commit fraud or other crimes. This can result in financial loss, damaged credit, and even legal issues for the victim. Common methods of identity theft include phishing scams, data breaches, and theft of physical documents like mail or ID cards." << endl;
                cout << "\nMoving on we will be learning more about Identity theft and Identity theft prevention." << endl;
                cout << "\nWe learn about its risk factors and and its preventive measures." << endl;
                cout << "\nWe also have a Quiz section for you to test your knowledge." << endl;
                cout << "\nAnd to help you learn more about identity theft prevention we have reference link of websites." << endl;
                break;

            case Riskfactor:
                infile.open("RiskFactor.txt");

                cout << "\nHere are the Risk Factors listed and their keywords. Please follow the instructions below:\n";
                cout << "Weak Passwords = Weak\n"
                     << "Unsecure Wi-Fi = Unsecure\n"
                     << "Phishing Scams = Phishing\n"
                     << "Social Media Oversharing = Oversharing\n"
                     << "Data Breaches = Breaches\n"
                     << "Mail Theft = Mail Theft\n"
                     << "Disposing of Documents Incorrectly = Disposing\n"
                     << "Lost or Stolen Personal Devices = Devices\n"
                     << "Stolen Wallet or ID = Wallet\n"
                     << "Using Unsafe Websites = Websites\n"
                     << "Insufficient Credit Monitoring = Insufficient\n"
                     << "Providing Information to Unknown Callers = Providing\n";

                while (riskChoice == 'y' || riskChoice == 'Y') {
                    cout << "\nEnter a keyword to filter lines or leave blank to access all at once: ";
                    cin.ignore();
                    getline(cin, keyword);

                    infile.clear();
                    infile.seekg(0);

                    bool found = false;

                    while (getline(infile, line)) {
                        if (keyword.empty() || line.find(keyword) != string::npos) {
                            cout << "\n" << line << "\n";
                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "\nNo lines matched the keyword \"" << keyword << "\".\n";
                    }

                    cout << "\nDo you want to look up another point? (y/n): ";
                    cin >> riskChoice;
                }

                infile.close();
                break;

            case Preventive:

                infile.open("PreventiveMeasure.txt");

                cout << "\nHere are the Preventive Measure listed and their keywords. Please follow the instructions below:\n" << endl;
                cout << "Enable Two-Factor Authentication = Factor" << endl;
                cout << "Shared Sensitive Documents = Shared" << endl;
                cout << "Monitor Financial Statements = Monitor" << endl;
                cout << "Use Secure Networks = Networks" << endl;
                cout << "Be Cautious with Apps = Cautious" << endl;
                cout << "Report Suspicious Activity = Report" << endl;

                while (preventiveChoice == 'y' || preventiveChoice == 'Y') {
                // Ask for a keyword
                cout << "\nEnter a keyword to filter lines or leave blank to access all at once: ";
                cin.ignore(); // Ignore leftover newline
                getline(cin, keyword);

                infile.clear();
                infile.seekg(0);
                bool found = false;

                while (getline(infile, line)) {
                    if (keyword.empty() || line.find(keyword) != string::npos) {
                    cout << "\n" << line << "\n";
                    found = true;
                    }
                }

                    if (!found) {
                    cout << "\nNo lines matched the keyword \"" << keyword << "\".\n";
                        }

                        cout << "\nDo you want to look up another point? (y/n): ";
                        cin >> preventiveChoice;
                }
                infile.close();
                break;

            case Quiz:
                cout << "\nWarning!!! Once you start the quiz you can only exit the section after you answer 5 question. All the best!!" << endl;
                cout << "\nPlease Capatalized your choice, Thank you!!" << endl;
                int choice;
                do {
                // Display the menu
                cout << "\n=== Quiz Menu ===\n";
                cout << "1. Start Quiz\n";
                cout << "2. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        // Run the quiz with questions from the text file
                        runQuiz("Quiz.txt");
                        break;
                    case 2:
                        cout << "Exiting the program. Goodbye!\n";
                        break;
                    default:
                        cout << "Invalid choice! Please select 1 or 2.\n";
                        }
                     } while (choice != 2); // Exit the loop if the user chooses 2

                break;
            case Resources:
                // Create an ifstream object to read the file
                infile.open("Resources.txt");

                // Check if the file is open and ready to be read
                if (infile.is_open()) {
                string line;
                cout << "--- File Contents ---" << endl;

                // Read each line from the file
                while (getline(infile, line)) {
                    cout << line << endl; // Output the line to the console
                }

                infile.close(); // Close the file after reading
                } else {
                // If the file cannot be opened
                cout << "Error: Unable to open the file." << endl;
                }
                break;

            default:
                cout << "Invalid section." << endl;
        }
           cout << "\nDo you want to choose another section? (y/n): ";
           cin >> continueChoice;
    }

    cout << "\nThank you so much for your time!. Goodbye!!\n";
    return 0;
}