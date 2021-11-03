#include <iostream>
#include <sstream>
#include <cstring>
#include <typeinfo>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;
struct id {
  string firstName;
  string lastName;
  int studentId;
  float gpa;
};
id*p = new id;
bool isNum(string num){
    cout << num.length() << endl;
    for (int i; i < num.length(); i++){
        cout << "n2" << endl;
        if (isdigit(i) == false){
            cout << "yes2" << endl;
          return false;
        }
    }
    return true;
}
void add();
void print();
void delet();
int number = 0;
vector<id*> * student = new vector<id*>(0);
int size = student->size();
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
        print();
        main();
    }else if (terminal == "DELETE"){
        delet();
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
void delet(){
    int delID;
    cout << "Enter the student id of the student you want to delete from the catalogue." << endl;
    cin >> delID;
    while (cin.fail()){
        cout << "Only enter numbers for the gpa." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        delet();
    }
    bool found = false;
    for (int i = 0; i < student->size(); i++){
        id*n = new id;
        student->at(i) = n;
        if (n->studentId == delID){
            found = true;
            delID = i;
            break;
        }
    }
    if (found == true){
        student->erase(student->begin(), student->begin()+delID);
        print();
        //cout << "Erased!" << endl;
    }else{
        cout << "Enter a valid id number." << endl;
        delet();
    }
    
}
void print(){
    if (size == 0){
        cout << "There are no students to print." << endl;
    }
    cout << "" << endl;
    for (int i = 0; i < size; i++){
        cout << "First name: " << student->at(i)->firstName << " Last name: " << student->at(i)->lastName << endl;
        cout << " GPA: " << student->at(i)->gpa << " Student ID: " << student->at(i)->studentId << endl;
        cout << "\n";
    }
}
void add(){
    id*p = new id;
    student->push_back(p);
    id*e = new id;
    student->at(number) = e;
    string info;
    int infi;
    cout << "Enter the students gpa." << endl;
    cin >> infi;
    while (cin.fail()){
        cout << "Only enter numbers for the gpa." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        student->erase(student->begin(),student->begin()+number);
        student->pop_back();
        add();
    }
    e->gpa = infi;
    cout << "Enter the student's first name." << endl;
    cin >> info;
    e->firstName = info;
    cout << "Enter the students last name." << endl;
    cin >> info;
    e->lastName = info;
    cout << "Enter the students id number. " << endl;
    cin >> infi;
    while (cin.fail()){
        cout << "Only enter numbers for the student id." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        student->erase(student->begin(),student->begin()+number);
        student->pop_back();
        add();
    }
    e->studentId = infi;
    number++;
}
