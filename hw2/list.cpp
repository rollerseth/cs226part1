/*
#Filename: list.cpp

#Author: Seth Roller

#Date: 2/21/19

#Program Name: assign4a.cpp

#Assignment Number: 4a

#Problem: Will create a abstract data type(ADT)
list that will hold structs that contain
an integer and a pointer to a node. 

#Flow: The cpp file contains the function declarations. These
include the constructor, deconstructor, display, insert, and
so on

#Sources:
*http://mathcs.wilkes.edu/~bracken/cs226/sp2012/assign4a.html
*link above was used for the skeleton files

I have thoroughly tested my code and it works properly 

 */

#include "list.h"

list::list()
{
  // set the head to NULL and element to 0
  // for intializing 
 head=NULL;
 numberofelements = 0;
 cout << "Constructor is executing" << "\n\n";
}


list::~list()
{
  while (numberofelements > 0) {
    deleteElement(head->item); //delete next element
  }
  cout << "Deconstructor is executing" << "\n\n";
}


  //list operations
  void list::displayList() const
  {
    
    if (numberofelements > 0) {
      node *show = head;
      for (int i = 0; i < numberofelements; i++) {
	cout << show->item << endl;
	if (show->next != NULL)
	  show = show->next;
      }
      cout << endl;
    } // end of if

    else {
      cout << "The list is empty" << "\n\n";
    }
    
  } // end of function


  int list::findElement(int element) const
  {
     //note return is to satisfy compiler
    //you must code this function to return the appropriate value

    if (numberofelements == 0)
      return 0;

    else {
      // count is for the position of the
      // element if found
      // the positions start at 1 since 0
      // represents a number not being found
      int count = 0;
      node *tracker = head;
      while (count < numberofelements) {
	if (tracker->item == element) 
	  return (count + 1);
	count++;
	tracker = tracker->next;
      }
      return 0;
    } // end of else
    
  } // end of findElement


  void list::insertElement(int element)
  {

    // nothing is in the list
    if (numberofelements == 0) {
      head = new node;
      head->item = element;
      head->next = NULL;
    }

    // else will following steps
    else {

      node *temp = new node;
      node *current = head;
      temp->item = element;

      // first check to see if current next is pointing
      // to null and then check if the next item
      // is less than entered element
      while (current->next != NULL && (current->next->item < element)) 
          current = current->next;
      
      // accounts for if element entered is smalled than
      // the head      
      if (head->item > element && numberofelements > 1) {
	temp->next = head;
	head = temp;
      }

      // account insertion in a list size of 1
      else if (numberofelements == 1) {
	if (temp->item > head->item) {
	  head->next = temp;
	  temp->next = NULL;
	} // end of temp/head comparison

	else {
	  temp->next = head;
	  head = temp; 
	} // end of insertion at beginning 
	
	
      } // end of 1 element scenerio

      // will insert at the end and middle of lists
      // any size list of 2 or greater
      else {
	temp->next = current->next;
	current->next = temp;
      }
      
    } //end of first else
    numberofelements = numberofelements + 1;
    
  }//end of function

  bool list::deleteElement(int element)
  {
    if (numberofelements == 0)
      return false;

    else {
      int count = 0;
      node *tracker = head;
      node *previous = new node;
      while (count < numberofelements) {

        if (tracker->item == element) {
	  // if size is 1
	  if (numberofelements == 1) {
	    delete head;
	    head = NULL;
	    numberofelements--;
	    return true;
	  }

	  // if the tracker is of size greater
	  // than one and finds in head
	  else if (tracker == head){
	    node *temp = head->next;
	    delete head;
	    head = temp;
	    numberofelements--;
	    return true;
	  }
	  // size greater than 1 and not in the head
	  // position
	  else {
	    previous->next = tracker->next;
	    delete tracker;
	    tracker = NULL;
	    numberofelements--;
	    return true;
	    
	  }
	}
	// if not found
	// perform these actions
        count++;
	previous = tracker;
	tracker = tracker->next;
      }
      
      return false;
    }// end of else
    
  }//end of function
  
   int list::numberOfElements() const
   {
   return(numberofelements);
  }
