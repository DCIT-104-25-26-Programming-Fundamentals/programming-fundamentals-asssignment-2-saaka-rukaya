// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<double> scores;
};


double calculateAverage(const vector<double>& scores)
{
    double total_score = 0;

    for (int score_index = 0; score_index < scores.size(); score_index++)
    {
        total_score = total_score + scores[score_index];
    }

    return total_score / scores.size();
}


bool studentIdExists(const vector<Student>& students, int student_id)
{
    for (int student_index = 0;
         student_index < students.size();
         student_index++)
    {
        if (students[student_index].id == student_id)
        {
            return true;
        }
    }

    return false;
}


void addStudent(vector<Student>& students)
{
    Student new_student;
    int number_of_scores;

    cout << "Student name: ";
    getline(cin, new_student.name);

    cout << "Student ID: ";
    cin >> new_student.id;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Student ID must be a number." << endl;
        return;
    }

    if (studentIdExists(students, new_student.id))
    {
        cin.ignore(1000, '\n');
        cout << "Error: A student with this ID already exists." << endl;
        return;
    }

    cout << "How many scores? ";
    cin >> number_of_scores;

    if (cin.fail() || number_of_scores <= 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Number of scores must be a positive integer." << endl;
        return;
    }

    for (int score_number = 1;
         score_number <= number_of_scores;
         score_number++)
    {
        double student_score;

        cout << "Enter score " << score_number << ": ";
        cin >> student_score;

        if (cin.fail() || student_score < 0 || student_score > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Scores must be between 0 and 100." << endl;
            return;
        }

        new_student.scores.push_back(student_score);
    }

    cin.ignore(1000, '\n');

    students.push_back(new_student);

    cout << "Student \"" << new_student.name
         << "\" added successfully." << endl;
}


void displayAllStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student records have been added yet." << endl;
        return;
    }

    cout << "\n"
         << left
         << setw(22) << "Name"
         << setw(15) << "ID"
         << setw(30) << "Scores"
         << setw(10) << "Average"
         << endl;

    cout << string(77, '-') << endl;

    for (int student_index = 0;
         student_index < students.size();
         student_index++)
    {
        string scores_text = "";

        for (int score_index = 0;
             score_index < students[student_index].scores.size();
             score_index++)
        {
            scores_text = scores_text
                + to_string(
                    static_cast<int>(
                        students[student_index].scores[score_index]
                    )
                );

            if (score_index <
                students[student_index].scores.size() - 1)
            {
                scores_text = scores_text + ", ";
            }
        }

        double average_score =
            calculateAverage(students[student_index].scores);

        cout << left
             << setw(22) << students[student_index].name
             << setw(15) << students[student_index].id
             << setw(30) << scores_text
             << fixed << setprecision(2)
             << average_score
             << endl;
    }

    cout << string(77, '-') << endl;
}


void displayStudentAverage(const vector<Student>& students)
{
    int student_id;

    cout << "Enter student ID: ";
    cin >> student_id;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Student ID must be a number." << endl;
        return;
    }

    cin.ignore(1000, '\n');

    for (int student_index = 0;
         student_index < students.size();
         student_index++)
    {
        if (students[student_index].id == student_id)
        {
            double average_score =
                calculateAverage(students[student_index].scores);

            cout << students[student_index].name
                 << "'s average score: "
                 << fixed << setprecision(2)
                 << average_score << endl;

            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}


void displayMenu()
{
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}


int main()
{
    vector<Student> students;
    int menu_choice;

    while (true)
    {
        displayMenu();

        cout << "Enter your choice (1-4): ";
        cin >> menu_choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Please enter a number from 1 to 4." << endl;
            continue;
        }

        cin.ignore(1000, '\n');

        if (menu_choice == 1)
        {
            addStudent(students);
        }
        else if (menu_choice == 2)
        {
            displayAllStudents(students);
        }
        else if (menu_choice == 3)
        {
            displayStudentAverage(students);
        }
        else if (menu_choice == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Error: Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}