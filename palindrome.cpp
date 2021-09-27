#include <iostream>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;
char store [80];
string response;
int lets;
int checkn();
int half;
int palin();
char palf [40];
int end();
int main(){
    cout << "enter a palindrome please." << endl;
    getline(cin,response);
    if (response.length() > 80){
        cout << "only enter up to 80 characters" << endl;
        main();
    }
    checkn();
    return 0;
}
int checkn(){
    lets = 0;
    for (int i = 0; i < response.length(); i++){
        if (isalpha(response[i])){
            store[lets] = response[i];
            lets++;
        }else{
            cout << "enter only letters please." << endl;
            std::fill_n(store, 80, 0);
            main();
        }
    }
    if (lets % 2 == 1){
        int half = 1;
    }else{
        int half = 0;
    }
    palin();
    return 0;
}
int palin(){
    int flag;
    lets -= half;
    for (int o = 0; o < (lets/2); o++){
        palf[o] = store[o];
    }
    int countopalf = 0;
    for (int u = ((lets + half)- 1); u > ((lets / 2)+ 1); u--){
        if (store[u] == palf[countopalf]){
            countopalf++;
        }else{
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        cout << "that is not a palindrome" << endl;
        flag = 0;
        std::fill_n(store, 80, 0);
        std::fill_n(palf, 40, 0);
        half = 0;
        lets = 0;
        main();
    }else{
        cout << "you entered " << store << " which is a palindrome! Great job!" << endl;
        end();
    }
    return 0;
}
int end(){
    string proposal;
    cout << "Good job! You made a palindrome!" << endl;
    cout << "Would you like to exit the program, or restart? (exit, restart)" << endl;
    transform(proposal.begin(), proposal.end(), proposal.begin(), :: tolower);
    if (proposal == "exit"){
        cout << "Ok goodbye." << endl;
        exit(0);
    }else if (proposal == "restart"){
        cout << "Again!!" << endl;
        std::fill_n(store, 80, 0);
        std::fill_n(palf, 40, 0);
        half = 0;
        lets = 0;
        main();
    }else{
        cout << "Only enter exit, or restart." << endl;
        end();
    }
    return 0;
}
