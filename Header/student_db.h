#prgma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    char grade;
};

int isExisted(vector<Student>& std_db, int id) {
    for (int i = 0; i < std_db.size(); i++) {
        if (std_db[i].id == id) return i;
    }

    return -1;
}

void addStudent(vector<Student>& std_db, Student student) {
    if (isExisted(std_db, student.id) < 0)
        throw runtime_error("This id of this student already existed !!");
    std_db.push_back(student);
}

void updateStudent(vector<Student>& std_db, int std_id, Student new_std) {
    int idx = isExisted(std_db, std_id);
    if (idx < 0)
        throw runtime_error("No student with this id!!");

    std_db[idx] = new_std;
}

Student searchStudent(vector<Student>& std_db, int id) {
    int idx = isExisted(std_db, id);
    if (idx < 0) throw runtime_error("No student with this ID!!!");

    return std_db[idx];
}

void displayStudent(vector<Student>& std_db, int idx) {
        cout << "Student ID : " << std_db[idx].id << endl;
        cout << "Student Name : " << std_db[idx].name << endl;
        cout << "Student Age : " << std_db[idx].age << endl;
        cout << "Student Grade : " << std_db[idx].grade << endl;
        cout << "==================";
}

void displayAllStudent(vector<Student>& std_db) {
    for (auto std : std_db) {
        cout << "Student ID : " << std.id << endl;
        cout << "Student Name : " << std.name << endl;
        cout << "Student Age : " << std.age << endl;
        cout << "Student Grade : " << std.grade << endl;
        cout << "==================";
    }
}

void run_t_6() {
    vector<Student> students;

    students.push_back({1, "Alice", 20, 'A'});
    students.push_back({2, "Bob", 19, 'B'});
    students.push_back({3, "Charlie", 21, 'A'});
    students.push_back({4, "Diana", 22, 'C'});

    displayAllStudent(students);
}