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
bool isNum(string y){
  for (int i; i < y.length(); i++){
    if (isdigit(i) == false){
      return false;
    }
  }
  return true;
}
int add();
int print();
int delete();
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
int delete(){
    string delID;
    cout << "Enter the student id of the student you want to delete from the catalogue." << endl;
    cin >> delID;
    int ud;
    if (isNum(delID)){
        stringstream io(delID)
        io >> ud;
    }
    
}
int print(){
    if (size == 0){
        cout << "There are no students to print." << endl;
    }
    cout << "" << endl;
    for (int i = 0; i < size; i++){
        cout << "First name: " << student->at(i)->firstName << " Last name: " << student->at(i)->lastName << endl;
        cout << " GPA: " << student->at(i)->gpa << " Student ID: " << student->at(i)->studentId << endl;
        cout << "\n";
    }
    return 0;
}
int add(){
    id*p = new id;
    student->push_back(p);
    id*e = new id;
    student->at(number) = e;
    string info;
    cout << "Enter the student's first name." << endl;
    cin >> info;
    e->firstName = info;
    cout << "Enter the students last name." << endl;
    cin >> info;
    e->lastName = info;
    cout << "Enter the students gpa." << endl;
    cin >> info;
    float f;
    if (isNum(info)){
        stringstream io(info);
        io >> f;
        e->gpa = f;
    }
    cout << "Enter the students id number. " << endl;
    cin >> info;
    int b;
    if (isNum(info)){
        stringstream io(info);
        io >> b;
        e->studentId = b;
    }
    number++;
    return 0;
}
