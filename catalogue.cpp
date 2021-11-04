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
  #include "boost/variant.hpp"

  using namespace std;
  /*
  cout << (anything);
  cout.precision(2);
  */
  struct id {
  string firstName;
  string lastName;
  int studentId;
  float gpa;
  };
  id * newStudent = new id;
  void add();
  void print();
  //void delet();
  int number = 0;
  vector<boost::variant<string, int, float>> students;
  //vector<id> *student = &students;
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
      //delet();
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
      cout << "Only enter numbers for the student id." << endl;
      cin.clear();
      main();
    }
    bool found = false;
    for (int i = 0; i < students.size(); i++){
      id*n = new id;
      n->studentId = students[i];
      if (n->studentId == delID){
        found = true;
        delID = i;
        break;
      }
    }
    if (found == true){
      students.erase(students.begin(), students.begin()+delID);
      students.pop_back();
      print();
      cout << "Erased!" << endl;
    }else{
      cout << "Enter a valid id number." << endl;
      delet();
    }
    
  }
  void print(){
    int size = students.size();
    if (size == 0){
      cout << "There are no students to print." << endl;
    }
    cout << "" << endl;
    for (int i = 0; i < size; i++){
      cout << students[i] << endl;
    }
  }
  void add(){
    cout << "Enter the students gpa." << endl;
    cin >> newStudent->gpa;
    while (cin.fail()){
      cout << "Only enter numbers for the gpa." << endl;
      cin.clear();
      main();
    }
    cout << "Enter the student's first name." << endl;
    cin >> newStudent->firstName;
    cout << "Enter the students last name." << endl;
    cin >> newStudent->lastName;
    cout << "Enter the students id number. " << endl;
    cin >> newStudent->studentId;
    while (cin.fail()){
      cout << "Only enter numbers for the student id." << endl;
      cin.clear();
      main();
    }
    students.push_back(newStudent->gpa);
    students.push_back(newStudent->firstName);
    students.push_back(newStudent->lastName);
    students.push_back(newStudent->studentId);
    number++;
  }
