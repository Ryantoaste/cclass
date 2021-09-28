//this program will allow the user to input a palindrome, it will only allow 80 characters and 
//will remove all spaces and non-alphanumeric characters.
//all the imports I need.
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;
//these are all the variables that need to be used across multiple functions
//and functions too.
char store [80];
string response;
int lets;
int checkn();
int half;
int palin();
char palf [40];
int end();
//this function asks the user to enter a palindrome and checks if it is under 80 characters
int main(){
    cout << "enter a palindrome please." << endl;
    //getline allows the program to pick up the entire line of what the user enters, including 
    //spaces
    getline(cin, response);
    if (response.length() > 80){
        //if they enter more than 80 characters, it will tell them not to do that, and restart
        //the function
        cout << "only enter up to 80 characters" << endl;
        main();
    }else if (response.length() == 0){
        //this line is a fix for a previous bug that would not let the user enter the 
        //palindrome after restarting, it knew there was nothing in the string and did it
        //anyways, so if there is nothing in the string, it takes input again
        getline(cin, response);
    }
    //goes to the funnction removing all spaces and non-alphanumeric characters
    checkn();
    return 0;
}
//this function removes all spaces and non-alphanumeric characters
int checkn(){
    //lets gets the number of valid characters (stands for letters) in the response
    lets = 0;
    for (int i = 0; i < response.length(); i++){
        //the isalpha condition makes sure it is a letter
        if (isalpha(response[i])){
            //stores the contents of response in an array in the for loop
            store[lets] = response[i];
            //increases lets so it always puts it into the next place in store
            lets++;
        }else{
            //if they enter a space or a special character, it does not include that in the 
            //palindrome and moves on.
        }
    }
    //this segment makes it so if the palindrome has an odd number of characters,
    //half, which will subtract from lets, equals one
    if (lets % 2 == 1){
        int half = 1;
    }else{
        int half = 0;
    }
    //goes to the function which checks for a palindrome.
    palin();
    return 0;
}
int palin(){
    int flag;
    //halfs purpose is so if the user enters a palindrome with an odd number of characters, 
    //it will check the letters past the middle letter, and before it, because otherwise,
    //words like oko would not be counted as palindromes.
    lets -= half;
    for (int o = 0; o < (lets/2); o++){
        //appends the first half of store to palf, because palf will be compared with
        //the second half of store, or the palindrome.
        palf[o] = store[o];
    }
    //countopalf makes sure the compared character from palf is increasing.
    int countopalf = 0;
    for (int u = ((lets + half)- 1); u > (lets / 2); u--){
        //the condition makes sure that it starts comparing at the last character in store,
        //then goes one lower every loop, and doesnt go below halfway through store.
        if (store[u] == palf[countopalf]){
            //if it equals palf, it moves on to the next character of palf
            countopalf++;
        }else{
            //if it does not equal palf, flag is set to one and the loop breaks,
            //because it is not a palindrome.
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        //if the user does not enter a palindrome, (according to flag)
        //all the arrays and variables are reset and the program goes back to the beginning
        //function.
        //it also tells them that is not a palindrome.
        cout << "that is not a palindrome" << endl;
        flag = 0;
        std::fill_n(store, 80, 0);
        std::fill_n(palf, 40, 0);
        half = 0;
        lets = 0;
        main();
    }else{
        //otherwise, the program says goodjob, tells them the palindrome they entered, 
        cout << "you entered " << store << " which is a palindrome! Great job!" << endl;
        //and goes to the end function.
        end();
    }
    return 0;
}
//this function asks the user whether they want to restart or exit, and makes
//sure they only enter restart or exit.
int end(){
    //string used for user input.
    string proposal;
    cout << "Good job! You made a palindrome!" << endl;
    cout << "Would you like to exit the program, or restart? (exit, restart)" << endl;
    //gets user input.
    cin >> proposal;
    //the below line makes the user input that was entered lowercase, to avoid 
    //RESTART not being seen as restart or vice versa.
    transform(proposal.begin(), proposal.end(), proposal.begin(), :: tolower);
    if (proposal == "exit"){
        //if the user wishes to exit, program says goodbye and exits the program.
        cout << "Ok goodbye." << endl;
        exit(0);
    }else if (proposal == "restart"){
        //if the user wants to restart, the program resets all the arrays and
        //variables, says Again!! and goes back to the beginning function.
        cout << "Again!!" << endl;
        std::fill_n(store, 80, 0);
        std::fill_n(palf, 40, 0);
        half = 0;
        lets = 0;
        cin.clear();
        main();
    }else{
        //however, if the user does not enter either restart or exit, the program
        //tells them they screwed up, and makes them enter it again.
        cout << "Only enter exit, or restart." << endl;
        end();
    }
    return 0;
}
