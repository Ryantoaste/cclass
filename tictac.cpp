#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;
int y;
int win;
int xwins;
int owins;
int end();
string victor;
int victory();
int rndom;
int turn = 1;
string playersnum;
string player1;
string player2;
string wrote;
int mark();
int play();
string places[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
int other();
string takelist[9];
int done = 0;
int main(){
    cout << "This is tic tac toe. Are there 2 players or 1 player?" << endl;
    cin >> playersnum;
    if (playersnum == "2" || playersnum == "1"){
        string xo;
        cout << "Will you be x or o player one?" << endl;
        cin >> xo;
        if (xo == "x" || xo == "o"){
            player1 = xo;
            if (xo == "x"){
                cout << "Player 2, you are o." << endl;
                player2 = "o";
            }else{
                cout << "Player 2, you are x." << endl;
                player2 = "x";
            }
        }else{
            cout << "Only say x or o please" << endl;
            main();
        }
    }else{
        cout << "Only say 1 or two for number of players." << endl;
        main();
    }
    mark();
    play();
    return 0;
}
int mark(){
    if (turn%2 == 1){
        wrote = player1;
        victor = "Player 1";
    }else{
        wrote = player2;
        victor = "Player 2";
    }
    return 0;
}
int play(){
    done = 0;
    string move;
    cout << "| " << places[0] << " | " << places[1] << " | " << places[2] << endl;
    cout << "| " << places[3] << " | " << places[4] << " | " << places[5] << endl;
    cout << "| " << places[6] << " | " << places[7] << " | " << places[8] << endl;
    cout << "Which one will you play? " << endl;
    cin >> move;
    for (int i = 0; i < 9; i++){
        if (places[i] == move){
            for (int l = 0; l < 9; l++){
                if (places[i] == takelist[l]){
                    cout << "That place is taken." << endl;
                    play();
                }
            }
            takelist[i] = places[i];
            places[i] = wrote;
            done = 1;
            turn += 1;
        }
    }
    if (done == 0){
        cout << "Only type the numbers in the grid to make a move." << endl;
        play();
    }else if (playersnum == "1"){
        victory();
        mark();
        other();
    }else{
        victory();
        mark();
        play();
    }
    return 0;
}
int victory(){
    if (wrote == places[0] && wrote == places[4] && wrote == places[8]){
        win = 1;
    }else if (wrote == places[0] && wrote == places[3] && wrote == places[6]){
       win = 1;
    }else if (wrote == places[0] && wrote == places[1] && wrote == places[2]){
        win = 1;
    }else if (wrote == places[1] && wrote == places[4] && wrote == places[7]){
        win = 1;
    }else if (wrote == places[2] && wrote == places[4] && wrote == places[6]){
        win = 1;
    }else if (wrote == places[2] && wrote == places[5] && wrote == places[8]){
        win = 1;
    }else if (wrote == places[3] && wrote == places[4] && wrote == places[5]){
        win = 1;
    }else if (wrote == places [6] && wrote == places[7] && wrote == places[8]){
        win = 1;
    }
    if (win == 1){
        cout << victor << " Has won the game! The game took " << turn << " turns!" << endl;
        end();
    }else if(turn == 10){
        cout << "There is a tie between player 1 and 2. Nobody wins." << endl;
        victor = "";
        wrote = "";
        end();
    }
    return 0;
}
int end(){
    if (wrote == "o"){
        owins++;
    }else if (wrote == "x"){
        xwins++;
    }
    cout << "o has won " << owins << " times and x has won " << xwins << " times." << endl;
    cout << "would you like to exit or restart? ";
    string finalDes;
    cin >> finalDes;
    if (finalDes == "exit") {
        cout << "goodbye." << endl;
        exit(0);
    }else if(finalDes == "restart") {
        cout << "Again!" << endl;
        for (int i = 0; i < 9; i++){
            takelist[i] = "";
        }
        std::fill_n(places, 9, 0);
        places[0] = "1"; places[1] = "2"; places[2] = "3"; places[3] = "4"; places[4] = "5";
        places[5] = "6"; places[6] = "7"; places[7] = "8"; places[8] = "9";
        turn = 1;
        win = 0;
        main();
    }
    return 0;
}
int other(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rndom(0,8);
    for (int i = 0; i < 9; i++){
        cout << places[i] << " that was in places" << endl;
    }
    if (places[rndom(rng)] == "x" || places[rndom(rng)] == "o"){
        other();
    }
    cout << places[rndom(rng)] << " what was in places?" << endl;
    places[rndom(rng)] = wrote;
    for (int i = 0; i < 9; i++){
        cout << places[i] << " also was places" << endl;
    }
    turn += 1;
    victory();
    mark();
    play();
    return 0;
}
