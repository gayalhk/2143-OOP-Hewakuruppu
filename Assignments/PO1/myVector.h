//Name - Gayal Hewakuruppu
//OOP program 1
//File - myVector.h

#include <iostream>

using namespace std;

class myVector{
private:
  int *theVector; //Pointer to integer array
  int vSize;//Initial size of array
  int index; //Always stays at the next free space
public:
  //Parameterized constructor
  myVector(int size);
  //Returns the size of the array
  int size();
  //Returns the % of the array that is full
  double percentFull();
  //Adds an item to the end of vector array
  void push_back(int);
  //Deletes item in the end of the vector array
  void pop_back();
  //Increase the size of array by 1.5 times
  int* increase_vec();
  //decrease the size of vector by half
  int* decrease_vec();
  //print out vector
  void print();
};
