#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <sstream>
/* cin >> checkinput;
for (int i = 0, i < checkinput.length(); i++)
{
    if (isdigit(checkinput[i]) == false)
    {
        ask()
    }
}
stringstream geek(checkinput);
geek >>input
*/
using namespace std;
int rndom;
int ask();
int main(){
    srand((unsigned)time(0));
    rndom = (rand()%100)+1;
    cout << rndom << endl;
    ask();
    return 0;
}
int ask (){
    cout << rndom << endl;
    int guess = 0;
    cout << "guess a number between 1 and 100, if you guess it, you win." << endl;
    if ((cin >> guess)){
        cout << "enter a number please.";
        cin.clear();
        cin.ignore(1000);
        ask();
    }
    if (guess == rndom){
        cout << "you win!";
    }
    if (guess > rndom){
        cout << "guess lower" << endl;
        ask();
    }
    if (guess < rndom){
        cout << "guess higher" << endl;
        ask();
    }
    return 0;
}
