#include <iostream>
using namespace std;

unsigned int attendance = 0;   // bit storage for attendance

// Mark attendance
void markAttendance(int roll, char status) {
    if (status == 'P' || status == 'p') {
        attendance |= (1 << roll);   // set bit
    } 
    else if (status == 'A' || status == 'a') {
        attendance &= ~(1 << roll);  // clear bit
    }
    else {
        cout << "Invalid entry! Use P/p or A/a.\n";
    }
}

// Count present students
int countPresent() {
    int count = 0;
    unsigned int temp = attendance;

    while (temp) {
        temp &= (temp - 1);  // removes the lowest set bit
        count++;
    }
    return count;
}

int main() {
    int totalStudents, roll, choice;
    char status;

    cout << "Enter number of students (max 32): ";
    cin >> totalStudents;

    if (totalStudents > 32 || totalStudents < 1) {
        cout << "Invalid number of students!\n";
        return 0;
    }

    cout << "\n------ Mark Attendance ------\n";

    for (roll = 1; roll <= totalStudents; roll++) {
        cout << "Roll " << roll << " ? Enter P/p for Present or A/a for Absent: ";
        cin >> status;
        markAttendance(roll, status);
    }

    // Menu for operations
    while (true) {
        cout << "\n========== MENU ==========\n";
        cout << "1. Count Present Students\n";
        cout << "2. Count Absent Students\n";
        cout << "3. Check Attendance of a Roll Number\n";
        cout << "4. Show Bits Used\n";
        cout << "5. Replace Attendance for a Roll No\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Total Present: " << countPresent() << "\n";
                break;

            case 2:
                cout << "Total Absent: " << totalStudents - countPresent() << "\n";
                break;

            case 3:
                cout << "Enter Roll Number: ";
                cin >> roll;

                if (roll >= 1 && roll <= totalStudents) {
                    if (attendance & (1 << roll))
                        cout << "Roll " << roll << " is PRESENT.\n";
                    else
                        cout << "Roll " << roll << " is ABSENT.\n";
                } else {
                    cout << "Invalid roll number!\n";
                }
                break;

            case 4:
                cout << "Total Bits Used for Attendance = " << totalStudents << " bits\n";
                break;

            case 5:
                cout << "Enter Roll Number to Replace: ";
                cin >> roll;

                if (roll >= 1 && roll <= totalStudents) {
                    cout << "Enter new status (P/p or A/a): ";
                    cin >> status;
                    markAttendance(roll, status);
                    cout << "Attendance updated for Roll " << roll << ".\n";
                } 
                else {
                    cout << "Invalid roll number!\n";
                }
                break;

            case 6:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid option!\n";
        }
    }

    return 0;
}
