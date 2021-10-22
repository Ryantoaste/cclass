#include <iostream>
#include <sstream>
#include <cstring>
#include <typeinfo>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
struct id {
    string firstName;
    string lastName;
    int studentId;
    float gpa;
} ;

int main(){
    string terminal;
    cout << "This is a catalogue of students. Type ADD to add a student, PRINT to "
    "print all entries, DELETE to delete an entry, or EXIT to exit." << endl;
    cin >> terminal;
    transform(terminal.begin(), terminal.end(), terminal.begin(), :: toupper);
    if (terminal == "ADD"){
        cout << "ADD function coming soon." << endl;
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
    string 1name;
    string 2name;
    int numberd;
    float grades;
    return 0;
}
