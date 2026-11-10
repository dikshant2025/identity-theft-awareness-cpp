#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()
using namespace std;

const int MAX_QUESTIONS = 30;      // Based on the maximum number of questions
const int LINES_PER_QUESTION = 7; // Number of lines per question block (excluding blank line)
const int QUESTIONS_TO_DISPLAY = 5; // Number of questions to display in each run

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
        // Skip empty lines
        if (!lines[lineCount].empty()) {
            lineCount++;
        }
    }
    quizFile.close();

    // Calculate the total number of complete questions in the file
    int totalQuestions = lineCount / LINES_PER_QUESTION;
    if (totalQuestions == 0) {
        cout << "No valid questions found in the file!" << endl;
        return;
    }

    srand(static_cast<unsigned>(time(nullptr))); // different questions each run
    bool usedQuestions[MAX_QUESTIONS] = {false}; // To track which questions have already been used
    int score = 0;

    cout << "\nNOTE: Please enter your answers in UPPERCASE letters (e.g., A, B, C, or D).\n";

    // Display random questions
    for (int i = 0; i < QUESTIONS_TO_DISPLAY; i++) {
        int questionIndex;

        // Select a random question that hasn't been used
        do {
            questionIndex = rand() % totalQuestions; // Random index from 0 to totalQuestions-1
        } while (usedQuestions[questionIndex]);

        usedQuestions[questionIndex] = true; // Mark this question as used

        int baseIndex = questionIndex * LINES_PER_QUESTION; // Starting index for the question block

        // Display the question and options
        cout << "\n" << lines[baseIndex] << "\n";       // Question
        cout << lines[baseIndex + 1] << "\n";           // Option A
        cout << lines[baseIndex + 2] << "\n";           // Option B
        cout << lines[baseIndex + 3] << "\n";           // Option C
        cout << lines[baseIndex + 4] << "\n";           // Option D

        // Get user's answer
        string userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        // Check if the answer is correct
        if (userAnswer == lines[baseIndex + 5] || userAnswer == string(1, toupper(lines[baseIndex + 5][0]))) {
            cout << "Correct! " << lines[baseIndex + 6] << "\n"; // Feedback
            score++;
        } else {
            cout << "Incorrect. " << lines[baseIndex + 6] << "\n"; // Feedback
        }
    }

    // Display the final score
    cout << "\nYour total score: " << score << "/" << QUESTIONS_TO_DISPLAY << "\n";
}

int main() {
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

    return 0;
}