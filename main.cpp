#include <iostream>
#include <string>
using namespace std;

struct Student { int id; string name; float grade; };

Student students[100];
int maxStudents = 0, count = 0;

string letterGrade(float g) {
    if (g >= 90) return "A";
    if (g >= 80) return "B";
    if (g >= 70) return "C";
    if (g >= 60) return "D";
    return "F";
}

void printStudent(int i) {
    cout << "ID: " << students[i].id << "  Name: " << students[i].name
         << "  Grade: " << students[i].grade << " (" << letterGrade(students[i].grade) << ")\n";
}

int findByID(int id) {
    for (int i = 0; i < count; i++)
        if (students[i].id == id) return i;
    return -1;
}

void addStudent() {
    if (count >= maxStudents) { cout << "Limit reached!\n"; return; }
    Student s;
    cout << "Enter ID: ";    cin >> s.id;
    cout << "Enter Name: ";  cin.ignore(); getline(cin, s.name);
    cout << "Enter Grade: "; cin >> s.grade;
    if (findByID(s.id) != -1)         { cout << "ID already exists!\n"; return; }
    if (s.grade < 0 || s.grade > 100) { cout << "Invalid grade!\n";     return; }
    students[count++] = s;
    cout << "Student added! (" << count << "/" << maxStudents << ")\n";
}

void displayAll() {
    if (count == 0) { cout << "No students yet.\n"; return; }
    cout << "\nID    Name                  Grade  Letter\n"
         << "------------------------------------------\n";
    for (int i = 0; i < count; i++) printStudent(i);
}

void searchByID() {
    int id; cout << "Enter ID: "; cin >> id;
    int i = findByID(id);
    if (i != -1) printStudent(i); else cout << "Not found!\n";
}

void searchByName() {
    string name; bool found = false;
    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    for (int i = 0; i < count; i++)
        if (students[i].name == name) { printStudent(i); found = true; }
    if (!found) cout << "Not found!\n";
}

void sortByGrade() {
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (students[j].grade < students[j+1].grade)
                { Student t = students[j]; students[j] = students[j+1]; students[j+1] = t; }
    cout << "Sorted! Displaying from highest to lowest:\n";
    displayAll();
}

int main() {
    cout << "How many students? "; cin >> maxStudents;
    if (maxStudents > 100) maxStudents = 100;
    int choice;
    do {
        cout << "\n1.Add  2.Display  3.Search by ID  4.Search by Name  5.Sort by Grade  0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent();        break;
            case 2: displayAll();        break;
            case 3: searchByID();        break;
            case 4: searchByName();      break;
            case 5: sortByGrade();       break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 0);

    return 0;
}
