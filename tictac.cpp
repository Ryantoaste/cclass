#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int rndom;
string playersnum;
string player1;
string player2;
int play();
string places[3] [3];
string upleft;
string upmid;
string uprig;
string medleft;
string medmid;
string medrig;
string dnleft;
string dnmid;
string dnrig;
int other();
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
                player2 = "o";
            }else{
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
    cout << player1 << " " << player2 << " " << playersnum << endl;
    return 0;
}
int play(){
    string move;
    cout << "| " << places[0] << " | " << places[1] << " | " << places[2] << endl;
    cout << "| " << places[3] << " | " << places[4] << " | " << places[5] << endl;
    cout << "| " << places[6] << " | " << places[7] << " | " << places[8] << endl;
    cout << "which one will you play? " << endl;
    getline(cin, move);
    return 0;
}
int other(){
    srand((unsigned)time(0));
    rndom = (rand()%100)+1;
    cout << rndom << endl;
    return 0;
}
