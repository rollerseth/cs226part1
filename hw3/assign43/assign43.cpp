/*
#Filename: assign43.cpp

#Author: Seth Roller

#Date: 3/14/19

#Program Name: assign43.cpp

#Assignment Number: 4.3

#Problem: Will create a abstract data type(ADT)
list that will hold structs that contain
an integer and a pointer to a node. This list 
is a circular one. Will be solving the Josephus
problem 

#Flow: The main file the layout for the menu
decision process. This utilizes a while true
loop until specified

#Sources:
*http://mathcs.wilkes.edu/~bracken/cs226/
*link above was used for the skeleton files

I have thoroughly tested my code and it works properly 

 */

#include "listj.h"
using namespace std;


int main()
{
  // for turnin
  cout << endl;

  int itemN = 0;
  int itemM = 0;
  int result;

  while (true) {
    cout << "Enter N, the number of nodes in the list: ";
    cin >> itemN;
    if (cin.good() && itemN > 0) {
      cout << "You entered " << itemN << "\n\n";
      break;
    }
    cout << endl << endl;
    cout << "Invalid input, enter an integer";
    cout << endl << endl;
    cin.clear();
    cin.ignore(120, '\n'); 
  }

  while (true) {
    cout << "Enter M, the number of nodes in the list: ";
    cin >> itemM;
    if (cin.good() && itemM >= 0) {
      cout << "You entered " << itemM  << "\n\n";
      break;
    }
    cout << endl << endl;
    cout << "Invalid input, enter an integer";
    cout << endl << endl;
    cin.clear();
    cin.ignore(120, '\n'); 
  }

  list mylist;

  for (int i = 1; i <= itemN; i++)
    mylist.insertElement(i);

  cout << "my list is" << endl;
  mylist.displayList();
  result = mylist.Josephus(itemM);

  cout << "The winner with n= " << itemN << " and m= ";
  cout << itemM << " is " << result << endl << endl;
  
}
