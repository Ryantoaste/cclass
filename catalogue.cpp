#include <iostream>
#include <sstream>
#include <cstring>
#include <typeinfo>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;
struct id {
    string firstName;
    string lastName;
    int studentId;
    float gpa;
};
int add();
int i = 0;
vector<id*> * student = new vector<id*>(3);
int main(){
    string terminal;
    cout << "This is a catalogue of students. Type ADD to add a student, PRINT to "
    "print all entries, DELETE to delete an entry, or EXIT to exit." << endl;
    cin >> terminal;
    transform(terminal.begin(), terminal.end(), terminal.begin(), :: toupper);
    if (terminal == "ADD"){
        add();
        main();
    }else if (terminal == "PRINT") {
        cout << "PRINT function coming soon." << endl;
        main();
    }else if (terminal == "DELETE"){
        cout << "DELETE function coming soon!" << endl;
        main();
    }else if (terminal == "EXIT") {
        cout << "Goodbye!" << endl;
        exit(0);
    }else{
        cout << "Only enter ADD, PRINT, DELETE, or EXIT." << endl;
        main();
    }
    return 0;
}
int add(){
    cout << "Enter the student's first name." << endl;
    cin >> student->at(i)->firstName;
    cout << "Enter the students last name." << endl;
    cin >> student->at(i)->lastName;
    cout << "Enter the students gpa." << endl;
    if (!(student->at(i)->gpa)){
        student->erase(student->begin()+i);
        cout << "Only enter a float for gpa." << endl;
    }else{
        student->at(i)->gpa;
    }
    i++;
    return 0;
}
