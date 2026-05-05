#include <iostream>
#include <string>
using namespace std;

struct Student {
    int    id;
    string name;
    float  grade;
};

Student students[100];
int maxStudents = 0;
int count = 0;

string letterGrade(float g) {
    if (g >= 90) return "A";
    if (g >= 80) return "B";
    if (g >= 70) return "C";
    if (g >= 60) return "D";
    return "F";
}

void addStudent() {
    if (count >= maxStudents) { cout << "Limit reached!\n"; return; }
    Student s;
    cout << "Enter ID: ";    cin >> s.id;
    cout << "Enter Name: ";  cin.ignore(); getline(cin, s.name);
    cout << "Enter Grade: "; cin >> s.grade;

    for (int i = 0; i < count; i++) {
        if (students[i].id == s.id) { cout << "ID already exists!\n"; return; }
    }
    if (s.grade < 0 || s.grade > 100) { cout << "Invalid grade!\n"; return; }

    students[count++] = s;
    cout << "Student added! (" << count << "/" << maxStudents << ")\n";
}

void displayAll() {
    if (count == 0) { cout << "No students yet.\n"; return; }
    cout << "\nID    Name                  Grade  Letter\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << students[i].id    << "    "
             << students[i].name  << "    "
             << students[i].grade << "    "
             << letterGrade(students[i].grade) << "\n";
    }
}

// البحث بالـ ID
void searchByID() {
    int id;
    cout << "Enter ID: "; cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Name: "  << students[i].name  << "\n"
                 << "Grade: " << students[i].grade << " ("
                 << letterGrade(students[i].grade) << ")\n";
            return;
        }
    }
    cout << "Not found!\n";
}

// البحث بالاسم (جديد)
void searchByName() {
    string name;
    cout << "Enter Name: "; cin.ignore(); getline(cin, name);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].name == name) {
            cout << "ID: "    << students[i].id    << "\n"
                 << "Grade: " << students[i].grade << " ("
                 << letterGrade(students[i].grade) << ")\n";
            found = true;
        }
    }
    if (!found) cout << "Not found!\n";
}

// تعديل الاسم والدرجة (محدّث)
void updateStudent() {
    int id;
    cout << "Enter ID: "; cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "1.Update Name  2.Update Grade  3.Update Both\nChoice: ";
            int ch; cin >> ch;
            if (ch == 1 || ch == 3) {
                cout << "New Name: "; cin.ignore(); getline(cin, students[i].name);
            }
            if (ch == 2 || ch == 3) {
                cout << "New Grade: "; cin >> students[i].grade;
            }
            cout << "Updated!\n"; return;
        }
    }
    cout << "Not found!\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID: "; cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            cout << "Deleted!\n"; return;
        }
    }
    cout << "Not found!\n";
}

void showStats() {
    if (count == 0) { cout << "No students yet.\n"; return; }
    float sum = 0, high = students[0].grade, low = students[0].grade;
    int pass = 0, fail = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
        if (students[i].grade > high) high = students[i].grade;
        if (students[i].grade < low)  low  = students[i].grade;
        if (students[i].grade >= 60) pass++; else fail++;  // ناجح/راسب (جديد)
    }
    cout << "Total: "   << count       << "\n"
         << "Average: " << sum / count << "\n"
         << "Highest: " << high        << "\n"
         << "Lowest: "  << low         << "\n"
         << "Passed: "  << pass        << "\n"  // جديد
         << "Failed: "  << fail        << "\n"; // جديد
}

// ترتيب حسب الدرجة - Bubble Sort (جديد)
void sortByGrade() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp  = students[j];
                students[j]   = students[j + 1];
                students[j+1] = temp;
            }
        }
    }
    cout << "Sorted! Displaying from highest to lowest:\n";
    displayAll();
}

int main() {
    cout << "How many students? "; cin >> maxStudents;

    int choice;
    do {
        cout << "\n1.Add  2.Display  3.Search by ID  4.Search by Name\n"
             << "5.Update  6.Delete  7.Stats  8.Sort by Grade  0.Exit\n"
             << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent();   break;
            case 2: displayAll();   break;
            case 3: searchByID();   break;
            case 4: searchByName(); break;
            case 5: updateStudent();break;
            case 6: deleteStudent();break;
            case 7: showStats();    break;
            case 8: sortByGrade();  break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 0);

    return 0;
}
