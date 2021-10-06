#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
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
    cout << "this is tic tac toe. are there 2 players or 1 player?" << endl;
    cin >> playersnum;
    if (playersnum == "2" || playersnum == "1"){
        string xo;
        cout << "will you be x or o player one?" << endl;
        cin >> xo;
        if (xo == "x" || xo == "o"){
            player1 = xo;
            if (xo == "x"){
                cout << "player 2, you are o." << endl;
                player2 = "o";
            }else{
                cout << "player 2, you are x." << endl;
                player2 = "x";
            }
        }else{
            cout << "only say x or o please" << endl;
            main();
        }
    }else{
        cout << "only say 1 or two for number of players." << endl;
        main();
    }
    play();
    return 0;
}
int mark(){
    if (turn%2 == 1){
        wrote = player1;
    }else{
        wrote = player2;
    }
    return 0;
}
int play(){
    mark();
    done = 0;
    string move;
    cout << "| " << places[0] << " | " << places[1] << " | " << places[2] << endl;
    cout << "| " << places[3] << " | " << places[4] << " | " << places[5] << endl;
    cout << "| " << places[6] << " | " << places[7] << " | " << places[8] << endl;
    cout << "which one will you play? " << endl;
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
    cout << playersnum << endl;
    if (done == 0){
        cout << "Only type the numbers in the grid to make a move." << endl;
        play();
    }else if (playersnum == "1"){
        other();
    }
    return 0;
}
int victory(){
    
    return 0;
}
int other(){
    srand((unsigned)time(0));
    rndom = (rand()%8)+0;
    play();
    return 0;
}
