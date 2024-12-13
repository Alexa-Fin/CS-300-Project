//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Alexa Finnell
// Data        : 12/13/2024
// Description : This program has the ability to load data from a csv file,
// read and print out data (course number, course title, prerequisites)
// from the file, and search for information on a specific course by searching
// using the course number.
//============================================================================

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Course {
    string number;
    string title;
    vector<string> prerequisites;
};

// Global course table
unordered_map<string, Course> courseTable;

// Function to load course data from file
void loadCourseData(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "ERROR! Unable to open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        Course course;
        getline(ss, course.number, ',');
        getline(ss, course.title, ',');

        while (getline(ss, token, ',')) {
            course.prerequisites.push_back(token);
        }

        transform(course.number.begin(), course.number.end(), course.number.begin(), ::tolower);
        courseTable[course.number] = course;
    }

    file.close();
    cout << "Course data loaded successfully!" << endl;
}

// Function to print all courses in alphanumeric order
void printCourseList() {
    vector<string> courseNumbers;
    for (const auto& pair : courseTable) {
        courseNumbers.push_back(pair.first);
    }

    sort(courseNumbers.begin(), courseNumbers.end());

    for (const auto& courseNumber : courseNumbers) {
        const Course& course = courseTable[courseNumber];
        cout << "Course Number: " << course.number << endl;
        cout << "Course Title: " << course.title << endl;
        cout << "Prerequisites: ";
        if (!course.prerequisites.empty()) {
            for (const string& prereq : course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "None" << endl;
        }
        cout << endl;
    }
}

// Function to print course details
void printCourseDetails() {
    string courseNumber;
    cout << "Enter course number: ";
    cin >> courseNumber;
    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::tolower);

    if (courseTable.find(courseNumber) != courseTable.end()) {
        const Course& course = courseTable[courseNumber];
        cout << "Course Number: " << course.number << endl;
        cout << "Course Title: " << course.title << endl;
        cout << "Prerequisites: ";
        if (!course.prerequisites.empty()) {
            for (const string& prereq : course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "None" << endl;
        }
    }
    else {
        cout << "ERROR! Course not found." << endl;
    }
}

int main() {

    int userChoice;

    do {
        cout << "\nPlease choose an option:" << endl;
        cout << "1: Load course data" << endl;
        cout << "2: Print list of all courses" << endl;
        cout << "3: Print course details" << endl;
        cout << "9: Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            loadCourseData("CS 300 ABCU_Advising_Program_Input.csv"); // Automatically load the CSV file
            break;
        case 2:
            printCourseList();
            break;
        case 3:
            printCourseDetails();
            break;
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (userChoice != 9);

    return 0;
}
