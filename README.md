# Identity Theft Prevention: Interactive Guide (C++)

A menu-driven C++ program that teaches users about identity theft. Built for a group assignment in a C++ programming course at Jacksonville State University (Nov 2024).

**I wrote all of the code.** The program has five sections: Introduction, Risk Factors, Preventive Measures, Quiz and Resources. Each section was first written as a standalone program (in `modules/`), and `Group4.cpp` combines them into one menu-driven program.

## Features
- Section menu backed by an `enum` with input validation.
- Keyword search over text files (`getline`, `string::find`, rewinding the file with `seekg`).
- Quiz that reads multiple-choice questions from `Quiz.txt`, asks 5 random questions without repeats, and gives feedback and a score.

## Run it
```bash
clang++ -std=c++17 Group4.cpp -o identity-guide   # or g++
./identity-guide
```
Keep the `.txt` files in the same folder as the program.

## Changes since submission
The quiz now seeds the random number generator, so each run shows different questions (before, every run showed the same 5).
