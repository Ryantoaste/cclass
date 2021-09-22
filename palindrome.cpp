#include <iostream>
#include <sstream>
#include <typeinfo>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int i;
    char response;
    for (i = 0; i < 6; i++){
        cout << "mibecraft" << endl;
    }
    cout << "what do you think of that" << endl;
    cin >> response;
    response = response + 32;
    cout << response << endl;
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
