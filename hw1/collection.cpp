/*

#Filename: collection.cpp
#Name: Seth Roller
#Date: 2/12/19
#Program Name: assign2.cpp
#Assignment Number: 2
#Problem: Creating a template class to
hold objects with a number of functions
#Flow: The collection.cpp file contains all of the filled
in member functions starting with the constructor 
and ending with the operator overloads
#Sources:
*Andrew Chupka-on how arrays function in C++
*http://mathcs.wilkes.edu/~bracken/cs226/sp2019/labs.html
*Dr. Bracken helped me with the opertors 

I have thoroughly tested my code and it works properly

*/

template<class T>
collection<T>:: collection() {
  
  cout << "Constructor is Executing" << endl;

  size = 0;
}


template<class T>
bool collection<T>:: isEmpty() {
  
  if (size == 0)
    return true;
  
  else
    return false;
}


template<class T>
void collection<T>:: makeEmpty() {
  size = 0;
}


template<class T>
bool collection<T>:: insert(T item) {
  if (size == MAX)
    return false;
  
  else {
    theBox[size++] = item;
    return true;
  }

}


template<class T>
bool collection<T>:: remove(int& removeRef) {
  
  if (size > 0) {
    // set the ref var to the item being removed
    removeRef = theBox[size - 1];
    size--;
    return true;
  }

  else
    return false;
}


template<class T>
bool collection<T>:: contains(T item) {

  // loop through until found
  for (int i = 0; i < size; i++)
    if (theBox[i] == item)
      return true;
  return false;
  
}

template<class T>
void collection<T>:: display() {

  for (int i = 0; i < size; i++)
    cout << theBox[i] << "\n";
  cout << endl;

}

template<class T>
void collection<T>::operator = (const collection <T>&Rhs) {
  // dr bracken helped with how to call theBox from
  // the Rhs object
  size = Rhs.size; 
  
  for (int k = 0; k < Rhs.size; k++) {
    theBox[k] = Rhs.theBox[k];
  }

}


template<class T>
bool collection<T>::operator == (const collection <T>&Rhs) {

  if (Rhs.size != size)
    return false;

  // if the sizes match, check for contents
  for (int i = 0; i < Rhs.size; i++) {
    if (theBox[i] != Rhs.theBox[i])
      return false;
  }
  return true;

}

