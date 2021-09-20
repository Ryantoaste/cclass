#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <sstream>
using namespace std;
int rndom;
int ask();
int final();
int input = 0;
int guesses = 0;
int main(){
    srand((unsigned)time(0));
    rndom = (rand()%100)+1;
    cout << rndom << endl;
    ask();
    return 0;
}
int ask (){
    string guess = "";
    cout << "guess a number between 1 and 100, if you guess it, you win." << endl;
    cin >> guess;
    for (int i = 0; i < guess.length(); i++){
        if (isdigit(guess[i]) == false){
            cout << "enter a number please." << endl;
            guesses ++;
            ask();
        }
    }
    stringstream geek(guess);
    geek >> input;
    if (input == rndom){
        guesses ++;
        cout << "you won in " << guesses << " guesses!" << endl;
        final();
    }
    else if (!(input <= 100 && input >= 1 )){
        cout << "enter a number between 1 and 100" << endl;
        guesses ++;
        ask();
    }
    else if (input > rndom){
        cout << "guess lower" << endl;
        guesses ++;
        ask();
    }
    else if (input < rndom){
        cout << "guess higher" << endl;
        guesses ++;
        ask();
    }
    return 0;
}
int final(){
    string answer = "";
    cout << "Would you like to, exit (1), or restart the game(2)? " << endl;
    cin >> answer;
    if (answer == "1"){
        cout << "goodbye.";
        exit(0);
    }
    else if (answer == "2"){
        cout << "here we go again!" << endl;
        input = 0;
        guesses = 0;
        main();
    }
    else{
        cout << "please enter only one or two." << endl;
        final();
    }
    return 0;
}
