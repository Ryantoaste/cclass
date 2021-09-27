#include <iostream>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;
string response;
char store [80];
int checkn();
int lets;
int half;
int palin();
char palf [40];
int countopalf;
int flag;
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
    lets -= half;
    for (int o = 0; o < (lets/2); o++){
        palf[o] = store[o];
    }
    for (int u = ((lets / 2)+ half); u < (lets + half); u++){
        countopalf = 0;
        if (store[u] == palf[countopalf]){
            
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
    }
    return 0;
}


/*
int main(){
  string str;
  cout<<"Enter a string: ";
  getline(cin,str);
  int flag=0;
 // Checking if string contians special character
  for(int i=0;i<str.length();i++)
  {
    if ((str[i]>=48 && str[i]<=57)||
        (str[i]>=65 && str[i]<=90)||
        (str[i]>=97 && str[i]<=122))
        {
          continue;
        }
    else
    {
      cout<<"String contains special character.\n";
      flag=1;
      break;
    }
  }
  if(flag==0)
  {
    cout<<"There is no special character in the string.\n";
  }
  return 0;
}*/
