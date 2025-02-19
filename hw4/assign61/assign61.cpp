/*
#Filename: assign61.cpp

#Author: Seth Roller

#Date: 3/19/19

#Program Name: assign61.cpp

#Assignment Number: 6.1

#Problem: Will create a abstract data type(ADT)
queue that will hold structs that contain
an integer and a pointer to a queueNode. This queue 
is a circular one

#Flow: The layout the main program will separate
function calls that never edit the queues contents 

#Sources:
*http://mathcs.wilkes.edu/~bracken/cs226/
*link above was used for the skeleton files

I have thoroughly tested my code and it works properly 

 */
#include<fstream>
#include<cassert>
#include<iostream>
#include"queuei.h"
#include<string>

int main()
{
  //DECLARATIONS 
  string fn;
  ifstream fin;
  int newitem;
  bool success;
  queueClass queue1;
  //below are the ints for passing
  //into functions and the sum/average
  int sum = 0;
  int adder = 0;
  int average = 0;
  
  cout<<"please enter the name of the file containing your data:";
  cin>>fn;
  cout<<"\nThe file name entered is "<<fn<<endl;
  fin.open(fn.c_str());
  assert(fin.is_open());
  while(true)
  {
     fin>>newitem;
     if(fin.eof())
     {
        break;
     }
     cout<<"About to insert "<< newitem <<" into the queue "<<endl;
     
     queue1.QueueInsert(newitem, success);
     if (success == true)
       cout << "Successfully inserted " << newitem << endl;
     //Insert newitem into the queue     
     
  }//end of input loop

  
  //print the contents of the queue
  cout << "The queue contents are:" << endl;
  
  queue1.QueuePrint();
  
  int currentNum = queue1.NumberOfQueueElements();

  //calculate sum and average

  cout << "\nTime to add up to find the sum" << endl << endl;
  for (int i = 0; i < currentNum; i++) {
    queue1.QueueDelete(adder, success);
    if (success == true) {
      sum = sum + adder;
      cout << "successfully dequeued " << adder << endl;
    }
    queue1.QueueInsert(adder, success);
    if (success == true)
      cout << "successfully enqueued " << adder << endl;
  } // end of for

  
  if (currentNum != 0)
    average = sum / currentNum;

  //average and sum printing
  cout << "The sum: " << sum << endl;
  cout << "The average: " << average << endl; 
  

}//end of main
