//all the imports I need 
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
//all the variables I need universally available
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
//this function will ask the user if there are two players or one player,
//and if they want to be x or o.
int main(){
    //asks for number of players
    cout << "This is tic tac toe. Are there 2 players or 1 player?" << endl;
    cin >> playersnum;
    if (playersnum == "2" || playersnum == "1"){
        string xo;
        //asks if they want to be x or o
        cout << "Will you be x or o player one?" << endl;
        cin >> xo;
        if (xo == "x" || xo == "o"){
            //then it tells player two who they are
            player1 = xo;
            if (xo == "x"){
                cout << "Player 2, you are o." << endl;
                player2 = "o";
            }else{
                cout << "Player 2, you are x." << endl;
                player2 = "x";
            }
        }else{
            //if they don't say x or o, the program gives them a warning and starts the function
            //again.
            cout << "Only say x or o please" << endl;
            main();
        }
    }else{
        //same if they don't enter one or two for number of players.
        cout << "Only say 1 or two for number of players." << endl;
        main();
    }
    //advances the game
    mark();
    play();
    return 0;
}
int mark(){
    //this function determines whose turn it is
    //and makes sure the correct symbol shows on the grid.
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
    //this function outputs the tic tac toe grid, asks the user where they want
    //to place the x/o, makes sure the input is valid, and assigns it to the correct place.
    done = 0;
    string move;
    //the grid.
    cout << "| " << places[0] << " | " << places[1] << " | " << places[2] << endl;
    cout << "| " << places[3] << " | " << places[4] << " | " << places[5] << endl;
    cout << "| " << places[6] << " | " << places[7] << " | " << places[8] << endl;
    cout << "Which one will you play? " << endl;
    cin >> move;
    for (int i = 0; i < 9; i++){
        //checks if it is possible to place 
        if (places[i] == move){
            //makes sure place is not already taken.
            for (int l = 0; l < 9; l++){
                if (places[i] == takelist[l]){
                    cout << "That place is taken." << endl;
                    play();
                }
            }
            //if it is not, makes it appear on grid, puts it on takelist
            //advances the turn, and makes done equal to one.
            takelist[i] = places[i];
            places[i] = wrote;
            done = 1;
            turn += 1;
        }
    }
    if (done == 0){
        //if done is equal to zero, that means the player did not
        //enter a valid character, so it starts the function over again.
        cout << "Only type the numbers in the grid to make a move." << endl;
        play();
    }else if (playersnum == "1"){
        //if there is one player, goes to the victory function, 
        //then advances in mark function,
        //then goes to the function where the "computer" makes a move.
        victory();
        mark();
        other();
    }else{
        //if the player number is two, goes to the victory function, 
        //then the mark function to advance turns, then is restarts the play function.
        victory();
        mark();
        play();
    }
    return 0;
}
int victory(){
    //this function is responsible for determining whether or not either player has
    //won, or if there is a tie. There is definitely a more efficient way to do
    //this other than a ton of if statements, but I want to finish this project soon.
    //all the if statements account for any three in a rows, and if there is one, 
    //it sets win to one.
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
        //if win hasa been set to one, the program will say that either player one or
        //player two haas won the game, and goes to the final function.
        cout << victor << " Has won the game! The game took " << turn << " turns!" << endl;
        end();
    }else if(turn == 10){
        //if there has been ten turns, but no one has won yet, that means there is a tie,
        //so it says so, makes sure the end function will not say anybody won by 
        //setting victor and wrote to 0, then it goes to the ending function.
        cout << "There is a tie between player 1 and 2. Nobody wins." << endl;
        victor = "";
        wrote = "";
        end();
    }
    return 0;
}
int end(){
    //this function is in charge of determining if the user wants to exit or restart
    //the program, adding to number of x wins and o wins if applicable,
    //and exiting or restarting the program.
    if (wrote == "o"){
        //if wrote is o, (which is who won from the last turn, )
        //(this is the same for x) adds to owins, (or xwins) to keep
        //track of wins for x and o.
        owins++;
    }else if (wrote == "x"){
        xwins++;
    }
    //so if the function restarts, it doesn't add another victory.
    wrote = "";
    //says how many times o has won, and how many times x has won.
    cout << "o has won " << owins << " times and x has won " << xwins << " times." << endl;
    //asks the user if they would like to exit or restart.
    cout << "would you like to exit or restart? ";
    //takes the users input
    string finalDes;
    cin >> finalDes;
    if (finalDes == "exit") {
        //if the user decides to exit, the program says goodbye, and exits.
        cout << "goodbye." << endl;
        exit(0);
    }else if(finalDes == "restart") {
        //if the user says restart, the program says again, resets takelist, places, 
        //turn, and win then it goes back to the first function.
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
    }else{
        //if the user enters anything other than exit or restart, the computer
        //tells them, and restarts the function.
        cout << "Only say exit or restart." << endl;
        end();
    }
    return 0;
}
int other(){
    //this funtion is in charge of randomly chhosing a number between 0 and 8,
    //checking if the chosen array element is already occupied in places, then
    //if so, rechoosing a number, and then making that element equal to x or o
    //
    //choosing a random number
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rndom(0,8);
    //if the chosen element contains either x or o, the function will restart
    if (places[rndom(rng)] == "x" || places[rndom(rng)] == "o"){
        other();
    }else{
        //if not, makes the random number element equal to either 
        //x or o, adds to turn, then goes to determine victory, then advances\
        //in mark, then goes to the play function.
        places[rndom(rng)] = wrote;
        turn += 1;
        victory();
        mark();
        play();
    }
    return 0;
}
