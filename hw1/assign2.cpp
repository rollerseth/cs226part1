/*

#Filename: assign2.cpp
#Name: Seth Roller
#Date: 2/12/19
#Program Name: assign2.cpp
#Assignment Number: 2
#Problem: Creating a user interface to edit
the collections defined in the main program
#Flow: The assign2.cpp file starts out with a menu
displaying the options then goes into while true 
loop prompting users for options
#Sources:
*Andrew Chupka-on how arrays function in C++
*http://mathcs.wilkes.edu/~bracken/cs226/sp2019/labs.html
*Dr. Bracken helped me with the opertors 

I have thoroughly tested my code and it works properly

*/

#include "collection.h"

int main() {
  
  // for turnin
  cout << endl;

  // DECLARATIONS

  // the two collection defined have an array
  // of ints, where the max size is 20 
  collection<int>first;
  collection<int>second;
  bool answer = true;
  bool theLoop = true;
  int option = 0;
  int item = 0;
  int removeRef = 0;

  cout << endl;
  cout << "Name: Seth Roller" << endl;
  cout << "Lab Name: Class Templates" << endl;
  cout << "Problem: A collection template has been implemented to";
  cout << endl;
  cout << "modify two collections of integers." << endl;
  cout << endl;

  // the choices to be outputted 
  cout << "1. Add an item onto collection1" << endl;
  cout << "2. Add an item onto collection2" << endl;
  cout << "3. Remove an item from collection1" << endl;
  cout << "4. Remove an item from collection2" << endl;
  cout << "5. Display collection1" << endl;
  cout << "6. Display collection2" << endl;
  cout << "7. Compare collection1 and collection2" << endl;
  cout << "8. Assign collection1 to collection2" << endl;
  cout << "9. Assign collection2 collection1" << endl;
  cout << "10.Is collection1 empty" << endl;
  cout << "11.Is collection2 empty" << endl;
  cout << "12.Make collection1 empty" << endl;
  cout << "13.Make collection2 empty" << endl;
  cout << "14.Determine if an item is in collection1" << endl;
  cout << "15.Determine if an item is in collection2" << endl;
  cout << "16.Exit\n" << endl;

  // infinite loop that prompts users
  // for an option 
  while (theLoop) {
    
    cout << "Enter your option: ";
    cin >> option;
    cout << endl; // for turnin
    // checks to see if the entered input is an integer
    if (!cin.good()) {
      cin.clear();
      cin.ignore(60, '\n');
      
      cout << "Invalid input!" << endl << endl;
      cout << endl;
      cout << "Please enter an integer that is between 1 and 16";
      cout << "\n\n";
      
    }

    // then goes to check if the integer is valid
    // and processes the integer through a switch case
    else {
    
    cout << "You entered " << option << endl << endl;

    //checks to see if option is within bounds
    if (option >= 1 && option < 16) {

      switch(option) {

      case 1:
	// cases with entering another integer
	// have another infinite loop until valid
	// input is entered
	while (true) {
	  cout << "Enter an integer: ";
	  cin >> item;
	  if (cin.good() && option == option) {
	    answer = first.insert(item);
	    cout << endl; // for turnin
	    cout << "You entered " << item << endl << endl;
	    break;
	  }
	  cout << endl << endl;
	  cout << "Invalid input, enter an integer";
	  cout << endl << endl;
	  cin.clear();
	  cin.ignore(120, '\n');
	}
	if (answer == true)
	  cout << item << " was added to collection1" << "\n\n";
	else {
	  cout << item << " was not added to collection1 since";
	  cout << " collection1 is full" << "\n\n";
	}
	break;
	
      case 2:
	while (true) {
	  cout << "Enter an integer: ";
	  cin >> item;
	  if (cin.good() && option == option) {
	    answer = second.insert(item);
	    cout << endl; // for turnin
	    cout << "You entered " << item << "\n\n";
	    break;
	  }
	  cout << endl << endl;
          cout << "Invalid input, enter an integer";
          cout << endl << endl;
	  cin.clear();
	  cin.ignore(120, '\n');
	}
	if (answer == true)
	  cout << item << " was added to collection2" << "\n\n";
	else {
	  cout << item << " was not added to collection2 since ";
	  cout << "collection2 is full" << "\n\n";
	}
	break;

      case 3:
	answer = first.remove(removeRef);
	if (answer == true) {
	  cout << removeRef << " was removed from collection1" << endl;
	  cout << "\n\n";
	}
	else {
	  cout << "collection1 is empty so nothing can be removed";
	  cout<< "\n\n";
	}
	break;
	
      case 4:
	answer = second.remove(removeRef);
	if (answer == true) {
	  cout << removeRef << " was removed from collection2" << endl;
	  cout << "\n\n";
	}
	else {
	  cout << "collection2 is empty so nothing can be removed";
	  cout << "\n\n";
	}
	break;

      case 5:
	first.display();
	break;

      case 6:
	second.display();
	break;

      case 7:
	if (first == second)
	  cout << "collection1 and collection2 are equal" << "\n\n";
	else
	  cout << "collection1 and collection2 are not equal" << "\n\n";
	break;

      case 8:
	second = first;
	cout << "collection2 now has the same contents ";
	cout << "as collection1" << "\n\n";
	break;

      case 9:
	first = second;
	cout << "collection1 now has the same contents ";
	cout << "as collection2" << "\n\n";
	break;

      case 10:
	answer = first.isEmpty();
	if (answer == true)
	  cout << "collection1 is empty" << endl << endl;
	else
	  cout << "collection1 is not empty" << endl << endl;
	break;

      case 11:
	answer = second.isEmpty();
	if (answer == true)
	  cout << "collection2 is empty" << endl << endl;
	else
	  cout << "collection2 is not empty" << endl << endl;
	break;

      case 12:
	first.makeEmpty();
	cout << "collection1 is now empty" << "\n\n";
	break;

      case 13:
	second.makeEmpty();
	cout << "collection2 is now empty" << "\n\n";
	break;

      case 14:
	while (true) {
	  cout << "Enter an integer: ";
	  cin >> item;
	  if (cin.good()) {
	    answer = first.contains(item);
	    cout << endl; // for turnin
	    cout << "You entered " << item << endl << endl;
	    break;
	  }
	  cout << endl << endl;
          cout << "Invalid input, enter an integer";
          cout << endl << endl;
	  cin.clear();
	  cin.ignore(120, '\n');
	}
	if (answer == true) {
	  cout << "collection1 does contain " << item;
	  cout << endl << endl;
	}
	else {
	  cout << "collection1 does not contain ";
	  cout << item << endl << endl;
	}
	break;

      case 15:
	while (true) {
	  cout << "Enter an integer: ";
	  cin >> item;
	  if (cin.good()) {
	    answer = second.contains(item);
	    cout << endl; // for turnin
	    cout << "You entered " << item << endl << endl;
	    break;
	  }
	  cout << endl << endl;
          cout << "Invalid input, enter an integer";
          cout << endl << endl;
	  cin.clear();
	  cin.ignore(120, '\n');
	}
	if (answer == true)
	  cout << "collection2 does contain " << item << endl << endl;
	else {
	  cout << "collection2 does not contain " << item;
	  cout << endl << endl;
	}
	break;
	

      }

    }
    

    // if the user choose option 16
    else if (option == 16) {
      cout << "You have exited the program" << endl;
      cout << endl;
      theLoop = false;
    }

    // if a user enters an integer out of bounds
    else {
      cout << "Please enter an integer that is between 1 and 16";
      cout << "\n\n";
    }
    }

  }
  
  return 0; // for int main 
  
    }
