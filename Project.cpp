#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_STAFF = 50;

struct Student {
    string name;
    int rollNumber;
    string fatherName;
    string department;
    string address;
};

struct Staff {
    string name;
    string fatherName;
    string post;
    string address;
};

void saveStudentsToFile(Student students[], int studentCount) {
    ofstream file("students.txt");
    for (int i = 0; i < studentCount; ++i) {
        file << students[i].rollNumber << endl;
        file << students[i].name << endl;
        file << students[i].fatherName << endl;
        file << students[i].department << endl;
        file << students[i].address << endl;
    }
    file.close();
}

void saveStaffToFile(Staff staff[], int staffCount) {
    ofstream file("staff.txt");
    for (int i = 0; i < staffCount; ++i) {
        file << staff[i].name << endl;
        file << staff[i].fatherName << endl;
        file << staff[i].post << endl;
        file << staff[i].address << endl;
    }
    file.close();
}

int loadStudentsFromFile(Student students[]) {
    ifstream file("students.txt");
    if (!file.is_open()) return 0;

    int count = 0;
    while (file >> students[count].rollNumber) {
        file.ignore();
        getline(file, students[count].name);
        getline(file, students[count].fatherName);
        getline(file, students[count].department);
        getline(file, students[count].address);
        count++;
    }
    file.close();
    return count;
}

int loadStaffFromFile(Staff staff[]) {
    ifstream file("staff.txt");
    if (!file.is_open()) return 0;
	  
    int count = 0;
    while (getline(file, staff[count].name)) {
        getline(file, staff[count].fatherName);
        getline(file, staff[count].post);
        getline(file, staff[count].address);
        count++;
    }
    file.close();
    return count;
}

int addStudent(Student students[], int studentCount) {
    if (studentCount >= MAX_STUDENTS) {
        cout << "HOSTEL IS FULL. Cannot add more students.\n";
        return studentCount;
    }

    cout << "Enter Roll Number: ";
    cin >> students[studentCount].rollNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Name: ";
    getline(cin, students[studentCount].name);

    cout << "Enter Father's Name: ";
    getline(cin, students[studentCount].fatherName);
    
    cout << "Enter Department: ";
    getline(cin, students[studentCount].department);

    cout << "Enter Address: ";
    getline(cin, students[studentCount].address);

    cout << "Student added successfully!\n";
    saveStudentsToFile(students, studentCount + 1);
    return studentCount + 1;
}

int addStaff(Staff staff[], int staffCount) {
    if (staffCount >= MAX_STAFF) {
        cout << "No more positions available. Cannot add more staff.\n";
        return staffCount;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Name: ";
    getline(cin, staff[staffCount].name);

    cout << "Enter Father's Name: ";
    getline(cin, staff[staffCount].fatherName);

    cout << "Enter Post: ";
    getline(cin, staff[staffCount].post);

    cout << "Enter Address: ";
    getline(cin, staff[staffCount].address);

    cout << "Staff member added successfully!\n";
    saveStaffToFile(staff, staffCount + 1);
    return staffCount + 1;
}

void displayStudents(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students in the hostel.\n";
        return;
}

    for (int i = 0; i < studentCount; ++i) {
        cout << "ROLL NO: " << students[i].rollNumber << endl;
        cout << "NAME: " << students[i].name << endl;
        cout << "FATHER NAME: " << students[i].fatherName << endl;
        cout << "DEPARTMENT: " << students[i].department << endl;
        cout << "ADDRESS: " << students[i].address << endl;
        cout << "--------------------------" << endl;
    }
}

void displayStaff(Staff staff[], int staffCount) {
    if (staffCount == 0) {
        cout << "No staff members found.\n";
        return;
    }

    for (int i = 0; i < staffCount; ++i) {
        cout << "NAME: " << staff[i].name << endl;
        cout << "FATHER NAME: " << staff[i].fatherName << endl;
        cout << "POST: " << staff[i].post << endl;
        cout << "ADDRESS: " << staff[i].address << endl;
        cout << "--------------------------" << endl;
    }
}

void searchStudentByRoll(Student students[], int studentCount) {
    if (studentCount == 0) {
        cout << "No students in the hostel.\n";
        return;
    }

    int rollNumber;
    cout << "Enter Roll Number to search: ";
    cin >> rollNumber;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].rollNumber == rollNumber) {
            cout << "STUDENT FOUND:\n";
            cout << "ROLL NO: " << students[i].rollNumber << endl;
            cout << "NAME: " << students[i].name << endl;
            cout << "FATHER NAME: " << students[i].fatherName << endl;
            cout << "DEPARTMENT: " << students[i].department << endl;
            cout << "ADDRESS: " << students[i].address << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void searchStaffByName(Staff staff[], int staffCount) {
    if (staffCount == 0) {
        cout << "No staff members found.\n";
        return;
    }

    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Name to search: ";
    getline(cin, name);
    
    for (int i = 0; i < staffCount; ++i) {
        if (staff[i].name == name) {
            cout << "STAFF MEMBER FOUND:\n";
            cout << "NAME: " << staff[i].name << endl;
            cout << "FATHER NAME: " << staff[i].fatherName << endl;
            cout << "POST: " << staff[i].post << endl;
            cout << "ADDRESS: " << staff[i].address << endl;
            return;
        }
    }

    cout << "Staff member not found.\n";
}

void removeStudent(Student students[], int &studentCount) {
    if (studentCount == 0) {
        cout << "No students to remove.\n";
        return;
    }

    int rollNumber;
    cout << "Enter Roll Number to remove: ";
    cin >> rollNumber;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student removed successfully!\n";
            saveStudentsToFile(students, studentCount);
            return;
        }
    }

    cout << "Student not found.\n";
}

void removeStaff(Staff staff[], int &staffCount) {
    if (staffCount == 0) {
        cout << "No staff members to remove.\n";
        return;
    }
    
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Name to remove: ";
    getline(cin, name);

    for (int i = 0; i < staffCount; ++i) {
        if (staff[i].name == name) {
            for (int j = i; j < staffCount - 1; ++j) {
                staff[j] = staff[j + 1];
            }
            staffCount--;
            cout << "Staff member removed successfully!\n";
            saveStaffToFile(staff, staffCount);
            return;
        }
    }

    cout << "Staff member not found.\n";
}

int main() {
    Student students[MAX_STUDENTS];
    Staff staff[MAX_STAFF];
    int studentCount = loadStudentsFromFile(students);
    int staffCount = loadStaffFromFile(staff);
    string password;

    cout << "WELCOME TO HOSTEL MANAGEMENT SYSTEM\n";
    cout << "Enter Admin Password: ";
    cin >> password;

    if (password != "3921") {
        cout << "Invalid password. Exiting program.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\nMENU:\n";
        cout << "1. Add Student\n";
        cout << "2. Add Staff\n";
        cout << "3. Display Students\n";
        cout << "4. Display Staff\n";
        cout << "5. Search Student by Roll Number\n";
        cout << "6. Search Staff by Name\n";
        cout << "7. Remove Student\n";
        cout << "8. Remove Staff\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studentCount = addStudent(students, studentCount);
                break;
            case 2:
                staffCount = addStaff(staff, staffCount);
                break;
            case 3:
                displayStudents(students, studentCount);
                break;
            case 4:
                displayStaff(staff, staffCount);
                break;
            case 5:
                searchStudentByRoll(students, studentCount);
                break;
            case 6:
                searchStaffByName(staff, staffCount);
                break;
            case 7:
                removeStudent(students, studentCount);
                break;
            case 8:
                removeStaff(staff, staffCount);
                break;
            case 9:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
